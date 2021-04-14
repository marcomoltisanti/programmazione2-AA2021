#include <iostream>

using namespace std;

class Mammifero {
	protected:
	
	string nomeSpecie;
	int numeroArti;
	int eta;
	string nome;
	
	public:
	
	Mammifero(string _nomeSpecie, int _numeroArti, int _eta) {
		nomeSpecie = _nomeSpecie;
		numeroArti = _numeroArti;
		eta = _eta;
	}
	
	void print() {
		cout << "Mammifero di specie " << nomeSpecie << " con " << numeroArti << " arti, che ha " << eta << " anni." << endl;
		cout << "Il mammifero si chiama " << nome << endl;
	}
	
	void setNome(string _nome) {
		nome = _nome;
	}
};

class Gatto: public Mammifero {
	public:
		Gatto(int _eta) : Mammifero("gatto", 4, _eta) {
		}
		
		void miagola() {
			cout << "MIAO" << endl;
		}
		
		void printGatto() {
			cout << "Il gatto si chiama " << nome << endl;
		}
};

class Cane: protected Mammifero {
	private:
	
	string coloreCollare;
	
	public:
	
	Cane(int _eta, string _coloreCollare) : Mammifero("cane", 4, _eta) {
		coloreCollare = _coloreCollare;
	}
	
	void abbaia() {
		cout << "BAU BAU" << endl;
	}
	
	void siedi() {
		cout << "Mi sono seduto. Dammi un crocchino" << endl;
	}
	
	void print() {
		
		cout << "Il cane ha il collare " << coloreCollare << endl;
	}
};

int main() {
	
	Mammifero m1("homo sapiens", 4, 30);
	m1.setNome("Marco");
	m1.print();
	
	Gatto g(5);
	g.setNome("Ofelia");
	g.print();
	g.miagola();
	
	Cane c(4, "rosso");
	c.setNome("Sandrino");
	c.print();
	c.abbaia();
	c.siedi();
	
}

