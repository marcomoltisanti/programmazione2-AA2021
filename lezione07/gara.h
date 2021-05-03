#ifndef GARA_H
#define GARA_H
#include "veicolo.h"
#include <cstdlib>

class Gara {
	int durata;
	int numeroPartecipanti;
	void controlla(int t);
	Veicolo * veicoli;
	
	public:
	
	Gara(int durata, int partecipanti) : durata(durata), numeroPartecipanti(partecipanti) {
		veicoli = new Veicolo[numeroPartecipanti];
	}
	
	~Gara() {
		delete [] veicoli;
	}
	
	void partenza();
	void stampaClassifica();
};

#endif

void Gara::controlla(int t) {
	
	int massimo_temporaneo = veicoli[0]->getVelocita();
	int indice_massimo = 0;
	//int massimo_temporaneo = -1;
	
	for(int i=1; i < numeroPartecipanti; i++) {
		//estrarre la velocita di ogni veicolo
		//e verificare chi è più avanti
		//RICERCA se vogliamo solo trovare il massimo
		//ORDINAMENTO se vogliamo la classifica completo
		if(veicolo[i]->getVelocita() > massimo_temporaneo) {
			massimo_temporaneo = veicoli[i]->getVelocita();
			indice_massimo = i;
		}
	}
	
	std::cout << "Il veicolo più veloce è " << veicoli[indice_massimo] << " e ha velocità " << massimo_temporaneo << std::endl;
	
	
}

void Gara::partenza() {
	srand(42);
	for(int i=0; i < durata; i++) {
		for(int j=0; j < numeroPartecipanti; j++) {
			int scelta = rand() % 2;
			if(scelta == 1)
				veicoli[j]->accelera();
			else
				veicoli[j]->decelera();
			
		}
		this->controlla(i);
	}
	
	this->stampaClassifica();
}

void Gara::stampaClassifica() {
	std::cout << "Da stampare dopo aver implementato l'ordinamento" << std::endl;
}