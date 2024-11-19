#ifndef SECTION_H
#define SECTION_H
#include "Book.h"
#include "LinkedList.h"
using namespace std;

class  Section {
private:
    string name;
    vector<Book> books = vector<Book>();

public:
    Section() = default;
    Section(const string &name) {
        this->name = name;
    };

    string getName() {
        return this->name;
    }

    vector<Book> getBooks() {
        return this->books;
    }

    void setBooks(const vector<Book> &books) {
        this->books = books;
    }

    void setName(const string &name) {
        this->name = name;
    }
};
#endif // SECTION_H
