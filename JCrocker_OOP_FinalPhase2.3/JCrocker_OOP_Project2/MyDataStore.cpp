#include "MyDataStore.h"
#include "Customer.h"
#include "Address.h"
#include "Book.h"
#include "LineItem.h"
#include <fstream>
#include <iostream>
#include <sstream>


// Declare a pointer
MyDataStore* MyDataStore::iInstance;

// Declare customer Array
Customer customer[5];

// Customer list Prototype
void getCustomerList(Customer[], int);

// Implement Private MyDataStore Constructor 
MyDataStore::MyDataStore()
{
	//cout << "In Constructor...." << endl;
	getCustomerList(customer, 5);
}

// Implement Public GetInstance Method
MyDataStore* MyDataStore::GetInstance() {

	// If pointer is Null create a new instance
	if (iInstance == NULL) {
		iInstance = new MyDataStore();
	}
	
	// If not Null return the Instance
	return iInstance;
}

// Recieve books Array from constructor
// Read data from a file into book object
// Fill the Array with the data
void MyDataStore::getBooks(Book books[], int size) {
	ifstream input;
	input.open("Book.txt");
	string isbn, title, author;
	char genre, fiction;
	double price = 0.0;

	// Array indexer i
	int i = 0;

	// Read the data into variables
	while (!input.eof()) {
		input >> title;
		input >> author;
		input >> isbn;
		input >> price;
		input >> genre;
		input >> fiction;
		


		// Instatiate a book using overloaded constructor
		Book b = Book(isbn, title, author, price, genre, fiction);

		// Loop book info to an Array
		if (i < size) {
			books[i] = b;
			i++;
		}
	}
	input.close();

}

Customer MyDataStore::getCustomer(string custID) {
	// Search Customer Array for customer ID, instatiate customer if found
	// return the customer...
	for (Customer c : customer) {
		if (c.getCustID() == custID)
			return c;
	}
}

// Validate customer ID using Boolean variable
bool MyDataStore::validateCustomer(string searchID) {
	for (Customer c : customer) {
		if (c.getCustID() == searchID)
			return true;
	}
	for (Customer c : customer) {
		if (c.getCustID() != searchID)
			return false;
	}
	
}

// Print customer invoice
void MyDataStore::printInvoice(Customer c, LineItem order[3]) {
	ofstream outfile;
	double grandTotal = 0.0;
	outfile.open("invoice.txt");

	/* Testing Output to console
	cout << "anything?";
	cout << order[1].getSale();
	cout << order[2].getSale();
	cout << c.print();

	// Invoice Header
	cout << "________________________________________________________________________\n";
	cout << "			    Customer Invoice" << endl;
	cout << "________________________________________________________________________\n";

	// Print Customer information
	cout << "Customer Info: " << c.print() << endl;

	// Print line Items
	for (int i = 0; i <= 2; i++) {
		grandTotal += order[i].getTotal();
		cout << order[i].print();
	}

	// Acumulate and print out the grand total
	cout << "\n____________________________________________\n";
	cout << "*****GRAND TOTAL:	$" << fixed << setprecision(2) << grandTotal << endl;
	cout << endl;*/

	// Printing the invoice to file
	// Invoice Header
	outfile << "________________________________________________________________________\n";
	outfile << "			    Customer Invoice" << endl;
	outfile << "________________________________________________________________________\n";

	// Print Customer information
	outfile << "Customer Info: \n" << c.print() << endl;

	// Print line Items
	for (int i = 0; i <= 2; i++) {
		grandTotal += order[i].getTotal();
		outfile << order[i].print();
	}

	// Acumulate and print out the grand total
	outfile << "\n____________________________________________\n";
	outfile << "*****GRAND TOTAL:	$" << fixed << setprecision(2) << grandTotal << endl;
	outfile << endl << endl;
	outfile << "________________________________________________________________________\n";
	outfile << "			    Thank You!" << endl;
	outfile << "________________________________________________________________________\n";

	outfile.close();
}

// Get customer list method
void getCustomerList(Customer cus[], int size) {
	// Load Customer Array
	ifstream inputC;
	inputC.open("Customer.txt");
	string custID;
	string firstName;
	string lastName;
	string street, city, state, zip;
	Address ad1;

	// Array indexer i
	int i = 0;

	// Read the data into variables
	while (!inputC.eof()) {
		inputC >> custID;
		inputC >> firstName;
		inputC >> lastName;
		inputC >> street;
		inputC >> city;
		inputC >> state;
		inputC >> zip;

		// Instatiate an Address object using overloaded constructor
		Address ad1 = Address(street, city, state, zip);

		// Instatiate a Customer object using overloaded constructor
		Customer c = Customer(custID, firstName, lastName, ad1);

		// Loop Customer info to an Array
		if (i < size) {
			cus[i] = c;
			i++;
		}
	}
	inputC.close();
}







MyDataStore::~MyDataStore()
{
}
