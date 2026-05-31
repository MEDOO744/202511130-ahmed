#include "Functions.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Add a new book
void addBook(LibraryBook books[], int& bookCount) {
    if (bookCount >= MAX_BOOKS) {
        cout << "\nLibrary is full! Cannot add more books." << endl;
        return;
    }
    
    int id;
    string title, author;
    
    cout << "\n--- Add New Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    
    // Check if ID already exists
    if (findBookIndex(books, bookCount, id) != -1) {
        cout << "Book with this ID already exists!" << endl;
        return;
    }
    
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);
    
    books[bookCount] = LibraryBook(id, title, author);
    bookCount++;
    
    cout << "\nBook added successfully!" << endl;
}

// Display all books
void displayAllBooks(const LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        cout << "\nNo books in the library." << endl;
        return;
    }
    
    cout << "\n" << string(100, '=') << endl;
    cout << left << setw(10) << "ID"
         << setw(25) << "Title"
         << setw(20) << "Author"
         << setw(20) << "Borrower"
         << setw(10) << "Days"
         << setw(10) << "Overdue"
         << setw(10) << "Fine ($)" << endl;
    cout << string(100, '-') << endl;
    
    for (int i = 0; i < bookCount; i++) {
        books[i].displayBook();
    }
    cout << string(100, '=') << endl;
}

// Find book index by ID
int findBookIndex(const LibraryBook books[], int bookCount, int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            return i;
        }
    }
    return -1;
}

// Borrow a book
void borrowBookMenu(LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        cout << "\nNo books available in the library." << endl;
        return;
    }
    
    int id, days;
    string borrowerName;
    
    cout << "\n--- Borrow Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    
    int index = findBookIndex(books, bookCount, id);
    if (index == -1) {
        cout << "Book not found!" << endl;
        return;
    }
    
    if (books[index].getIsBorrowed()) {
        cout << "Book is already borrowed by " << books[index].getBorrowerName() << endl;
        return;
    }
    
    cin.ignore();
    cout << "Enter Borrower Name: ";
    getline(cin, borrowerName);
    cout << "Enter Number of Days to Borrow: ";
    cin >> days;
    
    if (days <= 0) {
        cout << "Invalid number of days!" << endl;
        return;
    }
    
    books[index].borrowBook(borrowerName, days);
}

// Return a book
void returnBookMenu(LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        cout << "\nNo books in the library." << endl;
        return;
    }
    
    int id;
    
    cout << "\n--- Return Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    
    int index = findBookIndex(books, bookCount, id);
    if (index == -1) {
        cout << "Book not found!" << endl;
        return;
    }
    
    if (!books[index].getIsBorrowed()) {
        cout << "Book is not currently borrowed." << endl;
        return;
    }
    
    books[index].returnBook();
}

// Search book by ID
void searchBookByID(const LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        cout << "\nNo books in the library." << endl;
        return;
    }
    
    int id;
    
    cout << "\n--- Search Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    
    int index = findBookIndex(books, bookCount, id);
    if (index == -1) {
        cout << "Book not found!" << endl;
        return;
    }
    
    cout << "\n" << string(100, '=') << endl;
    cout << left << setw(10) << "ID"
         << setw(25) << "Title"
         << setw(20) << "Author"
         << setw(20) << "Borrower"
         << setw(10) << "Days"
         << setw(10) << "Overdue"
         << setw(10) << "Fine ($)" << endl;
    cout << string(100, '-') << endl;
    books[index].displayBook();
    cout << string(100, '=') << endl;
}

// Display overdue books
void displayOverdueBooks(const LibraryBook books[], int bookCount) {
    bool found = false;
    
    cout << "\n--- Overdue Books ---" << endl;
    cout << string(100, '=') << endl;
    cout << left << setw(10) << "ID"
         << setw(25) << "Title"
         << setw(20) << "Author"
         << setw(20) << "Borrower"
         << setw(10) << "Days"
         << setw(10) << "Fine ($)" << endl;
    cout << string(100, '-') << endl;
    
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isOverdue()) {
            books[i].displayBook();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No overdue books found." << endl;
    }
    cout << string(100, '=') << endl;
}

// Calculate total fines
void calculateTotalFines(const LibraryBook books[], int bookCount) {
    double totalFines = 0.0;
    
    for (int i = 0; i < bookCount; i++) {
        totalFines += books[i].calculateFine();
    }
    
    cout << "\n--- Total Fines Summary ---" << endl;
    cout << "Total number of books: " << bookCount << endl;
    cout << "Total fines accumulated: $" << fixed << setprecision(2) << totalFines << endl;
}