// COMSC - 210 || Lab 18 || Jose Luis Ramos
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

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


		}
		fin.close();
	}




};




int main()
{
	string file = "input.txt";
	const int numOfMovie = 4;
	vector<Movie> movieVector;

	for (int i = 0; i < numOfMovie; i++) {
		
		Movie movie(file);



	}


}
