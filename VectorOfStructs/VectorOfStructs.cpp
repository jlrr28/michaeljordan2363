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

	random_device rd;  
	mt19937 gen(rd()); 
	uniform_int_distribution<> dist(0, 255);

	vector <Color> colorVector;
	
	Color temp;
	temp.R = dist(gen);
	temp.G = dist(gen);
	temp.B = dist(gen);
	
	cout << "Coluor" << temp.R << " " << temp.G << " " << temp.B << endl << endl;
	
	colorVector.push_back(temp);
	
	temp.R = dist(gen);
	temp.G = dist(gen);
	temp.B = dist(gen);

	cout << "Coluor" << temp.R << " " << temp.G << " " << temp.B << endl << endl;

	colorVector.push_back(temp);

	temp.R = dist(gen);
	temp.G = dist(gen);
	temp.B = dist(gen);

	cout << "Coluor" << temp.R << " " << temp.G << " " << temp.B << endl << endl;

	colorVector.push_back(temp);
	
	for (auto& val : colorVector) cout << val.R << " " << val.G << " " << val.B << endl;;


}