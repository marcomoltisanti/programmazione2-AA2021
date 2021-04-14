#include <iostream>

using namespace std;

class Persona {
	private:
		string nome;
		string cognome;
		int eta;
	public:
		Persona(string _nome,
				string _cognome,
				int _eta) : nome(_nome), 
						   cognome(_cognome),
						   eta(_eta) {}
		
		Persona(string _nome) : Persona(_nome, "", 0) {}
		//Persona(string _cognome) : Persona("", _cognome, 0) {}		
		Persona(int _eta): Persona("", "", _eta) {}
		Persona(string _nome, string _cognome) : Persona(_nome, _cognome, 0) {}
}