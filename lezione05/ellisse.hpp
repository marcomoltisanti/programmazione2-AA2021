#include <iostream>
#include <sstream>
#include <cmath>
#include "forma.hpp"

class Ellisse : public Forma {
	protected:
		double x, y;
		double r1, r2;
	public:
		Ellisse(double _x, double _y, double _r1, double _r2):
			x(_x), y(_y), r1(_r1), r2(_r2) {}
		
		double perimetro() {
			return 2*M_PI*sqrt((pow(r1, 2.0) + pow(r2, 2.0)) / 2);
		}
		
		double area() {
			return M_PI*r1*r2;
		}
		
		void setCenter(double _x, double _y) {
			x = _x;
			y = _y;
		}
		
		void setSemiasseMaggiore(double _r1) {
			r1 = _r1;
		}
		
		void setSemiasseMinore(double _r2) {
			r2 = _r2;
		}
		
		double getX() {
			return x;
		}
		
		double getY() {
			return y;
		}
				
		double getSemiasseMaggiore() {
			return r1;
		}
				
		double getSemiasseMinore() {
			return r2;
		}
		
		std::string toString() {
			std::stringstream stream;
			stream << "Ellisse di centro (" <<x<<","<<y<<") con semiassi ("<<r1<<","<<r2<<")";
			return stream.str();
		}
};