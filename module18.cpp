// in this module i am trying to connect the previous modules
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib> // For rand() and srand()
#include <queue>
#include <random>
#include <ctime>
#include <iomanip>
#include <unordered_set>
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

void displayCurrentTime()
{
    // Get the current time
    time_t now = time(0);

    // Convert to local time format
    char *dt = ctime(&now);

    // Print the formatted time
    cout << "\t\t\t\t\t\t\t\tCurrent local time: " << dt;
}
class NodeforComputerAllotment
{
public:
    int regnumber;
    string computertype;
    string contact;
    int duration;
    NodeforComputerAllotment *next;

public:
    NodeforComputerAllotment(int regnumber, string computertype, string contact, int duration)
    {
        this->computertype = computertype;
        this->contact = contact;
        this->duration = duration;
        this->regnumber = regnumber;
        next = nullptr;
    }
};
class LinkedListforcomputerAllotment
{
private:
    NodeforComputerAllotment *head;
    NodeforComputerAllotment *tail;
    int length;

public:
    LinkedListforcomputerAllotment()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedListforcomputerAllotment()
    {
        NodeforComputerAllotment *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void searchByRegNumber(int regnumber)
    {
        NodeforComputerAllotment *temp = head;
        while (temp != nullptr)
        {
            if (temp->regnumber == regnumber)
            {
                Sleep(1000);
                cout << "\t\t\t\tYour Reciept is as follows" << endl;
                cout << endl;
                Sleep(1000);
                cout << "\t\t\t\t---------------------------" << endl;
                cout << "\t\t\t\t| Computer Type: " << temp->computertype << endl;
                cout << "\t\t\t\t| Registration Number: " << temp->regnumber << endl;
                cout << "\t\t\t\t| Contact: " << temp->contact << endl;
                cout << "\t\t\t\t| Duration: " << temp->duration << " hours" << endl;
                cout << "\t\t\t\t---------------------------" << endl;
                Sleep(1000);
                cout << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No record found with Registration Number: " << regnumber << endl;
    }

    void append(int regnumber, string computertype, string contact, int duration)
    {
        NodeforComputerAllotment *newNode = new NodeforComputerAllotment(regnumber, computertype, contact, duration);
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
        NodeforComputerAllotment *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            NodeforComputerAllotment *pre = head;
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

    void deleteFirst()
    {
        if (length == 0)
        {
            return;
        }
        NodeforComputerAllotment *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }
    void printList()
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }

        NodeforComputerAllotment *temp = head;
        while (temp != nullptr)
        {
            Sleep(500);
            cout << "\t\t\t\t---------------------------" << endl;
            cout << "\t\t\t\t| Computer Type: " << temp->computertype << endl;
            cout << "\t\t\t\t| Registration Number: " << temp->regnumber << endl;
            cout << "\t\t\t\t| Contact: " << temp->contact << endl;
            cout << "\t\t\t\t| Duration: " << temp->duration << " hours" << endl;
            cout << "\t\t\t\t---------------------------" << endl;
            Sleep(500);
            temp = temp->next;
        }
    }
};
class Nodeforborrowedbooks
{
public:
    int regnumber;
    string nameofbook;
    int ISBN;
    string contactNumber;
    Nodeforborrowedbooks *next;

    Nodeforborrowedbooks(int regnumber, string nameofbook, int ISBN, string contactNumber)
    {
        this->regnumber = regnumber;
        this->nameofbook = nameofbook;
        this->ISBN = ISBN;
        this->contactNumber = contactNumber;
        next = nullptr;
    }
};

class StackforBorrowedbooks
{
private:
    Nodeforborrowedbooks *top;
    int height;

public:
    StackforBorrowedbooks()
    {
        top = nullptr;
    }

    ~StackforBorrowedbooks()
    {
        Nodeforborrowedbooks *temp = top;
        while (top)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    void printStack()
    {
        // Helper lambda to generate a random time one day ahead
        auto generateRandomTimeOneDayAhead = []() -> std::string
        {
            std::time_t currentTime = std::time(nullptr);         // Get current time
            std::time_t nextDayTime = currentTime + 24 * 60 * 60; // Add 24 hours (1 day)

            // Random offset between -6 and +6 hours
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> offsetDist(-6 * 60 * 60, 6 * 60 * 60);
            int randomOffset = offsetDist(gen);

            nextDayTime += randomOffset; // Apply the offset

            // Format the time as a string
            std::tm *localTime = std::localtime(&nextDayTime);
            std::ostringstream oss;
            oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
            return oss.str();
        };
        Nodeforborrowedbooks *temp = top;
        while (temp)
        {
            Sleep(500);
            cout << endl;
            Sleep(500);
            cout << "\t\t\tContact-Number: " << temp->contactNumber << endl;
            cout << "\t\t\tReg-Number: " << temp->regnumber << endl;
            cout << "\t\t\tName of Book: " << temp->nameofbook << endl;
            cout << "\t\t\tISBN: " << temp->ISBN << endl;
            cout << "\t\t\tReturned Deadline: " << generateRandomTimeOneDayAhead() << endl;
            cout << "\t\t\tPlease be mindful to return before the deadline" << endl;
            cout << endl;
            temp = temp->next;
        }
    }

    void getHeight()
    {
        cout << "Height: " << height << endl;
    }

    void push(int regnumber, string nameofbook, int ISBN, string contactNumber)
    {
        Nodeforborrowedbooks *newNode = new Nodeforborrowedbooks(regnumber, nameofbook, ISBN, contactNumber);
        newNode->next = top;
        top = newNode;
        height++;
    }
};

const int maximum_computers_mac = 50;
const int maximum_computers_windows = 50;

class NodeofComputerInfo
{
public:
    string type;
    string location;
    string ip_address;
    bool internet_access;
    int serialNumber;
    NodeofComputerInfo *next;

    NodeofComputerInfo(int serialNumber, string type, string location, string ip_address, bool internet_access)
        : serialNumber(serialNumber), type(type), location(location), ip_address(ip_address), internet_access(internet_access), next(nullptr) {}
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
        while (temp)
        {
            Sleep(50);
            cout << "\t\t\t\t---------------------------" << endl;
            cout << "\t\t\t\t|" << " Serial-Number: " << temp->serialNumber << endl;
            cout << "\t\t\t\t|" << " Location: " << temp->location << endl;
            cout << "\t\t\t\t|" << " Type: " << temp->type << endl;
            cout << "\t\t\t\t|" << " IP Address: " << temp->ip_address << endl;
            cout << "\t\t\t\t|" << " Internet Access: " << (temp->internet_access ? "Yes" : "No") << endl; // Print internet access
            cout << "\t\t\t\t---------------------------" << endl;                                         // Separator for readability
            temp = temp->next;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int serialNumber, string type, string location, string ip_address, bool internet_access)
    {
        NodeofComputerInfo *newNode = new NodeofComputerInfo(serialNumber, type, location, ip_address, internet_access);
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
    void deleteFirst()
    {
        if (length == 0)
        {
            return;
        }
        NodeofComputerInfo *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
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
    NodeforBookDetails *next;
    NodeforBookDetails *prev;

    NodeforBookDetails(int SerialNumber, int ISBN, string book_details)
    {
        this->SerialNumber = SerialNumber;
        this->ISBN = ISBN;
        this->book_details = book_details;
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
    DoublyLinkedListForBooksStorage(int SerialNumber, int ISBN, string book_details)
    {
        NodeforBookDetails *newNode = new NodeforBookDetails(SerialNumber, ISBN, book_details);
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
    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "The list is empty. No head to delete.\n";
            return;
        }

        NodeforBookDetails *temp = head;
        head = head->next;

        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; // If the list becomes empty
        }

        delete temp;
        length--;
    }

    void deleteTail()
    {
        if (tail == nullptr)
        {
            cout << "The list is empty. No tail to delete.\n";
            return;
        }

        NodeforBookDetails *temp = tail;
        tail = tail->prev;

        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr; // If the list becomes empty
        }

        delete temp;
        length--;
    }

    void deleteMiddleNode(NodeforBookDetails *node)
    {
        if (node == nullptr)
        {
            cout << "Invalid node to delete.\n";
            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;
        length--;
    }

    void deleteBookByISBN(int ISBN)
    {
        if (length == 0)
        {
            cout << "The list is empty. No books to delete.\n";
            return;
        }

        NodeforBookDetails *temp = head;

        while (temp)
        {
            if (temp->ISBN == ISBN)
            {
                if (temp == head)
                {
                    deleteHead();
                }
                else if (temp == tail)
                {
                    deleteTail();
                }
                else
                {
                    deleteMiddleNode(temp);
                }
                return;
            }
            temp = temp->next;
        }

        cout << "Book with ISBN " << ISBN << " not found in the list.\n";
    }

    void printListBooks()
    {
        NodeforBookDetails *temp = head;
        while (temp != nullptr)
        {
            Sleep(100);
            cout << "\t\t\t|Serail Number: " << temp->SerialNumber << endl;
            cout << "\t\t\t|ISBN: " << temp->ISBN << endl;
            cout << "\t\t\t|Book_Details: " << temp->book_details << endl;
            cout << endl;
            temp = temp->next;
        }
    }

    void appendintoBooks(int SerialNumber, int ISBN, string book_details)
    {
        NodeforBookDetails *newNode = new NodeforBookDetails(SerialNumber, ISBN, book_details);
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

    void prependintobooks(int SerialNumber, int ISBN, string book_details)
    {
        NodeforBookDetails *newNode = new NodeforBookDetails(SerialNumber, ISBN, book_details);
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
    string getName(int ISBN)
    {
        NodeforBookDetails *temp = head;
        while (temp)
        {
            if (temp->ISBN == ISBN)
            {
                return temp->book_details;
            }
            temp = temp->next;
        }
        return "";
    }
};
void populateArray()
{
    // this is to ensure that a new ISBN is generated each time
    unordered_set<int> usedISBNs; // Set to track unique ISBNs
    srand(time(0));               // Seed for random number generation

    for (int i = 0; i < maximum_entries; i++)
    {
        int newISBN;
        do
        {
            newISBN = (rand() % 1001) + 1000; // Generate ISBN in the range [1000, 2000]
        } while (usedISBNs.find(newISBN) != usedISBNs.end()); // Repeat if ISBN is already used

        ISBN[i] = newISBN;
        usedISBNs.insert(newISBN); // Add to the set of used ISBNs
    }
}
class NodeOfBSTStdDetails
{
public:
    int value;
    string emailadress;
    NodeOfBSTStdDetails *left;
    NodeOfBSTStdDetails *right;

    NodeOfBSTStdDetails(int value, string emailadress)
    {
        this->value = value;
        this->emailadress = emailadress;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTreeStdDetails
{
public:
    NodeOfBSTStdDetails *root;

public:
    BinarySearchTreeStdDetails() { root = nullptr; }
    void destroy(NodeOfBSTStdDetails *currentNode)
    {
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTreeStdDetails() { destroy(root); }

    bool insert(int value, string emailadress)
    {
        NodeOfBSTStdDetails *newNode = new NodeOfBSTStdDetails(value, emailadress);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        NodeOfBSTStdDetails *temp = root;
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
        NodeOfBSTStdDetails *temp = root;
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
        NodeOfBSTStdDetails *currentNode = root;
        queue<NodeOfBSTStdDetails *> myQueue;
        myQueue.push(currentNode);

        while (myQueue.size() > 0)
        {
            currentNode = myQueue.front();
            myQueue.pop();
            cout << "\t\t\t\tRegnumber - " << currentNode->value << endl;
            cout << "\t\t\t\tEmail - " << currentNode->emailadress << endl;
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

    void DFSPreOrder(NodeOfBSTStdDetails *currentNode)
    {
        cout << endl;
        cout << "\t\t\t\t\t\tRegnumber - " << currentNode->value << endl;
        cout << "\t\t\t\t\t\tEmail - " << currentNode->emailadress << endl;
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

    void DFSPostOrder(NodeOfBSTStdDetails *currentNode)
    {
        Sleep(100);
        if (currentNode->left != nullptr)
        {
            DFSPostOrder(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            DFSPostOrder(currentNode->right);
        }
        cout << endl;
        cout << "\t\t\t\t\t\tRegnumber - " << currentNode->value << endl;
        cout << "\t\t\t\t\t\tEmail - " << currentNode->emailadress << endl;
    }

    void DFSPostOrder() { DFSPostOrder(root); }

    void DFSInOrder(NodeOfBSTStdDetails *currentNode)
    {
        if (currentNode->left != nullptr)
        {
            DFSPreOrder(currentNode->left);
        }
        cout << endl;
        cout << "\t\t\t\t\t\tRegnumber - " << currentNode->value << endl;
        cout << "\t\t\t\t\t\tEmail - " << currentNode->emailadress << endl;
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
BinarySearchTreeStdDetails *mybst = new BinarySearchTreeStdDetails();
void Initialisationofregnumber()
{
    string email = "";
    // the below code will store 700 regnumbers in the bst.
    int regnumber = 2023000;
    for (int i = 0; i <= 700; i++)
    {
        email = "u" + to_string(regnumber + i) + "@giki.edu.pk";
        mybst->insert(regnumber + i, email);
    }
};
DoublyLinkedListForBooksStorage *myDoublyLinked = new DoublyLinkedListForBooksStorage(0, ISBN[0], book_details[0]);
void initialisationforbooks()
{

    for (int i = 1; i < maximum_entries; i++)
    {
        myDoublyLinked->appendintoBooks(i, ISBN[i], book_details[i]);
    }
}
ComputerInfoLinkedList *CI = new ComputerInfoLinkedList();
void initialisationforcomputerinfo()
{
    for (int i = 0; i < maximum_computers_mac; i++)
    {
        bool hasinternetAccess = false;
        if (i % 2 == 0)
        {
            hasinternetAccess = true;
        }
        CI->append(i + 1, "Mac", "Second Floor", "192.168.1.1", hasinternetAccess);
    }
    // the below code will populate for windows computers
    for (int i = 0; i < maximum_computers_windows; i++)
    {
        bool hasinternetAccess = false;
        if (i % 2 == 0)
        {
            hasinternetAccess = true;
        }
        CI->append(maximum_computers_mac + i + 1, "Windows", "Third Floor", "192.168.1.1", true);
    }
}
class Nodefororderbook
{
public:
    int urgency_level;
    string book_name;
    string author_name;
    string category;
    Nodefororderbook *next;

    Nodefororderbook(int urgency_level, string book_name, string author_name, string category)
    {
        this->urgency_level = urgency_level;
        this->author_name = author_name;
        this->book_name = book_name;
        this->category = category;
        next = nullptr;
    }
};

class LinkedListBookRequests
{
private:
    Nodefororderbook *head;
    Nodefororderbook *tail;
    int length;

public:
    LinkedListBookRequests() : head(nullptr), tail(nullptr), length(0) {}

    ~LinkedListBookRequests()
    {
        Nodefororderbook *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Nodefororderbook *temp = head;
        while (temp != nullptr)
        {
            Sleep(500);
            cout << endl;
            cout << "\t\t\tYour Query Receipt is as follows" << endl;
            cout << endl;
            Sleep(500);
            cout << "\t\t\t|Author Name: " << temp->author_name << endl;
            cout << "\t\t\t|Book Name: " << temp->book_name << endl;
            cout << "\t\t\t|Category: " << temp->category << endl;
            cout << "\t\t\t|Urgency Level: " << temp->urgency_level << endl;
            temp = temp->next;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int urgency_level, string book_name, string author_name, string category)
    {
        Nodefororderbook *newNode = new Nodefororderbook(urgency_level, book_name, author_name, category);
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
        Nodefororderbook *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Nodefororderbook *pre = head;
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

    Nodefororderbook *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        Nodefororderbook *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp;
    }
};
void orderBookOnDemand(LinkedListBookRequests &request)
{
    string name;
    string author_name;
    string category;
    int urgency_level;
    cout << endl;
    cout << "\t\t\tRequesting Book Form is as follows" << endl;
    Sleep(1000);
    cout << "\t\t\tPLease Enter the category of the book: " << endl;
    cout << "\t\t\t\tFor Example" << endl;
    cout << "\t\t\t\tEducational " << endl;
    cout << "\t\t\t\tFiction" << endl;
    cout << "\t\t\t\tNon-Fiction" << endl;
    cout << "\t\t\t\tPoetry And Drama" << endl;
    cout << "\t\t\t\tYoung Adult" << endl;
    cout << "\t\t\t\tCategory: ";
    cin >> category;
    cout << "\t\t\tPlease Enter The name of the book: ";
    cin.ignore(); // To ignore any newline character left by previous inputs
    getline(cin, name);
    cout << "\t\t\tPlease Enter The Author Name: ";
    cin >> author_name;
    cout << "\t\t\tPlease Enter The Urgency Level between 0-5: ";
    cin >> urgency_level;
    while (urgency_level > 5 || urgency_level < 0)
    {
        cout << "\t\t\tPlease Enter A Valid Urgency Level between 0-5: ";
        cin >> urgency_level;
    }
    request.append(urgency_level, name, author_name, category);
}
LinkedListBookRequests request;
LinkedListForFaculty *LL = new LinkedListForFaculty();
StackforBorrowedbooks *SS = new StackforBorrowedbooks();
LinkedListforcomputerAllotment *CA = new LinkedListforcomputerAllotment();
void Library()
{
    int choice;
    int regno;
    int passwordsArray[3] = {0011, 1122, 3344};
    string designation;
    int password;
    int adminPortal;
    string Faculty;
    int ISBN;
    string phonenumber;
    char choiceofcontinuity;
    string typeofcomputer;
    string borrowedBook;
    int ISBNnumber;
    int SerailNumber;
    int duration;
    int choiceforadmin;
    char choiceofprint;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\tLibrary Management System" << endl;
    Sleep(1000);
    cout << "\t\t\t\tGhulam Ishaq Khan Institute OF Engineering Sciences And Technology Topi Swabi Khyber Pukhtoonkhua" << endl;
    Sleep(500);
    displayCurrentTime();
    cout << "\t\t\t\t\t\t\t\t\t\tA Project By" << endl;
    Sleep(500);
    cout << "\t\t\t\t\t\tSalman Shahzad Ali\t\t";
    cout << "2023504\t\t";
    cout << "DataScience" << endl;
    Sleep(500);
    cout << "\t\t\t\t\t\tMusab Altaf\t\t\t";
    cout << "2023476\t\t";
    cout << "DataScience" << endl;
    Sleep(500);
    cout << "\t\t\t\t\t\tRayyan Hassna\t\t\t";
    cout << "2023598\t\t";
    cout << "DataScience" << endl;
    Sleep(1000);
    cout << endl;
    cout << "\t\t\t\tIf you are an admin then please press 1 to access admin portal otherisw press anynumber: ";
    cin >> adminPortal;
    if (adminPortal == 1)
    {
        system("CLS");
        cout << endl;
        cout << "\t\t\t\t\t\t\tLibrary Management System" << endl;
        cout << "\t\t\tGhulam Ishaq Khan Institute OF Engineering Sciences And Technology Topi Swabi Khyber Pukhtoonkhua" << endl;
        cout << "\t\t\t\t\t\t\tWelcome to the Admin Panel" << endl;
        displayCurrentTime();
        Sleep(500);
        cout << endl;
        cout << "\t\t\t\t\t\tPlease Enter Your Designation Please: ";
        cin >> designation;
        Sleep(500);
        if (designation != "Librarian" && designation != "Superviser" && designation != "FinanceOfficer")
        {
            cout << "Your designation is not authorised to access the libraray as an admin" << endl;
        }
        else
        {
            cout << "\t\t\t\t\t\tPlease Enter Your Password: ";
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
        Sleep(200);
        cout << endl;
        cout << "\t\t\t\t\t\tLogged in as " << designation << endl;
        Sleep(500);
        cout << "\t\t\t\t\t\tyou may continue to perform the daily activites" << endl;
        cout << endl;
        Sleep(500);
        cout << "\t\t\t\t\t\tTo view the list of all students registered in the institue please press 1: " << endl;
        cout << "\t\t\t\t\t\tTo view the list of ordered books please press 2" << endl;
        cout << "\t\t\t\t\t\tTo view the list of borrwed books please press 3" << endl;
        cout << "\t\t\t\t\t\tTo view the list of computer allotments please press 4" << endl;
        Sleep(1000);
        cout << "\t\t\t\t\t\tChoice: ";
        cin >> choiceforadmin;
        Sleep(1000);
        if (choiceforadmin == 1)
        {
            cout << "\t\t\t\t\t\tAs per Your Request Printing You all The Registered Students" << endl;
            Sleep(500);
            mybst->DFSInOrder();
            Sleep(100);
            cout << endl;
            cout << "\t\t\t\t\t\tDo you require the list in printed form ? (Y/N): ";
            cin >> choiceofprint;
            if (choiceofprint == 'Y' || choiceofprint == 'y')
            {
                Sleep(100);
                cout << "\t\t\t\t\t\tYou will have the list at hand in 2 minutes" << endl;
                cout << endl;
            }
        }
        if (choiceforadmin == 2)
        {
            Sleep(1000);
            cout << "\t\t\t\t\t\tDisplaying you the list of ordered books" << endl;
            Sleep(500);
            request.printList();
        }
        if (choiceforadmin == 3)
        {
            Sleep(1000);
            cout << endl;
            cout << "\t\t\t\t\t\tDisplaying you the list of borrowed books" << endl;
            Sleep(500);
            cout << endl;
            SS->printStack();
        }
        if (choiceforadmin == 4)
        {
            Sleep(1000);
            cout << "\t\t\t\t\t\tDisplaying you the list of computer allotments" << endl;
            Sleep(500);
            CA->printList();
        }
    }
    else
    {
        Sleep(500);
        cout << endl;
        cout << "\t\t\t\t\tYou will be able to browse books" << endl;
        Sleep(500);
        cout << "\t\t\t\t\tWe have the following categories" << endl;
        Sleep(500);
        cout << "\t\t\t\t\tEducational Books" << endl;
        Sleep(500);
        cout << "\t\t\t\t\tNon-fiction Books" << endl;
        Sleep(500);
        cout << "\t\t\t\t\tFiction Books" << endl;
        Sleep(100);
        cout << endl;
        cout << "\t\t\t\t\tYou will be able to use computer resources" << endl;
        Sleep(500);
        cout << "\t\t\t\t\tWe have the following categories" << endl;
        Sleep(500);
        cout << "\t\t\t\t\tWindows Operating System" << endl;
        Sleep(500);
        cout << "\t\t\t\t\tMac Operating System" << endl;
        Sleep(500);
        cout << endl;
        cout << "\t\t\tYou will be able to request new books" << endl;
        Sleep(500);
        cout << "\t\t\tFor Example you require a book that is not present in the library hence you can request it via submitting a form" << endl;
        Sleep(500);
        cout << "\t\t\tThe Librarian will resolve the request as soon as possible" << endl;
        cout << endl;
        // cout << "Which Faculty Do You belong To: ";
        // cin >> Faculty;
        // LL->append(Faculty);

        cout << "\t\t\tPlease Leave Your Bags In the designated Space" << endl;
        cout << "\t\t\tPlease take care of your belongings The Administration will not be responsible for any losses" << endl;
        Sleep(1000);
        cout << endl;
        cout << "\t\t\tPlease Enter Your reg number: ";
        cin >> regno;
        cout << endl;
        if (mybst->containsRegno(regno))
        {
            Sleep(1000);
            cout << "\t\t\tRegno successfully Found" << endl;
            cout << endl;
            Sleep(1000);
            cout << "\t\t\tTo Browse Books press 1" << endl;
            cout << "\t\t\tTo Browse Computer Resources press 2" << endl;
            cout << "\t\t\tTo Return a borrowed book press 3" << endl;
            cout << "\t\t\tTo Request A Book Which is not present in catalouge press 4" << endl;
            cout << "\t\t\tChoice: ";
            cin >> choice;
            Sleep(1000);
            // the below code is for validation
            while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
            {
                Sleep(1000);
                cout << "\t\t\tInvalid choice entered" << endl;
                Sleep(1000);
                cout << "\t\t\tPlease Enter A Valid Choice" << endl;
                Sleep(1000);
                cout << "\t\t\tTo Browse Books press 1 " << endl;
                cout << "\t\t\tTo Browse Computer Resources press 2 " << endl;
                cout << "\t\t\tTo Return a borrowed book press 3: " << endl;
                cout << "\t\t\tChoice: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                cout << endl;
                cout << "\t\t\tDisplaying You all the books we have" << endl;
                Sleep(1000);
                cout << endl;
                myDoublyLinked->printListBooks();
                Sleep(1000);
                cout << "\t\t\tPlease Enter The ISBN Number of the book which you want: ";
                cin >> ISBN;
                // getting the name from the list
                string name = myDoublyLinked->getName(ISBN);
                Sleep(500);
                cout << "\t\t\tPlease Enter Your Contact Number: ";
                cin >> phonenumber;
                // now pushing into the stack the book the user has borrowed
                SS->push(regno, name, ISBN, phonenumber);
                cout << endl;
                cout << "\t\t\tYour Reciept is as follows" << endl;
                cout << endl;
                SS->printStack();
                myDoublyLinked->deleteBookByISBN(ISBN);
                Sleep(5000);
                cout << "\t\t\tPrinting The Catalouge After Update" << endl;
                cout << endl;
                Sleep(1000);
                myDoublyLinked->printListBooks();
                cout << "\t\t\tDo you requie any other assistance ? (Y/N): ";
                cin >> choiceofcontinuity;
                if (choiceofcontinuity == 'N' && choiceofcontinuity == 'n')
                {
                    cout << "Thank You So Much" << endl;
                }
            }
            if (choice == 2)
            {
                cout << "\t\t\tDisplaying You all computer resources we have" << endl;
                Sleep(1000);
                CI->printList();
                Sleep(1000);
                cout << "\t\t\t\tPlease Enter The Type of Computer you would like to use: ";
                cin >> typeofcomputer;
                cout << "\t\t\t\tPlease Enter The Duration for which you want to use the computer: ";
                cin >> duration;
                cout << "\t\t\t\tPlease Enter Your Reg Number: ";
                cin >> regno;
                cout << "\t\t\t\tPlease Enter Your Contact Number: ";
                cin >> phonenumber;
                CA->append(regno, typeofcomputer, phonenumber, duration);
                CA->searchByRegNumber(regno);
                if (typeofcomputer == "windows" || typeofcomputer == "Windows")
                {
                    CI->deleteLast();
                }
                else if (typeofcomputer == "Mac" || typeofcomputer == "mac")
                {

                    CI->deleteFirst();
                }
                Sleep(1000);
                cout << endl;
                cout << "\t\t\t\tDisplaying Catalouge After Alloting Computer" << endl;
                CI->printList();
            }
            if (choice == 3)
            {
                Sleep(1000);
                cout << endl;
                cout << "\t\t\tPrinting Catalouge Off Borrowed Books" << endl;
                Sleep(1000);
                SS->printStack();
                cout << "\t\t\tPlease Enter The Name For Borrwed Book: ";
                cin >> borrowedBook;
                cout << "\t\t\tPlease Enter The Serial Number: ";
                cin >> SerailNumber;
                cout << "\t\t\tPlease Enter The ISBN number: ";
                cin >> ISBNnumber;
                myDoublyLinked->appendintoBooks(SerailNumber, ISBN, borrowedBook);
            }
            if (choice == 4)
            {
                orderBookOnDemand(request);
                request.printList();
            }
        }
        else
        {
            cout << "\t\t\tRegno not found " << endl;
            Sleep(1000);
            cout << "\t\t\tPlease wait we are registering you" << endl;
            Sleep(1000);
            string tempname = "u" + to_string(regno) + "@giki.edu.pk";
            mybst->insert(regno, tempname);
        }
    }
}
int main()
{
    char choice;
    srand(static_cast<unsigned int>(time(0))); // Seed with current time
    // the below function will populate the array this is server side thing to handle.
    populateArray();
    initialisationforbooks();
    initialisationforcomputerinfo();
    Initialisationofregnumber();
    system("CLS");
    // this is the main driver function
    do
    {
        Library();
        cout << "\t\t\t\tDo you wish to avail anything else from library (Y/N): ";
        cin >> choice;
    } while (choice != 'N' && choice != 'n');

    return 0;
}