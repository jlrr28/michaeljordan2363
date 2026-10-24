#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, vector<string>> villagerColors;
    
    map<string, tuple<int,string,string> > villagerData;
    
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = { "Orange", "Yellow", "Red" };
    villagerColors["Raymond"] = { "Black", "Gray", "White" };
    villagerColors.insert({ "Marshal", {"Blue", "White", "Black"} });

    villagerData["Michael"] = {5, "dog" ,"wazzup"};

    auto& m = villagerData["Michael"];
    cout << "Michael " << get<0>(m) << get<1>(m) << get<2>(m) << endl;
    //int friendRating = get<0>(villagerData);
    //string vSpecies =  get<1>(villagerData);
    //string vCatchphrase = get<2>(villagerData);
    //auto [friendRating, vSpecies, vCatchphrase] = villagerData;
    
    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin();
        it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    }
    else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}