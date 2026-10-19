#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

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

void sortVec(vector<string> &v) {

    for (int i = 0; i < v.size() - 1; i++) {
        
        int iLeast = i;

        for (int j = i + 1; j < v.size(); j++) {
            
            if (v.at(j) < v.at(iLeast)) {
                iLeast = j;
            }
        
        }
        string temp = v.at(i);
        v.at(i) = v.at(iLeast);
        v.at(iLeast) = temp;

    }

}

void insertMid(vector<string>& v , string ins) {

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
    
    v.erase(v.begin()+mid);

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

int main() {
    string file = "alphabet.txt";
    string insertT = "TESTCODE";

    vector<string> vec;
    list<string> list;
    set<string> set;
    
    int vTime = 0;
    int lTime = 0;
    int sTime = 0;
    Cout << "DATA STRUCTURE RACING" << 

    //////////////////////Reading
    //Vector
    auto start = high_resolution_clock::now();

    readData(vec, file);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Vector: " << vec.size() << " nanoseconds:" << duration.count() << endl;

    //List
    start = high_resolution_clock::now();
    readData(list, file);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
   
    cout << "List:   " << list.size() << " nanoseconds:" << duration.count() << endl;

    //Set
    start = high_resolution_clock::now();
    readData(set, file);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "Set:    " << set.size() << " nanoseconds:" << duration.count() << endl;


    //////////////////////SORTING
    
    //Vector
    start = high_resolution_clock::now();

    sortVec(vec);

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "Vector Sort: " << vec.size() << " nanoseconds:" << duration.count() << endl;

    //for (int i = 0; i < vec.size(); i++)
    //    cout << vec.at(i) << endl;

    //List
    start = high_resolution_clock::now();
    
    list.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "List Sort: " << list.size() << " nanoseconds:" << duration.count() << endl;
    
    //set
    
    cout << "Set sorted: -1" << endl;


    //////////////////////SORTING

    //Vector
    
    start = high_resolution_clock::now();
    insertMid(vec, insertT);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    
    cout << "Vector Sort: " << vec.size() << " nanoseconds:" << duration.count() << endl;
    
    //for (int i = 0; i < vec.size(); i++)
    //    cout << vec.at(i) << endl;

    //List

    start = high_resolution_clock::now();
    insertMid(list, insertT);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    cout << "List Insert: " << list.size() << " nanoseconds:" << duration.count() << endl;
    for (string value : list) cout << value << endl;

    //Set
    start = high_resolution_clock::now();
    set.insert(insertT);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
   
    cout << "Set Insert: " << set.size() << " nanoseconds:" << duration.count() << endl;
    for (string value : set) cout << value << endl;


    //////////////////////DELETING

    //Vector
    
    start = high_resolution_clock::now();
    deleteMid(vec);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    cout << "Vector Sort: " << vec.size() << " nanoseconds:" << duration.count() << endl;
    for (int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << endl;


    
    //List
    start = high_resolution_clock::now();
    deleteMid(list);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    cout << "List Insert: " << list.size() << " nanoseconds:" << duration.count() << endl;
    for (string value : list) cout << value << endl;

    //Set
    start = high_resolution_clock::now();
    deleteMid(set);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    cout << "List Insert: " << set.size() << " nanoseconds:" << duration.count() << endl;
    for (string value : set) cout << value << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/