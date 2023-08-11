#include "Book.h"

Book::Book(){
    year = 9999;
    title = "null";
    firstName = "null";
    lastName = "null";
    genre = "null";
    rating = 999.999;
}
Book::Book(const int y, const string t, const string l, const string f, const string g, const float r){
    year = y;
    title = t;
    lastName = l;
    firstName = f;
    genre = g;
    rating = r;
}
Book::Book(const Book & copy){
    year = copy.year;
    title = copy.title;
    lastName = copy.lastName;
    firstName = copy.firstName;
    genre = copy.genre;
    rating = copy.rating;
}
Book::~Book(){

}
int Book::getYear(){
    return year;
}
string Book::getTitle(){
    return title;
}
string Book::getLastName(){
    return lastName;
}
string Book::getFirstName(){
    return firstName;
}
string Book::getGenre(){
    return genre;
}
float Book::getRating(){
    return rating;
}
void Book::setYear(const int y){
    year = y;
}
void Book::setTitle(const string t){
    title = t;
}
void Book::setLastName(const string l){
    lastName = l;
}
void Book::setFirstName(const string f){
    firstName = f;
}
void Book::setGenre(const string g){
    genre = g;
}
void Book::setRating(const float r){
    rating = r;
}

void Book::print(){
    cout<< year << "," << title << "," << lastName << "," << firstName << "," << genre << "," << rating << endl;
}

