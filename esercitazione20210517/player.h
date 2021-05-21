#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Player {
	string cognome, nome, club;
	double punteggio;
	int anno;

	public:

	Player(string cognome, string nome, string club, double punteggio, int anno) : 
		cognome(cognome), nome(nome), club(club), punteggio(punteggio), anno(anno) {}
	Player() : Player("", "", "", 0.0, 0) {}
	
	friend istream& operator>>(istream& in, Player &p) {
		string punteggio_string, anno_string;
		getline(in, p.cognome, ';');
		getline(in, p.nome, ';');
		getline(in, p.club, ';');
		getline(in, punteggio_string, ';');
		getline(in, anno_string, '\n');
		p.punteggio = stod(punteggio_string);
		p.anno= stoi(anno_string);
		/*in >> p.nome;
		in >> p.club;
		in >> p.punteggio;
		in >> p.anno;*/
		return in;

	}

	friend ostream& operator<<(ostream& out, const Player& p) {

		out << " " << p.cognome << ", " << p.nome << ", " << p.club << ", " << p.punteggio << ", " << p.anno;
		return out;
	}

	bool operator >(const Player& p) const {
		return this->punteggio > p.punteggio;
	}

	bool operator <(const Player& p) const {
		return this->punteggio < p.punteggio;
	}

	bool operator >=(const Player& p) const {
		return this->punteggio >= p.punteggio;
	}

	bool operator <=(const Player& p) const {
		return this->punteggio <= p.punteggio;
	}
	
	bool operator ==(const Player& p) const {
		return this->punteggio == p.punteggio;
	}

	string getCognome() const { return this->cognome; }
	void setScore(double score) { this->punteggio = score; }

};

#endif
