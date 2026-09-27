// COMSC - 210 || Lab 15 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Movie {
private:
    string title;
    int year;
    string writerName;
public:
    string getTitle()           { return title; }
    int getYear()               { return year; }
    string getWriterName()      { return writerName; }

    void setTitle(string t)     { title = t; }
    void setYear(int y)         { year = y; }
    void setWriterName(string w) {writerName = w;}

    void print() {
        cout << title << " written by " << writerName << ", released in " << year << endl;
    }

};

void inputMovieData(string f, vector<Movie>& s) {

    Movie temp;

    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        //cout << f << " opened" << endl;

        for (int i = 0; i < s.size(); i++) {
            
            //cout << temp.ID << "  ";
            
            //cout << temp.Grade << endl;
            
            
            s.push_back(temp);
        }

        fin.close();
    }
    else
        cout << "File not found.\n";
}

    

int main()
{
    string file = "input.txt";
    vector<Movie> movieVector;





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
