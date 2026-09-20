// COMSC - 210 || Lab 11 || Jose Luis Ramos

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Team {
	string name;
	int gamesWon;
	string* roster;
    ~Team() {
    //    if (roster)
    //        delete[]roster;
    //    roster = nullptr;
    //}

};

void inputTeamData(string tData, Team *tPtr) {
    string tempN;
    int tempGamesWon;


    ifstream fin;
    fin.open(tData);
    if (fin.good()) {
        //int i = 0;
        cout << "opening " << tData << endl;
        getline(fin, tPtr -> name);
        fin >> tPtr -> gamesWon;
        
        fin.ignore();
        //while (fin >> temp) {
            //scoreArray[i] = temp;
            //i++;
        //}

        fin.close();
    }
    else
        cout << "File not found.\n";


}

int main()
{
	vector<string> teamData = { "sasData.txt", "okcData.txt" };

    Team bbTeam;
    Team* bbtPtr = &bbTeam;


	for (int i = 0; i < teamData.size(); i++) {
	
		inputTeamData(teamData.at(i), bbtPtr);
	
	}

    cout << bbtPtr->name;
    cout << bbtPtr->gamesWon;

}


