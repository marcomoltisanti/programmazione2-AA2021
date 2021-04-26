/*
Implementare una classe che simuli il comportamento di un array
in maniera dinamica. L'array conterrà solo interi.
*/

#include <iostream>

using namespace std;

class ArrayDinamico {
	int numeroElementi;
	int dimensioneMassima;
	int * array;
	
	public:
	
	ArrayDinamico(int _dimensioneMassima) : dimensioneMassima(_dimensioneMassima) {
		numeroElementi = 0;
		array = new int[dimensioneMassima];
	}
	
	void print() {
		
		cout << "ArrayDinamico di dimensione massima = " << dimensioneMassima << endl;
		
		for(int i=0; i < numeroElementi; i++) {
			cout << array[i] << "\t";
		}
		
		cout << endl;
	}
};

int main() {
	
	ArrayDinamico ad(10);
	
	ad.print();
	
}
