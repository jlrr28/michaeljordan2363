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

    vector<sData>sortedData;
    cout << sortedData.size() << " students are due to be sorted" << endl;

    return sortedData;

}

vector<sData> inputStudentData(string f, vector<sData> s) {
    vector<sData>inputData;
    cout << s.size() << " students are being input to studentData" << endl;
    
    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        cout << f << " opened" << endl;
        
       for (int i = 0; i < s.size(); i++) {
           fin >> inputData.ID;
           cout << s.at(i) << endl;
           fin >> s.at(i)->Grade;


       }
       
       



        fin.close();
    }
    else
        cout << "File not found.\n";

    return inputData;

}
    

int main() {

    string file = "shortgrades.txt";
	int numberOfStudents = getFileLines(file);

    vector<sData> studentData(numberOfStudents);
    
    sData stuData = inputStudentData;
    
    inputStudentData(file, studentData);


    //cout << numberOfStudents;
    //cout << studentData.size();
    sortStudentData(file, studentData);


}