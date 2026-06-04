#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    int year;
    bool isIssued;

public:
    Book();
    Book(int id, string title, string author, int year);

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    bool getIsIssued() const;

    void setTitle(const string& title);
    void setAuthor(const string& author);
    void setYear(int year);
    void issue();
    void returnBook();

    void display() const;

    string toFileString() const;
    static Book fromFileString(const string& line);

};

#endif