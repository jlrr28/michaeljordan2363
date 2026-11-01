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
const int YEARS = 26, STARTYEAR = 2000, REGIONS = 3, STATES = 3, CITIES = 3;

class City {
private:
	string state;
	string name;
	int population;
	double popRate;
public:
	City()							{ state = "Statless"; name = "Town with no Name"; population = 0; popRate = 0; }
	//Constructors
	City(string s, string n, int p, double r) { state = s; name = n; population = p; popRate = r; }

	//Sets and Gets
	string getState()			{ return state; }
	string getName()			{ return name; }
	int getPop()				{ return population; }
	double getPopRate()			{ return popRate; }

	void setState(string s)		{ state = s; }
	void setName(string n)		{ name = n; }
	void setPop(int p)			{ population = p; }
	void setPopRate(double r)	{ popRate = r; }

	//Methods

	void wcPositiveRate() { popRate += 0.001; } //This is where the random events will be 
	void wcNegativeRate() {};                  //To change popRate

	void rbPositiveRate() {
		int x = rng1to100();
		if (x >= 0 && x <= 49) {
			popRate += 0.002;
			cout << " || A factory has opened " << name << " || ";
		}
		//popRate+=0.001; /*cout << popRate << " ";*/
		if (x >= 50 && x <= 99)
			popRate += 0.001;
	}
	void rbNegativeRate() {
		int x = rng1to100();
		if (x >= 0 && x <= 49)
			popRate -= 0.001;
		//popRate+=0.001; /*cout << popRate << " ";*/
		if (x >= 50 && x <= 99) {
			popRate -= 0.002;
			cout << " || A factory has closed in " << name << " || ";
		}
	}





	void gsPositiveRate() {};
	void gsNegativeRate() {};

	
	void incrementPopulation() { population = population + (population * popRate); }


	//Overload
	bool operator< (const City& other) const {
		return population < other.population;
	}

};

/*void printMap(const map < string, array <list<City>, REGIONS>> rM) {
	
	for (auto pair : rM) {
		cout << pair.first << endl;

		for (auto value : rustArray[0]) {
			cout << value.getName() << " ( " << value.getPop() <<
				", " << value.getPopRate() << " )" << endl;

		}

	}

}*/

void rustbeltPositiveNegativeBoth(City& c) {
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

void westcoastPositiveNegativeBoth(City& c) {
	int x = rng1to3();
	if (x == 0)
		c.wcPositiveRate();
	if (x == 1)
		c.wcNegativeRate();
	if (x == 2) {
		c.wcPositiveRate();
		c.wcNegativeRate();
	}

}

void gulfstatePositiveNegativeBoth(City& c) {
	int x = rng1to3();
	if (x == 0)
		c.gsPositiveRate();
	if (x == 1)
		c.gsNegativeRate();
	if (x == 2) {
		c.gsPositiveRate();
		c.gsNegativeRate();
	}

}

void inputDataInMap(map < string, array <list<City>, REGIONS>> rM){




}


int main(){
	

	map < string, array <list<City>, REGIONS>> regionsMap;
	//map < string, array <list<City>, REGIONS>>* mPointer;

	string wFile = "westcoast.txt";
	string rFile = "rustbelt.txt";
	string gFile = "gulfcoast.txt";
	array<string, REGIONS> regionArray { "West_Coast", "Rust_Belt", "Gulf_Coast" };

	list<City> wStates;
	list<City> rStates;
	list<City> gStates;
	
	//State of Ohio
	//Data would be read in by file
	City temp("Ohio", "Columbus", 10000, 0.001);
	City temp2("Ohio", "Temptopia", 20000, -0.005);
	City temp3("Ohio", "Temp City", 400000, 0.005);
	//cout << "class:" << endl;
	//cout << temp.getName() << " " << temp.getPop() << " " << temp.getPopRate() << endl;
	City empty;

	regionsMap["Rust_Belt"][0].push_back(City{ "Ohio", "Columbus", 715971, 0.001 });
	regionsMap["Rust_Belt"][0].push_back(City{ "Ohio", "Cleveland", 476574, 0.001 });
	regionsMap["Rust_Belt"][0].push_back(City{ "Ohio", "Cincinnati", 331258, 0.001 });

	regionsMap["Rust_Belt"][1].push_back(City{ "Michigan", "Detroit", 951270, -0.001 });
	regionsMap["Rust_Belt"][1].push_back(City{ "Michigan", "Grand Rapids", 197800, 0.001 });
	regionsMap["Rust_Belt"][1].push_back(City{ "Michigan", "Warren", 138247, 0.001 });

	regionsMap["Rust_Belt"][2].push_back(City{ "Illnois", "Chicago", 2896016, 0.001 });
	regionsMap["Rust_Belt"][2].push_back(City{ "Illnois", "Rockford", 150115, 0.001 });
	regionsMap["Rust_Belt"][2].push_back(City{ "Illnois", "Aurora", 142990, 0.001 });

	//States
	list<City>Ohio = {temp,temp2,temp3};
	list<City>Illinois = {empty,empty,empty};
	list<City>Michigan = {empty,empty,empty};
	
	list<City>California = { empty,empty,empty };
	list<City>Oregon = {};
	list<City>Seattle = {};

	list<City>Florida = { empty,empty,empty };
	list<City>Louisiana = {};
	list<City>Alabama = {};

	/*
	cout << "List of Classes: " << endl;
	for (City value : Ohio) {
		cout << value.getName() << " ( " << value.getPop() <<
			", " << value.getPopRate() << " )" << endl;

	}*/
	//Gets pushed into an array
	array<list<City>, STATES> rustArray {Ohio,Illinois,Michigan};
	array<list<City>, STATES> westArray {California,Oregon,Seattle};
	array<list<City>, STATES> gulfArray {Florida,Louisiana,Alabama};


	//cout << "Map of Arrays of Lists of Classes: " << endl;

	//regionsMap.insert({ "Rust_Belt", {rustArray} });
	regionsMap.insert({ "West_Coast", {westArray} });
	regionsMap.insert({ "Gulf_States", {gulfArray} });

	cout << "INITIAL STATE" << endl;
	for (auto pair : regionsMap) {
		cout << pair.first << endl;

		for (auto list : regionsMap.at(pair.first)) {
		
			for (City value : list) {
				cout << value.getState() << " " << value.getName() << " " << value.getPop() << " "
				<< value.getPopRate() << endl;
				
			}

		}

	}

    for (int j = 0; j < YEARS; j++) {

		for (auto pair : regionsMap) {
			//cout << pair.first << endl;

			for (list<City>& list : regionsMap.at(pair.first)) {

				for (City& value : list) { //Gets to the city objects in list
					//Actual operations on the city objects
					//cout << pair.first << endl;
					//populationPositiveNegativeBoth(value);
					if (pair.first == "Rust_Belt")
						rustbeltPositiveNegativeBoth(value);
					if (pair.first == "West_Coast")
						westcoastPositiveNegativeBoth(value);
					if (pair.first == "Gulf_State")
						gulfstatePositiveNegativeBoth(value);
					
					value.incrementPopulation();
				
				
				
				


				
				
				}

			}

		}

    }

	//Output final numbers
	cout << endl;
	cout << "AFTER SIMULATION" << endl << endl;
	for (auto pair : regionsMap) {
		cout << pair.first << endl;

		for (auto list : regionsMap.at(pair.first)) {

			for (auto value : list) {
				cout << value.getState() << " " << value.getName() << " " << value.getPop() << " "
					<< value.getPopRate() << endl;

			
}

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


/*
 				cout << regionArray[i] << endl;
				auto it = regionsMap.find(regionArray[i]);
				if (it != regionsMap.end()) {

					for (int j; j < STATES; j++) {






					}

				}
				else
					// Key does not exist
					cout << regionArray[i] << " not found." << endl;
					*/