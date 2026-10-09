// COMSC - 210 || Lab 20 || Jose Luis Ramos
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;
const int SIZE = 3;

double getRNG();
int getLegsRNG();

class Chair {
private:
	int legs;
	double* prices;
public:
	
	// constructors
	Chair() {
		prices = new double[SIZE];
		legs = getLegsRNG();
		for (int i = 0; i < SIZE; i++)
			prices[i] = getRNG();
	}
	Chair(int l, new double[] p) {
		prices = new double p;
		legs = l;
		for (int i = 0; i < SIZE; i++)
			prices[i] = 0;
	}
	
	// setters and getters
	void setLegs(int l) { legs = l; }
	int getLegs() { return legs; }
	void setPrices(double p1, double p2, double p3) {
		prices[0] = p1; prices[1] = p2; prices[2] = p3;
	}
	
	double getAveragePrices() {
		double sum = 0;
		for (int i = 0; i < SIZE; i++)
			sum += prices[i];
		return sum / SIZE;
	}
	
	void print() {
		cout << "CHAIR DATA - legs: " << legs << endl;
		cout << "Price history: ";
		for (int i = 0; i < SIZE; i++)
			cout << prices[i] << " ";
		cout << endl << "Historical avg price: " << getAveragePrices();
		cout << endl << endl;
	}
};


int main() {
	cout << fixed << setprecision(2);
	//creating pointer to first chair object
	Chair* chairPtr = new Chair;
	chairPtr->setLegs(4);
	chairPtr->setPrices(121.21, 232.32, 414.14);
	chairPtr->print();
	//creating dynamic chair object with constructor
	Chair* livingChair = new Chair(3);
	livingChair->setPrices(525.25, 434.34, 252.52);
	livingChair->print();
	delete livingChair;
	livingChair = nullptr;
	
	//creating dynamic array of chair objects
	//In the third code block (starting at line 67), 
	// amend this such that the default constructors
	// are used to populate these objects.
	cout << "third block of code, with only leg number being populated by setters." << endl;
	
	Chair* collection = new Chair[SIZE];

	collection[0].setLegs(4);
	collection[1].setLegs(5);
	collection[2].setLegs(36);
	for (int i = 0; i < SIZE; i++)
		collection[i].print();
	return 0;
}

double getRNG() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> randomN(100.0, 999.99);
	double x = (randomN(gen));

	return x;
}

int getLegsRNG() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(3,4);
	double x = (randomN(gen));

	return x;
}