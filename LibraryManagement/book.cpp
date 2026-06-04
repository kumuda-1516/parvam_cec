#include "Book.h"
#include <sstream>
#include <iomanip>
using namespace std;

Book::Book() : id(0), title("N/A"), author("N/A"), year(0), isIssued(false) {}

Book::Book(int id, string t, string a, int y)
    : id(id), title(t), author(a), year(y), isIssued(false) {}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
bool Book::getIsIssued() const { return isIssued; }

void Book::setTitle(const string& t) { 
    title = t; 
}

void Book::setAuthor(const string& a) { 
    author = a; 
}

void Book::setYear(int y){
    if (y < 0 || y > 2025) {
        throw invalid_argument("Invalid year!");
    }

    year = y;
}

void Book::issue() {
    if (isIssued) {
        throw runtime_error("Book is already issued!");
    }
    isIssued = true;
}

void Book::returnBook() {
    if (!isIssued) {
        throw runtime_error("Book was not issued!");
    }

    isIssued = false;
}

void Book::display() const {
    cout << left << setw(5) << id
         << setw(30) << title
         << setw(20) << author
         << setw(10) << year
         << setw(10) << (isIssued ? "Issued" : "Available") << endl;

}

string Book::toFileString() const {
    return to_string(id) + "|" + title + "|" + author + "|" +
           to_string(year) + "|" + (isIssued ? "1" : "0");
}

Book Book::fromFileString(const string& line) {
    stringstream ss(line);
    string token;

    getline(ss, token, '|');int id = stoi(token);

    getline(ss, token, '|');string title = token;

    getline(ss, token, '|');string author = token;

    getline(ss, token, '|');int year = stoi(token);

    getline(ss, token, '|');bool isIssued = (token == "1");

    Book book(id, title, author, year);
    if (isIssued)book.issue();
    return book;
}
