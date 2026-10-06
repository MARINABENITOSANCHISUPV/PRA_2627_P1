#ifndef NODE_H
#define NODE_H
#include <ostream>
using namespace std;

template <typename T> 
class Node {
    public:
        // miembros públicos
	//Atributos
	T data;
	Node<T>* next;

	//Metodos
	Node(T data, Node<T>*next=nullptr){
		this->data=data;
		this->next=next;

	}

	friend ostream&operator<<(ostream&out, const Node<T> &node){
		out << node.data;
		return out;
	}
    
};

#endif
