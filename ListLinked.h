#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
 	Node<T>* first;
	int n;

    public:
	ListLinked(){
		first=nullptr;
		n=0;
	}
        
	~ListLinked(){
		while(first!=nullptr){
			Node<T>* aux= first ->next;
			delete first;
			first=aux;
		}
	}

	T operator[](int pos){
		if(pos<0 || pos>n-1){
			throw out_of_range("La posción no es válida");
		}
		Node<T>* aux= first;
		for (int i=0;i<pos;i++){
			aux=aux->next;
		}
		return aux-> data;		
	}

	friend ostream& operator<<(ostream &out, ListLinked<T> &list) {
		Node<T>* aux = list.first;
		while (aux != nullptr) {
       			out << aux->data;
        		aux = aux->next;
    		}
    		return out;
	}

	//Métodos de List
	
	void insert(int pos, T e){
		if(pos<0 || pos>n){
			throw out_of_range("Posición no válida");
		}
		Node<T>* nuevo = new Node<T>(e);
		if(pos==0){
			nuevo->next = first;
			first= nuevo;
			n++;
		}else{
			Node<T>* aux= first;
			for(int i=0;i<(pos-1);i++){
				aux=aux->next;
			}
			nuevo->next = aux ->next;
			aux->next = nuevo;
			n++;
		}			
	}

	void append(T e){
		insert(n,e);
	}

	void prepend(T e){
		insert(0,e);
	}

	T remove(int pos){
		if(pos<0 || pos>=n){
                        throw out_of_range("Posición no válida");
                }
		T dato=(*this)[pos];
		if(pos==0){
			Node<T>* aux = first;
			first=first->next;
			delete aux;
			n--;
			return dato;
		} else {
			Node<T>* aux = first;
			for(int i=0;i<pos-1;i++){
				aux=aux->next;
			}
			Node<T>* borrar = aux -> next;
			aux->next = borrar ->next;
			delete borrar;
			n--;
			return dato;
		}
	}

	T get(int pos){
		if(pos<0 || pos>=n){
                        throw out_of_range("Posición no válida");
                }
		return (*this)[pos];

	}
	
	int search(T e){
		Node<T>* aux = first;
		int cont=0;
		while(aux!=nullptr && aux -> data !=e){
			cont++;
			aux=aux->next;
		}
		if(aux==nullptr){
			return -1;
		} else {
			return cont;
		}
	}

	bool empty(){
		if(first==nullptr){
			return true;
		} else {
			return false;
		}
	
	}

	int size(){
		return n;
	}


};

#endif
