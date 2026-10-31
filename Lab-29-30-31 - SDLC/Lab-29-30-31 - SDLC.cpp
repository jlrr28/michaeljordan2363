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


const int YEARS = 26, STARTYEAR = 2000;

int main(){
	

	string wFile = "westcoast.txt";
	string rFile = "rustbelt.txt";
	string gFile = "gulfcoast.txt";

	list<City> wStates;
	list<City> rStates;
	list<City> gStates;
	
	//State of temporia
	City temp("temptown", 100000, 0.1);
	City temp2("Temptopia", 20000, -0.05);
	City temp3("Temp City", 400000, 0.05);

	//States
	list<City>temporia = {temp,temp2,temp3};
	list<City>Illinois = {};
	list<
	//Gets pushed into an array



	array<list<City>, 3> westArray {};

	map < string, array <list<City>,3>> regionsMap;
	
	regionsMap["westcoast"] = {



	}

    for (int j = 0; j < YEARS; j++) {

        for (int i = 0; i < sArray.size(); i++) {


            switch (i) { //WestCoast
            case 0: {
				
                break;
            }
            case 1: {

                break;
            }
            case 2: {


                break;
            }
            }
        }
    }




}