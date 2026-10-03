// COMSC - 210 || Lab 14 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <random>
using namespace std;



class Dcolor {
private:
	int R;
	int G;
	int B;

	//using constructors
public:
	Dcolor() { R = 0; G = 0; B = 0; }
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
	Color(int r, int g, int b) { R = 0; G = 0; B = 0;}
	int getR() { return R; }
	int getG() { return G; }
	int getB() { return B; }
	//Normal function	
/*
	int getR() { return R; }
	void setR(int r) { R = r; }
	int getG() { return G; }
	void setG(int g) { G = g; }
	int getB() { return B; }
	void setB(int b) { B = b; }

	void print() {
		cout << R << " " << G << " " << B << endl;
	}
*/


};



int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomRGB(0, 255);
	//Color temp;


	Dcolor dConstructor;
	cout << dConstructor.getR() << dConstructor.getG() << dConstructor.getB() << endl;
	//dConstructor.print();


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