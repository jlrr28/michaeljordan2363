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
	void wcNegativeRate() { 
		int x = rng1to100();
		if (x >= 0 && x <= 97) {
			popRate -= 0.0002;
			//cout << " || Rising costs is pushing people out of " << name << " || ";
		}
		if (x >= 98 && x <= 99) {
			int y = rng1to100();
			

			if (y>= 0 && y <= 49) {
				popRate -= 0.002;
				//cout << " || A major earthquake has hit " << name << " || ";
			}
			if (y >= 50 && y <= 99) {
				population = population - (population * 0.1);
				popRate -= 0.01;
				cout << " XX A DEVESTATING EARTHQUAKE HAS HIT " << name << " THOUSANDS HAVE BEEN DISPLACED XX" << endl;
			}
		
		
		}


	};                  //To change popRate

	void rbPositiveRate() {
		int x = rng1to100();
		if (x >= 0 && x <= 49) {
			popRate += 0.002;
			//cout << " || A factory has opened " << name << " || ";
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

void printMap(const map < string, array <list<City>, REGIONS>> rM) {
	
	for (auto pair : rM) {
		cout << pair.first << endl;

		for (auto list : rM.at(pair.first)) {

			for (City value : list) {
				cout << value.getState() << " " << value.getName() << " " << value.getPop() << " "
				<< value.getPopRate() << endl;

			}

		}
	}

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

void inputDataInMap(map < string, array <list<City>, REGIONS>>& rM, string f, string r){

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


int main(){
	
	map < string, array <list<City>, REGIONS>> regionsMap;

	array<string, REGIONS> regionArray { "Rust_Belt", "West_Coast", "Gulf_States" };
	array<string, REGIONS> fileArray   { "rustbelt.txt", "westcoast.txt", "gulfstates.txt" };

	for (int i = 0; i < REGIONS; i++){
	inputDataInMap(regionsMap, fileArray[i], regionArray[i]);
	}

	cout << "INITIAL STATE" << endl;
	printMap(regionsMap);
	
	map < string, array <list<City>, REGIONS>> startingMap = regionsMap;
	//printMap(startingMap);

	//SIMULATION
	int year = 2000;
    for (int j = 0; j < YEARS; j++) {
		cout << " YEAR: " << year << endl;
		for (auto pair : regionsMap) {
			//cout << pair.first << endl;
			cout << pair.first << endl;
			for (list<City>& list : regionsMap.at(pair.first)) {

				for (City& value : list) { //Gets to the city objects in list
					//Actual operations on the city objects
					//cout << pair.first << endl;
					if (pair.first == "Rust_Belt")
						rustbeltPositiveNegativeBoth(value);
					if (pair.first == "West_Coast")
						westcoastPositiveNegativeBoth(value);
					if (pair.first == "Gulf_State")
						gulfstatePositiveNegativeBoth(value);
					
					value.incrementPopulation();
				}

			}
			cout << endl;
		}
		year++;
    }

	//Output final numbers
	cout << endl;
	cout << "AFTER SIMULATION" << endl << endl;
	// calculate growth/decline, has city shrunk or grown since starting year
	auto pair2 = startingMap;
	
	for (auto pair : regionsMap, startingMap) {
		
		cout << pair.first << endl;
		
		//for (auto pair2 : startingMap) {
			cout << "Hello from startingMap!" << endl;
			
			for (auto list : regionsMap.at(pair.first)) {

				for (auto list2 : startingMap.at(pair.first)) {


					for (auto value : list) {

						for (auto value2 : list2) {
							cout << "This is population of " << value2.getName() << " in 2000 " << value2.getPop() << " and this is population of " << value.getName() << " in 2026 " << value.getPop() << " " << endl;

						}

					}
			
				}
			
			}
		
		//}

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