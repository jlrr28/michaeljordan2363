// COMSC - 210 || Lab 11 || Jose Luis Ramos

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


struct sData {
	int ID;
	double Grade;
};

int getFileLines(string f) {

    int i = 0;
    string lines;
    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        cout << f << " opened" << endl;
        while(getline(fin,lines)) i++;
        fin.close();
    }
    else
        cout << "File not found.\n";
    return i;

}


vector<sData> sortStudentData(string f, vector<sData> s) {

    vector<sData>sortedData = s;
    cout << sortedData.size() << " students are due to be sorted" << endl;

    return sortedData;

}

void inputStudentData(string f, vector<sData>* s) {
    vector<sData>inputData;
    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        cout << f << " opened" << endl;
 


        fin.close();
    }
    else
        cout << "File not found.\n";


}
    

int main() {

    string file = "shortgrades.txt";
	int numberOfStudents = getFileLines(file);

    vector<sData>studentData(numberOfStudents);
    inputStudentData(file, studentData);


    //cout << numberOfStudents;
    //cout << studentData.size();
    sortStudentData(file, studentData);


}