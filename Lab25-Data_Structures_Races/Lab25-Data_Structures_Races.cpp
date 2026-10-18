#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

void sortVec(vector<string>& v) {

    for (int i = 0; i < v.size() - 1; i++) {
        int iLeast = i;

        for (int j = i + 1; j < v.size(); j++) {
            if (v.at(i) < v.at(i))
                iLeast = j;
        }

        string temp = v.at(i);
        v.at(i) = v.at(iLeast);
        v.at(iLeast) = temp;



    }

}


int main() {
    string file = "codesShort.txt";

    vector<string> vec;
    list<string> list;
    set<string> set;
    string temp;
    ifstream fin;
    
    //////////////////////Inserting
    //Vector
    auto start = high_resolution_clock::now();
    fin.open(file);
    while (fin.good()){
        fin >> temp;
        vec.push_back(temp);
    }
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Vector: " << vec.size() << " nanoseconds:" << duration.count() << endl;

    //List
    start = high_resolution_clock::now();
    fin.open(file);
    while (fin.good()) {
        fin >> temp;
        list.push_back(temp);
    }
    fin.close();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "List:   " << list.size() << " nanoseconds:" << duration.count() << endl;

    //Set
    start = high_resolution_clock::now();
    fin.open(file);
    while (fin.good()) {
        fin >> temp;
        set.insert(temp);
    }
    fin.close();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "Set:    " << set.size() << " nanoseconds:" << duration.count() << endl;

    //////////////////////SORTING
    
    //Vector
    start = high_resolution_clock::now();

    sortVec(vec);

    fin.close();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "Vector Sort: " << vec.size() << " nanoseconds:" << duration.count() << endl;

    for (int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << endl;

    //List
    start = high_resolution_clock::now();
    
    list.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "List Sort: " << list.size() << " nanoseconds:" << duration.count() << endl;
    for (string value : list) cout << value << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/