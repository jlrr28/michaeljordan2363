//COMSC-210 || LAB 32 || JOSE LUIS RAMOS
#include <iostream>
#include <deque>
#include <array>
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
		cout << "Car paid: "; x.print();
		//cout << endl;
		cD.pop_front();

	}
	if (y >= 56 && y <= 100) {
		Car temp;
		cout << "Joined lane: "; temp.print();
		//cout << endl;
		cD.push_back(temp);

	}

}

deque<Car> generateDeque() {
	deque<Car> carD;

	for (int j = 0; j < INITIALDEQUE; j++)
	{
		Car temp;
		carD.push_back(temp);
	}
	return carD;
}


const int INITIALDEQUE = 2, TOLLSIZE = 4;

int main()
{
	Car car1;
	Car car2;
	 
	//deque<Car> carDeque;
	//carDeque.push_back(car1);
	//carDeque.push_back(car2);

	array<deque<Car>,TOLLSIZE> tollArray;

	for (int i = 0; i < tollArray.size(); i++) {

		//printDeque(carDeque);
		tollArray[i] = generateDeque();

	}
	cout << "tollArray[0]" << endl;
	printDeque(tollArray[0]);
	cout << "tollArray[3]" << endl;
	printDeque(tollArray[3]);
	/*

	cout << "Initial queue:" << endl;
	printDeque(carDeque);
	cout << endl;
	int i = 1;
	while (!carDeque.empty()) {

		cout << "Time " << i << " Operation: ";
		dequeAddOrRemove(carDeque);
		cout << "Queue:" << endl;
		printDeque(carDeque);
		cout << endl;
		i++;

	}
	*/
	cout << "empty" << endl;

}

int rng1to100() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(1, 100);
	double x = (randomN(gen));

	return x;
}
