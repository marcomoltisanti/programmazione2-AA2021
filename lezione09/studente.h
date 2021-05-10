#ifndef STUDENTE_H
#define STUDENTE_H

#include <iostream>
#include <sstream>
using namespace std;

class Studente {
	string cognome, nome, matricola;
	int eta;

	int compareTo(const Studente& s) {
		int GREATER = 1, LESS = -1, EQUAL = 0;
		if(this->cognome > s.getCognome()) {
			return GREATER;
		}
		else if(this->cognome < s.getCognome()) {
			return LESS;
		}
		else {
			if(this->nome > s.getNome()) {
				return GREATER;
			}
			else if(this->nome < s.getNome()) {
				return LESS;
			}
			else if(this->matricola > s.getMatricola()) {
				return GREATER;
			}
			else if(this->matricola < s.getMatricola()) {
				return LESS;
			}
			else if(this->eta > s.getEta()) {
				return GREATER;
			}
			else if(this->eta < s.getEta()) {
				return LESS;
			}
			else return EQUAL;
		}
	}
	public:

	Studente(string cognome, string nome, string matricola, int eta) :
		cognome(cognome), nome(nome), matricola(matricola), eta(eta) {}

	string getCognome() const { return cognome; }
	string getNome() const { return nome; }
	string getMatricola() const { return matricola; }
	int getEta() const { return eta; }

	void setCognome(string cognome) { this->cognome = cognome; }
	void setNome(string nome) { this->nome = nome; }
	void setMatricola(string matricola) { this->matricola = matricola; }
	void setEta(int eta) { this->eta = eta; }

	bool operator<(const Studente& s) {
		return this->compareTo(s) == -1;
	}

	bool operator>(const Studente& s) {
		return this->compareTo(s) == 1;
	}

	bool operator>=(const Studente& s) {
		return this->compareTo(s) >= 0;
	}

	bool operator<=(const Studente& s) {
		return this->compareTo(s) <= 0;
	}

	bool operator==(const Studente& s) {
		return this->compareTo(s) == 0;
	}

	string toString() const {
		stringstream stream;
		stream << "Cognome: " << cognome << " Nome: " << nome << " Matricola: " << matricola << " Età: " << eta;
		return stream.str();
	}

	friend ostream& operator<<(ostream& out, const Studente& s) {
		out << s.toString();
		return out;
	}
};
#endif
