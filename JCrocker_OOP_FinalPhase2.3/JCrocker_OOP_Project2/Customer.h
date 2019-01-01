#pragma once
#include <string>
#include "Address.h"
using namespace std;

// Customer Class
class Customer
{

	// Customer Constructor Headers
public:
	Customer();
	Customer(string custID, string firstName, string lastName, Address address);

	// Private Methods
private:
	string custID;
	string firstName;
	string lastName;
	Address address;

	// Private Method Prototypes
public:
	void setFirstName(string firstName);
	string getFirstName();

	void setLastName(string lastName);
	string getLastName();

	void setCustId(string custID);
	string getCustID();

	void setAddress(Address address);
	Address getAddress();

	string print();








	~Customer();
};

