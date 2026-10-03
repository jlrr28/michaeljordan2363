// COMSC - 210 || Lab 14 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

int getRNG();

class Dcolor {
private:
	int R;
	int G;
	int B;

	//using constructors
public:
	Dcolor() { R = getRNG(); G = getRNG(); B = getRNG(); }
	int getR() { return R; }
	int getG() { return G; }
	int getB() { return B; }

};



class Color {
private:
	int R;
	int G;
	int B;

//using constructors
public:
	//constuctors
	Color() { R = 0; G = 0; B = 0; }
	Color(int g) { R = 0; G = g; B = 0;}
	Color(int r, int g, int b) { R = r; G = g; B = b;}
	
	int getR() { return R; }
	int getG() { return G; }
	int getB() { return B; }

	void setR(int r) { R = r; }
	void setG(int g) { G = g; }
	void setB(int b) { B = b; }

	void print() {
		cout << R << " " << G << " " << B << endl;
	}

};


int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomRGB(0, 255);
	//Color temp;


	Color dConstructor;
	cout << "Default Constructor: " << dConstructor.getR() << " " << dConstructor.getG() << " " << dConstructor.getB() << endl;

	Color paraConstructor (45);
	cout << "Partial constructor: "; paraConstructor.print(); cout << endl;

	/*
	vector<Color> colorVector;
	cout << "          R   G  B  " << endl;
	for (int i = 0, x = 1; i < 10; ++i, ++x) {
		temp.setR(randomRGB(gen));
		temp.setG(randomRGB(gen));
		temp.setB(randomRGB(gen));
		cout << "color #" << x << ": ";
		temp.print(); cout << endl;
		colorVector.push_back(temp);
	}
*/


}


int getRNG() {
	random_device rd; //probably not effiecient, but just playing around with things right now
	mt19937 gen(rd());
	uniform_int_distribution<> randomRGB(0, 255);
	int x = (randomRGB(gen));
	return x;
}