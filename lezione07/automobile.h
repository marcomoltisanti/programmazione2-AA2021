#include "veicolo.h"
#include <sstream>


class Auto : public Veicolo {
	
	public:
	
	Auto(int velocitaMassima, double prezzo, std::string marca, std::string carburante, std::string motorizzazione) : Veicolo(4, velocitaMassima, prezzo, marca, carburante, motorizzazione) {}
	
	std::string toString() const {
		std::stringstream stream;
		stream << "Sono un'auto di marca " << marca << ", " << motorizzazione << " " << carburante << ". La mia velocità è di " << velocita << " km/h";
		return stream.str();
	}
};