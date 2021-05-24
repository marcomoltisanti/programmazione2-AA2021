#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template<class T>
class Queue {
	int length;
	int nElem = 0;
	T *queue;
	int head = -1, tail = -1;

	public:
	
	Queue(int length): length(length) {
		queue = new T[length];
	}
	Queue() : Queue(10) {}
	
	void enqueue(T value) {
		if(this->isFull()) 
			return;
		if(this->isEmpty()) {
			head = 0;
		}

		this->queue[(++tail) % length] = value;
		tail %= length;
		nElem++;
	}
	
	T dequeue() {
		if(this->isEmpty()) {
			return 0;
		}
		//restituire l'elemento in testa e aggiornare head facendo attenzione alla circolarità
		nElem--;
		T temp = this->queue[head];
		head = (head+1) % length;
		return temp; //this->queue[head++%length];
	}

	bool isFull() {
		return ((head - (tail+1)) % length) == 0;
	}

	bool isEmpty() {
		return nElem == 0; //(head == tail);
	}

	int size() const {
		return this->length - (((this->length - (tail - head)) -1 ) % this->length);
	}

	friend ostream& operator<<(ostream& out, const Queue& q) {
		out << "Coda di lunghezza massima " << q.length << " con " << q.nElem << " inseriti size=" << q.size() << endl;
		out << "head = " << q.head << " tail = " << q.tail << endl;
		for(int i=0; i < q.length; i++) 
			out << "\t" << q.queue[i] << ((i == q.head) ? " <- head" : ((i == q.tail) ? " <- tail" : "")) << endl;
		return out;
}
	~Queue() {
		delete [] queue;
	}
	
	
};

#endif
