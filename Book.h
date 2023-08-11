#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <fstream>
using namespace std;

class Book{
public:
    Book();
    Book(const int y, const string t, const string l, const string f, const string g, const float r);
    Book(const Book & copy);
    ~Book();

    int getYear();
    string getTitle();
    string getLastName();
    string getFirstName();
    string getGenre();
    float getRating();

    void setYear(const int y);
    void setTitle(const string t);
    void setLastName(const string l);
    void setFirstName(const string f);
    void setGenre(const string g);
    void setRating(const float r);

    void print();



private:
    int year;
    string title;
    string lastName;
    string firstName;
    string genre;
    float rating;

};
#endif