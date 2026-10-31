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

	void WCpositiveRate() {};
	void WCnegativeRate() {};

	void RBpositiveRate() {};
	void RBnegativeRate() {}; 

	void GSpositiveRate() {};
	void GSnegativeRate() {};

	//Overload
	bool operator< (const City& other) const {
		return population < other.population;
	}

};


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
	City temp("temptown", 100000, 0.1);
	City temp2("Temptopia", 20000, -0.05);
	City temp3("Temp City", 400000, 0.05);
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
	rustArray[0];
	rustArray.at(0);
	
	for (auto value : rustArray[0]) {
		cout << value.getName() << " ( " << value.getPop() <<
			", " << value.getPopRate() << " )" << endl;

	}

	cout << "Map of Arrays of Lists of Classes: " << endl;

	regionsMap.insert({ "Rust_Belt", {rustArray} });


	for (auto pair : regionsMap) {
		cout << pair.first;

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
            case 1: {//Rust Belt, factory closures and openings
				//Go through the cities in the lists
				//Output what random events happen
				//Output what city is largest in region
				//Increment the popualtion number of the cities
                break;
            }
            case 2: {//Gulf States


                break;
            }
            }
        }
    }

}