#include "MyDataStore.h"
#include "Book.h"
#include "Customer.h"
#include <iomanip>

using namespace std;

int main() {


	// Instantiate two data objects using pointers
	MyDataStore* data1 = MyDataStore::GetInstance();
	//MyDataStore* data2 = MyDataStore::GetInstance();

	// Instantiate a books Array
	Book books[6];

	// Send array to getBooks
	MyDataStore::getBooks(books, 6);

	// Instatiate an array of lineitems
	//LineItem order[];

	// Loop through books Array and show authors
	//for (Book b : books) {
		//cout << b.getAuthor() << endl;
	//}

	// initiate a search variable
	string searchID;
	string choice;

	// Get info from user
	cout << "Please enter your customer ID: ";
	cin >> searchID;

	// Validate customer ID 
	// instatiate bool variable
	// If not found communicate to the client
	// Instatiate a Customer c object
	// A loop woud be nice to give more tries here
	bool customerFound;
	customerFound = MyDataStore::validateCustomer(searchID);
	if (customerFound == false) {
		cout << "Customer ID not valid. Please enter a valid ID" << endl;
		cout << endl;
		system("pause");
		return 0;
	}

	// If customer is found offer to show available books
	else if (customerFound == true) {
		cout << "Would you like to see our available books? \n(Enter 'Y' for yes) ";
		cin >> choice;
	}

	// Instatiate and retrieve the customer information for use if valid
	Customer c = MyDataStore::getCustomer(searchID);
	
	// If yes show books else exit the program gracefully
	if (choice == "y" || choice == "Y") {

		// Show customer available books
		// Call header
		cout << endl;
		Book h;
		cout << h.getHeader();

		// Call to show all books available and accumulate number for choice
		int i = 1;
		// Call books
		for (Book b : books) {
			cout << i << ". " << b.sprint() << endl;
			i++;
		}
		system("pause");
	}

	// Any choice but yes exits
	else {
		cout << "\nOK, GOODBYE\n" << endl;
		system("pause");
		return 0;
	}
	
	// Ask customer how many different books they would like to order
	// Ask customer which book they would like to order
	// Limit them to three books but unlimited qty of each
	/*int number;
	cout << "How many titles would you like to order?: ";
	cin >> number;

	LineItem order[number];

	for (int i = 1; i <= number; i++) {
		int boc = 0;
		int qty = 0;

		// Get the order information from the customer
		cout << "Please enter the number of the book you would like to order: ";
		cin >> boc;
		cout << "How many of this book would you like to order: ";
		cin >> qty;
		cout << endl << endl;

		// Instatiate first line item object
		// Create and Array for the line item objects
		LineItem line1 = LineItem(books[boc - 1], qty);
		LineItem order[3];
		order[0] = line1;
	}*/

	// Designate the order quantity
	cout << "				Your Order Quantity = 3\n\n";

	// Instatiate book of choice and quantity variables
	int boc = 0;
	int quantity1 = 0;
	int quantity2 = 0;
	int quantity3 = 0;

	// Get the order information from the customer
	cout << "Please enter the number of the first book you would like to order: ";
	cin >> boc;
	cout << "How many of this book would you like to order: ";
	cin >> quantity1;
	cout << endl << endl;

	// Instatiate first line item object
	// Create and Array for the line item objects
	LineItem line1 = LineItem(books[boc-1], quantity1);
	LineItem order[3];
	order[0] = line1;

	// Get second line item
	cout << "Please enter the number of the next book you would like to order: ";
	cin >> boc;
	cout << "How many of this book would you like to order: ";
	cin >> quantity2;
	cout << endl << endl;

	LineItem line2 = LineItem(books[boc-1], quantity2);
	order[1] = line2;

	// Get third line item
	cout << "Please enter the number of the final book you would like to order: ";
	cin >> boc;
	cout << "How many of this book would you like to order: ";
	cin >> quantity3;
	cout << endl << endl;

	LineItem line3 = LineItem(books[boc-1], quantity3);
	order[2] = line3;

	// Send customer info and array to print invoice 
	MyDataStore::printInvoice(c, order);

	// Pause to communicate
	cout << "Thank you for your order! Your invoice has been printed.\n";
	cout << "It is located in the file with this program, named 'invoice.txt'." << endl << endl;

	// Pause then end program
	system("pause");
	return 0;

}