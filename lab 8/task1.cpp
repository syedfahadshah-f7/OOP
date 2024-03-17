
#include <iostream>
using namespace std;
class book
{
    string title, author, publisher;

public:
    book(string t, string a, string p) : title(t), author(a), publisher(p)
    {
    }
    void display()
    {
        cout << "Book Title :" << title << endl
             << "Book Author :" << author << endl
             << "Publisher Name :" << publisher << endl;
    }
};
class Fictionbook : public book
{

    string genre, protagonist;

public:
    Fictionbook(string genre, string protagonist, string title, string author, string publisher)
        : book(title, author, publisher)
    {
        this->genre = genre;
        this->protagonist = protagonist;
    }
    void display()
    {
        book ::display();
        cout << "Book genre :" << genre << endl
             << "Book protagonist :" << protagonist << endl;
    }
};
int main()
{

    Fictionbook JOY("horror", "Pta nhi", "Ghar mn bhoot", "Mehta", "Fahad");
    JOY.display();
    return 0;
}
