#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <array>

using namespace std;
using namespace std::chrono;

void readData(vector<string>& v, string f);

void readData(list<string>& v, string f);

void readData(set<string>& v, string f);


void insertMid(vector<string>& v, string ins);

void insertMid(list<string>& v, string ins);


void deleteMid(vector<string>& v);

void deleteMid(list<string>& v);

void deleteMid(set<string>& v);



const int COL = 3, ROWS = 4, RUNS = 15;
const int STRUCTURES = 3;

int main() {
    string file = "codes.txt";
    string insertT = "TESTCODE";

    vector<string> vec;
    list<string> list;
    set<string> set;
    //[Test][Structure][2 sets of tests and structures, [0] keeping the times from runs, [1] keeping the sum of times from the runs]
    array<array<array<int,2>,ROWS >,STRUCTURES >oArray;// [COL] [ROWS] [SET] ;

    int vTime = 0;
    int lTime = 0;
    int sTime = 0;
    cout << RUNS << " runs will be done" << endl;
    cout << "DATA STRUCTURE RACING" << endl;
    cout << "        VECTOR    ----    LIST  ----    SET" << endl;
    //////////////////////Reading
    //Vector
    
    int vSum = 0;
    int lSum = 0;
    int sSum = 0;

    for (int j = 0; j < RUNS; j++) {

        for (int i = 0; i < STRUCTURES; i++) {
            auto start = chrono::high_resolution_clock::now();

            switch (i) {
            case 0: {
                readData(vec, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                
                oArray[0][i][0] = duration.count();
                oArray[0][i][1] = vSum;
                vSum += oArray[0][i][0];
                
                //cout << " vec day times: " << oArray[0][i][0] << " vec day sum: " << j << " " << oArray[0][i][1] << endl; 
                break;
            }
            case 1: {
                readData(list, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[0][i][0] = duration.count();
                oArray[0][i][1] = lSum;
                lSum += oArray[0][i][0];

                break;
            }
            case 2: {
                readData(set, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                
                oArray[0][i][0] = duration.count();
                oArray[0][i][1] = sSum;
                sSum += oArray[0][i][0];
                
                break;
            }
            }
        }
    }

    cout << "  READING|| " << oArray[0][0][1]/RUNS << " microsec || " << oArray[0][1][1] / RUNS << " nanosec || " << oArray[0][2][1] / RUNS << " nano sec " << endl;

    /////////////////////*SORTING

    for (int i = 0; i < STRUCTURES; i++) {
        auto start = chrono::high_resolution_clock::now();

        switch (i) {
        case 0: {
            sort(vec.begin(), vec.end());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);

            oArray[1][i][0] = duration.count();
            oArray[1][i][1] = vSum;
            vSum += oArray[0][i][0];
            
            
            break;
        }
        case 1: {
            list.sort();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);

            oArray[1][i][0] = duration.count();
            oArray[1][i][1] = vSum;
            vSum += oArray[0][i][0];
            
            break;
        }
        case 2: {

            sTime = -1;
            break;
        }
        }
    }

    cout << "  SORTING|| " << oArray[1][0][1] / RUNS << " microsec || " << oArray[1][1][1] / RUNS << " microsec || " << sTime << " microsec " << endl;

    //////////////////////INSERTING

    //Vector

    for (int i = 0; i < STRUCTURES; i++) {
        auto start = chrono::high_resolution_clock::now();

        switch (i) {
        case 0: {
            insertMid(vec, insertT);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            vTime = duration.count();
            break;
        }
        case 1: {
            insertMid(list, insertT);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            lTime = duration.count();
            break;
        }
        case 2: {
            set.insert(insertT);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            sTime = duration.count();
            break;
        }
        }
    }

    cout << "Inserting|| " << vTime << " nanosec || " << lTime << " nanosec || " << sTime << " nano sec " << endl;

    //////////////////////DELETING

    for (int i = 0; i < STRUCTURES; i++) {
        auto start = chrono::high_resolution_clock::now();

        switch (i) {
        case 0: {
            deleteMid(vec);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            vTime = duration.count();
            break;
        }
        case 1: {
            deleteMid(list);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            lTime = duration.count();
            break;
        }
        case 2: {
            deleteMid(set);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            sTime = duration.count();
            break;
        }
        }
    }

    cout << "Deleting|| " << vTime << " nanosec || " << lTime << " nanosec || " << sTime << " nano sec " << endl;

    return 0;
}

void readData(vector<string>& v, string f) {
    ifstream fin;
    string in;
    fin.open(f);
    while (fin >> in) {
        v.push_back(in);
    }
    fin.close();
}

void readData(list<string>& v, string f) {
    ifstream fin;
    string in;
    fin.open(f);
    while (fin >> in) {
        v.push_back(in);
    }
    fin.close();
}

void readData(set<string>& v, string f) {
    ifstream fin;
    string in;
    fin.open(f);
    while (fin >> in) {
        v.insert(in);
    }
    fin.close();
}

void insertMid(vector<string>& v, string ins) {

    int mid = v.size() / 2;
    auto it = v.begin();
    advance(it, mid);

    v.insert(it, ins);

}

void insertMid(list<string>& v, string ins) {

    int mid = v.size() / 2;

    auto it = v.begin();
    advance(it, mid);

    v.insert(it, ins);

}


void deleteMid(vector<string>& v) {

    int mid = v.size() / 2;

    v.erase(v.begin() + mid);

}

void deleteMid(list<string>& v) {

    int mid = v.size() / 2;
    auto it = v.begin();
    advance(it, mid);
    string target = *it;
    v.remove(target);

}

void deleteMid(set<string>& v) {

    int mid = v.size() / 2;
    auto it = v.begin();
    advance(it, mid);
    string target = *it;
    v.erase(target);;

}