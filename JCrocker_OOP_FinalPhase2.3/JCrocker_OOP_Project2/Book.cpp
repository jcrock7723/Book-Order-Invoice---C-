#include "Book.h"
#include <sstream>
#include <iomanip>


// Constructor Implementations
Book::Book()
{
}
Book::Book(string isbn, string author, string title, double price, char g, char f) {
	
	// Get length of isbn input from user
	int size = isbn.length();
	// Input validation within the constructor
	if (size != 9 && size != 13)
		this->isbn = "00-000-00";
	else
		this->isbn = isbn;
	this->title = title;
	this->author = author;
	
	// Price Validation
	if (price < 1 || price>200)
		price = 0;
	else
		this->price = price;
	
	// setting genre
	if (g == 'R')
		this->genre = "Romance";
	else if (g == 'D')
		this->genre = "Drama";
	else if (g == 'M')
		this->genre = "Mystery";
	else
		this->genre = "NA";
	
	// setting isfiction
	if (f == 'N')
		this->isfiction = false;
	else
		this->isfiction = true;
	

}

// Get / set - Method Implementations
void Book::setISBN(string isbn) {
	int size = isbn.length();
	// Input validation within the constructor
	if (size != 9 && size != 13)
		this->isbn = "00-000-00";
	else
		this->isbn = isbn;
	//this->isbn = isbn;
}

string Book::getISBN() {
	return isbn;
}

void Book::setAuthor(string author) {
	this->author = author;
}
string Book::getAuthor() {
	return author;
}

void Book::setTitle(string title) {
	this->title = title;
}
string Book::getTitle() {
	return title;
}

void Book::setPrice(double price) {

	// Price Validation
	if (price < 1 || price>200)
		price = 0;
	else
		this->price = price;
}

double Book::getPrice() {
	return price;
}

void Book::setGenre(char g) {
	if (g == 'R')
		this->genre = "Romance";
	else if (g == 'D')
		this->genre = "Drama";
	else if (g == 'M')
		this->genre = "Mystery";
	else
		this->genre = "NA";
}

string Book::getGenre() {
	return genre;
}

void Book::setIsFiction(char f) {
	if (f == 'N')
		isfiction = false;
	else
		isfiction = true;
}

bool Book::getIsFiction() {
	return isfiction;
}

// Header Method
string Book::getHeader() {
	stringstream ss;
	ss << "                      Currently Available Books:\n\n";
	ss << fixed << setw(10) << "Author";
	ss << fixed << setw(21) << "Title";
	ss << fixed << setw(15) << "Genre";
	ss << fixed << setw(12) << "Fiction";
	ss << fixed << setw(11) << "Price" << endl;
	ss << "____________________________________________________________________\n";
	return ss.str();
}


// Book Print function
string Book::print() {
	stringstream s;
	s << "ISBN: " << isbn << endl;
	s << "Author: " << author << endl;
	s << "Title: " << title << endl;
	s << "Price: $" << fixed << setprecision(2) << price << endl;
	return s.str();
}

// Updated Print method
string Book::sprint() {
	string fict;
	if (isfiction == true)
		fict = "Fiction";
	else if (isfiction == false)
		fict = "Non-Fiction";
	stringstream ss;
	ss << left << setw(18) << title << left << setw(20) << author;
	ss << left << setw(10) << genre << left << setw(13) << fict;
	ss << right << fixed << setprecision(2) << "$" << price << endl;
	return ss.str();
}

Book::~Book()
{
}
