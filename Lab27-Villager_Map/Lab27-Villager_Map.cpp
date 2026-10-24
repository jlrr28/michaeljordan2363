#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>;
using namespace std;

int mainMenu() {
    int in = 0;
    cout << endl;
    cout << "1. Add Villager" << endl << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl << "6. exit" << endl;

    while (in < 1 || in > 6) {
        cout << "choice -->";
        cin >> in;
        if (in < 1 || in > 6)
            cout << "Invalid input\n" << endl;
    }

    return in;

}

void searchForVillager(map<string, tuple<int, string, string> > vD) {
    cin.ignore();
    string searchKey;

    cout << "Enter villager to look for : ";
    getline(cin, searchKey);
    auto it = vD.find(searchKey);

    if (it != vD.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found
        cout << "\nFound the villager " << searchKey;
        auto& m = vD[searchKey];
        cout << ", their friendship rating is " << get<0>(m) << " , species is " << get<1>(m);
        cout << ", catchphrase is \" " << get<2>(m) << "\"";
        cout << endl;
    }
    else
        cout << endl << searchKey << " not found." << endl;

}

void increaseFriendship(map<string, tuple<int, string, string> > &vD) {
    cin.ignore();
    string searchKey;

    cout << "Enter villager to increase friendship : ";
    getline(cin, searchKey);
    auto it = vD.find(searchKey);

    if (it != vD.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found
        cout << "\nIncreasing friendship of " << searchKey;
        auto& m = vD[searchKey];
        get<0>(m) = get<0>(m) + 1;
    }
    else
        cout << endl << searchKey << " not found." << endl;

}

void decreaseFriendship(map<string, tuple<int, string, string> >& vD) {
    cin.ignore();
    string searchKey;

    cout << "Enter villager to decrease friendship : ";
    getline(cin, searchKey);
    auto it = vD.find(searchKey);

    if (it != vD.end()) {  // the iterator points to beyond the end of the map
        // if searchKey is not found
        auto& m = vD[searchKey];

        if (  get<0>(m) <= 0) {
            cout << "Villager friendship at minimum" << endl;
        }
        else {
            cout << "\nDecreasing friendship of " << searchKey;
            get<0>(m) = get<0>(m) - 1;
            cout << endl;
        }
    
    }
    else
        cout << endl << searchKey << " not found." << endl;

}

void addVillager(map<string, tuple<int, string, string> >& vD) {
    cin.ignore();
    //string searchKey;
    cout << "Villager name: ";
    string name;
    getline(cin, name);
    
    cout << "\nFriendship level: ";
    int fL;
    cin >> fL;
    
    cin.ignore();
    cout << "\nSpecies: ";
    string species;
    getline(cin, species);

    cout << "\nCatchphrase: ";
    string catchP;
    getline(cin, catchP);

    vD.insert({ name , { fL, species, catchP } });

}


void deleteVillager(map<string, tuple<int, string, string> >& vD) {
    cin.ignore();
    string searchKey;

    cout << "Enter villager to delete : ";
    getline(cin, searchKey);
    auto it = vD.find(searchKey);

    if (it != vD.end()) {  // the iterator points to beyond the end of the map
        cout << "Deleting villager " << searchKey << endl;
        
        vD.erase(searchKey);

    }
    else
        cout << endl << searchKey << " not found." << endl;

}



int main() {
    // declarations
    map<string, vector<string>> villagerColors;
    
    map<string, tuple<int,string,string> > villagerData;
    
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerData["Audie"] = { 4, "Yellow", "Red" };
    villagerData["Raymond"] = { 5, "Gray", "White" };
    villagerData.insert({ "Marshal", {0, "White", "Black"} });

    villagerData["Michael"] = {5, "dog" , "wazzup"};
    villagerData["BBB"] = { 7, "Hound" , "No playin !" };
    villagerData.insert({ "Duncan" , { 3, "Kangaroo", "boing" } });
    
    // cout << "Michael " << get<0>(m) << get<1>(m) << get<2>(m) << endl;
    
    int input = 0;
    while (input != 6) {

        cout << "Current Villagers:" << endl;
        for (auto pair : villagerData) {
            cout << pair.first << ": ";
            auto& m = villagerData[pair.first];
            cout << get<0>(m) << ", " << get<1>(m) << ", " << get<2>(m);
            cout << endl;
        }

        input = mainMenu();

        switch (input) {
        case 1:
            addVillager(villagerData);
            break;
        case 2:
            deleteVillager(villagerData);
            break;
        case 3:
            increaseFriendship(villagerData);
            break;
        case 4:
            decreaseFriendship(villagerData);
            break;
        case 5:
            searchForVillager(villagerData);
            break;
        case 6:
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