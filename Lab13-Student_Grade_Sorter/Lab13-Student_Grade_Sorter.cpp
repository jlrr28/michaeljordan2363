// COMSC - 210 || Lab 11 || Jose Luis Ramos

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <array>
using namespace std;


struct sData {
	int ID;
	double Grade;
};

int getFileLines(string f) {

    int i = 0;
    string lines = "";
    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        cout << f << " opened" << endl;
        while(getline(fin,lines))
        i++;
        fin.close();
    }
    else
        cout << "File not found.\n";
    return i;

}


int main() {

    string file = "shortgrades.txt";
	int numberOfStudents = getFileLines(file);
	array<sData, 2>studentData;
    cout << numberOfStudents;

}