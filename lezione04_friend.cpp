#include <iostream>

using namespace std;

class A {
	int x, y;
	
	public:
	
	A(int _x, int _y) : x(_x), y(_y) {}
	
	friend void print(const A& a) {
		cout << "X=" << a.x << ", Y=" << a.y << endl;
	}
};

class B {
	string s;
	int a, b;
	
	public:
	
	B(string _s, int _a, int _b) :
		s(_s), a(_a), b(_b) {}
	
	void print() {
		cout << "S=" << s << ", a=" << a << ", b=" << b << endl;
	}
	
	int somma() {
		return a+b;
	}
	
	friend int somma_amica(const B& r) {
		return r.a + r.b;
	}
};

int main() {
	A a(1,2);
	//cout << a.x << endl;
	print(a);
	
	B b("ciao", 3, 4);
	b.print();
	int c = b.somma();
	int d = somma_amica(b);
	
	cout << c << " " << d << endl;
}