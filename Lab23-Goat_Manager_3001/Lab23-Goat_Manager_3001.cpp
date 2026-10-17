#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);

void delete_goat(list<Goat>& trip);

void add_goat(list<Goat>& trip, string n[], string c[]) {
    int age = rand() % 20;
    Goat temp(n[rand() % SZ_NAMES], age , );

    trip.push_back(temp);



}

void display_trip(list<Goat> trip);

int main_menu() {
    int in = 0;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl << "[4] Quit" << endl;

    while (in < 1 || in > 4) {
        cout << "choice -->";
        cin >> in;
        cout << endl;
        if (in < 1 || in>4) 
            cout << "Invalid input" << endl;
        else
            cout << "Chose " << in << endl;
    }

    return in;
};

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> gTrip;

    int input = 0;
    while (input != 4) {
        
        input = main_menu();

        switch (input) {
        case '1':
            add_goat(gTrip, names, colors);
            break;
        case '2':
            //
            break;
        case '3':
            //
            break;
        case '4':
            break;
        default: break;

    }

    cout << "Thanks for using Goat Manager 3001" << endl;


    return 0;
}

