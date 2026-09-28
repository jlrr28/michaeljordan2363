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

    Movie mTemp;
    string sTemp;
    int size = s.size();
    int iTemp = 0;

    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        cout << f << " opened" << endl;

        for (int i = 0; i < size; ++i) {
            
            getline(fin, sTemp);
            //cout << sTemp << endl;
            mTemp.setTitle(sTemp);
            cout << mTemp.getTitle() << endl;
            
            fin >> iTemp;
            //cout << iTemp << endl;
            mTemp.setYear(iTemp);
            cout << mTemp.getYear() << endl;

            fin.ignore();

            getline(fin, sTemp);
            //cout << sTemp << endl;
            mTemp.setWriterName(sTemp);
            cout << mTemp.getWriterName() << endl;
            
            //fin.ignore();
            
            
            s.push_back(mTemp);
        }

        fin.close();
    }
    else
        cout << "File not found.\n";
}

int getFileLines(string f) {

    int i = 0;
    string lines;
    ifstream fin;
    fin.open(f);
    if (fin.good()) {
        //cout << f << " opened" << endl;
        while (getline(fin, lines)) i++;
        fin.close();
    }
    else
        cout << "File not found.\n";
    i /= 3;
    return i;
}

int main()
{
    string file = "input.txt";
    

    vector<Movie> movieVector(getFileLines(file));
    cout << movieVector.size() << endl;

    inputMovieData(file, movieVector);


}

