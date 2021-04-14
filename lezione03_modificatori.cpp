#include <iostream>

using namespace std;

class EssereVivente {
	private:
		string nome;
		
	public:
		int eta;
		EssereVivente(int _eta, string _nome, string _regno, string _specie) {
			this->eta = _eta;
			this->nome = _nome;
			this->regno = _regno;
			this->specie = _specie;
		}
		void print() {
			cout << "Sono un'istanza della classe EssereVivente" << endl;
			cout << "\tNome: " << this->nome << endl;
			cout << "\tRegno: " << this->regno << endl;
			cout << "\tSpecie: " << this->specie << endl;
			cout << "\tEta: " << this->eta << endl;
			cout << "--------------" << endl;
		}
		
		string getNome() {
			return this->nome;
		}
		
	protected:
		string regno;
		string specie;
		
};


class Animale : protected EssereVivente {
	public:
		Animale(int eta, string nome, string specie) : 
			EssereVivente(eta, nome, "Animale", specie) {}
		
		/*void print() {
			cout << "Sono un'istanza della classe Animale e appartengo al regno " << regno << endl;
			cout << "\tNome: " << getNome() << endl;
			cout << "\tSpecie: "<< specie << endl;
			cout << "\tEtà: " << eta << endl;
			cout << "------------------" << endl;
		}*/
};

class Mammifero: private Animale {
	public:
		Mammifero(int eta, string nome) : 
			Animale(eta, nome, "Mammifero") {}
		
		void print() {
			cout << "Sono un'istanza della classe Mammifero e appartengo al regno " << regno << endl;
			cout << "\tNome: " << getNome() << endl;
			cout << "\tSpecie: "<< specie << endl;
			cout << "\tEtà: " << eta << endl;
			cout << "------------------" << endl;
		}
};


int main() {
	EssereVivente ev(10, "Pippo", "Animale", "Cane");
	ev.print();
	Animale a1(11, "Paperino", "Papero");
	//a1.print();
	Mammifero m1(12, "Eta Beta");
	m1.print();
}