// COMSC 210 || LAB 9 || Jose Luis Ramos

#include <iostream>
#include <algorithm>  
#include <numeric>
#include <array>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	const int SIZE = 30;

	array<int, SIZE> scoreArray;
    int temp = 0;

    ifstream fin;
    fin.open("scores.txt");
    if (fin.good()) {
        int i = 0;
        while (fin >> temp){
            scoreArray[i] = temp;
            i++;
        }

        fin.close();    
    }
    else
        cout << "File not found.\n";

    //point summary
    cout << "The point total is " << accumulate(scoreArray.begin(), scoreArray.end(), 0)
    << " points over " << scoreArray.size() << " games played." << endl;;
    cout << "The average score of the " << scoreArray.size() << " games played is "
    << static_cast<double>(accumulate(scoreArray.begin(), scoreArray.end(), 0)) / scoreArray.size()
    << " points" << endl;

    //Find lowest score game
    int target = *min_element(scoreArray.begin(), scoreArray.end());
    array<int, SIZE>::iterator it;
    it = find(scoreArray.begin(), scoreArray.end(), target);
        cout << "The lowest score was on game " << (it - scoreArray.begin()) + 1 <<
    " with " << target << " points being scored. " << endl;
    
    //Find highest score game
    target = *max_element(scoreArray.begin(), scoreArray.end());
    it = find(scoreArray.begin(), scoreArray.end(), target);
        cout << "The highest score was on game " << (it - scoreArray.begin()) + 1
    << " with " << target << " points being scored. " << endl << endl;
    
    // Display sorted score list with game played
    cout << "Score list top to bottom" << setfill('#') << setw(25); cout << endl << "\n";
    array<int, SIZE> sortedArray = scoreArray;
    sort(sortedArray.begin(), sortedArray.end());
    
    for (int i = scoreArray.size(); i >= 1; i--) {
        
        target = sortedArray.at(i-1);
        it = find(scoreArray.begin(), scoreArray.end(), target);
        
        cout << "Game:" << (it - scoreArray.begin()) + 1;
        cout << ((((it - scoreArray.begin()) + 1) < 10) ? "   |||  " : "  |||  ");
        cout << target;
        cout << ((target <= 100) ? "  points" : " points") << endl;
       // " points" << endl;

    }
    
    //Didn't get enough time to implement duplicate checker

    cout << endl << " ------------- same code but with vector ------------- " << endl << endl;

    vector<int> scoreVector;
    
    fin.open("scores.txt");
    if (fin.good()) {
        int i = 0;
        while (fin >> temp) {
            scoreVector.push_back(temp);
            //temp = scoreVector.at(i);
            i++;
        }

        fin.close();
    }
    else
        cout << "File not found.\n";

    // point summary
        cout << "The point total is " << accumulate(scoreVector.begin(), scoreVector.end(), 0)
        << " points over " << scoreVector.size() << " games played." << endl;;
    cout << "The average score of the " << scoreVector.size() << " games played is "
        << static_cast<double>(accumulate(scoreVector.begin(), scoreVector.end(), 0)) / scoreVector.size()
        << " points" << endl;

    //Find lowest score game
    target = *min_element(scoreVector.begin(), scoreVector.end());
    vector<int>::iterator itV;
    itV = find(scoreVector.begin(), scoreVector.end(), target);
    cout << "The lowest score was on game " << (it - scoreArray.begin()) + 1 <<
        " with " << target << " points being scored. " << endl;

    //Find highest score game
    target = *max_element(scoreVector.begin(), scoreVector.end());
    itV = find(scoreVector.begin(), scoreVector.end(), target);
    cout << "The highest score was on game " << (itV - scoreVector.begin()) + 1
        << " with " << target << " points being scored. " << endl << endl;

    // Display sorted score list with game played
    cout << "Score list top to bottom" << setfill('#') << setw(25); cout << endl << "\n";
    vector<int> sortedVector = scoreVector;
    sort(sortedVector.begin(), sortedVector.end());

    for (int i = scoreVector.size(); i >= 1; i--) {

        target = sortedVector.at(i - 1);
        itV = find(scoreVector.begin(), scoreVector.end(), target);

        cout << "Game:" << (itV - scoreVector.begin()) + 1;
        cout << ((((itV - scoreVector.begin()) + 1) < 10) ? "   |||  " : "  |||  ");
        cout << target;
        cout << ((target <= 100) ? "  points" : " points") << endl;

    }
    
    //Didn't get enough time to implement duplicate checker

}