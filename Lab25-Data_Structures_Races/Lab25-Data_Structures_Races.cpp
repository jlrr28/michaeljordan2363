#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
using namespace std;

int main() {
    string file = "codesShort.txt";

    vector<string> vec;
    list<string> list;
    set<string> set;
    string temp;

    ifstream fin;
    fin.open(file);
    while (fin.good()){
        fin >> temp;
       vec.push_back(temp);
    }
    fin.close
    cout << vec.size() << endl;



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/