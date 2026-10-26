#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <random>
#include <numeric>
#include <string>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);

void display_trip(list<Goat> trip);

void delete_goat(list<Goat>& trip);

void add_goat(list<Goat>& trip, string n[], string c[]);

int main_menu();

//New functions

void findAgeSum(list<Goat> trip);

void findAverageAge(list<Goat> trip);

void findGoat(list<Goat>trip);

void paintAllGoatsBlack(list<Goat>& trip);

void advanceOneYear(list<Goat>& trip);

void reverseList(list<Goat>& trip);

void sortList(list<Goat>& trip);

void clearList(list<Goat>& trip);

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

    list<Goat> gTrip{
        {"Bum Bum", 4, "red"},
        {"Bum Boo", 7, "red"},
        {"Bum Bee", 8, "red"}
    };


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
            findAgeSum(gTrip);
            break;
        case 5:
            findAverageAge(gTrip);
            break;
        case 6:
            findGoat(gTrip);
            break;
        case 7:
            advanceOneYear(gTrip);
            break;
        case 8:
            paintAllGoatsBlack(gTrip);
            break;
        case 9:
            sortList(gTrip);
            break;
        case 10:
            reverseList(gTrip);
            break;
        case 11:
            clearList(gTrip);
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
    cout << "[3] List of goats" << endl << "[4] Show age sum" << endl;
    cout << "[5] Show average age" << endl << "[6] Find goat" << endl;
    cout << "[7] Advance One Year" << endl << "[8] Paint All Goats Black" << endl;
    cout << "[9] Sort List" << endl << "[10] Reverse list" << endl;
    cout << "[11] Clear list" << endl << "[12] Quit" << endl;
    while (in < 1 || in > 12) {
        cout << "choice -->";
        cin >> in;
        if (in < 1 || in > 12)
            cout << "Invalid input\n" << endl;
    }

    return in;
};

void display_trip(list<Goat> trip) {

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

void delete_goat(list<Goat>& trip) {

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

void add_goat(list<Goat>& trip, string n[], string c[]) {

    int age = rand() % 20;

    Goat temp(n[rand() % SZ_NAMES], age, c[rand() % SZ_COLORS]);

    //cout << temp.get_age() << temp.get_color() << temp.get_name();

    cout << "Goat: " << temp.get_name() << " added to trip set." << endl;

    trip.push_back(temp);

}

//New functions
void findAgeSum(list<Goat> trip) {
    int ageSum = accumulate(trip.begin(), trip.end(), 0, [](int a, Goat& g) { return a + g.get_age(); });
    cout << "Sum of ages is " << ageSum << endl;

}

void findAverageAge(list<Goat> trip) {

    int ageSum = accumulate(trip.begin(), trip.end(), 0, [](int a, Goat& g) { return a + g.get_age(); });
    cout << "Average age is " << ageSum / trip.size() << endl;

}

void findGoat(list<Goat>trip) {
    cin.ignore();
    string search;

    cout << "Enter name of goat to look for: " << endl;
    getline(cin, search);
    cout << endl;
    cout << "Searching for " << search << endl;
    auto it = find_if(trip.begin(), trip.end(), [search](const Goat& v) { return v.get_name() == search; });
    if (it != trip.end())
        cout << "Found goat " << search << " it is " << it->get_age() << " years old and " << it->get_color() << " colored." << endl;
    else
        cout << "Did not find goat " << search << endl;

}

void paintAllGoatsBlack(list<Goat>& trip) {
    for_each(trip.begin(), trip.end(), [](Goat& n) { n.set_color("black"); });
}

void advanceOneYear(list<Goat>& trip) {

    transform(trip.begin(), trip.end(), trip.begin(), [](Goat& g) { g.set_age(g.get_age() + 1); return g; });
    cout << "All goats are now 1 year older." << endl;
}

void reverseList(list<Goat>& trip) {
    trip.reverse();
}

void sortList(list<Goat>& trip) {
    trip.sort();
    cout << "List sorted alphabetically" << endl;
}

void clearList(list<Goat>& trip) {
    trip.clear();
}
