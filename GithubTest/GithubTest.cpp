

#include <iostream>
using namespace std;

bool IsMult(int a, int b) {
    cout << a % b << endl;
    return(a % b);
}

int main()
{
    int number;
    int multiple;

    cout << "enter number:";
    cin >> number;
    cout << "  check for multiple: ";
    cin >> multiple;
    cout << "Entered:" << number << " and and test test " << multiple << endl;
    if (IsMult(number, multiple) == false)
        cout << multiple << " is a multiple of " << number << endl;
    else
        cout << multiple << " is not a multiple of " << number << endl;

}

