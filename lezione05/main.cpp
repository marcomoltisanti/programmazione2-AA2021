#include "ellisse.hpp"


int main() {
	Ellisse e(0.0, 0.0, 3.0, 4.0);
	
	Ellisse e1(1.0, 1.0, 6.0, 7.0);
	
	Forma *ptr = &e;
		
	std::cout << e.toString() << std::endl;
	std::cout << e.perimetro() << std::endl;
	std::cout << e.area() << std::endl;
	
	std::cout << ptr->toString() << std::endl;
	std::cout << ptr->perimetro() << std::endl;
	std::cout << ptr->area() << std::endl;
	
}