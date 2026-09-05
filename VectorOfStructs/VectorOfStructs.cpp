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
	uniform_int_distribution<> randomRGB(0, 255);
	uniform_int_distribution<> rColorsgenerated(25, 50);

	vector <Color> colorVector;
	
	Color temp;
	
	int r = rColorsgenerated(gen);
	cout << "generate this many " << r << endl;
	
	for (int i = 0; i < r; i++){
		temp.R = randomRGB(gen);
		temp.G = randomRGB(gen);
		temp.B = randomRGB(gen);
		colorVector.push_back(temp);
	}
	
	cout << colorVector.size();
	for (auto& val : colorVector) cout << val.R << " " << val.G << " " << val.B << endl;


}