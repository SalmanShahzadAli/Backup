// this module will handle the admin panel
// for example there are 3 people who can access the admin panel
// librarian , Supervisor , FinanceOfficer
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main()
{

    system("CLS");
    cout << "\t\t\t\tLibrary Management System" << endl;
    cout << "\t\t\t\tWelcome to the Admin Panel" << endl;
    Sleep(500);
    cout << "Please Enter Your Designation Please: ";
    cin >> designation;
    Sleep(500);
    if (designation != "Librarian" && designation != "Superviser" && designation != "FinanceOfficer")
    {
        cout << "Your designation is not authorised to access the libraray as an admin" << endl;
    }
    else
    {
        cout << "Please Enter Your Password: ";
        cin >> password;
        while(password != passwordsArray[0] && password != passwordsArray[1] && password != passwordsArray[2])
        {
            cout << "Wrong Password" << endl;
            Sleep(500);
            cout << "Please Try Again" << endl;
            Sleep(500);
            cout << "Please Enter Your Password: ";
            cin >> password;
        }
    }
    system("CLS");
    cout << "Logged in as " << designation << endl;
    Sleep(500);
    cout << "you may continue to perform the daily activites" << endl;
    


    return 0;
}
