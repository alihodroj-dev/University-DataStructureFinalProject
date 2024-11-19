#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

#include "Section.h"
using namespace std;

class Employee {
private:
    string username;
public:
    Employee(const string& username) {
        this->username = username;
    }

    void displayMenu(vector<Section> sections, LinkedList& employees, string& currentUsername) {
        int choice;
        cout << "-----Welcome EMPLOYEE " << username;
        do {
            cout << endl;
            cout << "1) View Sections" << endl;
            cout << "2) View Books" << endl;
            cout << "3) Change username" << endl;
            cout << "4) Change Password" << endl;
            cout << "5) Exit" << endl;
            cout << "Choice: ";
            cin >> choice;
            while (choice < 1 || choice > 5) {
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
                    changeUsername(employees, currentUsername);
                    break;
                case 4:
                    changePassword(employees, currentUsername);
                break;

            }
        } while(choice != 5);
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

    void changeUsername(LinkedList& employees, string& currentUsername) {
        string newUsername;
        int userPosition;
        cout << "New username: ";
        cin >> newUsername;
        for (int i = 0; i < employees.getUsers().size(); i++) {
            if (employees.getUsers()[i].getUsername() == currentUsername) {
                userPosition = i;
            }
        }

        User newUser = User(newUsername, employees.getUsers()[userPosition].getPassword());
        employees.deleteFromPosition(userPosition + 1);
        employees.insertAtEnd(newUser);
    }

    void changePassword(LinkedList& employees, string& currentPassword) {
        string newPassword;
        int userPosition;
        cout << "New password: ";
        cin >> newPassword;
        for (int i = 0; i < employees.getUsers().size(); i++) {
            if (employees.getUsers()[i].getPassword() == currentPassword) {
                userPosition = i;
            }
        }

        User newUser = User(employees.getUsers()[userPosition].getUsername(), newPassword);
        employees.deleteFromPosition(userPosition + 1);
        employees.insertAtEnd(newUser);
    }
};
#endif // EMPLOYEE_H
