// COMSC-210 | Lab 4 | Jose Luis Ramos

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>    
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
	

	cout << "Color# " << " R Value " << " G Value " << " B Value " << endl;
	cout << setfill('-') << setw(60) << "\n";
	int x = 0;
	for (auto& val : colorVector) {
		x++;
		if (x < 10)cout << " ";
		cout << x << setfill(' ') << setw(10) << val.R << setw(10) << val.G << setw(10) << val.B << endl;
	}

}