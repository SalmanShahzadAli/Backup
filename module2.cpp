// this is the second module in which we will store data in a doubly linked list the reason to choose a doubly linked list is so that we can access from both ends
// one node will store name,isbn,quantity

#include <cstdlib> // For rand() and srand()
#include <iostream>

using namespace std;

class Node
{
public:
    int ISBN;
    string book_details;
    int qunatity;
    Node *next;
    Node *prev;

    Node(int ISBN, string book_details, int quantity)
    {
        this->ISBN = ISBN;
        this->book_details = book_details;
        this->qunatity = quantity;
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
    DoublyLinkedList(int ISBN, string book_details, int quantity)
    {
        Node *newNode = new Node(ISBN, book_details, quantity);
        head = newNode;
        tail = newNode;
        length = 1;
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
            cout << "ISBN: " << temp->ISBN << endl;
            cout << "Book_Details: " << temp->book_details << endl;
            cout << "Quantity: " << temp->qunatity << endl;
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
            cout << "Head: " << head->ISBN << endl;
            cout << "Book Details: " << head->book_details << endl;
            cout << "Head: " << head->qunatity << endl;
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
            cout << "Tail: " << tail->ISBN << endl;
            cout << "Book_details: " << tail->book_details << endl;
            cout << "Tail: " << tail->qunatity << endl;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int ISBN, string book_details, int quantity)
    {
        Node *newNode = new Node(ISBN, book_details ,quantity);
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
    void prepend(int ISBN, string book_details, int quantity)
    {
        Node *newNode = new Node(ISBN, book_details, quantity);
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
};

int main()
{
    return 0;
}
