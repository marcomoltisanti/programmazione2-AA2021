#include "node.h"
#include "list.h"
#include <iostream>

using namespace std;

int main() {
	Node<int> n0(10);
	Node<int> n1(11); //, &n0);
	Node<int> n2;
	
	cout << &n0 << endl;
	cout << &n1 << endl;
	cout << &n2 << endl;
	cout << n0.getValue() << endl;
	cout << n0.getNext() << endl;
	
	//n1.setValue(100);
	//n1.setNext(&n0);
	
	cout << n1.toString() << endl;
	
	List<int> list;
	list.insert(&n0);
	list.insert(&n1);
	list.insert(&n2);
	list.insert(14);
	
	cout << list << endl;
	
}