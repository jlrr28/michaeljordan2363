// COMSC 210 || Lab 6 || Jose Luis Ramos

#include <iostream>   
using namespace std;

double* enterArrayData(int s) {

	cout << "Data entry for the array: " << endl;

	double* arr = nullptr;
	arr = new double[s];
	for (int i = 0; i < s; i++) {
		cout << "> Element #" << i << ": ";
		cin >> arr[i];
	}

	cout << "Data entry complete." << endl;
	return arr;

}

void outputArrayData(int s, double *dA) {
	
	cout << "Outputting array elements: ";
	for (int i = 0; i < s; i++)
		cout << dA[i] << " ";
	cout << endl;

}

double sumArray(int s, double *dA) {
	
	double x = 0;

	for (int i = 0; i < s; i++)
		x += dA[i];

	return x;
}

int main() {

	const int SIZE = 5;

	double* dArray = nullptr;
	
	dArray = enterArrayData(SIZE);
	outputArrayData(SIZE, dArray);

	cout << "Sum of values: " << sumArray(SIZE, dArray);

	delete [] dArray;

}