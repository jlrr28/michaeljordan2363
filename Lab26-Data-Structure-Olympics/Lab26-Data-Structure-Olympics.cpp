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



const int COL = 3, TESTS = 4, RUNS = 15;
const int STRUCTURES = 3;

int main() {
    string file = "codes.txt";
    string insertT = "TESTCODE";

    vector<string> vec;
    list<string> list;
    set<string> set;
    //[Test]: [0] = Reading, [1] = Sorting, [2] = Inserting , [3] = Deleting
    //[Structures]: [0] = Vector, [1] = List, [2] = Set 
    //[2]: [0] keeping the time from run, [1] keeping the sum of times from the runs]
    
    int oArray[TESTS][STRUCTURES][2];
    
    int vTime = 0;
    int lTime = 0;
    int sTime = 0;
    
    cout << RUNS << " runs will be done" << endl;
    cout << "DATA STRUCTURE RACING" << endl;
    cout << "        VECTOR    ----    LIST  ----    SET" << endl;
    
    //////////////////////Reading

    int vSum = 0;
    int lSum = 0;
    int sSum = 0;
    int test = 0;

    for (int j = 0; j < RUNS; j++) {

        for (int i = 0; i < STRUCTURES; i++) {
            auto start = chrono::high_resolution_clock::now();

            switch (i) {
            case 0: {
                readData(vec, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                vSum += oArray[test][i][0];
                oArray[test][i][1] = vSum;
               
                break;
            }
            case 1: {
                readData(list, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                lSum += oArray[test][i][0];
                oArray[test][i][1] = lSum;

                break;
            }
            case 2: {
                readData(set, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                sSum += oArray[test][i][0];
                oArray[test][i][1] = sSum;

                break;
            }
            }
        }
    }
    

    //cout << "  READING|| " << oArray[0][0][1]/RUNS << " microsec || " << oArray[0][1][1] / RUNS << " microsec || " << oArray[0][2][1] / RUNS << " microsec " << endl;

    /////////////////////SORTING
    vSum = 0; lSum = 0; sSum = 0; test++;
    for (int j = 0; j < RUNS; j++) {

        for (int i = 0; i < STRUCTURES; i++) {
            auto start = chrono::high_resolution_clock::now();

            switch (i) {
            case 0: {
                sort(vec.begin(), vec.end());
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                vSum += oArray[test][i][0];
                oArray[test][i][1] = vSum;

                break;
            }
            case 1: {
                list.sort();
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                lSum += oArray[test][i][0];
                oArray[test][i][1] = lSum;

                break;
            }
            case 2: {

                oArray[test][i][1] = -1;
                break;
            
            }
            }
        }
    }

    //////////////////////INSERTING

    vSum = 0; lSum = 0; sSum = 0; test++;
    for (int j = 0; j < RUNS; j++) {

        for (int i = 0; i < STRUCTURES; i++) {
            auto start = chrono::high_resolution_clock::now();

            switch (i) {
            case 0: {
                insertMid(vec, insertT);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                vSum += oArray[test][i][0];
                oArray[test][i][1] = vSum;

                break;
            }
            case 1: {
                insertMid(list, insertT);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                lSum += oArray[test][i][0];
                oArray[test][i][1] = lSum;

                break;
            }
            case 2: {
                set.insert(insertT);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                sSum += oArray[test][i][0];
                oArray[test][i][1] = sSum;

                break;
            }
            }
        }
    }
    //cout << "Inserting|| " << oArray[2][0][1] / RUNS << " microsec || " << oArray[2][1][1] / RUNS << " microsec || " << oArray[2][2][1] / RUNS << " microsec " << endl;

    //////////////////////DELETING
    vSum = 0; lSum = 0; sSum = 0; test++; 
    for (int j = 0; j < RUNS; j++) {

        for (int i = 0; i < STRUCTURES; i++) {
            auto start = chrono::high_resolution_clock::now();

            switch (i) {
            case 0: {
                deleteMid(vec);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                vSum += oArray[test][i][0];
                oArray[test][i][1] = vSum;

                break;
            }
            case 1: {
                deleteMid(list);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                lSum += oArray[test][i][0];
                oArray[test][i][1] = lSum;

                break;
            }
            case 2: {
                deleteMid(set);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);

                oArray[test][i][0] = duration.count();
                sSum += oArray[test][i][0];
                oArray[test][i][1] = sSum;
                cout << "structure [" << i << "] test index [" << test << "] time: " << oArray[test][i][0] << " times sum: " << oArray[test][i][1] << endl;

                break;
            }
            }
        }
    }
    cout << "  READING|| " << oArray[0][0][1] / RUNS << " microsec || " << oArray[0][1][1] / RUNS << " microsec || " << oArray[0][2][1] / RUNS << " microsec " << endl;

    cout << "  SORTING|| " << oArray[1][0][1] / RUNS << " microsec || " << oArray[1][1][1] / RUNS << " microsec || " << oArray[1][2][1] << " microsec " << endl;

    cout << "Inserting|| " << oArray[2][0][1] / RUNS << " microsec || " << oArray[2][1][1] / RUNS << " microsec || " << oArray[2][2][1] / RUNS << " microsec " << endl;

    cout << "Deleting|| " << oArray[3][0][1] / RUNS << " microsec || " << oArray[3][1][1] / RUNS << " microsec || " << oArray[3][2][1] / RUNS << " microsec " << endl;

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
    v.erase(target);

}