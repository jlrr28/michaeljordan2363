// COMSC - 210 || Lab 18 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
using namespace std;
const int NUM_OF_MOVIE = 4;

void addNodeFront(Rnode* &h, string f);
int getRNG();


struct Rnode {
	string comment;
	double rating;
	Rnode* next;
};


class Movie {
private:
	string name;
	Rnode* reviews;
public:
	Movie() { name = "none"; reviews = nullptr;}
	Movie(string n) { name = n; }
		
	string getName() { return name; }



};

int main()
{
	string file = "input.txt";
	vector<Movie> movieVector;
	string tempString = "n/a";
	double tempDouble = 0;
	Movie tempMovie;

	ifstream fin;
	fin.open(file);
	cout << file << " opened" << endl;
	if (fin.good()) {
		getline(fin, tempString);
		Movie tempMovie(tempString);
		cout << "Input" << tempMovie.getName() << endl;
		//addNodeFront(reviews, f);

	}
	fin.close();


}




void addNodeFront(Rnode*& h, string f) {
	string tmp = "n/a";
	double rate = 0;

	ifstream fin;
	fin.open(f);
	cout << f << " opened" << endl;
	h = nullptr;
	if (fin.good()) {
		getline(fin, tmp);
		rate = getRNG();

		Rnode* newVal = new Rnode;
		// adds node at head
		if (!h) {
			h = newVal;
			newVal->next = nullptr;
			newVal->comment = tmp;
			newVal->rating = rate;
		}
		else {
			newVal->next = h;
			newVal->comment = tmp;
			newVal->rating = rate;
			h = newVal;
		}

	}
	fin.close();
}

int getRNG() {
	random_device rd; //probably not effiecient, but just playing around with things right now
	mt19937 gen(rd());
	uniform_int_distribution<> randomRGB(0, 5.0);
	double x = (randomRGB(gen));
	return x;
}