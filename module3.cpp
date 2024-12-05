// in this module we have just hard coded some data into data sets and now we will use this in another file to just simply populate the list.
#include <iostream>
#include <cstdlib> // For rand() and srand()
const int maximum_entries = 108;
using namespace std;

int main()
{
    int Serial_Numbers[maximum_entries] = {};
    int ISBN[maximum_entries] = {};
    string book_detailsofFictionBooks[maximum_entries] = {"I Know Why the Caged Bird Sings - Maya Angelou",
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

    // filling the ISBN array starting from 0 to 110;
    for (int i = 0; i < maximum_entries; i++)
    {
        ISBN[i] = (rand() % 1001) + 1000;
        quantity[i] = (rand() % 5) + 1;
        Serial_Numbers[i] = i;
    }
    for (int i = 0; i < maximum_entries; i++)
    {
        cout << "ISBN[" << i << "] = " << ISBN[i] << endl;
        cout << "Serial_Number[" << i << "] = " << Serial_Numbers[i] << endl;
        cout << "Quantity[" << i << "] = " << quantity[i] << endl;
        cout << "book_details[" << i << "] = " << book_detailsofFictionBooks[i] << endl;
        cout << endl;
    }

    return 0;
}