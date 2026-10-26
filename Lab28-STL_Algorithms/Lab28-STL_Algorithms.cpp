#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <string>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);

void display_trip(set<Goat> trip);

void delete_goat(set<Goat>& trip);

void add_goat(set<Goat>& trip, string n[], string c[]);

int main_menu();

void findNumOfColors(set<Goat>& trip) {
    
    int found = 0;
    string in;
    getline(cin, in);

    Goat search("xxxxxxx",0,in);

    
    auto it = find(trip.begin(), trip.end(), search);
    




    cout << found;

}

void averageAge(set<Goat>& trip){}

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

    set<Goat> gTrip{
        {"Bum Bum", 8, "White"},
        {"Bum Boo", 7, "White"},
        {"Bum Bee", 8, "White"}
    };

    //Goat g1("Bum Bum", 6, "White");
    //Goat g2("Bum Boo", 7, "White");
    //Goat g3("Bum Bee", 8, "White");
    //gTrip.insert(g1); gTrip.insert(g2); gTrip.insert(g3);

    int input = 0;
    while (input != 12) {
        display_trip(gTrip);
        input = main_menu();

        switch (input) {
        case 1:
            add_goat(gTrip, names, colors);
            break;
        case 2:
            delete_goat(gTrip);
            break;
        case 3:
            display_trip(gTrip);
            break;
        case 4:
            findNumOfColors(gTrip);
            break;
        case 5:
            //newfunction
            break;
        case 6:
            //newfunction
            break;
        case 7:
            //newfunction
            break;
        case 8:
            //newfunction
            break;
        case 9:
            //newfunction
            break;
        case 10:
            //newfunction
            break;
        case 11:
            //newfunction
            break;
        case 12:
            break;
        default: break;
        }
    }

    cout << endl << "Thanks for using Goat Manager 3001." << endl;


    return 0;
}

int main_menu() {
    int in = 0;
    cout << endl;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl << "[2] Delete a goat" << endl;
    cout << "[3] Set of goats" << endl << "[4] Quit" << endl;

    while (in < 1 || in > 12) {
        cout << "choice -->";
        cin >> in;
        if (in < 1 || in > 12)
            cout << "Invalid input\n" << endl;
    }

    return in;
};

void display_trip(set<Goat> trip) {

    cout << endl;

    int x = 1;
    cout << "There are " << trip.size() << " goats in the Trip set:" << endl;
    for (Goat value : trip) {
        cout << "[" << x << "] " << value.get_name() << " ( " << value.get_age() <<
            ", " << value.get_color() << " )" << endl;
        x++;
    }

    cout << endl;

}

void delete_goat(set<Goat>& trip) {

    if (trip.empty())
        cout << "Set is empty, no goats to delete." << endl;
    else {

        display_trip(trip);
        cout << "Select which goat you want to delete" << endl;

        int position = 0;
        while (position < 1 || position > trip.size()) {
            //cout << trip.size();
            cin >> position;
            if ((position < 1) || (position > trip.size()))
                cout << "Position input not in set" << endl;

        }

        cout << "Deleting goat at position [" << position << "]" << endl;
        auto it = trip.begin();
        advance(it, position - 1);

        trip.erase(it);

    }

}

void add_goat(set<Goat>& trip, string n[], string c[]) {

    int age = rand() % 20;

    Goat temp(n[rand() % SZ_NAMES], age, c[rand() % SZ_COLORS]);

    //cout << temp.get_age() << temp.get_color() << temp.get_name();

    cout << "Goat: " << temp.get_name() << " added to trip set." << endl;

    trip.insert(temp);

}