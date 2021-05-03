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
	
	
	Moto m(120, 10000, "Ducati", "1000cc");
	Auto a(160, 8000, "Fiat Punto", "diesel", "1.300 MTJ");
	std::cout << m << std::endl;
	std::cout << a << std::endl;
	
	Gara gara(10, 10);
	gara.aggiungiPartecipante(m);
	gara.aggiungiPartecipante(a);
	gara.partenza();
}