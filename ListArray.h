#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "List.h"
using namespace std;

template <typename T> 
class ListArray {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;
		void resize(int new_size){
			T* newArray = new T[new_size];
			for (int i=0;i<n;i++){
				newArray[i]=arr[i];
			}
			delete[] arr;
			arr=newArray;
			max=new_size;
		}
	
	
	public:
		ListArray(){
			n=0;
			arr=new T[MINSIZE];
			max=MINSIZE;
		}
		~ListArray(){
			delete[] arr;
		}
		T operator[](int pos){
			if (pos<0 || pos>n-1){
				throw out_of_range("Posición no valida");
			}
			return arr[pos];
		}
		friend ostream&operator<<(ostream &out,ListArray<T> &list){
			for(int i=0;i<list.n;i++){
				cout<<list.arr[i]<<" ";
			
			}
			cout << endl;
			return out;
		
		}

		//Metodos List.h
		
		void insert(int pos, T e){
			if (pos<0 || pos>n){
				throw out_of_range("Posición no válida");	
			}
			for(int i=n;i>pos;i--){
				arr[i]=arr[i-1];
			}
			arr[pos]=e;
			n++;
		}

		void append(T e){
			insert(n,e);
		}
		void prepend(T e){
			 insert(0,e);
		}

		T remove(int pos){
			if (pos <0 || pos>n){
				throw out_of_range("Posición no válida");
			}
			T aux=arr[pos];
			for(int i=pos;i<n;i++){
				arr[i]=arr[i+1];
			
			}
			n--;
			return aux;
		}

		T get(int pos){
			if (pos <0 || pos>n){
                                throw out_of_range("Posición no válida");
			}
			return arr[pos];
		}

		int search(T e){
			for(int i=0;i<n;i++){
				if(arr[i]==e){
					return i;
				}
			}
			return -1;
		}

		bool empty(){
			if(n==0){
				return true;
		
			}
			return false;
		}

		int size(){
			return n;
		}



};

#endif
