// COMSC - 210 || Lab 18 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
using namespace std;
const int NUM_OF_MOVIE = 4;

//void addNodeFront(Rnode* &h, string f);
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
	Movie() { name = "none"; reviews = nullptr; }
	Movie(string n) { name = n; reviews = nullptr; }

	string getName() { return name; }

	void setReviews(string s) {
		//reviews = nullptr;
		double rate = getRNG();
		cout << &reviews << endl;
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
		cout << "Movie Tile:" << name << endl;
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

	/*~Movie() {
		if (reviews)
			delete[]reviews;
		reviews = nullptr;
	}*/


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
		
		for (int i = 0; i < NUM_OF_MOVIE; i++) {
			getline(fin, tempString);
			Movie tempMovie(tempString);
			cout << "Input " << tempMovie.getName() << endl;

			//fin.ignore();

			getline(fin, tempString);
			tempMovie.setReviews(tempString);
			getline(fin, tempString);
			tempMovie.setReviews(tempString);
			getline(fin, tempString);
			tempMovie.setReviews(tempString);

			//fin.ignore();
			cout << endl;
			movieVector.push_back(tempMovie);
			//addNodeFront(reviews, f);
		}
	//	tempMovie.outputReviewList();
	}
	fin.close();



	for (int i = 0; i < movieVector.size(); i++) {
		tempMovie = movieVector.at(i);
		tempMovie.outputReviewList();
		cout << endl;
	}




}




/*void addNodeFront(Rnode*& h, string f) {
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
}*/

int getRNG() {
	random_device rd; //probably not effiecient, but just playing around with things right now
	mt19937 gen(rd());
	uniform_int_distribution<> randomRGB(0.0, 5.0);
	double x = (randomRGB(gen));
	return x;
}