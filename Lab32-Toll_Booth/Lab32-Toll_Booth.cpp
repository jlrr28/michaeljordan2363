//COMSC-210 || LAB 32 || JOSE LUIS RAMOS
#include <iostream>
#include <deque>
#include "Car.h"
#include <random>
using namespace std;

int rng1to100();

int main()
{



	 
}

int rng1to100() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(1, 100);
	double x = (randomN(gen));

	return x;
}
