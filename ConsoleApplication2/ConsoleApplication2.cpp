#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Car {
    int doors;
    string make;
    string model;
    bool hatchback;
};

Car populateCar();
void outputCar(const Car&);

int main() {
    //demonstrate with a single struct using console input
    Car myCar = populateCar();
    cout << "\nOutputting single car in single struct:\n";
    outputCar(myCar);
    cout << endl << endl;

    //demonstrate with multiple structs using file input
    Car carCollection[3];
    ifstream infile("input.txt");
    int in_doors;
    string in_make, in_model;
    string in_hatchback;
    int index = 0;

    while (infile >> in_doors) {
        infile.ignore();
        //get the three remaining data elements in the record
        getline(infile, in_make);
        getline(infile, in_model);
        infile >> in_hatchback;

        Car temp;
        temp.doors = in_doors;
        temp.make = in_make;
        temp.model = in_model;
        if (in_hatchback == "yes") temp.hatchback = true;
        else temp.hatchback = false;

        //store the temp struct into the array
        carCollection[index++] = temp;
    }

    //output array of cars
    cout << "Outputting array of cars:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Car #" << i + 1 << ":\n";
        outputCar(carCollection[i]);
    }

    infile.close();

    return 0;
}

Car populateCar() {
    Car temp;
    cout << "Enter # doors: ";
    cin >> temp.doors;
    cin.ignore();
    cout << "Enter make: ";
    getline(cin, temp.make);
    cout << "Enter model: ";
    getline(cin, temp.model);
    cout << "Hatchback? Y/N: ";
    char entry;
    cin >> entry;
    entry = toupper(entry);
    while (entry != 'Y' and entry != 'N') {
        cout << "\t> ERROR: Y/N only: ";
        cin >> entry;
        entry = toupper(entry);
    }
    temp.hatchback = entry == 'Y' ? true : false;
    return temp;
}

void outputCar(const Car& c) {
    cout << "\t> Make/Model: " << c.make << " " << c.model << endl;
    cout << "\t> Doors: " << c.doors << endl;
    cout << "\t> Hatchback: ";
    c.hatchback ? cout << "yes" : cout << "no";
    cout << endl;
}