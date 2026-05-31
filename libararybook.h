#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>
#include <iostream>
using namespace std;

class LibraryBook {
private:
    int bookID;
    string title;
    string author;
    string borrowerName;
    int daysBorrowed;
    bool isBorrowed;
    
public:
    // Constructors
    LibraryBook();
    LibraryBook(int id, string t, string a);
    
    // Destructor
    ~LibraryBook();
    
    // Getters
    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getBorrowerName() const;
    int getDaysBorrowed() const;
    bool getIsBorrowed() const;
    
    // Setters
    void setBookID(int id);
    void setTitle(string t);
    void setAuthor(string a);
    void setBorrowerName(string name);
    void setDaysBorrowed(int days);
    void setIsBorrowed(bool status);
    
    // Additional methods
    void borrowBook(string borrower, int days);
    void returnBook();
    double calculateFine() const;
    bool isOverdue() const;
    void displayBook() const;
};

#endif