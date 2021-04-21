#include <iostream>

class Forma {
	
	public:
	
		virtual double perimetro() {} //= 0;
		virtual double area() { return 0.0;}
		virtual std::string toString() { return "Forma";}
		friend std::ostream& operator<<(std::ostream& out, const Forma& forma) { return out;}
};