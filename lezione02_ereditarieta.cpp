#include <iostream>

class A {
	public:
		//Costruttore senza parametri
		A() {
			this->pippo = 10;
			this->paperino = 20;
			this->pluto = 30;
		}
		
		//Costruttore con parametri
		A(int _p1, int _p2, int _p3) {
			pippo = _p1;
			paperino = _p2;
			pluto = _p3;
		}
		
		int pippo;
		void print() {
			std::cout << "Classe A" << std::endl;
			std::cout << "La somma è " << somma() << std::endl;
		}
		
	protected:
		int pluto;
		int somma() {
			return pippo + paperino + pluto;
		}
		
	private:
		int paperino;
};

class B: public A {
	
	public:
		B() : A() {}
		B(int a, int b, int c) : A(a,b,c) {}
		B(int a, int b) : A(a,b, 100) {}
	
		void print() {
			std::cout << "Sono la classe B" << std::endl;
			std::cout << "Somma = " << somma() << std::endl;
		}
};


int main() {
	
	A oggettoA1;
	A oggettoA2(1,2,3);
	B oggettoB;
	
	//std::cout << oggettoA1.somma() << std::endl;
	//std::cout << oggettoA2.somma() << std::endl;
	//std::cout << oggettoB.somma() << std::endl;
	
	oggettoA1.print();
	oggettoA2.print();
	oggettoB.print();
	
}