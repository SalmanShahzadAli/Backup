// this module will cover storing of regestration numbers in a doubly linked list.
// the reason to choose doubly linked list is if we have to access a given node hence we can go back and forward.
// the linkedlist will have 700 nodes each node having a regno.
// in this module we have connected the two modules where identity will be verified and then the user will be directed to either the library or to register his reg number

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>
using namespace std;
const int maximum_entries = 108;
using namespace std;
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
// filling the ISBN array starting from 0 to 108;
void populateArray()
{
    for (int i = 0; i < maximum_entries; i++)
    {
        ISBN[i] = (rand() % 1001) + 1000;
        quantity[i] = (rand() % 5) + 1;
    }
};
class NodeofLibraryContent
{
public:
    int ISBN;
    string book_details;
    int qunatity;
    NodeofLibraryContent *next;
    NodeofLibraryContent *prev;

    NodeofLibraryContent(int ISBN, string book_details, int quantity)
    {
        this->ISBN = ISBN;
        this->book_details = book_details;
        this->qunatity = quantity;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class DoublyLinkedListofLibraryContents
{
private:
    NodeofLibraryContent *head;
    NodeofLibraryContent *tail;
    int length;

public:
    DoublyLinkedListofLibraryContents(int ISBN, string book_details, int quantity)
    {
        NodeofLibraryContent *newNode = new NodeofLibraryContent(ISBN, book_details, quantity);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedListofLibraryContents()
    {
        NodeofLibraryContent *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        NodeofLibraryContent *temp = head;
        while (temp != nullptr)
        {
            cout << "ISBN: " << temp->ISBN << endl;
            cout << "Book_Details: " << temp->book_details << endl;
            cout << "Quantity: " << temp->qunatity << endl;
            cout << endl;
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
        NodeofLibraryContent *newNode = new NodeofLibraryContent(ISBN, book_details, quantity);
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
        NodeofLibraryContent *temp = tail;
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
        NodeofLibraryContent *newNode = new NodeofLibraryContent(ISBN, book_details, quantity);
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

class NodeofRegnumber
{
public:
    int value;
    NodeofRegnumber *next;
    NodeofRegnumber *prev;

    NodeofRegnumber(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedListofRegnumber
{
private:
    NodeofRegnumber *head;
    NodeofRegnumber *tail;
    int length;

public:
    DoublyLinkedListofRegnumber()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~DoublyLinkedListofRegnumber()
    {
        NodeofRegnumber *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        NodeofRegnumber *temp = head;
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
        NodeofRegnumber *newNode = new NodeofRegnumber(value);
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
        NodeofRegnumber *temp = tail;
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
        NodeofRegnumber *newNode = new NodeofRegnumber(value);
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
        NodeofRegnumber *temp = head;
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
    bool IdentityVerification()
    {
        int regno;
        cout << "Please Enter Your Regno: ";
        cin >> regno;
        bool Found = SearchRegno(regno);
        if (Found)
        {
            cout << "Successfully Found Your Regno You May Proceed To Borrow Books" << endl;
        }
        else
        {
            cout << "Regno not found please get your regno registered first" << endl;
        }
    }
    void displayLibrary()
    {
    }
    void getRegistered(int value)
    {
        append(value);
        return;
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed with current time
    // the below function will populate the array this is server side thing to handle.
    populateArray();
    DoublyLinkedListofLibraryContents *myDoublyLinked = new DoublyLinkedListofLibraryContents(ISBN[0], book_details[0], quantity[0]);
    for (int i = 1; i < maximum_entries; i++)
    {
        myDoublyLinked->append(ISBN[i], book_details[i], quantity[i]);
    }
    myDoublyLinked->printList();
    // the part1 is the year of arrival in giki university followed by part2 which is the serial number.
    // the below code generates all of the serial numbers and store them in the linked list.
    int part1 = 2023000;
    DoublyLinkedListofRegnumber *myDLL = new DoublyLinkedListofRegnumber();
    for (int i = 0; i <= 700; i++)
    {
        myDLL->append(2023000 + i);
    }
    myDLL->printList();
    myDLL->IdentityVerification();
    return 0;
}
