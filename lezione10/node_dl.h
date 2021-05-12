#ifndef NODEDL_H
#define NODEDL_H

#include <iostream>
#include <sstream>

using namespace std;

template<class T>
class NodeDL {
		T value;
		NodeDL<T> * prev;
		NodeDL<T> * next;

	int compareTo(const NodeDL<T>& n) const {
		if(this->value < n.value) 
			return -1;
		if(this->value == n.value)
			return 0;
		if(this->value > n.value) 
			return 1;

		return 0;
	}

	public:

	NodeDL(T value, NodeDL<T> *prev, NodeDL<T> *next):
		value(value), prev(prev), next(next) {}
	NodeDL(T value) : NodeDL(value, NULL, NULL) {}

	void setValue(T value) { this->value = value; }
	void setPrev(NodeDL<T> *prev) { this->prev = prev; }
	void setNext(NodeDL<T> *next) { this->next = next; }

	T getValue() const { return value; }
	NodeDL<T> * getPrev() const { return prev; }
	NodeDL<T> * getNext() const { return next; }

	string toString() const {
		stringstream stream;
		stream << "NodeDL value = " << value << ", prev = " << prev << ", next = " << next;
		return stream.str();
	}

	friend ostream& operator<<(ostream& out, const NodeDL<T>& n) {
		out << n.toString();
		return out;
	}

	bool operator<(NodeDL<T>& n) {
		return this->compareTo(n) < 0;
	}

	bool operator<=(NodeDL<T>& n) {
		return this->compareTo(n) <= 0;
	}

	bool operator>(NodeDL<T>& n) {
		return this->compareTo(n) > 0;
	}

	bool operator>=(NodeDL<T>& n) {
		return this->compareTo(n) >= 0;
	}

	bool operator==(NodeDL<T>& n) {
		return this->compareTo(n) == 0;
	}

};

#endif
