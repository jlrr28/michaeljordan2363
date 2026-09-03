// COMSC-210 | Lab 3 | Jose Luis Ramos

#include <iostream>
#include <string>
#include <vector>
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
	
	cout << "enter name of restraunt: ";
	getline(cin, temp.name);
	cout << "enter address of restraunt: ";
	getline(cin, temp.address);
	cout << "enter type of food restraunt serves: ";
	getline(cin, temp.foodType);
	cout << "enter star rating out of 5: ";
	cin >> temp.starRating;
	cout << "enter how many years it has been open: ";
	cin >> temp.yearsOpen;
	cin.ignore();
	return temp;

}

void outputRestrauntInfo(const Restraunt& i);

int main(){

	Restraunt r1 = fillRestrauntInfo();
	outputRestrauntInfo(r1);

	Restraunt r2 = fillRestrauntInfo();
	outputRestrauntInfo(r2);

	Restraunt r3 = fillRestrauntInfo();
	outputRestrauntInfo(r3);

	Restraunt r4 = fillRestrauntInfo();
	outputRestrauntInfo(r4);

}

void outputRestrauntInfo(const Restraunt& i) {

	cout << "\n" << i.name << " is located at " << i.address <<
		" and is a " << i.foodType << " restraunt." << endl;
	cout << "It has a " << i.starRating <<
		" star rating on yelp and has been open for " << i.yearsOpen << " years.\n \n";
}

Restraunt fillRestrauntInfo() {

	Restraunt temp;

	cout << "enter name of restraunt: ";
	getline(cin, temp.name);
	cout << "enter address of restraunt: ";
	getline(cin, temp.address);
	cout << "enter type of food restraunt serves: ";
	getline(cin, temp.foodType);
	cout << "enter star rating out of 5: ";
	cin >> temp.starRating;
	cout << "enter how many years it has been open: ";
	cin >> temp.yearsOpen;
	cin.ignore();
	return temp;

}