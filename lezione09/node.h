#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <sstream>

using namespace std;

template<class T>
class Node {
	T value;
	Node<T> * next;
	
	public:
	
	Node(T value, Node<T> * next) : value(value), next(next) {}
	Node(T value) : Node(value, NULL) {}
	Node() : Node(0, NULL) {}
	
	Node<T> * getNext() {
		return this->next;
	}
	
	T getValue() {
		return this->value;
	}
	
	void setNext(Node<T> * next) {
		this->next = next;
	}
	
	void setValue(T value) {
		this->value = value;
	}
	
	string toString() {
		stringstream stream;
		stream << "Node value = " << value << ", next = " << next;
		return stream.str();
	}
	
};

#endif