#include <iostream>

using namespace std;

class A {
	private:
		int x;
		float y;
	public:
		A() {}
		/*
		A(int _x, float _y) {
			this->x = _x;
			this->y = _y;
		}
		*/
		
		A(int _x, float _y) : x(_x) {
			this->y = _y;
		}
		
		A(int _x) :  A(_x, 0.0f) {}
		A(float _y) : A(0, _y) {}
		
		
		
		void print() {
			cout << "Classe A" << endl;
			cout << "x = " << x << ", y = " << y << endl;
		}
};

int main() {
	A a0;
	cout << "a0" << endl;
	a0.print();
	
	A a1(1, 1.0f);
	a1.print();
	
	A a2(2);
	a2.print();
	
	A a3(2.5f);
	a3.print();
	
	A a4 = {4, 4};
	a4.print();
	
	A a5 = 5;
	a5.print();
	
	A a6 = 6.5f;
	a6.print();
}