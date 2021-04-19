#include <iostream>
#include <fstream>

using namespace std;

class Punto {
	double x, y;
	
	public:
	
	Punto() : Punto(0.0, 0.0) {}
	
	Punto(double x, double y) :
		x(x), y(y) {}
	
	void print() {
		cout << "x=" << x << ", y=" << y << endl;
	}
	
	friend ostream& operator<<(ostream& out, const Punto& p) {
		out << "Redirezione - x=" << p.x << ", y=" << p.y;
		return out;
	}
	
	friend istream& operator>>(istream& in, Punto& p) {
		in >> p.x >> p.y;
		//in >> p.y;
		return in;
	}
};

int main() {
	
	Punto p1(4.5, 6.3);
	p1.print();
	
	cout << &p1 << endl;
	cout << p1 << endl;
	
	double x, y;
	
	cin >> x;
	cin >> y;
	
	Punto p2(x, y);
	
	cout << p2 << endl;
	
	Punto p3;
	
	cin >> p3;
	
	Punto p4;
	
	ifstream ifs("input_punti.txt");
	
	ifs >> p4;
	
	ifs.close();
	
	cout << "P4" << endl << p4 << endl;
	
	ofstream ofs("punti.txt");
	
	ofs << p1 << endl;
	
	ofs.close();
	
	
}