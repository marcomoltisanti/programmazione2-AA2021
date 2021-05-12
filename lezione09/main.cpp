#include "node.h"
#include "list.h"
#include "studente.h"
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
	
	Studente s1("a", "a", "a", 20);
	Studente s2("b", "a", "a", 20);
	Studente s3("a", "b", "a", 20);
	Studente s4("a", "a", "a", 21);

	cout << (s1 < s2) << endl; //true
	cout << (s1 > s2) << endl; //false
	cout << (s1 > s3) << endl; //false
	cout << (s3 > s2) << endl; //true
	cout << (s1 > s4) << endl; //false
	cout << (s1 == s1) << endl; //true

	//n1.setValue(100);
	//n1.setNext(&n0);
	
	cout << n1.toString() << endl;
	bool ascend = true;
	List<int> list;

	list.insertInOrder(9, ascend);
	cout << list << endl;
	list.insertInOrder(3, ascend);
	cout << list << endl;
	list.insertInOrder(5, ascend);
	cout << list << endl;
	list.insertInOrder(19, ascend);
	cout << list << endl;
	list.insertInOrder(7, ascend);
	cout << list << endl;
	list.insertInOrder(42, ascend);
	cout << list << endl;
	Node<int> * d1 = list.deleteNode(5);
	cout << list << endl;
	Node<int> * d2 =list.deleteNode(3);
	cout << list << endl;
	Node<int> * d3 =list.deleteNode(42);
	cout << list << endl;

	List<Studente> list2;
	list2.insertInOrder(s1, !ascend);	
	cout << list2 << endl;
	list2.insertInOrder(s2, !ascend);	
	cout << list2 << endl;
	list2.insertInOrder(s3, !ascend);	
	cout << list2 << endl;
	list2.insertInOrder(s4, !ascend);	
	cout << list2 << endl;
}
