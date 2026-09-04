// COMSC-210 | Lab 4 | Jose Luis Ramos

#include <iostream>
#include <vector>
using namespace std;

struct Color {
	int R;
	int G;
	int B;
};

int main() {

	Color c1;
	c1.R = 10;
	c1.G = 29;
	c1.B = 235;

	cout << c1.R << " " << c1.G << " " << c1.B;

}