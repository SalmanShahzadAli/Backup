// in this module i am trying to connect the previous modules
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib> // For rand() and srand()
#include <queue>
using namespace std;
const int maximum_entries = 108;
int ISBN[maximum_entries] = {};
string book_details[maximum_entries] = {"I Know Why the Caged Bird Sings - Maya Angelou",
                                        "East of Eden - John Steinbeck",
                                        "The Sun Also Rises - Ernest Hemingway",
                                        "Do Androids Dream of Electric Sheep? - Philip K. Dick",
                                        "The Curious Incident of the Dog in the Night-Time - Mark Haddon",
                                        "Pride and Prejudice and Zombies - Seth Grahame-Smith",
                                        "The House of Mirth - Edith Wharton",
                                        "Are You There, Vodka? It's Me, Chelsea - Chelsea Handler",
                                        "And Then There Were None - Agatha Christie",
                                        "Their Eyes Were Watching God - Zora Neale Hurston",
                                        "The Devil Wears Prada - Lauren Weisberger",
                                        "Brave New World - Aldous Huxley",
                                        "Bury My Heart at Wounded Knee - Dee Brown",
                                        "The Man Who Was Thursday - G.K. Chesterton",
                                        "The Catcher in the Rye - J.D. Salinger",
                                        "1984 - George Orwell",
                                        "To Kill a Mockingbird - Harper Lee",
                                        "Animal Farm - George Orwell",
                                        "Fahrenheit 451 - Ray Bradbury",
                                        "The Great Gatsby - F. Scott Fitzgerald",
                                        "One Hundred Years of Solitude - Gabriel García Márquez",
                                        "The Alchemist - Paulo Coelho",
                                        "The Picture of Dorian Gray - Oscar Wilde",
                                        "War and Peace - Leo Tolstoy",
                                        "Crime and Punishment - Fyodor Dostoevsky",
                                        "The Grapes of Wrath - John Steinbeck",
                                        "Wuthering Heights - Emily Brontë",
                                        "Little Women - Louisa May Alcott",
                                        "The Secret Garden - Frances Hodgson Burnett",
                                        "The Hobbit - J.R.R. Tolkien",
                                        "A Tale of Two Cities - Charles Dickens",
                                        "The Fault in Our Stars - John Green",
                                        "Life of Pi - Yann Martel",
                                        "The Kite Runner - Khaled Hosseini",
                                        "The Road - Cormac McCarthy",
                                        "The Hunger Games - Suzanne Collins",
                                        "Divergent - Veronica Roth",
                                        "Ready Player One - Ernest Cline",
                                        "The Night Circus - Erin Morgenstern",
                                        "Station Eleven - Emily St. John Mandel",
                                        "The Perks of Being a Wallflower - Stephen Chbosky",
                                        "The Book Thief - Markus Zusak",
                                        "The Nightingale - Kristin Hannah",
                                        "The Help - Kathryn Stockett",
                                        "The Light We Lost - Jill Santopolo",
                                        "Me Before You - Jojo Moyes",
                                        "The Girl on the Train - Paula Hawkins",
                                        "Big Little Lies - Liane Moriarty",
                                        "Gone Girl - Gillian Flynn",
                                        "Water for Elephants - Sara Gruen",
                                        "The Immortalists - Chloe Benjamin",
                                        "A Man Called Ove - Fredrik Backman",
                                        "The Seven Husbands of Evelyn Hugo - Taylor Jenkins Reid",
                                        "The Giver - Lois Lowry",
                                        "The Glass Castle - Jeannette Walls",
                                        "The 5th Wave - Rick Yancey",
                                        "An Ember in the Ashes - Sabaa Tahir",
                                        "Shadow and Bone - Leigh Bardugo",
                                        "The Cruel Prince - Holly Black",
                                        "Children of Blood and Bone - Tomi Adeyemi",
                                        "Cinder - Marissa Meyer",
                                        "Red Rising - Pierce Brown",
                                        "The Lunar Chronicles - Marissa Meyer",
                                        "The Hate U Give - Angie Thomas",
                                        "Everything, Everything - Nicola Yoon",
                                        "Simon vs. the Homo Sapiens Agenda - Becky Albertalli",
                                        "Eleanor Oliphant Is Completely Fine - Gail Honeyman",
                                        "The Rosie Project - Graeme Simsion",
                                        "The Martian - Andy Weir",
                                        "Ready Player Two – Ernest Cline",
                                        "Dune – Frank Herbert",
                                        "Hyperion – Dan Simmons",
                                        "Ender's Game – Orson Scott Card",
                                        "Foundation – Isaac Asimov",
                                        "Neuromancer – William Gibson",
                                        "Snow Crash – Neal Stephenson",
                                        "Brave New World Revisited – Aldous Huxley",
                                        "The Wind-Up Bird Chronicle – Haruki Murakami",
                                        "Kafka on the Shore – Haruki Murakami",
                                        "The Night Circus – Erin Morgenstern",
                                        "The Song of Achilles – Madeline Miller",
                                        "Circe – Madeline Miller",
                                        "The Water Dancer – Ta-Nehisi Coates",
                                        "The Overstory – Richard Powers",
                                        "The Vanishing Half – Brit Bennett",
                                        "Homegoing – Yaa Gyasi",
                                        "The Underground Railroad – Colson Whitehead",
                                        "An American Marriage – Tayari Jones",
                                        "The Testaments – Margaret Atwood",
                                        "Normal People – Sally Rooney",
                                        "Conversations with Friends – Sally Rooney",
                                        "Daisy Jones & The Six – Taylor Jenkins Reid",
                                        "The Goldfinch – Donna Tartt",
                                        "A Little Life – Hanya Yanagihara",
                                        "The Amazing Adventures of Kavalier & Clay – Michael Chabon",
                                        "The Brief Wondrous Life of Oscar Wao – Junot Díaz",
                                        "Middlesex – Jeffrey Eugenides",
                                        "The Secret History – Donna Tartt",
                                        "A Thousand Splendid Suns – Khaled Hosseini",
                                        "Wild: From Lost to Found on the Pacific Crest Trail – Cheryl Strayed",
                                        "Eat, Pray, Love – Elizabeth Gilbert",
                                        "Becoming – Michelle Obama",
                                        "Educated – Tara Westover",
                                        "Hillbilly Elegy – J.D. Vance",
                                        "Sapiens: A Brief History of Humankind – Yuval Noah Harari",
                                        "Homo Deus: A Brief History of Tomorrow – Yuval Noah Harari",
                                        "The Immortal Life of Henrietta Lacks – Rebecca Skloot",
                                        "Quiet: The Power of Introverts in a World That Can't Stop Talking – Susan Cain"};
int quantity[maximum_entries] = {};

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
            Sleep(1000);
            cout << "---------------------------" << endl;
            cout <<"|"<< " Location: " << temp->location << "  |"<<endl;
            cout <<"|"<< " Type: " << temp->type << "              |" <<endl;
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
class NodeforBookDetails
{
public:
    int SerialNumber;
    int ISBN;
    string book_details;
    int quantity;
    NodeforBookDetails *next;
    NodeforBookDetails *prev;

    NodeforBookDetails(int SerialNumber, int ISBN, string book_details, int quantity)
    {
        this->SerialNumber = SerialNumber;
        this->ISBN = ISBN;
        this->book_details = book_details;
        this->quantity = quantity;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedListForBooksStorage
{
private:
    NodeforBookDetails *head;
    NodeforBookDetails *tail;
    int length;

public:
    DoublyLinkedListForBooksStorage(int SerialNumber, int ISBN, string book_details, int quantity)
    {
        NodeforBookDetails *newNode = new NodeforBookDetails(SerialNumber, ISBN, book_details, quantity);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedListForBooksStorage()
    {
        NodeforBookDetails *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printListBooks()
    {
        NodeforBookDetails *temp = head;
        while (temp != nullptr)
        {
            Sleep(500);
            cout << "|Serail Number: " << temp->SerialNumber << endl;
            cout << "|ISBN: " << temp->ISBN << endl;
            cout << "|Book_Details: " << temp->book_details << endl;
            cout << "|Quantity: " << temp->quantity << endl;
            cout << endl;
            temp = temp->next;
        }
    }

    void appendintoBooks(int SerialNumber, int ISBN, string book_details, int quantity)
    {
        NodeforBookDetails *newNode = new NodeforBookDetails(SerialNumber, ISBN, book_details, quantity);
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
        NodeforBookDetails *temp = tail;
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
    void prependintobooks(int SerialNumber, int ISBN, string book_details, int quantity)
    {
        NodeforBookDetails *newNode = new NodeforBookDetails(SerialNumber, ISBN, book_details, quantity);
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
void populateArray()
{
    for (int i = 0; i < maximum_entries; i++)
    {
        ISBN[i] = (rand() % 1001) + 1000;
        quantity[i] = (rand() % 5) + 1;
    }
}
class NodeOfBSTRegno
{
public:
    int value;
    NodeOfBSTRegno *left;
    NodeOfBSTRegno *right;

    NodeOfBSTRegno(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTreeRegno
{
public:
    NodeOfBSTRegno *root;

public:
    BinarySearchTreeRegno() { root = nullptr; }
    void destroy(NodeOfBSTRegno *currentNode)
    {
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTreeRegno() { destroy(root); }

    bool insert(int value)
    {
        NodeOfBSTRegno *newNode = new NodeOfBSTRegno(value);

        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        NodeOfBSTRegno *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
            {
                return false;
            }
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
    // the below function will check if a regno exits or not
    bool containsRegno(int value)
    {
        if (root == nullptr)
            return false;
        NodeOfBSTRegno *temp = root;
        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    void BFS()
    {
        NodeOfBSTRegno *currentNode = root;
        queue<NodeOfBSTRegno *> myQueue;
        myQueue.push(currentNode);

        while (myQueue.size() > 0)
        {
            currentNode = myQueue.front();
            myQueue.pop();
            cout <<currentNode->value << endl;
            if (currentNode->left)
            {
                myQueue.push(currentNode->left);
            }
            if (currentNode->right)
            {
                myQueue.push(currentNode->right);
            }
        }
    }

    void DFSPreOrder(NodeOfBSTRegno *currentNode)
    {
        Sleep(500);
        cout <<currentNode->value << endl;
        if (currentNode->left != nullptr)
        {
            DFSPreOrder(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            DFSPreOrder(currentNode->right);
        }
    }

    void DFSPreOrder() { DFSPreOrder(root); }

    void DFSPostOrder(NodeOfBSTRegno *currentNode)
    {
        Sleep(500);
        if (currentNode->left != nullptr)
        {
            DFSPostOrder(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            DFSPostOrder(currentNode->right);
        }
        cout <<currentNode->value << endl;
    }

    void DFSPostOrder() { DFSPostOrder(root); }

    void DFSInOrder(NodeOfBSTRegno *currentNode)
    {
        Sleep(500);
        if (currentNode->left != nullptr)
        {
            DFSPreOrder(currentNode->left);
        }
        cout << currentNode->value << endl;
        if (currentNode->right != nullptr)
        {
            DFSPreOrder(currentNode->right);
        }
    }

    void DFSInOrder() { DFSInOrder(root); }
};
class NodeforFaculty
{
public:
    string Faculty;
    NodeforFaculty *next;

    NodeforFaculty(string Faculty)
    {
        this->Faculty = Faculty;
        next = nullptr;
    }
};

class LinkedListForFaculty
{
private:
    NodeforFaculty *head;
    NodeforFaculty *tail;
    int length;

public:
    LinkedListForFaculty()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedListForFaculty()
    {
        NodeforFaculty *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void append(string Faculty)
    {
        NodeforFaculty *newNode = new NodeforFaculty(Faculty);

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
};
void Library()
{
    BinarySearchTreeRegno* mybst = new BinarySearchTreeRegno();
    // the below code will store 700 regnumbers in the bst.
    int regnumber = 2023000;
    for (int i = 0; i <= 700; i++)
    {
        mybst->insert(regnumber + i);
    }
    DoublyLinkedListForBooksStorage *myDoublyLinked = new DoublyLinkedListForBooksStorage(0, ISBN[0], book_details[0], quantity[0]);
    for (int i = 1; i < maximum_entries; i++)
    {
        myDoublyLinked->appendintoBooks(i, ISBN[i], book_details[i], quantity[i]);
    }
    ComputerInfoLinkedList* CI = new ComputerInfoLinkedList();
    for (int i = 0; i < maximum_computers_mac; i++)
    {
        bool hasinternetAccess = false;
        if (i % 2 == 0)
        {
            hasinternetAccess = true;
        }
        CI->append("Mac", "Second Floor", "192.168.1.1", hasinternetAccess);
    }
    // the below code will populate for windows computers
    for (int i = 0; i < maximum_computers_windows; i++)
    {
        bool hasinternetAccess = false;
        if (i % 2 == 0)
        {
            hasinternetAccess = true;
        }
        CI->append("Windows", "Third Floor", "192.168.1.1", true);
    }
    LinkedListForFaculty* LL = new LinkedListForFaculty();
    int choice;
    int regno;
    int passwordsArray[3] = {0011, 1122, 3344};
    string designation;
    int password;
    int adminPortal;
    string Faculty;
    cout << endl;
    cout << "\t\t\t\t\t\tLibrary Management System" << endl;
    Sleep(1000);
    cout << "\t\t\t\t\t\t\tA Project By" << endl;
    Sleep(500);
    cout << "\t\t\tSalman Shahzad Ali\t\t";
    cout << "2023504\t\t";
    cout << "DataScience" << endl;
    Sleep(500);
    cout << "\t\t\tMusab Altaf\t\t\t";
    cout << "2023476\t\t";
    cout << "DataScience" << endl;
    Sleep(500);
    cout << "\t\t\tRayyan Hassna\t\t\t";
    cout << "2023598\t\t";
    cout << "DataScience" << endl;
    Sleep(1000);
    cout << "If you are an admin then please press 1 to access admin portal: ";
    cin >> adminPortal;
    if (adminPortal == 1)
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
            while (password != passwordsArray[0] && password != passwordsArray[1] && password != passwordsArray[2])
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
    }
    else
    {
        Sleep(500);
        cout << endl;
        cout << "You will be able to browse books" << endl;
        Sleep(500);
        cout << "We have the following categories" << endl;
        Sleep(500);
        cout << "Educational Books" << endl;
        Sleep(500);
        cout << "Non-fiction Books" << endl;
        Sleep(500);
        cout << "Fiction Books" << endl;
        Sleep(100);
        cout << endl;
        cout << "You will be able to use computer resources" << endl;
        Sleep(500);
        cout << "We have the following categories" << endl;
        Sleep(500);
        cout << "Windows" << endl;
        Sleep(500);
        cout << "Mac" << endl;
        Sleep(500);
        cout << endl;
        cout << "You will be able to request new books" << endl;
        Sleep(500);
        cout << "For Example you require a book that is not present in the library hence you can request it via submitting a form" << endl;
        Sleep(500);
        cout << "The Librarian will resolve the request as soon as possible" << endl;
        cout << endl;
        cout << "Which Faculty Do You belong To: ";
        cin >> Faculty;
        LL->append(Faculty);
        Sleep(1000);
        cout << "Please Leave Your Bags In the designated Space" << endl;
        cout << "Please take care of your belongings The Administration will not be responsible for any losses" << endl;
        Sleep(1000);
        cout << endl;
        cout << "Please Enter Your reg number: ";
        cin >> regno;
        cout << endl;
        if (mybst->containsRegno(regno))
        {
            Sleep(1000);
            cout << "Regno successfully Found" << endl;
            cout << endl;
            Sleep(1000);
            cout << "To Browse Books press 1 " << endl;
            cout << "To Browse Computer Resources press 2 " << endl;
            cin >> choice;
            if (choice == 1)
            {
                cout << "Displaying You all the books we have" << endl;
                Sleep(1000);
                myDoublyLinked->printListBooks();
            }
            if (choice == 2)
            {
                cout << "Displaying You all computer resources we have" << endl;
                Sleep(1000);
                CI->printList();
            }
        }
        else
        {
            cout << "Regno not found " << endl;
            Sleep(1000);
            cout << "Please wait we are registering you" << endl;
            Sleep(1000);
            mybst->insert(regno);
        }
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed with current time
    // the below function will populate the array this is server side thing to handle.
    populateArray();

    system("CLS");
    Library();
    return 0;
}