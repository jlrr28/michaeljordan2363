// COMSC 210 || Lab 6 || Jose Luis Ramos

#include <iostream>   
using namespace std;

double* enterArrayData(int s) {

	double* arr = nullptr;
	arr = new double[s];
	for (int i = 0; i < s; i++) {
		cout << "Enter data:";
		cin >> arr[i];
	}
	//delete [] arr;
	cout << s << endl;
	return arr;
}

double outputArrayData(int s) {

	cout << s << endl;
	return 0;
}

double sumArray(int s) {
	
	cout << s << endl;
	return 0;
}

int main() {

	const int SIZE = 5;

	double* dArray = nullptr;
	dArray = enterArrayData(SIZE);

	for (int i = 0; i < SIZE; i++)
		cout << dArray[i];


	delete [] dArray;

}