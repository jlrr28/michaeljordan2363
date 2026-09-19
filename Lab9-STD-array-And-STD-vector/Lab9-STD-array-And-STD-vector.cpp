// COMSC 210 || LAB 9 || Jose Luis Ramos

#include <iostream>
#include <algorithm>  
#include <numeric>
#include <array>
#include <fstream>
using namespace std;

int main() {

	const int SIZE = 30;

	array<int, SIZE> scoreArray;
    int temp = 0;

    ifstream fin;
    fin.open("scores.txt");
    if (fin.good()) {
        cout << "good to go" << endl;
        int i = 0;
        while (fin >> temp){
            scoreArray[i] = temp;
            i++;
        }

        fin.close();    
    }
    else
        cout << "File not found.\n";

    //cout << scoreArray[0] << endl;
    //cout << scoreArray[20] << endl;
    //cout << scoreArray[29] << endl;
    //cout << scoreArray.data() << endl;



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
    << " with " << target << " points being scored. " << endl;
    
    // Display sorted score list with game played
    array<int, SIZE> sortedArray = scoreArray;
    sort(sortedArray.begin(), sortedArray.end());
    
    for (int i = 0; i < scoreArray.size(); i++) {
    
        sortedArray[i] << endl;

    }
    

    
    //for (int val : sortedArray) cout << val << " " << endl;


}