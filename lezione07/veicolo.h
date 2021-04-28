#include <iostream>

class Veicolo {
	protected:
		int numeroRuote;
		int velocitaMassima;
		int velocita;
		double prezzo;
		std::string marca;
		std::string carburante;
		std::string motorizzazione;
	
	public:
		Veicolo() {}
		
		int getNumeroRuote() {
			return numeroRuote;
		}
		
		int getVelocitaMassima() {
			return velocitaMassima;
		}
		
		int getVelocita() {
			return velocita;
		}
		
		double getPrezzo() {
			return prezzo;
		}
		
		std::string getMarca() {
			return marca;
		}
		
		std::string getCarburante() {
			return carburante;
		}
		
		std::string getMotorizzazione() {
			return motorizzazione;
		}
		
		void setNumeroRuote(int n) {
			numeroRuote = n;
		}
		
		void setVelocitaMassima(int n) {
			velocitaMassima = n;
		}
				
		void setPrezzo(double d) {
			prezzo = d;
		}
		
		void setMarca(std::string s) {
			marca = s;
		}
		
		void setCarburante(std::string s) {
			carburante = s;
		}
		
		void setMotorizzazione(std::string s) {
			motorizzazione = s;
		}
		
		
}