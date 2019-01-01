/*/* Object Orientated Project - JCrocker - CSC 134 - Rebecca Halsey */

// Include statements
/*#include <iostream>
#include <string>
#include "Address.h"
#include "Person.h"
#include "Customer.h"
#include "Book.h"
#include <fstream>

using namespace std;


// Main function
void main() {

	// Declare variables
	string title, author, isbn, fileName = "Books.txt";
	double price;
	ifstream inputfile;
	const int NUM_BOOKS = 6;
	Book books[NUM_BOOKS];

	// Open the file
	inputfile.open(fileName);

	// Testing if opened correctly
	if (inputfile.fail()) {
		cout << "The file " << fileName << " failed to open." << endl;
		cout << "Please enter the location of the file: ";
		while (inputfile.fail()) {
			getline(cin, fileName);
			inputfile.open(fileName);
		}
	}

	// Declare increment variable
	int i = 0;

	// Loop data into overloaded constructor
	while (inputfile >> title >> author >> isbn >> price) {
		Book book1 = Book(isbn, author, title, price);
		//cout << book1.print() << endl; // Test print authors while added to array

		// Send to books array
		books[i] = { book1.getTitle(), book1.getAuthor(), book1.getISBN(), book1.getPrice() };
		
		// Increment
		i++;
	}


	// Print out the Author's to the console from the array
	for (int i = 0; i < NUM_BOOKS; i++) {
		cout << books[i].getAuthor() << endl;
	}
		
		



	



	/* Old Instatitation of Customers, books, addresses

	Address ad1 = Address();
	Address ad2 = Address("456 Spring Street", "Boone", "North Carolina", "28692");

	Customer cust1 = Customer();
	Customer cust2 = Customer("0723", "Jeremy", "Crocker", ad2);


	Book book1 = Book();
	Book book2 = Book("123123123", "Hemmingway", "Lame Byrd", 23.90);

	// setup address 1 object
	ad1.setStreet("123 Sesame Street");
	ad1.setCity("Greensboro");
	ad1.setState("North Carolina");
	ad1.setZip("27408");

	// Instantiate Person1 object using empty constructor
	Person p1 = Person();
	p1.setFirstName("Mickey");
	p1.setLastName("Mouse");
	p1.setAge(105);

	// Setup customer1 object
	cust1.setCustId("1215");
	cust1.setFirstName("Jim");
	cust1.setLastName("Beam");
	cust1.setAddress(ad1);

	// Setup book1 object
	book1.setISBN("983245276");
	book1.setAuthor("Jim Henson");
	book1.setTitle("Muppet Food");
	book1.setPrice(123.67);

	// Utilize customer print method
	cout << p1.print() << endl;
	cout << cust2.print() << book2.print() << endl;
	cout << cust1.print() << book1.print() << endl;
	
	// Utilize book print method
	cout << book1.print() << endl; */

	// Pause for user
	//system("pause");


//}
