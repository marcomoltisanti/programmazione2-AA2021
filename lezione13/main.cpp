#include "queue.h"
#include "stack.h"

class AAA {
	string nome, cognome;
	public:
	AAA(string n, string c) : nome(n), cognome(c) {}
	AAA(): AAA("", "") {}
	friend ostream& operator<<(ostream& out, const AAA& a) {
		out << a.nome << " " << a.cognome;
		return out;
	}
};

int main() {
	Queue<int> q;
	cout << q << endl;
	Stack<int> s;
	cout << q << endl;
	cout << s << endl;
	//cout << q.isEmpty() << endl;
	//cout << q.isFull() << endl;
	for(int i=0; i < 10; i++) {
		q.enqueue(i);
		cout << "size=" << q.size() << endl;
		s.push(i);
	}
	
	//cout << q.isEmpty() << endl;
	//cout << q.isFull() << endl;
	cout << q << endl;
	cout << s << endl;
	
	int a = q.dequeue();
	int a1 = s.pop();
	cout << q << endl;
	cout << s << endl;
	cout << "valore estratto dalla coda = " << a << endl;
	cout << "valore estratto dallo stack = " << a1 << endl;
	int b = q.dequeue();
	int b1 = s.pop(); 
	cout << "valore estratto dalla coda = " << b << endl;
	cout << "valore estratto dallo stack = " << b1 << endl;
	cout << q << endl;
	cout << s << endl;
	q.enqueue(11);
	q.enqueue(12);
	s.push(11);
	s.push(12);
	cout << q << endl;
	cout << s << endl;
}
