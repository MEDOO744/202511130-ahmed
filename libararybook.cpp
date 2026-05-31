#include "LibraryBook.h"
#include <iomanip>

// Default constructor
LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Parameterized constructor
LibraryBook::LibraryBook(int id, string t, string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Destructor
LibraryBook::~LibraryBook() {
    cout << "Book \"" << title << "\" (ID: " << bookID << ") has been destroyed." << endl;
}

// Getters
int LibraryBook::getBookID() const { return bookID; }
string LibraryBook::getTitle() const { return title; }
string LibraryBook::getAuthor() const { return author; }
string LibraryBook::getBorrowerName() const { return borrowerName; }
int LibraryBook::getDaysBorrowed() const { return daysBorrowed; }
bool LibraryBook::getIsBorrowed() const { return isBorrowed; }

// Setters
void LibraryBook::setBookID(int id) { bookID = id; }
void LibraryBook::setTitle(string t) { title = t; }
void LibraryBook::setAuthor(string a) { author = a; }
void LibraryBook::setBorrowerName(string name) { borrowerName = name; }
void LibraryBook::setDaysBorrowed(int days) { daysBorrowed = days; }
void LibraryBook::setIsBorrowed(bool status) { isBorrowed = status; }

// Borrow a book
void LibraryBook::borrowBook(string borrower, int days) {
    if (!isBorrowed) {
        borrowerName = borrower;
        daysBorrowed = days;
        isBorrowed = true;
        cout << "\nBook \"" << title << "\" has been borrowed by " << borrower << " for " << days << " days." << endl;
    } else {
        cout << "\nBook \"" << title << "\" is already borrowed by " << borrowerName << "." << endl;
    }
}

// Return a book
void LibraryBook::returnBook() {
    if (isBorrowed) {
        double fine = calculateFine();
        if (fine > 0) {
            cout << "\nBook returned LATE! Fine amount: $" << fixed << setprecision(2) << fine << endl;
        } else {
            cout << "\nBook returned on time. No fine." << endl;
        }
        borrowerName = "";
        daysBorrowed = 0;
        isBorrowed = false;
    } else {
        cout << "\nBook is not currently borrowed." << endl;
    }
}

// Calculate fine (Assuming 14 days is the borrowing limit, $1 per extra day)
double LibraryBook::calculateFine() const {
    const int MAX_BORROW_DAYS = 14;
    const double FINE_PER_DAY = 1.0;
    
    if (isBorrowed && daysBorrowed > MAX_BORROW_DAYS) {
        return (daysBorrowed - MAX_BORROW_DAYS) * FINE_PER_DAY;
    }
    return 0.0;
}

// Check if book is overdue
bool LibraryBook::isOverdue() const {
    const int MAX_BORROW_DAYS = 14;
    return (isBorrowed && daysBorrowed > MAX_BORROW_DAYS);
}

// Display book details
void LibraryBook::displayBook() const {
    cout << left << setw(10) << bookID
         << setw(25) << title
         << setw(20) << author;
    
    if (isBorrowed) {
        cout << setw(20) << borrowerName
             << setw(10) << daysBorrowed
             << setw(10) << (isOverdue() ? "Yes" : "No");
        if (isOverdue()) {
            cout << setw(10) << fixed << setprecision(2) << calculateFine();
        } else {
            cout << setw(10) << "0.00";
        }
    } else {
        cout << setw(20) << "Available"
             << setw(10) << "N/A"
             << setw(10) << "No"
             << setw(10) << "0.00";
    }
    cout << endl;
}