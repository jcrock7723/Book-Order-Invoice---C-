#pragma once
#include <string>
using namespace std;

// Class book
class Book
{

	// Public Constructor Headers
public:
	Book();
	Book(string isbn, string title, string author, double price, char genre, char fiction);

	// Private Method Prototypes
private:
	string isbn;
	string title;
	string author;
	double price;

	// New
	string genre;
	bool isfiction;

	//private setters
	void setGenre(char g);
	void setIsFiction(char f);

	// Public Method Prototypes
public:
	string getGenre();
	bool getIsFiction();
	string getHeader();

	void setISBN(string isbn);
	string getISBN();

	void setTitle(string title);
	string getTitle();

	void setAuthor(string author);
	string getAuthor();

	void setPrice(double price);
	double getPrice();

	string print();

	string sprint();









	// Deconstructor Prototypes
	~Book();
};

