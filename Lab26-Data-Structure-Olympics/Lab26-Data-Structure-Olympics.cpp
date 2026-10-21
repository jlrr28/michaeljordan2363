#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

void readData(vector<string>& v, string f);

void readData(list<string>& v, string f);

void readData(set<string>& v, string f);


void sortVec(vector<string>& v);


void insertMid(vector<string>& v, string ins);

void insertMid(list<string>& v, string ins);


void deleteMid(vector<string>& v);

void deleteMid(list<string>& v);

void deleteMid(set<string>& v);

int main() {
    string file = "codes.txt";
    string insertT = "TESTCODE";

    vector<string> vec;
    list<string> list;
    set<string> set;

    int vTime = 0;
    int lTime = 0;
    int sTime = 0;
    cout << "DATA STRUCTURE RACING" << endl;
    cout << "        VECTOR    ----    LIST  ----    SET" << endl;
    //////////////////////Reading
    //Vector
    auto start = high_resolution_clock::now();

    readData(vec, file);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    vTime = duration.count();

    //List
    start = high_resolution_clock::now();

    readData(list, file);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    lTime = duration.count();

    //Set
    start = high_resolution_clock::now();

    readData(set, file);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    sTime = duration.count();

    cout << "READING|| " << vTime << " nanosec || " << lTime << " nanosec || " << sTime << " nano sec " << endl;

    //////////////////////SORTING

    //Vector
    start = high_resolution_clock::now();

    sortVec(vec);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    vTime = duration.count();

    //List
    start = high_resolution_clock::now();

    list.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    lTime = duration.count();

    //set

    sTime = -1;

    cout << "SORTING|| " << vTime << " nanosec || " << lTime << " nanosec || " << sTime << " nano sec " << endl;

    //////////////////////INSERTING

    //Vector

    start = high_resolution_clock::now();

    insertMid(vec, insertT);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    vTime = duration.count();

    //List

    start = high_resolution_clock::now();

    insertMid(list, insertT);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    lTime = duration.count();

    //Set
    start = high_resolution_clock::now();

    set.insert(insertT);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    sTime = duration.count();

    cout << "Inserting|| " << vTime << " nanosec || " << lTime << " nanosec || " << sTime << " nano sec " << endl;

    //////////////////////DELETING

    //Vector

    start = high_resolution_clock::now();

    deleteMid(vec);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    vTime = duration.count();

    //List
    start = high_resolution_clock::now();

    deleteMid(list);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    lTime = duration.count();

    //Set
    start = high_resolution_clock::now();

    deleteMid(set);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    sTime = duration.count();

    cout << "Deleting|| " << vTime << " nanosec || " << lTime << " nanosec || " << sTime << " nano sec " << endl;

    return 0;
}

void readData(vector<string>& v, string f) {
    ifstream fin;
    string temp;
    fin.open(f);
    while (fin.good()) {
        fin >> temp;
        v.push_back(temp);
    }
}

void readData(list<string>& v, string f) {
    ifstream fin;
    string temp;
    fin.open(f);
    while (fin.good()) {
        fin >> temp;
        v.push_back(temp);
    }
}

void readData(set<string>& v, string f) {
    ifstream fin;
    string temp;
    fin.open(f);
    while (fin.good()) {
        fin >> temp;
        v.insert(temp);
    }
}


void sortVec(vector<string>& v) {

    sort(v.begin(), v.end());

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
    v.erase(it);

}

void deleteMid(set<string>& v) {

    int mid = v.size() / 2;
    auto it = v.begin();
    advance(it, mid);
    v.erase(it);

}