#ifndef LIST_H
#define LIST_H

#include "node.h"

using namespace std;

template<class T>
class List {
	Node<T> * head;
	int length;
	
	public:
	
	List(Node<T> * head) : head(head), length(0) {}
	List() : List(NULL) {}
	
	void insert(Node<T> * n) {
		if(head == NULL) {
			head = n;
			length++;
			return;
		}
		
		Node<T> * current = head;
		while(current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNext(n);
		length++;
	}
	
	void insert(T value) {
		Node<T> * temp = new Node<T>(value);
		this->insert(temp);
	}
	
	int getLength() {
		return this->length;
	}
	
	Node<T> * getHead() {
		return this->head;
	}
	
	friend ostream& operator<<(ostream& out, const List<T>& l) {
		out << "Lista head = " << l.head << endl;
		Node<T> * current = l.head;
		while(current != NULL) {
			out << "\t" << current->toString() << endl;
			current = current->getNext();
		}
		return out;
	}
};

#endif