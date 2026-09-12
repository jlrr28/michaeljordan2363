#include <iostream>
using namespace std;

int main() {

	int x = 10;
	int y = 2;
	cout << x << endl;
	cout << &x << endl;

	x += 10;
	cout << x << endl;
	cout << &x << endl;

	x += 10;
	cout << x << endl;
	cout << &y + 10 << endl;
	cout << y << endl;
}