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

	vector <Color> colorVector;
	
	Color temp;
	temp.R = 10;
	temp.G = 29;
	temp.B = 235;



	cout << temp.R << " " << temp.G << " " << temp.B;

}