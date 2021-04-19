#include <iostream>

using namespace std;

class Persona {
	
	public:
		Persona() {
			this->nome = "";
			this->eta = 0;
		}
		
		Persona(string _nome, int _eta) {
			this->nome = _nome;
			this->eta = _eta;
		}
		
		void print() {
			cout << "Mi chiamo " << this->nome << " e ho " << this->eta << " anni." << endl;
		}
		
		void parla() {
			cout << "Sono " << this->nome << " e sto parlando da solo." << endl;
		}
		
		void parla(string s) {
			cout << "Sono " << this->nome << " e sto parlando con " << s << endl;
		}
	
	protected:
		string nome;
		int eta;
	
};

class Oratore: public Persona {
	public:
		Oratore() : Persona() {}
		Oratore(string _nome, int _eta) :
			Persona(_nome, _eta) {}
		void parla() {
			Persona::parla();
			cout << "Sono l'oratore " << nome << " e sto proclamando un discorso." << endl;
		}
};


int main() {
	Persona p1;
	Persona p2("Marco", 37);
	
	p1.print();
	p2.print();
	
	p1.parla();
	p2.parla("Giulia");
	
	Oratore o1("Cicerone", 2000);
	o1.parla();
	
	std::cout << "Modifica a caso" << std::endl;
}