#include "./Book.h"
#include "../std_lib_facilities.h"

Book::Book(string isbn, string t, string a)
    : ISBN(isbn), title(t), author(a) {
        if (!isValid()) {
            error("Invalid book entry.");
        }
    }

bool Book::isValid() {
    regex validISBN("^\d-\d-\d-[a-zA-Z0-9]$");
    if (regex_match(ISBN, validISBN)) {
        return true;
    }
    return false;
}

void Book::checkIn() {
    if (checkedout) {
        checkedout = false;
    }
}

void Book::checkOut() {
    if (!checkedout) {
        checkedout = true;
    }
}

bool Book::isCheckedOut() {
    return checkedout;
}

string Book::getISBN() {
    return ISBN;
}

string Book::getAuthor() {
    return author;
}

string Book::getTitle() {
    return title;
}