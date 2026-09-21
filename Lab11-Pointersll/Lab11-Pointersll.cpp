// COMSC - 210 || Lab 11 || Jose Luis Ramos

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int TEAM_SIZE = 15;

struct Team {
	string name;
    string abreviation;
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
        
        getline(fin, tPtr->abreviation);
        //cout << "Got abreviation" << tPrt->abreviation <, endl;
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
        }
            
        fin.ignore();
        fin.close();
    }
    else
        cout << "File not found.\n";

}

void displayTeamData(string tData, Team* tPtr) {

    cout << tPtr->name << " roster for the 2026 Western Conference Finals" << endl;
    cout << "They won " << tPtr->gamesWon << " games in this series" << endl;
    for (int i = 0; i < TEAM_SIZE; i++) {
        cout << "Player " << i + 1;
        cout << ((i + 1 < 10) ? ":  " : ": ");
        cout << tPtr->roster[i] << endl;
    }
}

int getGamesWon(Team*tPtr){
    int x = tPtr->gamesWon;
    return x;
}

string getAbreviation(Team* tPtr) {
    string x = tPtr->abreviation;
    return x;
}

int main(){

    vector<string> teamData = { "sasData.txt", "okcData.txt" };
    Team* bbTeam = new Team[TEAM_SIZE];

	for (int i = 0; i < teamData.size(); i++) {
        inputTeamData(teamData.at(i), &bbTeam[i]);
	}

    int seriesLength = getGamesWon(&bbTeam[0]) + getGamesWon(&bbTeam[1]);

    cout << "2026 Western Conference Finals" << endl;
    cout << seriesLength << " games were played" << endl;
    cout << getAbreviation(&bbTeam[0]) << " || " << getGamesWon(&bbTeam[0]) << " || " << getGamesWon(&bbTeam[1]) << " || " << getAbreviation(&bbTeam[1]) << endl << endl;
    //Arrived at the point where a class would be useful

    for (int i = 0; i < teamData.size(); i++) {
        displayTeamData(teamData.at(i), &bbTeam[i]);
        cout << endl;
    }

}


