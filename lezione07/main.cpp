#include "moto.h"
#include "automobile.h"
#include "gara.h"

int main() {
	
	std::string * array;
	std::string array2[10];
	array = new std::string[10];
	
	for(int i=0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	
	std::cout << std::endl;
	
	for(int i=0; i < 10; i++) {
		std::cout << array[i] << " ";
	}
	
	std::cout << std::endl;
	
	
	Moto m0(100, 10000, "Ducati", "1000cc");
	Moto m1(110, 10000, "Honda", "1000cc");
	Moto m2(120, 10000, "Yamaha", "1000cc");
	Auto a0(90, 8000, "Fiat Punto", "diesel", "1.300 MTJ");
	Auto a1(130, 8000, "Fiat Fiorino", "diesel", "1.300 MTJ");
	Auto a2(140, 8000, "Fiat Panda", "diesel", "1.300 MTJ");
	//std::cout << m << std::endl;
	//std::cout << a << std::endl;
	
	Gara gara(10, 10);
	gara.aggiungiPartecipante(m0);
	gara.aggiungiPartecipante(m1);
	gara.aggiungiPartecipante(m2);
	gara.aggiungiPartecipante(a0);
	gara.aggiungiPartecipante(a1);
	gara.aggiungiPartecipante(a2);
	gara.partenza();
}