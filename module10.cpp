// in this module we will implement that ofr example the user wants to order a book or the case that the user has any request for a book that is not present in the library and that we can arrange.
// we will have a singly linked list to store all request made.
#include <iostream>
using namespace std;

class Node
{
public:
    int urgency_level;
    string book_name;
    string author_name;
    string category;
    Node *next;

    Node(int urgency_level, string book_name, string author_name, string category)
    {
        this->urgency_level = urgency_level;
        this->author_name = author_name;
        this->book_name = book_name;
        this->category = category;
        next = nullptr;
    }
};

class BookRequests
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    BookRequests() : head(nullptr), tail(nullptr), length(0) {}

    ~BookRequests()
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
            cout << "Author Name: " << temp->author_name << endl;
            cout << "Book Name: " << temp->book_name << endl;
            cout << "Category: " << temp->category << endl;
            cout << "Urgency Level: " << temp->urgency_level << endl;
            temp = temp->next;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int urgency_level, string book_name, string author_name, string category)
    {
        Node *newNode = new Node(urgency_level, book_name, author_name, category);
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
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        Node *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp;
    }
};
void orderBookOnDemand(BookRequests &request)
{
    string name;
    string author_name;
    string category;
    int urgency_level;
    cout << "PLease Enter the category of the book: " << endl;
    cout << "For Example" << endl;
    cout << "Educational " << endl;
    cout << "Fiction" << endl;
    cout << "Non-Fiction" << endl;
    cout << "Poetry And Drama" << endl;
    cout << "Young Adult" << endl;
    cout << "Category: ";
    cin >> category;
    cout << "Please Enter The name of the book: ";
    cin >> name;
    cout << "Please Enter The Author Name: ";
    cin >> author_name;
    cout << "Please Enter The Urgency Level between 0-5: ";
    cin >> urgency_level;
    while (urgency_level > 5 || urgency_level < 0)
    {
        cout << "Please Enter A Valid Urgency Level between 0-5: ";
        cin >> urgency_level;
    }
    request.append(urgency_level, name, author_name, category);
}
int main()
{
    BookRequests request;
    orderBookOnDemand(request);
    request.printList();
    return 0;
}