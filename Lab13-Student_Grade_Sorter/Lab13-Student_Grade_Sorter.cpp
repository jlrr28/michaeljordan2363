// COMSC - 210 || Lab 13 || Jose Luis Ramos

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
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
        //cout << f << " opened" << endl;
        while(getline(fin,lines)) i++;
        fin.close();
    }
    else
        cout << "File not found.\n";
    return i;

}

void inputStudentData(string f, vector<sData>& s) {

    sData temp;

    //cout << s.size() << " students are being input to studentData" << endl;

    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        //cout << f << " opened" << endl;

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

void outputStudentDataFile(vector<sData> s) {
    sData temp;
    
    ofstream fout;
    fout.open("student-data-sorted.txt");
    if (fout.good()) {

        for (int i = 0; i < s.size(); i++) {
            temp = s.at(i);
            fout << temp.ID << " " << temp.Grade << '\n';

        }
        cout << "Sorted results written to student-data-sorted.txt" << endl;
        fout.close();
    }
    else
        cout << "File not found.\n";

}

void sortByID(vector<sData> &s) {
    sData temp1;
    sData temp2;
    sData temp3;
    vector<sData>sortD;
    //cout << s.size() << " students are due to be sorted by ID" << endl;

    for (int i = 0; i < s.size() - 1; i++) {
        
        int  indexSmallest = i;
       
        for (int j = i + 1; j < s.size(); j++) {
            
            temp1 = s.at(j);
            //cout << temp1.ID << " compared to ";
            temp2 = s.at(indexSmallest);
            //cout << temp2.ID << endl;


            if (temp1.ID < temp2.ID) {
                indexSmallest = j;
            }
        
        }
        
        temp3 = s.at(i);
        sData swap = temp3;
        //cout << temp2.ID << " and " << temp2.Grade << " written to at index " << i << endl;
        temp3 = temp2;
        s.at(i) = temp3;
        s.at(indexSmallest) = swap;


    }

}

void sortByGrades(vector<sData>& s) {
    sData temp1;
    sData temp2;
    sData temp3;
    vector<sData>sortD;
    //cout << s.size() << " students are due to be sorted by Grades" << endl;

    for (int i = 0; i < s.size() - 1; i++) {

        int  indexSmallest = i;

        for (int j = i + 1; j < s.size(); j++) {

            temp1 = s.at(j);
            //cout << temp1.ID << " compared to ";
            temp2 = s.at(indexSmallest);
            //cout << temp2.ID << endl;


            if (temp1.Grade > temp2.Grade) {
                indexSmallest = j;
            }

        }

        temp3 = s.at(i);
        sData swap = temp3;
        //cout << temp2.ID << " and " << temp2.Grade << " written to at index " << i << endl;
        temp3 = temp2;
        s.at(i) = temp3;
        s.at(indexSmallest) = swap;


    }

}
   
void printData(vector<sData> s) {
    int i = 1;
    for (auto& val : s)
        cout << "student number " << i++ << " grade: " << val.Grade << " ID: " << val.ID << endl;

}

double findMean(vector<sData> s) {

    double x = 0;
    double y = 0;
    sData temp;

    for (int i = 0; i < s.size(); i++) {
        temp = s.at(i);
        x += temp.Grade;
    }
    double mean = x / s.size();

    return mean;
}

double findStandardDeviation(vector<sData> s, double m) {
    double sD = 0;
    double sum = 0;
    sData temp;
    for (int i = 0; i < s.size(); i++) {
        temp = s.at(i);
        temp.Grade -= m;
        //cout << temp.Grade << endl;
        temp.Grade *= temp.Grade;
        //cout << temp.Grade << endl;
        sum += temp.Grade;
    }
    //cout << sum << " / " << m << endl;
    sD = sum/s.size();
    //cout << sD << endl;
    sD = sqrt(sD);

    return sD;
}


int main() {

    string file = "grades.txt";
	int numberOfStudents = getFileLines(file);

    vector<sData> studentData(numberOfStudents);
    cout << "Read " << studentData.size() << " student records" << endl;
    inputStudentData(file, studentData);

    vector<sData> sortedDataID = studentData;
    sortByID(sortedDataID);
    //printData(sortedDataID);

    outputStudentDataFile(sortedDataID);

    vector<sData> sortedDataGrades = studentData;
    sortByGrades(sortedDataGrades);
    //printData(sortedDataGrades);

    sData temp;
    cout << setprecision(4);
    cout << " -- - Summary Statistics - -- " << endl;

    temp = sortedDataGrades.back();
    cout << "Minimum Score: " << temp.Grade << "(Student ID: " << temp.ID << ")" << endl;

    temp = sortedDataGrades.front();
    cout << "Maximum Score: " << temp.Grade << "(Student ID: " << temp.ID << ")" << endl;
    
    double meanScore = findMean(sortedDataGrades);
    cout << "Mean Score: " << meanScore << endl;

    temp = sortedDataGrades.at(sortedDataGrades.size() / 2);
    cout << "Median Score: " << temp.Grade << "(Student ID: " << temp.ID << ")" << endl;

    //Not sure what standard deviation is but tried my best
    cout << "Standard Deviation: " << findStandardDeviation(studentData, meanScore) << endl;


}