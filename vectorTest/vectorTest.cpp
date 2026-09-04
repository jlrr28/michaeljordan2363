#include <iostream>
#include <vector>
using namespace std;
int main() {
	
	vector<int> myVec(3);

	myVec[0] = 7;

	myVec[1] = 66;

	myVec[2] = 9;
	
	cout << "before delete \n";
	for (int val : myVec) cout << val << " ";
	cout << endl << endl;

	//deleting element at location 1
	cout << "Deleting element at location 1: \n";
	myVec.erase(myVec.begin() + 1);
	for (int val : myVec) cout << val << " ";
	cout << endl << endl;

	cout << myVec.at(0);
	// data at element 2 gets dropped down to element 1, element 2 no longer exists

}