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


void sortStudentData(vector<sData> &s) {
    sData temp1;
    sData temp2;
    vector<sData>sortD;
    cout << s.size() << " students are due to be sorted by ID" << endl;
    
    //int i = 5;
    //temp = s.at(i);
    //cout << "s.at " << i << " is " << temp.Grade << ", " << temp.ID;

    for (int i = 0; i < s.size() - 1; i++) {
        int  indexSmallest = i;
        for (int j = i + 1; j < s.size(); j++) {
            temp1 = s.at(j);
            cout << temp1.ID << endl;
            temp2 = s.at(indexSmallest);
            cout << temp2.ID << endl;

            if (temp1.ID < temp2.ID) {
                indexSmallest = j;
            }
        
        
        }
        
        }

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
           //cout << temp.ID << "  ";
           fin >> temp.Grade;
           //cout << temp.Grade << endl;
          
           s.at(i) = temp;

       }
       
        fin.close();
    }
    else
        cout << "File not found.\n";
}
    

int main() {

    string file = "simple.txt";
	int numberOfStudents = getFileLines(file);

    vector<sData> studentData(numberOfStudents);
    
    inputStudentData(file, studentData);

    for (auto& val : studentData) 
        cout << val.Grade << "  " << val.ID << endl;
    cout << studentData.size() << endl;
    
    vector<sData> sortedData = studentData;

    for (auto& val : sortedData)
        cout << val.Grade << "  " << val.ID << endl;

    sortStudentData(sortedData);

    //cout << numberOfStudents;
    //cout << studentData.size();



}