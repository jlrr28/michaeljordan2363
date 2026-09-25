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


void sortStudentData(vector<sData> s) {

    vector<sData>sortD;
    cout << sortD.size() << " students are due to be sorted" << endl;

    

}

void inputStudentData(string f, vector<sData> &s) {
    

    sData temp;

    cout << s.size() << " students are being input to studentData" << endl;
    
    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        cout << f << " opened" << endl;
        
       for (int i = 0; i < s.size(); i++) {
           fin >> temp.ID;
           cout << temp.ID << "  ";
           fin >> temp.Grade;
           cout << temp.Grade << endl;
          
           s.at(i) = temp;

       }
       
       



        fin.close();
    }
    else
        cout << "File not found.\n";


}
    

int main() {

    string file = "shortgrades.txt";
	int numberOfStudents = getFileLines(file);

    vector<sData> studentData(numberOfStudents);
    
    inputStudentData(file, studentData);

    for (auto& val : studentData) 
        cout << val.Grade << "  " << val.ID << endl;
    cout << studentData.size();
    
    vector<sData> sortedData = studentData;

    for (auto& val : sortedData)
        cout << val.Grade << "  " << val.ID << endl;
    cout << sortedData.size();

    //cout << numberOfStudents;
    //cout << studentData.size();



}