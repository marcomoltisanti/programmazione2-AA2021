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
	
	int getDimensioneMassima() {
		return dimensioneMassima;
	}
	
	void setDimensioneMassima(int _dimensioneMassima) {
		dimensioneMassima = _dimensioneMassima;
	}
	
	void inserisci(int n) {
		if(numeroElementi == dimensioneMassima) {
			cout << "Sto espandendo la memoria" << endl;
			
			dimensioneMassima *= 2;
			
			int * tmp = new int[dimensioneMassima];
			for(int i=0; i < numeroElementi; i++) {
				tmp[i] = array[i];
			}
			int * toDelete = array;
			array = tmp;
			delete [] toDelete;
			cout << "Nuova dimensioneMassima = " << dimensioneMassima << endl;
		}
			
		array[numeroElementi++] = n;
	}
	
	void cancella(int i) {
		if(i >= numeroElementi) {
			cout << "Non ci sono " << i+1 << " elementi nell'array" << endl;
			return;
		}
		
		for(int j=i; j<numeroElementi-1; j++) {
			array[j] = array[j+1];
		}
		numeroElementi--;
		
		if(numeroElementi < dimensioneMassima/2) {
			cout << "Sto riducendo la memoria" << endl;
			int * tmp = new int[dimensioneMassima/2];
			for(int j=0; j < numeroElementi; j++) {
				tmp[j] = array[j];
			}
			
			dimensioneMassima /= 2;
			
			int * toDelete = array;
			array = tmp;
			delete [] toDelete;
			cout << "Nuova dimensioneMassima = " << dimensioneMassima << endl;
		}
		
	}
};

int main() {
	
	ArrayDinamico ad(8);
	for(int i=0; i < 10; i++) {
		ad.inserisci(i);
	}
	
	ad.print();
	
	ad.inserisci(1000);
	ad.inserisci(1001);
	
	ad.print();
	
	
	ad.cancella(1000);
	ad.cancella(1001);
	ad.cancella(0);
	ad.cancella(5);
	ad.cancella(3);
	
	ad.print();
	
	ad.inserisci(11);
	ad.inserisci(12);
	
	ad.print();
	
	int c = 9 / 2;
	cout << "9/2 = " << c << endl;
	
	
}
