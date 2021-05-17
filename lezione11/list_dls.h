#ifndef LIST_DLS_H
#define LIST_DLS_H

#include <iostream>
#include "node_dl.h"

using namespace std;

template<class T>
class ListDLS {
	NodeDL<T> *head, *tail, *nil;
	int length;
	bool ascend;

	public:

	ListDLS(bool ascend) : head(NULL), tail(NULL), length(0), ascend(ascend) {
			nil = new NodeDL<T>;
	}
	ListDLS() : ListDLS(true) {}

	//verifico se la lista è vuota
	bool isEmpty() {
		return (head == NULL) && (tail == NULL);
	}

	//getter
	NodeDL<T> * getHead() const { return head; }
	NodeDL<T> * getTail() const { return tail; }
	NodeDL<T> * getNil() const { return nil; }
	int getLength() const { return length; }
	bool isAscend() const { return ascend; }

	//non implementiamo metodi setter per evitare di avere situazioni di memoria non consistente
	
	void insertHead(T value) {
		NodeDL<T> * n = new NodeDL<T>(value);

		if(this->isEmpty()) {
			n->setNext(nil);
			n->setPrev(nil);
			head = n;
			tail = n;
			nil->setNext(head);
			nil->setPrev(tail);
		}
		else {
			n->setNext(head);
			head->setPrev(n);
			n->setPrev(nil);
			head = n;
			nil->setNext(head);
		}
		length++;
	}
	



};
