// COMSC 210 || LAB 9 || Jose Luis Ramos

#include <iostream>
#include <algorithm>  
#include <numeric>
#include <array>
#include <fstream>
using namespace std;

int main() {

	const int SIZE = 30;

	array<int, 30>scoreArray;
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

    cout << scoreArray[0] << endl;
    cout << scoreArray[20] << endl;
    cout << scoreArray[29] << endl;
    cout << scoreArray.data() << endl;

}