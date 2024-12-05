// this module will cover storing of regestration numbers in a doubly linked list.
// the reason to choose doubly linked list is if we have to access a given node hence we can go back and forward.
// the linkedlist will have 700 nodes each node having a regno.
// identity verification.

#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        if (head == nullptr)
        {
            cout << "Head: nullptr" << endl;
        }
        else
        {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail()
    {
        if (tail == nullptr)
        {
            cout << "Tail: nullptr" << endl;
        }
        else
        {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0)
            return;
        Node *temp = tail;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }
    bool SearchRegno(int regno)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->value == regno)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void IdentityVerification()
    {
        int regno;
        cout << "Please Enter Your Regno: ";
        cin >> regno;
        bool Found = SearchRegno(regno);
        if (Found)
        {
            cout << "Successfully Found Your Regno You May Proceed To Borrow Books" << endl;
        } else {
            cout << "Regno not found please get your regno registered first" << endl;
        }
    }
};

int main()
{
    // the part1 is the year of arrival in giki university followed by part2 which is the serial number.
    // the below code generates all of the serial numbers and store them in the linked list.
    int part1 = 2023000;
    DoublyLinkedList *myDLL = new DoublyLinkedList();
    for (int i = 0; i <= 700; i++)
    {
        myDLL->append(2023000 + i);
    }
    myDLL->printList();
    myDLL->IdentityVerification();
    return 0;
}
