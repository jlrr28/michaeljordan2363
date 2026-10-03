// COMSC - 210 || Lab 14 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

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

int getRNG();

int main()
{

	//Color temp;


	Color dConstructor;
	cout << "Default Constructor: " << dConstructor.getR() << " " << dConstructor.getG() << " " << dConstructor.getB() << endl;

	Color partConstructor (45);
	cout << "Partial constructor: "; partConstructor.print();

	Color paraConstructor(67, 99, 22);
	cout << "Parameter constructor: "; paraConstructor.print();

	Color paraTakingFunctionsConstructor(getRNG(), getRNG(), getRNG());
	cout << "Parameter taking from function return constructor: "; paraTakingFunctionsConstructor.print();

	vector<Color> colorVector;
	Color temp(0,0,0);
	cout << "          R   G  B  " << endl;
	for (int i = 0, x = 1; i < 10; ++i, ++x) {
		
		Color temp(getRNG(), getRNG(), getRNG());
		//temp.setG(randomRGB(gen));
		//temp.setB(randomRGB(gen));
		cout << "color #" << x << ": ";
		temp.print(); cout << endl;
		colorVector.push_back(temp);
	}



}


int getRNG() {
	random_device rd; //probably not effiecient, but just playing around with things right now
	mt19937 gen(rd());
	uniform_int_distribution<> randomRGB(0, 255);
	int x = (randomRGB(gen));
	return x;
}