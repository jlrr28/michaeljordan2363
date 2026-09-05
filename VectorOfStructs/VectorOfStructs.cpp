// COMSC-210 | Lab 4 | Jose Luis Ramos

#include <iostream>
#include <vector>
#include <random>
using namespace std;

struct Color {
	int R;
	int G;
	int B;
};


int main() {

	srand(time(0));
	
	vector <Color> colorVector;
	
	
	
	Color temp;
	temp.R = rand() % 255;
	temp.G = rand() % 255;
	temp.B = rand() % 255;
	
	cout << "Coluor" << temp.R << " " << temp.G << " " << temp.B << endl << endl;
	
	colorVector.push_back(temp);
	
	temp.R = rand() % 255;
	temp.G = rand() % 255;
	temp.B = rand() % 255;

	cout << "Coluor" << temp.R << " " << temp.G << " " << temp.B << endl << endl;

	colorVector.push_back(temp);
	
	temp.R = rand() % 255;
	temp.G = rand() % 255;
	temp.B = rand() % 255;

	cout << "Coluor" << temp.R << " " << temp.G << " " << temp.B << endl << endl;

	colorVector.push_back(temp);
	
	for (auto& val : colorVector) cout << val.R << " " << val.G << " " << val.B << endl;;


}