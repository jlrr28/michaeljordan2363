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


    ifstream fin;
    fin.open(f);
    if (fin.good()) {





        fin.close();
    }
    else
        cout << "File not found.\n";

}


int main() {

    string file = "shortgrades.txt";
	int numberOfStudents = getFileLines();
	array<sData, 2>studentData;


}