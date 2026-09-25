// COMSC - 210 || Lab 11 || Jose Luis Ramos

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
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


vector<sData> sortStudentData(string f, vector<sData*> s) {

    vector<sData>sortedData;
    cout << sortedData.size() << " students are due to be sorted" << endl;

    return sortedData;

}

void inputStudentData(string f, vector<sData*> s) {
    
    double tempGrade;
    int tempID;
    cout << s.size() << " students are being input to studentData" << endl;
    
    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        cout << f << " opened" << endl;
        
       for (int i = 0; i < s.size(); i++) {
           fin >> temp.ID;
           //cout << temp.ID << "  ";
           fin >> temp.Grade;
           //cout << temp.Grade << endl;
          
           s.at(i) -> Grade;
           cout << s.at(i);
           s.at(i)->ID;



       }
       
       



        fin.close();
    }
    else
        cout << "File not found.\n";


}
    

int main() {

    string file = "shortgrades.txt";
	int numberOfStudents = getFileLines(file);

    vector<sData*> studentData(numberOfStudents);
    
    inputStudentData(file, studentData);


    //cout << numberOfStudents;
    //cout << studentData.size();
    //sortStudentData(file, studentData);


}