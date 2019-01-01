#include "Customer.h"
#include <sstream>


// Customer Constructor Implementations
Customer::Customer()
{
}
Customer::Customer(string custID, string firstName, string lastName, Address address) {
	this->custID = custID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;
}

// Get / Set - Method Implementations
void Customer::setFirstName(string firstName) {
	this->firstName = firstName;
}
string Customer::getFirstName() {
	return firstName;
}

void Customer::setLastName(string lastName) {
	this->lastName = lastName;
}
string Customer::getLastName() {
	return lastName;
}

void Customer::setCustId(string custID) {
	this->custID = custID;
}
string Customer::getCustID() {
	return custID;
}

void Customer::setAddress(Address address) {
	this->address = address;
}
Address Customer::getAddress() {
	return address;
}

// Customer Print Implementations
string Customer::print() {

	// Inititate StringStream Variable
	stringstream s;
	s << endl;
	s <<  "\t" << firstName << " " << lastName << " ID#: " << custID << endl;
	s <<  address.print();
	return s.str();
}



// Deconstructor Implementations
Customer::~Customer()
{
}
