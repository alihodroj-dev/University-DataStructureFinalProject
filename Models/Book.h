using namespace std;

class Book {
private:
    string bookName;
    string bookPrice = "0";
public:
    Book(string bookName) {
        this->bookName = bookName;
    }

    string getBookName() {
        return bookName;
    }

    void setBookName(string bookName) {
        this->bookName = bookName;
    }

    string getBookPrice() {
        return bookPrice;
    }

    void setBookPrice(string bookPrice) {
        this->bookPrice = bookPrice;
    }
};