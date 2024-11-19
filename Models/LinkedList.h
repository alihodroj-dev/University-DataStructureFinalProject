#include <iostream>
using namespace std;

class User {
    string username;
    string password;
    public:
    User() = default;
    User(const string &username, const string &password) {
        this->username = username;
        this->password = password;
    }
    string getUsername() {
        return this->username;
    }
    string getPassword() {
        return this->password;
    }
    void setUsername(const string &username) {
        this->username = username;
    }
    void setPassword(const string &password) {
        this->password = password;
    }
};

struct Node {
    User data;
    Node* next;
};

class LinkedList {
    Node* head{};

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(const User &value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(const User &value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(const User& value, const int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        // Traverse to the node before the desired position
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromPosition(const int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        // Save the node to be deleted
        Node* nodeToDelete = temp->next;
        // Update the next pointer
        temp->next = temp->next->next;
         // Delete the node
        delete nodeToDelete;
    }

    vector<User> getUsers() {
        vector<User> users = vector<User>();
        Node* temp = head;
        while (temp) {
            users.push_back(temp->data);
            temp = temp->next;
        }
        return users;
    }
};