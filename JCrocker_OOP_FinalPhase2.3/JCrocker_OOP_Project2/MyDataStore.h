#pragma once
#include <iostream>
#include <sstream>
#include "Book.h"
#include "Customer.h"
#include "LineItem.h"

using namespace std;

// Singleton class
class MyDataStore {

private:
	// private static pointer to instance
	static MyDataStore* iInstance;

public:
	// Public Methods - getters
	static MyDataStore* GetInstance();
	static void getBooks(Book books[], int size);
	static Customer getCustomer(string custID);
	static bool validateCustomer(string searchID);
	static void printInvoice(Customer c, LineItem order[3]);

	

private:
	// Private Constructor
	MyDataStore();








	~MyDataStore();
};

