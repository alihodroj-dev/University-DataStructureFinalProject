#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "../Models/Section.h"

using namespace std;

class ReadWrite {
public:
    ReadWrite() = default;
    static vector<string> readFile(const string& fileName) {
        // var to return containing all lines
        auto allLines = vector<string>();
        // opening file
        ifstream file;
        file.open(fileName);
        // var to store each line
        string line;
        // looping over lines in the file
        while(getline(file, line)) {
            allLines.push_back(line);
        }
        file.close();
        return allLines;
    }

    static void writeFile(const string& fileName, const vector<string>& lines) {
        // opening file
        ofstream file(fileName);
        // looping over lines
        for(auto& line : lines) {
            // writing each line to the file;
            file << line << endl;
        }
    }

    static vector<std::string> split (const string &s, const char delim) {
        vector<std::string> result;
        stringstream ss (s);
        string item;
        while (getline (ss, item, delim)) {
            result.push_back (item);
        }
        return result;
    }

    static vector<Section> loadData() {
        vector<Section> returnValue = vector<Section>();
        vector<string> sectionsFromFile = readFile("../Data/Sections.txt");

        for(string section: sectionsFromFile) {
            vector<string> splitLine = split(section, ';');
            Section newSection = Section(splitLine[0]);
            vector<Book> newSectionBooks = vector<Book>();
            for(int i = 1; i < splitLine.size(); i++) {
                Book newBook = Book(splitLine[i]);
                newBook.setBookPrice(splitLine[i+1]);
                newSectionBooks.push_back(newBook);
                i++;
            }
            newSection.setBooks(newSectionBooks);
            returnValue.push_back(newSection);
        }
        return returnValue;
    }

    static void saveData(vector<Section>& sections) {
        vector<string> lines = vector<string>();
        for(auto& section : sections) {
            string line;
            line += section.getName() + ";";
            for(Book book : section.getBooks()) {
                line += book.getBookName() + ";" + book.getBookPrice() + ";";
            }
            lines.push_back(line);
        }
        writeFile("../Data/Sections.txt", lines);
    }

    static LinkedList loadEmployees() {
        LinkedList returnValue = LinkedList();
        for(const string& line : readFile("../Users/employees.txt")) {
            vector<string> splitLine = split(line, ';');
            User employee = User(splitLine[0], splitLine[1]);
            returnValue.insertAtEnd(employee);
        }
        return returnValue;
    }

    static void saveEmployees(LinkedList& employees) {
        vector<string> lines = vector<string>();
        for(User employee : employees.getUsers()) {
            lines.push_back(employee.getUsername() + ";" + employee.getPassword());
        }
        writeFile("../Users/employees.txt", lines);
    }
};
