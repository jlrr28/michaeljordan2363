// COMSC - 210 || Lab 14 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
using namespace std;

class Color {
private:
	int R;
	int G;
	int B;
public:
	int getR()			{ return R; }
	void setR(int r)	{ R = r;}
	int getG()			{ return G; }
	void setG(int g)	{ G = g; }
	int getB()			{ return B; }
	void setB(int b)	{ B = b; }

	void print() {
		cout << R << " " << G << " " << B << endl;
	}

};


int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomRGB(0, 255);

	Color color1;
	color1.setR(randomRGB(gen));
	color1.setG(randomRGB(gen));
	color1.setB(randomRGB(gen));

	color1.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
