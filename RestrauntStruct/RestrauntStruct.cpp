// COMSC-210 | Lab 3 | Jose Luis Ramos

#include <iostream>
#include <string>
using namespace std;

struct Restraunt {
	string name;
	string address;
	string foodType;
	double starRating;
	int yearsOpen;
};

Restraunt fillRestrauntInfo() {

	Restraunt temp;
	cout << "enter name:";
	getline(cin, temp.name);
	cout << "enter address:";
	getline(cin, temp.address);
	cout << "enter food stype:";
	getline(cin, temp.foodType);
	cout << "enter star rating out of 5:";
	cin >> temp.starRating;
	cout << "enter how many years it has been open:";
	cin >> temp.yearsOpen;

	return temp;

}

void outputRestrauntInfo(const Restraunt& i) {

	cout << i.name << " is located at " << i.address << " and is a " << i.foodType << " restraunt." << endl;
	cout << "It has a " << i.starRating << " star rating on yelp and has been open for " << i.yearsOpen << " years." << endl;

}

int main(){

	Restraunt info = fillRestrauntInfo();
	outputRestrauntInfo(info);



}