#ifndef STACK_H
#define STACK_H

#include <iostream>

template<class T>
class Stack {
	int top = -1;
	T *stack;
	int length;

	public: 
	Stack(int length) : length(length) {
		stack = new T[length];
	}
	Stack() : Stack(10) {}
	
	void push(T value) {
		if(this->isFull())
			return;

		stack[++top] = value;
	}

	bool isEmpty() {
		return top == -1;
	}
	
	bool isFull() {
		return top == length-1;
	}

	T pop() {
		if(this->isEmpty()) 
			return 0;

		return stack[top--];
	}

	T getTop() const {
		return stack[top];
	}

	friend ostream& operator<<(ostream& out, const Stack& s) {
		out << "Stack con " << s.top+1 << " elementi" << endl;
		for (int i=s.top; i >= 0; i--) {
			out << "\t" << s.stack[i] << (i == s.top ? " <- top" : ":") << endl;
		}
		return out;
	}
	~Stack() {
		delete [] stack;
	}

};

#endif
