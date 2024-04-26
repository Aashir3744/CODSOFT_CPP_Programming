#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a Book structure to store book information
struct Book {
    string title;
    string author;
    string ISBN;
    bool available;

    Book(const string& t, const string& a, const string& isbn)
        : title(t), author(a), ISBN(isbn), available(true) {}
};

// Define a Library class to manage books
class Library {
private:
    vector<Book> books;

public:
    // Function to add a book to the library
    void addBook(const string& title, const string& author, const string& ISBN) {
        books.push_back(Book(title, author, ISBN));
        cout << "Book added successfully!\n";
    }

    // Function to search for a book by title, author, or ISBN
    void searchBook(const string& keyword) {
        cout << "Search Results:\n";
        for (const Book& book : books) {
            if (book.title.find(keyword) != string::npos ||
                book.author.find(keyword) != string::npos ||
                book.ISBN.find(keyword) != string::npos) {
                cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << endl;
            }
        }
    }

    // Function to checkout a book
    void checkoutBook(const string& ISBN) {
        for (Book& book : books) {
            if (book.ISBN == ISBN) {
                if (book.available) {
                    book.available = false;
                    cout << "Book checked out successfully!\n";
                } else {
                    cout << "Book is not available for checkout.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Function to return a book
    void returnBook(const string& ISBN) {
        for (Book& book : books) {
            if (book.ISBN == ISBN) {
                if (!book.available) {
                    book.available = true;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book is already available.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;
    int choice;
    string keyword, title, author, ISBN;

    cout << "Welcome to Library Management System\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book ISBN: ";
                getline(cin, ISBN);
                library.addBook(title, author, ISBN);
                break;
            case 2:
                cout << "Enter search keyword: ";
                cin.ignore();
                getline(cin, keyword);
                library.searchBook(keyword);
                break;
            case 3:
                cout << "Enter ISBN of the book to checkout: ";
                cin >> ISBN;
                library.checkoutBook(ISBN);
                break;
            case 4:
                cout << "Enter ISBN of the book to return: ";
                cin >> ISBN;
                library.returnBook(ISBN);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
