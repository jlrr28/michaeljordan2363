#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int mainMenu() {




}


int main() {
    // declarations
    map<string, vector<string>> villagerColors;
    
    map<string, tuple<int,string,string> > villagerData;
    
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerData["Audie"] = { 4, "Yellow", "Red" };
    villagerData["Raymond"] = { 5, "Gray", "White" };
    villagerData.insert({ "Marshal", {2, "White", "Black"} });

    villagerData["Michael"] = {5, "dog" , "wazzup"};
    villagerData["BBB"] = { 7, "Hound" , "No playing " };
    villagerData.insert({ "Duncan" , { 3, "Kangaroo", "boing" } });
    
    

    auto& m = villagerData["Michael"];
    // cout << "Michael " << get<0>(m) << get<1>(m) << get<2>(m) << endl;
    
    cout << "Current Villagers:" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": ";
        auto& m = villagerData[pair.first];
        cout << get<0>(m) << ", " << get<1>(m) << ", " << get<2>(m);
        cout << endl;
    }

    int input = 0;
    while (input != 4) {

        input = main_menu();

        switch (input) {
        case 1:
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;
        default: break;
        }
    }


    // delete an element
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        auto& m = villagerData[searchKey];
        cout << get<1>(m);
        cout << endl;
    }
    else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}