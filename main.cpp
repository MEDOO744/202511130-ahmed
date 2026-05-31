#include <iostream>
#include "Functions.h"

using namespace std;

int main() {
    LibraryBook books[MAX_BOOKS];
    int bookCount = 0;
    int choice;
    
    cout << "\n========================================" << endl;
    cout << "   KIGALI INDEPENDENT UNIVERSITY" << endl;
    cout << "   LIBRARY BOOK BORROWING SYSTEM" << endl;
    cout << "========================================" << endl;
    
    do {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Borrow Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Search Book by ID" << endl;
        cout << "6. Display Overdue Books" << endl;
        cout << "7. Calculate Total Fines" << endl;
        cout << "8. Exit" << endl;
        cout << "================================" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addBook(books, bookCount);
                break;
            case 2:
                displayAllBooks(books, bookCount);
                break;
            case 3:
                borrowBookMenu(books, bookCount);
                break;
            case 4:
                returnBookMenu(books, bookCount);
                break;
            case 5:
                searchBookByID(books, bookCount);
                break;
            case 6:
                displayOverdueBooks(books, bookCount);
                break;
            case 7:
                calculateTotalFines(books, bookCount);
                break;
            case 8:
                cout << "\nExiting system. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 8." << endl;
        }
    } while (choice != 8);
    
    return 0;
}