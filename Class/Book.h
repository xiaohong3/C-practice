#include "../std_lib_facilities.h"

class Book {
private:
    string ISBN;
    string title;
    string author;
    bool checkedout;
    bool isValid();
public:
    Book(string isbn, string title, string author);
    void checkIn();
    void checkOut();
    bool isCheckedOut();
    string getISBN();
    string getTitle();
    string getAuthor();
};