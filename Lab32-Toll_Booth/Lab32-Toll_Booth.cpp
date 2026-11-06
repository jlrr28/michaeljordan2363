//COMSC-210 || LAB 32 || JOSE LUIS RAMOS
#include <iostream>
#include <deque>
#include "Car.h"
#include <random>
using namespace std;

int rng1to100();

void printDeque(deque<Car> cD) {
	for (int i = 0; i < cD.size(); i++)
		cD[i].print();
}

void dequeAddOrRemove(deque<Car>& cD) {
	
	int y = rng1to100();

	if (y >= 1 && y <= 55) {
		Car x = cD.front();
		x.print();



	}
	if (y >= 56 && y <= 100) {
		Car temp;
		cD.push_back(temp);

	}


}

int main()
{
	Car car1;
	Car car2;

	deque<Car> carDeque;
	carDeque.push_back(car1);
	carDeque.push_back(car2);
	
	cout << "Initial queue:" << endl;
	printDeque(carDeque);
	while (!carDeque.empty()) {



	}


	 

}

int rng1to100() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(1, 100);
	double x = (randomN(gen));

	return x;
}
