// this module will store computer informations that we have like store the location and further detils of each computer if the user is willing to use computers
#include <iostream>
using namespace std;

const int maximum_computers_mac = 50;
const int maximum_computers_windows = 50;

class NodeofComputerInfo
{
public:
    string type;
    string location;
    string ip_address;
    bool internet_access;
    NodeofComputerInfo *next;

    NodeofComputerInfo(string type, string location, string ip_address, bool internet_access)
        : type(type), location(location), ip_address(ip_address), internet_access(internet_access), next(nullptr) {}
};

class ComputerInfoLinkedList
{
private:
    NodeofComputerInfo *head;
    NodeofComputerInfo *tail;
    int length;

public:
    ComputerInfoLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    ~ComputerInfoLinkedList()
    {
        NodeofComputerInfo *temp = head;
        while (temp)
        {
            NodeofComputerInfo *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void printList()
    {
        NodeofComputerInfo *temp = head;
        while (temp != nullptr)
        {
            cout << "---------------------------" << endl;
            cout <<"|"<< " Location: " << temp->location << "   |"<<endl;
            cout <<"|"<< " Type: " << temp->type << "           |" <<endl;
            cout <<"|"<< " IP Address: " << temp->ip_address <<" |"<< endl;
            cout <<"|"<< " Internet Access: " << (temp->internet_access ? "Yes" : "No") << "    |"<<endl; // Print internet access
            cout << "---------------------------" << endl;                                    // Separator for readability
            temp = temp->next;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(string type, string location, string ip_address, bool internet_access)
    {
        NodeofComputerInfo *newNode = new NodeofComputerInfo(type, location, ip_address, internet_access);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0)
            return;

        NodeofComputerInfo *temp = head;
        if (length == 1)
        {
            delete head; // Delete the only node
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            while (temp->next != tail)
            {
                temp = temp->next; // Traverse to the second last node
            }
            delete tail;          // Delete the last node
            tail = temp;          // Update tail to the second last node
            tail->next = nullptr; // Set next of new tail to nullptr
        }
        length--;
    }
};

int main()
{
    ComputerInfoLinkedList *myLL = new ComputerInfoLinkedList();
    // the below code will populate for Mac computers
    for (int i = 0; i < maximum_computers_mac; i++)
    {
        bool hasinternetAccess = false;
        if (i % 2 == 0)
        {
            hasinternetAccess = true;
        }
        myLL->append("Mac", "Second Floor", "192.168.1.1", hasinternetAccess);
    }
    // the below code will populate for windows computers
    for (int i = 0; i < maximum_computers_windows; i++)
    {
        bool hasinternetAccess = false;
        if (i % 2 == 0)
        {
            hasinternetAccess = true;
        }
        myLL->append("Windows", "Third Floor", "192.168.1.1", true);
    }

    myLL->printList();

    // Print length of the list
    myLL->getLength();

    delete myLL; // Clean up memory
    return 0;
}