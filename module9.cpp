// this module will allow a new user to get himself registered where he will be asked to input his regno
#include <iostream>
using namespace std;

void getRegistered()
{
    int regno;
    cout << "Please Enter your regestration number for example (2021504): ";
    cin >> regno;
    cout << "User registered Successfully" << endl;
    cout << "You can proced to borrowing Books" << endl;
}
int main()
{
    getRegistered();
    return 0;
}