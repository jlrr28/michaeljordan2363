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

void outputArrayData(int s, double *dA) {
	cout << "Outputting array elements: ";
	for (int i = 0; i < s; i++)
		cout << dA[i] << " ";
	cout << endl;
}

double sumArray(int s) {
	
	cout << s << endl;
	return 0;
}

int main() {

	const int SIZE = 5;

	double* dArray = nullptr;
	dArray = enterArrayData(SIZE);

	//for (int i = 0; i < SIZE; i++)
		//cout << dArray[i];

	outputArrayData(SIZE, dArray);

	delete [] dArray;

}