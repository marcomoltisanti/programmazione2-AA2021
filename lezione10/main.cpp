#include "node_dl.h"
#include "list_dl.h"

int main() {

	NodeDL<int> n(10);
	NodeDL<int> p(15);
	cout << n << endl;
	cout << (n < p) << endl;
	cout << (n > p) << endl;
	cout << (n == p) << endl;

	ListDL<int> list;
	list.insertHead(10);
	list.insertHead(5);
	list.insertTail(15);

	cout << list << endl;

	list.insert(7);
	list.insert(12);
	list.insert(9);
	list.insert(3);
	list.insert(42);

	cout << list << endl;

	list.deleteValue(9);
	cout << list << endl;
	list.deleteValue(3);
	cout << list << endl;
	list.deleteValue(42);

	cout << list << endl;
}
