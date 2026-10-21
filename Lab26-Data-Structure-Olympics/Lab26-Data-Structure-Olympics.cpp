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



const int COL = 3, ROWS = 4, DAYS = 15;
const int STRUCTURES = 3;

int main() {
    string file = "codes.txt";
    string insertT = "TESTCODE";

    vector<string> vec;
    list<string> list;
    set<string> set;

    int oArray[COL][ROWS][DAYS];

    int vTime = 0;
    int lTime = 0;
    int sTime = 0;
    cout << "DATA STRUCTURE RACING" << endl;
    cout << "        VECTOR    ----    LIST  ----    SET" << endl;
    //////////////////////Reading
    //Vector
    

    for (int j = 0; j < DAYS; j++) {


        for (int i = 0; i < STRUCTURES; i++) {
            auto start = chrono::high_resolution_clock::now();

            switch (i) {
            case 0: {
                readData(vec, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(end - start);
                oArray[0][i][j] = duration.count();
                cout << "vec" << oArray[0][i][j] << endl;
                break;
            }
            case 1: {
                readData(list, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(end - start);
                //lTime = duration.count();
                oArray[0][i][j] = duration.count();
                cout << "list" << oArray[0][i][j] << endl;
                break;
            }
            case 2: {
                readData(set, file);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(end - start);
                //sTime = duration.count();
                oArray[0][i][j] = duration.count();
                cout << "set" << oArray[0][i][j] << endl;
                break;
            }
            }
        }


    }
    cout << "READING|| " << vTime << " nanosec || " << lTime << " nanosec || " << sTime << " nano sec " << endl;



    /////////////////////*SORTING

    for (int i = 0; i < STRUCTURES; i++) {
        auto start = chrono::high_resolution_clock::now();

        switch (i) {
        case 0: {
            sort(vec.begin(), vec.end());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            vTime = duration.count();
            break;
        }
        case 1: {
            list.sort();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            lTime = duration.count();
            break;
        }
        case 2: {

            sTime = -1;
            break;
        }
        }
    }

    cout << "SORTING|| " << vTime << " nanosec || " << lTime << " nanosec || " << sTime << " nano sec " << endl;

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