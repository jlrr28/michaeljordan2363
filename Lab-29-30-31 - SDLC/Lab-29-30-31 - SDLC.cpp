// COMSC - 210 || SDLC LAB || JOSE LUIS RAMOS
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

//THIS IS THE BETA
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
	// This is where the random events will be
	void wcPositiveRate() { 
		int x = rng1to100();
		if (x >= 0 && x <= 59) 
			popRate += 0.0008;
	
		if (x >= 60 && x <= 99) {
			popRate += 0.002;
			//cout << " || Tech boom in " << name << "! ||";
		}
	} 
	void wcNegativeRate() { 
		int x = rng1to100();
		if (x >= 0 && x <= 97) {
			popRate -= 0.0001;
			//cout << " || Rising costs is pushing people out of " << name << " || ";
		}
		if (x >= 98 && x <= 99) {
			int y = rng1to100();
			
			if (y>= 0 && y <= 90) {
				popRate -= 0.005;
				cout << " || A major earthquake has hit " << name << " || ";
			}
			if (y >= 91 && y <= 99) {
				population = population - (population * 0.1);
				popRate -= 0.1;
				cout << " XX A DEVASTATING EARTHQUAKE HAS HIT " << name << ", THOUSANDS HAVE BEEN DISPLACED XX";
			}
		
		}

	};

	void rbPositiveRate() {
		int x = rng1to100();
		if (x >= 0 && x <= 49) {
			popRate += 0.0025;
		}
		if (x >= 50 && x <= 99)
			popRate += 0.001;
	}
	void rbNegativeRate() {
		int x = rng1to100();
		if (x >= 0 && x <= 49)
			popRate -= 0.001;
		if (x >= 50 && x <= 99) {
			popRate -= 0.002;
			cout << " || A factory has closed in " << name << " || ";
		}
	}

	void gsPositiveRate() {
		int x = rng1to100();
		if (x >= 0 && x <= 59)
			popRate += 0.008;

		if (x >= 60 && x <= 99) {
			popRate += 0.002;
			//cout << " || New developments in " << name << " ||";
		}

	}
	void gsNegativeRate() {
		int x = rng1to100();
		if (x >= 0 && x <= 97) {
			popRate -= 0.001;
		}
		if (x >= 98 && x <= 99) {
				population = population - (population * 0.05);
				popRate -= 0.08;
				cout << " XX A CATEGORY 5 HURRICANE HAS HIT " << name << ", THOUSANDS HAVE BEEN DISPLACED XX" << endl;
	
		}
	};
	
	void incrementPopulation() { population = population + (population * popRate); }

	//Overload
	bool operator< (const City& other) const {
		return population < other.population;
	}

};


void printMap(const map < string, array <list<City>, REGIONS>> rM);

void compareMap(const map < string, array <list<City>, REGIONS>> newMap, const map < string, array <list<City>, REGIONS>> initialMap, int y);

void inputDataInMap(map < string, array <list<City>, REGIONS>>& rM, string f, string r);


void rustbeltPositiveNegativeBoth(City& c);

void westcoastPositiveNegativeBoth(City& c);

void gulfstatePositiveNegativeBoth(City& c);


int main(){
	
	map < string, array <list<City>, REGIONS>> regionsMap;

	array<string, REGIONS> regionArray { "Rust_Belt", "West_Coast", "Gulf_States" };
	array<string, REGIONS> fileArray   { "rustbelt.txt", "westcoast.txt", "gulfstates.txt" };

	//Input data into the Map of Arrays of Lists of Objects
	for (int i = 0; i < REGIONS; i++){
	inputDataInMap(regionsMap, fileArray[i], regionArray[i]);
	}

	cout << "INITIAL STATE" << endl;
	printMap(regionsMap);
	
	map < string, array <list<City>, REGIONS>> startingMap = regionsMap;
	//printMap(startingMap);

	//SIMULATION
	int year = STARTYEAR;
    
	for (int j = 0; j < YEARS; j++) {
		cout << " YEAR: " << year << endl;
		if (year == 2008)
			cout << "XX The housing market has crashed! many are losing their homes XX" << endl;
		if (year == 2021)
			cout << "XX The Covid-19 Pandemic has led to an economic slump! XX" << endl;
		cout << endl;
		for (auto pair : regionsMap) {
			if (year != 2008 && year != 2021)
			cout << "NOTABLE EVENTS IN THE " << pair.first << " REGION" << endl;

			cout << endl;
			for (list<City>& list : regionsMap.at(pair.first)) {

				for (City& value : list) { //Gets to the city objects in list
					//Actual operations on the city objects
					
					if (year != 2008 && year !=2021) {
						if (pair.first == "Rust_Belt")
							rustbeltPositiveNegativeBoth(value);
						if (pair.first == "West_Coast")
							westcoastPositiveNegativeBoth(value);
						if (pair.first == "Gulf_States")
							gulfstatePositiveNegativeBoth(value);
					}
					else {
						if (year == 2008) 
							value.setPopRate(-0.001);
						if (year == 2021) 
							value.setPopRate(0.0001);
					
					}

					value.incrementPopulation();
				}

				cout << endl;
			}

		}
		year++;
    }

	//Output final numbers
	cout << endl;
	cout << "AFTER SIMULATION" << endl << endl;
	// calculate growth/decline, has city shrunk or grown since starting year
	compareMap(regionsMap, startingMap, year);

}

void printMap(const map < string, array <list<City>, REGIONS>> rM) {

	for (auto pair : rM) {
		cout << pair.first << endl;

		for (auto list : rM.at(pair.first)) {

			for (City value : list) {
				cout << value.getName() << ", " << value.getState() << ": pop " << value.getPop() << ", starting pop rate "
					<< value.getPopRate() << endl;

			}

		}
	}

}

void compareMap(const map < string, array <list<City>, REGIONS>> newMap, const map < string, array <list<City>, REGIONS>> initialMap, int y) {


	for (auto pair : newMap, initialMap) {
		cout << "||||| Cities from the " << pair.first << " region. |||||" << endl;
		cout << endl;
		int x = 0;
		for (list<City> list1 : newMap.at(pair.first)) {

			auto array = initialMap.at(pair.first);
			list<City> list2 = array[x];
			auto it = list2.begin();

			for (auto value : list1) {
				//cout << setprecision(3);
				City value2 = *it;
				int percentIncDec = ((static_cast<double>(value.getPop()) - static_cast<double>(value2.getPop())) / static_cast<double>(value2.getPop())) * 100;

				cout << value.getName() << ", " << value.getState() << ": Population is " << value.getPop() << " in the current year " << y << ".\n";

				if ((value.getPop() - value2.getPop()) < 0) {
					cout << "The city lost " << value.getPop() - value2.getPop() << " people over " << y - STARTYEAR << " Years. This is a ";
					cout << percentIncDec << "% decrease from it's original population " << value2.getPop() << " in the year " << STARTYEAR << ".\n";
				}
				else {
					cout << "The city gained " << value.getPop() - value2.getPop() << " people over " << y - STARTYEAR << " Years. This is a ";
					cout << percentIncDec << "% increase from it's original population " << value2.getPop() << " in the year " << STARTYEAR << ".\n";
				}
				cout << "\n";
				it++;
			}

			x++;

		}

	}

}

void inputDataInMap(map < string, array <list<City>, REGIONS>>& rM, string f, string r) {

	ifstream fin;
	fin.open(f);
	if (fin.good()) {
		for (int i = 0; i < STATES; i++) {
			for (int j = 0; j < CITIES; j++) {
				string state;
				getline(fin, state);
				string name;
				getline(fin, name);
				int pop;
				fin >> pop;
				fin.ignore();
				double popRate;
				fin >> popRate;
				fin.ignore();

				City temp(state, name, pop, popRate);

				rM[r][i].push_back(temp);
			}
		}
	}
	fin.close();

}


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
