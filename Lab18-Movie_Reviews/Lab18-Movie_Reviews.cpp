// COMSC - 210 || Lab 18 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const int NUM_OF_MOVIE = 4;

struct rNode {
	string comment;
	double rating;
	rNode* next;
};


class Movie {
private:
	string name;
	rNode* reviews;
public:
	Movie() { name = "none"; reviews = nullptr;};
	Movie(string f) {
		ifstream fin;
		fin.open(f);
		cout << f << " opened" << endl;
		reviews = nullptr;
		if (fin.good()) {
			getline(fin, name);
			cout << "input name:" << name << endl;
			addNodeFront(reviews, f);

		}
		fin.close();
	}




};

void addNodeFront(rNode*& h, string f);


int main()
{
	string file = "input.txt";
	vector<Movie> movieVector;

	for (int i = 0; i < NUM_OF_MOVIE; i++) {
		
		Movie movie(file);



	}


}


void addNodeFront(rNode*& h, string f) {
	string tmp = "n/a";
	double rate = 0;

	ifstream fin;
	fin.open(f);
	cout << f << " opened" << endl;
	h = nullptr;
	if (fin.good()) {
		getline(fin, tmp);
		rate = 

		rNode* newVal = new rNode;
		// adds node at head
		if (!h) {
			h = newVal;
			newVal->next = nullptr;
			newVal->comment = tmp;
		}
		else {
			newVal->next = n;
			newVal->value = tmp;
			n = newVal;
		}

	}
	fin.close();
}


}