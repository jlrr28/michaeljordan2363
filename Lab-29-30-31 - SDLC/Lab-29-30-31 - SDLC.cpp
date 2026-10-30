#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <map>
#include <array>
#include <random>
#include <numeric>
#include <string>
using namespace std;

class City {
private:
	string name;
	int population;
	double popRate;
public:
	City(string n, int p, double r) {name = n; population = p; popRate = r;}

	void WCpositiveRate() {};
	void WCnegativeRate() {};

	void RBpositiveRate() {};
	void RBnegativeRate() {};

	void GSpositiveRate() {};
	void GSnegativeRate() {};

};

class WestCoastCity : public City {
	public:
		void positiveRate() {};
		void negativeRate() {};
};

class RustBeltCity : public City {
	public:

};

class GulfStateCity : public City {
	public:

};

int main(){
	

	string wFile = "westcoast.txt";
	string rFile = "rustbelt.txt";
	string gFile = "gulfcoast.txt";

	list<WestCoastCity> wCities;
	list<RustBeltCity> rCities;
	list<GulfStateCity> gCities;
	

	array<list<WestCoastCity,RustBeltCity,GulfStateCity>, 3> sArray {wCities, rCities, gCities};

}