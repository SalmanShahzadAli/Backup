#include<iostream>
using namespace std;
// this code will search the reg no in the linkedlist in case its found it will return true else false;
bool SearchRegno(int regno)
{
    Node* temp = head;
    while (temp)
    {
        if (temp.value == regno)
        {
            return true;
        }   
    }
    return false;
}
int main()
{
    return 0;
}