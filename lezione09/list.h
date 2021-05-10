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

	void insertInOrder(T value) {
		Node<T> * temp = new Node<T>(value);
		if(head == NULL) {
			this->insert(temp);
			return;
		}
		if(head->getValue() >= value) {
			temp->setNext(head);
			head = temp;
			length++;
			return;
		}

		Node<T> * prev = head;
	       	Node<T>	* current = head->getNext();

		while(current != NULL) {
			if(prev->getValue() < value && current->getValue() >= value) {
				prev->setNext(temp);
				temp->setNext(current);
				length++;
				return;
			}
			else {
				prev = current; 
				current = current->getNext();
			}
		}

		prev->setNext(temp);
		length++;
		return;
	}

	bool search(T value) {
		if(head == NULL) {
			return false;
		}

		Node<T> * temp = head;
		while(temp != NULL) {
			if(temp->getValue() == value) 
				return true;
			
			temp = temp->getNext();
		}

		return false;
	}

	Node<T> * deleteNode(T value) {
		if(this->search(value)) {
			if(head->getValue() == value) {
				Node<T> * temp = head;
				head = head->getNext();
				length--;
				return temp;
			}	
			Node<T> * prev = head;
			Node<T> * current = head->getNext();
			while(current != NULL) {
				if(current->getValue() == value) {
					prev->setNext(current->getNext());
					length--;
					return current;
				}
				prev = current;
				current = current->getNext();
			}
		}

		return NULL;
	}
	
	int getLength() {
		return this->length;
	}

	Node<T> * getHead() {
		return this->head;
	}
	
	friend ostream& operator<<(ostream& out, const List<T>& l) {
		out << "Lista di lunghezza " << l.length << " head = " << l.head << endl;
		Node<T> * current = l.head;
		while(current != NULL) {
			out << "\t" << current->toString() << endl;
			current = current->getNext();
		}
		return out;
	}
};

#endif
