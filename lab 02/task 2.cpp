#include <iostream>
using namespace std;
struct Library
{
    string title, author, yop, genre;
};
void add_book(Library books[])
{
    int add;
    cout << "How many Books you want to add" << endl;
    cin >> add;
    if (add < 100)
    {
        for (int i = 0; i < add; i++)
        {
            cout << "Enter Details of Book" << i + 1 << endl;
            cout << "Enter Book title" << endl;
            cin >> books[i].title;
            cout << "Enter Author name" << endl;
            cin >> books[i].author;
            cout << "Enter year of publish" << endl;
            cin >> books[i].yop;
            cout << "Enter genre" << endl;
            cin >> books[i].genre;
        }
    }
    else
    {
        cout << "Library is full can't add new books";
    }
}
void search_book(Library books[])
{
    cout << "To search book enter book title" << endl;
    string search;
    cin >> search;
    for (int i = 0; i < 100; i++)
    {
        if (search == books[i].title)
        {
            cout << " Book title: " << books[i].title << endl;
            cout << " Author name: " << books[i].author << endl;
            cout << " Year of publish: " << books[i].yop << endl;
            cout << " Genre: " << books[i].genre << endl;
            break;
        }
        else
        {
            cout << "No book found !!" << endl;
        }
    }
}
void update_book(Library books[])
{
    cout << "Enter book title to update book" << endl;
    string update;
    cin >> update;
    for (int i = 0; i < 100; i++)
    {
        if (update == books[i].title)
        {
            cout << "Enter new book details" << endl
                 << endl;
            cout << "Enter Book title" << endl;
            cin >> books[i].title;
            cout << "Enter Author name" << endl;
            cin >> books[i].author;
            cout << "Enter year of publish" << endl;
            cin >> books[i].yop;
            cout << "Enter genre" << endl;
            cin >> books[i].genre;
            break;
        }
        else
        {
            cout << "No book found !!" << endl;
        }
    }
}

int main()
{
    Library books[100];
    int option;
    do
    {
        cout << "Add Book press 1" << endl
             << "Update Book press 2" << endl
             << "Search Book press 3" << endl
             << "Exit press 4" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            add_book(books);
            break;
        case 3:
            search_book(books);
            break;
        case 2:
            update_book(books);
            break;
        default:
            break;
        }
    } while (option != 4);
    cout << "Thanks For Visiting";
    return 0;
}
