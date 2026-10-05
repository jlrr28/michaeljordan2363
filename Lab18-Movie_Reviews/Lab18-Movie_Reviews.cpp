// COMSC - 210 || Lab 18 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <iomanip>
using namespace std;
const int NUM_OF_MOVIE = 4;

double getRNG();

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
	//Constructors
	Movie() { name = "none"; reviews = nullptr; }
	Movie(string n) { name = n; reviews = nullptr; }

	//Copy Constuctors
	Movie(const Movie &m) {
		name = m.name;
		reviews = m.reviews;
	}

	//Destructors
	~Movie() {
		//cout << "destructor running" << endl;
	}

	//Methods
	string getName() { return name; }

	void setReviews(string s) {
		//reviews = nullptr;
		double rate = getRNG();
		//cout << &reviews << endl;
		Rnode* newVal = new Rnode;
		// adds node at head
		if (!reviews) {
			reviews = newVal;
			newVal->next = nullptr;
			newVal->comment = s;
			//cout << newVal->comment << " added to list || " << "Address " << &newVal->comment << endl;
			newVal->rating = rate;
			//cout << newVal->rating << " added to list || " << "Address " << &newVal->rating << endl;
		}
		else {
			newVal->next = reviews;
			newVal->comment = s;
			//cout << newVal->comment << " added to list || " << "Address " << &newVal->comment << endl;
			newVal->rating = rate;
			//cout << newVal->rating << " added to list || " << "Address " << &newVal->rating << endl;
			reviews = newVal;
		}

	}

	void outputReviewList() {
		
		if (!reviews) {
			cout << "Empty list.\n";
			return;
		}
		int count = 1;
		double sum = 0;
		Rnode* current = reviews;
		cout << "Movie Tile: " << name << endl;
		cout << setprecision(2);
		while (current) {
			//cout << "[" << count++ << "] " << current->value << "  data address: " << &current ->value << " pointer address: " << &current << endl;
			cout << "> Review #" << count++ << ": " << current->rating <<
			": " << current->comment << endl;
			
			sum += current->rating;
			
			current = current->next;
		}
		cout << "> Average: " << sum / count << endl;
		cout << endl;
	}

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
	//cout << file << " opened" << endl;
	if (fin.good()) {
		
		for (int i = 0; i < NUM_OF_MOVIE; i++) {
			getline(fin, tempString);
			Movie tempMovie(tempString);

			getline(fin, tempString);
			tempMovie.setReviews(tempString);
			getline(fin, tempString);
			tempMovie.setReviews(tempString);
			getline(fin, tempString);
			tempMovie.setReviews(tempString);

			movieVector.push_back(tempMovie);
		}

	}
	fin.close();

	for (Movie x : movieVector) { x.outputReviewList(); };

}

double getRNG() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> randomN(0.0, 5.0);
	double x = (randomN(gen));

	return x;
}