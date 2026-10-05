// COMSC - 210 || Lab 18 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <iomanip>
using namespace std;
const int NUM_OF_MOVIE = 4;

//void addNodeFront(Rnode* &h, string f);
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
		cout << "address of *review is " << &reviews << endl;
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

	//~Movie() {
	//	cout << "destructor running" << endl;
	//	if (reviews)
	//		delete[]reviews;
	//	reviews = nullptr;
	//}


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


	/*
	for (int i = 0; i < movieVector.size(); i++) {
		tempMovie = movieVector.at(i);
		tempMovie.outputReviewList();
		cout << endl;
	}*/
	cout << setprecision(4);
	Movie t = movieVector.at(2);
	t.outputReviewList();

	//tempMovie.outputReviewList();
	//for (Movie x : movieVector) { x.outputReviewList(); };

}

double getRNG() {

	random_device rd;
	mt19937 gen(rd());

	double min = 0.0;
	double max = 5.0;
	uniform_int_distribution<> random(min, max);
	double x = (random(gen));
	cout << setprecision(4);
	cout << x << endl;
	return x;
}