#include <iostream>
#include <string>

#include "Models/Owner.h"
#include "Models/Employee.h"
#include "Helpers/ReadWrite.h"
using namespace std;

void displayAuthMenu(bool& isOwner, string& currentUsername, string& currentPassword) {
    string username, password;
    bool didFindUser = false;

    cout << "-----Bookshop Management System-----" << endl;

    while (!didFindUser) {
        cout << "-----Login-----" << endl;
        cout << "USERNAME: ";
        cin >> username;
        // error handling
        while(username.empty()) {
            cout << "Invalid username!" << endl << "USERNAME: ";
            cin >> username;
        }
        cout << "PASSWORD: ";
        cin >> password;

        // error handling
        while (password.empty()) {
            cout << "Invalid password!" << endl << "PASSWORD: ";
            cin >> password;
        }

        // check if owner
        auto owners = ReadWrite::readFile("../Users/owner.txt");
        for (const auto& user : owners) {
            auto splitLine = ReadWrite::split(user, ';');
            if(splitLine[0] == username && splitLine[1] == password) {
                didFindUser = true;
                isOwner = true;
                currentUsername = splitLine[0];
                currentPassword = splitLine[1];
            }
        }

        // check if employee
        auto employees = ReadWrite::readFile("../Users/employees.txt");
        for (const auto& employee : employees) {
            auto splitLine = ReadWrite::split(employee, ';');
            if(splitLine[0] == username && splitLine[1] == password) {
                didFindUser = true;
                isOwner = false;
                currentUsername = splitLine[0];
                currentPassword = splitLine[1];
            }
        }
        if (!didFindUser) {
            cout << "-----USER NOT FOUND-----" << endl;
        }
    }
}

int main() {
    // app variables
    bool isOwner;
    string currentUsername;
    string currentPassword;
    vector<Section> sections = ReadWrite::loadData();
    LinkedList employees = ReadWrite::loadEmployees();

    displayAuthMenu(isOwner, currentUsername, currentPassword);

    if(!currentUsername.empty()) {
        if(isOwner) {
            Owner owner = Owner(currentUsername, currentPassword);
            owner.displayMenu(sections, employees);
        } else {
            Employee employee = Employee(currentUsername);
            employee.displayMenu(sections, employees, currentUsername);
        }
    }

    // saving data
    ReadWrite::saveData(sections);
    ReadWrite::saveEmployees(employees);
    return 0;
}