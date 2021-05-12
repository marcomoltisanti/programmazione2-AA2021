#ifndef LIST_DL_H
#define LIST_DL_H

#include <iostream>
#include <sstream>
#include "node_dl.h"

template<class T>
class ListDL {
	NodeDL<T> *head, *tail;
	int length;
	bool ascend;

	void insertAscending(T value) {
		NodeDL<T> * temp = new NodeDL<T>(value);
		if(head == NULL && tail == NULL) {
			this->insertHead(value);
			return;
		}
		if(head->getValue() > value) {
			this->insertHead(value);
			return;
		}
		if(tail->getValue() <= value) {
			this->insertTail(value);
			return;
		}
		NodeDL<T> * current = head;
		//condizione di arresto = nodo corrente minore di value e nodo successivo maggiore o uguale
		while(current->getValue() < value) { // current < temp
			current = current->getNext();
		}

		temp->setPrev(current->getPrev());
		temp->setNext(current);
		current->getPrev()->setNext(temp);
		current->setPrev(temp);
		length++;
	}

	public:

	//ListDL() : head(NULL), tail(NULL), length(0), ascend(true) {}
	ListDL() : ListDL(true) {}
	ListDL(bool ascend) : head(NULL), tail(NULL), length(0), ascend(ascend) {}

	//setter e getter
	void setAscendingOrder() { ascend = true; }
	void setDescendingOrder() { ascend = false; }

	NodeDL<T> * getHead() const { return this->head; }
	NodeDL<T> * getTail() const { return this->tail; }
	bool isAscending() const { return this->ascend; }
	int getLength() const { return this->length; }

	void insertHead(T value) {
		NodeDL<T> * temp = new NodeDL<T>(value);
		if(head == NULL && tail == NULL) { 
			head = temp;
			tail = temp;
		}
		else {
			temp->setNext(head);
			head->setPrev(temp);
			head = temp;
		}

		length++;
	}

	void insertTail(T value) {
		NodeDL<T> * temp = new NodeDL<T>(value);
		if(head == NULL && tail == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->setPrev(tail);
			tail->setNext(temp);
			tail = temp;
		}

		length++;
	}

	void insert(T value) {
		if(this->isAscending()) 
			this->insertAscending(value);
		else
			cout << "to be implemented" << endl;
		return;
	}

	friend ostream& operator<<(ostream& out, const ListDL<T> list) {
		out << "Lista di lunghezza " << list.length << ", head = " << list.head << ", tail = " << list.tail << endl;
		NodeDL<T> * cur = list.head;
		while(cur != NULL) {
			out << "\t" << *cur << endl;
			cur = cur->getNext();
		}

		return out;
	}
};


#endif
