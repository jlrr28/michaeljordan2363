// COMSC - 210 || Lab 11 || Jose Luis Ramos

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int TEAM_SIZE = 15;

struct Team {
	string name;
	int gamesWon;
	string * roster;
  
    ~Team() {
        if (roster)
            delete[]roster;
        roster = nullptr;
    }

};

void inputTeamData(string tData, Team *tPtr) {

    ifstream fin;
    fin.open(tData);
    if (fin.good()) {
        //cout << "opening " << tData << endl;
        //fin.ignore();
        
        getline(fin, tPtr -> name);
        //cout << "Got name " << tPtr->name << endl;
        fin >> tPtr -> gamesWon;
        //cout << "Got games won  " << tPtr->gamesWon << endl;

        fin.ignore();
        tPtr->roster = new string[TEAM_SIZE];
        for (int i = 0; i < TEAM_SIZE; i++) {
            

            getline(fin, tPtr->roster[i]);
            if (tPtr->roster[i] == "\0")
                tPtr->roster[i] = "Player not found"; //Since array is fixed, filling in slots with no player names with this instead
                //cout << "empty at " << i << endl;

            //cout << tPtr->roster[i] << endl;
            
        }
            

        fin.ignore();
        fin.close();
    }
    else
        cout << "File not found.\n";


}

int main()
{
	vector<string> teamData = { "sasData.txt", "okcData.txt" };

    //Team bbTeam;
    Team* bbTeam = new Team[TEAM_SIZE];


	for (int i = 0; i < teamData.size(); i++) {
	
        inputTeamData(teamData.at(i), &bbTeam[i]);
        //cout << "Got name " << bbtPtr->name << endl;

	}

    cout << "2026 Western Conference Finals" << endl;
    //cout << &bbTeam[0].gamesWon + &bbTeam[1].gamesWon << " gamesd";



    cout << bbTeam->name;
    cout << bbTeam->gamesWon;

}


