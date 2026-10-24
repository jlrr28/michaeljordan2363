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
    villagerColors["Audie"] = { "p", "Yellow", "Red"};
    villagerData["Audie"] = { 4, "Yellow", "Red" };
    villagerData["Raymond"] = { 5, "Gray", "White" };
    villagerData.insert({ "Marshal", {2, "White", "Black"} });

    villagerData["Michael"] = {5, "dog" , "wazzup"};
    villagerData["BBB"] = { 7, "Hound" , "No playing " };
    villagerData.insert({ "Duncan" , { 3, "Kangaroo", "boing" } });
    
    

    auto& m = villagerData["Michael"];
    cout << "Michael " << get<0>(m) << get<1>(m) << get<2>(m) << endl;
    //int friendRating = get<0>(villagerData);
    //string vSpecies =  get<1>(villagerData);
    //string vCatchphrase = get<2>(villagerData);
    //auto [friendRating, vSpecies, vCatchphrase] = villagerData;
    
    // access the map using a range-based for loop
    
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": ";
        auto& m = villagerData[pair.first];
        cout << get<0>(m) << get<1>(m) << get<2>(m);
        cout << endl;
    }

    // delete an element
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        //for (auto color : it->second)  // range loop to traverse the value/vector
        //    cout << color << " ";
        //cout << endl;
    }
    else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}