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

//THIS IS THE ALPHA
int rng1to3();
int rng1to100();

class City {
private:
	string name;
	int population;
	double popRate;
public:
	City()							{ name = "Town with no Name"; population = 0; popRate = 0; }
	//Constructors
	City(string n, int p, double r) {name = n; population = p; popRate = r;}

	//Sets and Gets
	string getName()			{ return name; }
	int getPop()				{ return population; }
	double getPopRate()			{ return popRate; }

	void setName(string n)		{ name = n; }
	void setPop(int p)			{ population = p; }
	void setPopRate(double r)	{ popRate = r; }

	//Methods

	void wcPositiveRate() { popRate += 0.001; } //This is where the random events will be 
	void wcNegativeRate() {};                  //To change popRate

	void rbPositiveRate() { popRate+=0.001; cout << popRate << " "; }
	void rbNegativeRate() { popRate -= 0.0005; }

	void gsPositiveRate() {};
	void gsNegativeRate() {};

	void incrementPopulation() { population = population + (population * popRate); }


	//Overload
	bool operator< (const City& other) const {
		return population < other.population;
	}

};

void populationPositiveNegativeBoth(City& c) {
	int x = rng1to3();
	if (x == 0)
		c.rbPositiveRate();
	if (x == 1)
		c.rbNegativeRate();
	if (x == 2) {
		c.rbPositiveRate();
		c.rbNegativeRate();
	}

}

const int YEARS = 26, STARTYEAR = 2000, REGIONS = 3;

int main(){
	

	map < string, array <list<City>, 3>> regionsMap;

	string wFile = "westcoast.txt";
	string rFile = "rustbelt.txt";
	string gFile = "gulfcoast.txt";


	list<City> wStates;
	list<City> rStates;
	list<City> gStates;
	
	//State of Ohio
	//Data would be read in by file
	City temp("temptown", 100000, 0.001);
	City temp2("Temptopia", 20000, -0.005);
	City temp3("Temp City", 400000, 0.005);
	cout << "class:" << endl;
	cout << temp.getName() << " " << temp.getPop() << " " << temp.getPopRate() << endl;

	//States
	list<City>Ohio = {temp,temp2,temp3};
	list<City>Illinois = {};
	list<City>Michigan = {};
	
	cout << "List of Classes: " << endl;
	for (City value : Ohio) {
		cout << value.getName() << " ( " << value.getPop() <<
			", " << value.getPopRate() << " )" << endl;

	}
	//Gets pushed into an array
	array<list<City>, 3> rustArray {Ohio,Illinois,Michigan};

	cout << "Array of Lists of Classes:" << endl;

	for (auto value : rustArray[0]) {
		cout << value.getName() << " ( " << value.getPop() <<
			", " << value.getPopRate() << " )" << endl;

	}

	cout << "Map of Arrays of Lists of Classes: " << endl;

	regionsMap.insert({ "Rust_Belt", {rustArray} });

	for (auto pair : regionsMap) {
		cout << pair.first << endl;

		for (auto value : rustArray[0]) {
			cout << value.getName() << " ( " << value.getPop() <<
				", " << value.getPopRate() << " )" << endl;

		}

	}

    for (int j = 0; j < YEARS; j++) {

        for (int i = 0; i < REGIONS; i++) {


            switch (i) { //WestCoast
            case 0: {
				

                break;
            }
            case 1: {//Rust Belt
                
				for (auto pair : regionsMap) {
					cout << pair.first << " biggest city is xxx at xxx people" << endl;

					for (auto& value : rustArray[0]) {
						populationPositiveNegativeBoth(value);
						value.incrementPopulation();
					}

				}


				break;
            }
            case 2: {//Gulf States


                break;
            }
            }
        }
    }

	//Output final numbers
	for (auto pair : regionsMap) {
		cout << pair.first << endl;

		for (auto value : rustArray[0]) {
			cout << value.getName() << " ( " << value.getPop() <<
				", " << value.getPopRate() << " )" << endl;

		}

	}


}

int rng1to3() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(0, 2);
	double x = (randomN(gen));

	return x;
}

int rng1to100() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> randomN(0, 99);
	double x = (randomN(gen));

	return x;
}