#include <iostream>
#include <fstream>

#include "Section.h"
using namespace std;

class Owner {
private:
    string username;
    string password;
public:
    Owner(const string& username, const string& password) {
        this->username = username;
        this->password = password;
    }

    void displayMenu(vector<Section> &sections, LinkedList& employees) {
        int choice;
        cout << "-----Welcome OWNER " << username;
        do {
            cout << endl;
            cout << "1) View Sections" << endl;
            cout << "2) View Books" << endl;
            cout << "3) Add a new Section" << endl;
            cout << "4) Add a new Book" << endl;
            cout << "5) Edit a Section's name" << endl;
            cout << "6) Edit a Book" << endl;
            cout << "7) Delete a Section" << endl;
            cout << "8) Delete a Book" << endl;
            cout << "9) Add an Employee" << endl;
            cout << "10) Delete Employee" << endl;
            cout << "11) Change password" << endl;
            cout << "12) Change username" << endl;
            cout << "13) Exit" << endl;
            cout << "Choice: ";
            cin >> choice;
            while (choice < 1  || choice > 13) {
                cout << "Invalid choice, please try again." << endl;
                cout << "Choice: ";
                cin >> choice;
            }
            switch (choice) {
                case 1:
                    viewSections(sections);
                    break;
                case 2:
                    viewBooks(sections);
                    break;
                case 3:
                    addSection(sections);
                    break;
                case 4:
                    addBook(sections);
                    break;
                case 5:
                    editSectionName(sections);
                    break;
                case 6:
                    editBook(sections);
                    break;
                case 7:
                    deleteSection(sections);
                    break;
                case 8:
                    deleteBook(sections);
                    break;
                case 9:
                    addEmployee(employees);
                    break;
                case 10:
                    deleteEmployee(employees);
                    break;
                case 11:
                    changePassword();
                    break;
                case 12:
                    changeUsername();
                    break;

            }
        } while(choice != 13);
    }

    void viewSections(vector<Section> sections) {
        for (int i = 0; i < sections.size(); ++i) {
            cout << "" << i + 1 << ") " << sections[i].getName() << endl;
            for(Book book : sections[i].getBooks()) {
                cout << "---" << "NAME: " << "\"" << book.getBookName() << "\"" << " PRICE: " << "$" << book.getBookPrice() << endl;
            }
        }
    }

    void viewBooks(vector<Section> sections) {
        int sectionIndex;
        cout << "Which section's books would you like to view?" << endl;
        for (int i = 0; i < sections.size(); ++i) {
            cout << i + 1 << ") " << sections[i].getName() << endl;
        }

        cout << "Section number: ";
        cin >> sectionIndex;
        while (sectionIndex < 0 || sectionIndex > sections.size()) {
            cout << "Invalid selection, please try again." << endl;
            cout << "Section number: ";
            cin >> sectionIndex;
        }
        for(Book book : sections[sectionIndex - 1].getBooks()) {
            cout << "Name: " << book.getBookName() << " Price: $" << book.getBookPrice() << endl;
        }
    }

    void addSection(vector<Section>& sections) {
        Section newSection = Section("");
        vector<Book> newSectionBooks = vector<Book>();

        string sectionName;
        int numberOfBooks;

        cout << "---Enter Section Name: ";
        cin >> sectionName;

        while(sectionName.size() < 2) {
            cout << "Invalid Section Name, please try again." << endl;
            cout << "Section Name: ";
            cin >> sectionName;
        }

        newSection.setName(sectionName);

        cout << "Enter number of books: ";
        cin >> numberOfBooks;

        for (int i = 0; i < numberOfBooks; ++i) {
            string bookName;
            int bookPrice;
            cout << "Enter Book #" << i + 1 << " Name: ";
            cin >> bookName;
            cout << "Enter Book #" << i + 1 << " Price: ";
            cin >> bookPrice;
            while(bookPrice <= 0) {
                cout << "Invalid Book Price, please try again." << endl;
                cout << "Book Price: ";
                cin >> bookPrice;
            }
            Book newBook = Book(bookName);
            newBook.setBookPrice(std::to_string(bookPrice));
            newSectionBooks.push_back(newBook);
        }
        newSection.setBooks(newSectionBooks);
        sections.push_back(newSection);

    }

    void addBook(vector<Section>& sections) {
        string newBookName;
        int newBookPrice;
        int sectionIndex;

        cout << "To which Section do you want to add?" << endl;
        for (int i = 0; i < sections.size(); ++i) {
            cout << i + 1 << ") " << sections[i].getName() << endl;
        }
        cout << "Section Number: ";
        cin >> sectionIndex;

        while(sectionIndex < 0 || sectionIndex > sections.size()) {
            cout << "Invalid Section Number, please try again." << endl;
            cout << "Section Number: ";
            cin >> sectionIndex;
        }

        cout << "Enter book name: ";
        cin >> newBookName;
        cout << "Enter book price: ";
        cin >> newBookPrice;
        while(newBookPrice <= 0) {
            cout << "Invalid Book Price, please try again." << endl;
            cout << "Book Price: ";
            cin >> newBookPrice;
        }

        Book newBook = Book(newBookName);
        newBook.setBookPrice(std::to_string(newBookPrice));

        vector<Book> newSectionBooks = vector<Book>();

        for(Book book : sections[sectionIndex - 1].getBooks()) {
            newSectionBooks.push_back(book);
        }
        newSectionBooks.push_back(newBook);

        sections[sectionIndex - 1].setBooks(newSectionBooks);
    }

    void editSectionName(vector<Section>& sections) {
        string newSectionName;
        int sectionIndex;
        cout << "Which section's name do you want to edit?" << endl;
        for (int i = 0; i < sections.size(); ++i) {
            cout << i + 1 << ") " << sections[i].getName() << endl;
        }
        cout << "Section number: ";
        cin >> sectionIndex;
        while(sectionIndex < 0 || sectionIndex > sections.size()) {
            cout << "Invalid Section Number, please try again." << endl;
            cout << "Section Number: ";
            cin >> sectionIndex;
        }

        cout << "Enter new Section name: ";
        cin >> newSectionName;

        sections[sectionIndex - 1].setName(newSectionName);
    }

    void editBook(vector<Section>& sections) {
        int editChoice;
        int sectionIndex;
        int bookIndex;
        cout << "Inside which Section is the book you want to edit?" << endl;
        for (int i = 0; i < sections.size(); ++i) {
            cout << i + 1 << ") " << sections[i].getName() << endl;
        }
        cout << "Section number: ";
        cin >> sectionIndex;
        while(sectionIndex < 0 || sectionIndex > sections.size()) {
            cout << "Invalid Section Number, please try again." << endl;
            cout << "Section Number: ";
            cin >> sectionIndex;
        }

        cout << "Which book do you want to edit?" << endl;
        for (int i = 0; i < sections[sectionIndex - 1].getBooks().size(); ++i) {
            cout << i + 1 << ") " << sections[sectionIndex - 1].getBooks()[i].getBookName() << endl;
        }
        cout << "Book number: ";
        cin >> bookIndex;
        while(sectionIndex < 0 || sectionIndex > sections.size()) {
            cout << "Invalid Book Number, please try again." << endl;
            cout << "Book Number: ";
            cin >> bookIndex;
        }

        cout << "1) Edit name \n 2) Edit price" << endl;
        cout << "Choice: ";
        cin >> editChoice;
        while(editChoice < 1 || editChoice > 2) {
            cout << "Invalid Choice, please try again." << endl;
            cout << "Choice: ";
            cin >> editChoice;
        }

        vector<Book> newSectionBooks = sections[sectionIndex - 1].getBooks();

        if(editChoice == 1) {
            string newBookName;
            cout << "Enter new Book name: ";
            cin >> newBookName;
            newSectionBooks[bookIndex - 1].setBookName(newBookName);
            sections[sectionIndex - 1].setBooks(newSectionBooks);
        } else {
            int newBookPrice;
            cout << "Enter new Book price: ";
            cin >> newBookPrice;
            while(newBookPrice < 0) {
                cout << "Invalid Book Price, please try again." << endl;
                cout << "Book Price: ";
                cin >> newBookPrice;
            }

            newSectionBooks[bookIndex - 1].setBookPrice(std::to_string(newBookPrice));
            sections[sectionIndex - 1].setBooks(newSectionBooks);
        }
    }

    void deleteSection(vector<Section>& sections) {
        int sectionIndex;

        cout << "Which Section do you want to delete?" << endl;
        for (int i = 0; i < sections.size(); ++i) {
            cout << i + 1 << ") " << sections[i].getName() << endl;
        }

        cout << "Section number: ";
        cin >> sectionIndex;
        while(sectionIndex < 0 || sectionIndex > sections.size()) {
            cout << "Invalid Section Number, please try again." << endl;
            cout << "Section Number: ";
            cin >> sectionIndex;
        }

        sections.erase(sections.begin() + (sectionIndex - 1));
    }

    void deleteBook(vector<Section>& sections) {
        int sectionIndex;
        int bookIndex;
        cout << "Inside which Section is the book you want to delete?" << endl;
        for (int i = 0; i < sections.size(); ++i) {
            cout << i + 1 << ") " << sections[i].getName() << endl;
        }
        cout << "Section number: ";
        cin >> sectionIndex;
        while(sectionIndex < 0 || sectionIndex > sections.size()) {
            cout << "Invalid Section Number, please try again." << endl;
            cout << "Section Number: ";
            cin >> sectionIndex;
        }

        cout << "Which book do you want to delete?" << endl;
        for (int i = 0; i < sections[sectionIndex - 1].getBooks().size(); ++i) {
            cout << i + 1 << ") " << sections[sectionIndex - 1].getBooks()[i].getBookName() << endl;
        }
        cout << "Book number: ";
        cin >> bookIndex;
        while(sectionIndex < 0 || sectionIndex > sections.size()) {
            cout << "Invalid Book Number, please try again." << endl;
            cout << "Book Number: ";
            cin >> bookIndex;
        }

        vector<Book> newSectionBooks = sections[sectionIndex - 1].getBooks();
        newSectionBooks.erase(newSectionBooks.begin() + bookIndex - 1);
        sections[sectionIndex - 1].setBooks(newSectionBooks);
    }

    void addEmployee(LinkedList& employees) {
        string employeeUsername;
        string employeePassword;

        cout << "Enter employee's Username: ";
        cin >> employeeUsername;
        cout << "Enter employee's Password: ";
        cin >> employeePassword;

        User employeeUser = User(employeeUsername, employeePassword);
        employees.insertAtEnd(employeeUser);
    }

    void deleteEmployee(LinkedList& employees) {
        int employeeIndex;
        for (int i = 0; i < employees.getUsers().size(); ++i) {
            cout << i + 1 << ") " << employees.getUsers()[i].getUsername() << endl;
        }

        cout << "Which employee do you want to delete?" << endl;
        cout << "Employee's Number: ";
        cin >> employeeIndex;
        while(employeeIndex < 0 || employeeIndex > employees.getUsers().size()) {
            cout << "Invalid Employee Number, please try again." << endl;
            cout << "Employee Number: ";
            cin >> employeeIndex;
        }
        employees.deleteFromPosition(employeeIndex);
    }

    void changePassword() {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        ofstream file("../Users/owner.txt");
        file << username + ";" + newPassword;
    }

    void changeUsername() {
        string newUsername;
        cout << "Enter new username: ";
        cin >> newUsername;
        ofstream file("../Users/owner.txt");
        file << newUsername + ";" + password;
    }
};
