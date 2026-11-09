//COMSC-210 || LAB 32 || JOSE LUIS RAMOS
#include <iostream>
#include <deque>
#include <array>
#include "Car.h"
#include <random>
using namespace std;

const int INITIALDEQUE = 2, TOLLSIZE = 4, SIMULATIONS = 20;
//Probabilities for toll operations
const int LEAVELOWER = 1, LEAVEUPPER = 46, JOINLOWER = 47, JOINUPPER = 85,
SWAPLOWER = 86, SWAPUPPER = 100, FIFTYLOWLOWER = 1, FIFTYLOWUPPER = 50, FIFTYHIGHLOW = 51, FIFTYHIGHUPPER = 100;

int rng1to100();

void printDeque(deque<Car> cD) {
	for (int i = 0; i < cD.size(); i++) {
		cout << "        ";
		cD[i].print();
	}
}



void dequeAddOrRemoveOrSwap(deque<Car>& cD, array<deque<Car>, TOLLSIZE> tA, int currentLane) {

	if (cD.empty()) {
		int y = rng1to100();
		
		if (y >= FIFTYLOWLOWER && y <= FIFTYLOWUPPER) {//Join Deque
			Car temp;
			cout << "Joined: "; temp.print();
			//cout << endl;
			cD.push_back(temp);

		}

	}
	else {
		
		int y = rng1to100();
		if (y >= LEAVELOWER && y <= LEAVEUPPER) {//Leave Deque
			Car x = cD.front();
			cout << "Paid: "; x.print();
			//cout << endl;
			cD.pop_front();

		}
		if (y >= JOINLOWER && y <= JOINUPPER) {//Join Deque
			Car temp;
			cout << "Joined: "; temp.print();
			//cout << endl;
			cD.push_back(temp);

		}
		if (y >= SWAPLOWER && y <= SWAPUPPER) {//Swap Deque
			
			int randomLane = 0;
			
			while (randomLane != currentLane) {
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<> randomN(0, tA.size() - 1);
				randomLane = randomN(gen);
				//tA[randomN];
			}
			cout << "car in lane #" << currentLane << " swapping to lane # " << randomLane << endl;
			cout << "swap goes here" << endl;


		}

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

int main()
{ 

	array<deque<Car>,TOLLSIZE> tollArray;

	for (int i = 0; i < tollArray.size(); i++) {
		tollArray[i] = generateDeque();
	}
	cout << "tollArray[0]" << endl;
	printDeque(tollArray[0]);
	cout << "tollArray[3]" << endl;
	printDeque(tollArray[3]);
	

	cout << "Initial queue:" << endl;
	//printDeque(carDeque);
	cout << endl;
	int i = 1;
	for (int i = 0; i < SIMULATIONS; i++) {

		cout << "Time " << i + 1 << " Operation: ";
		
		for(int j = 0; j < tollArray.size(); j++)
			dequeAddOrRemoveOrSwap(tollArray[j], tollArray, j);
		

		for (int j = 0; j < tollArray.size(); j++){
			cout << "Lane " << j + 1 << " Queue:" << endl;
			if (!tollArray[j].empty())
				printDeque(tollArray[j]);
			else
				cout << "empty lane" << endl;

		}
			
		cout << endl;
		//printDeque(carDeque);

	}

}

int rng1to100() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(1, 100);
	int x = (randomN(gen));

	return x;
}
