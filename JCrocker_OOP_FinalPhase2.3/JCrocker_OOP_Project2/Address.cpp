#include "Address.h"
#include <sstream>


// Address Constructor Implementations
Address::Address()
{
}
Address::Address(string street, string city, string state, string zip) {
	this->street = street;
	this->city = city;
	this->state = state;
	setZip(zip);
}

//get / set - Method Implementations
void Address::setStreet(string street) {
	this->street = street;
}
string Address::getStreet() {
	return street;
}

void Address::setCity(string city) {
	this->city = city;
}
string Address::getCity() {
	return city;
}

void Address::setState(string state) {
	this->state = state;
}
string Address::getState() {
	return state;
}

void Address::setZip(string zip) {
	// validate a zip - use api call to validate zip code
	// 5 digits...
	// is (passes valid)
		this->zip = zip;
	// else
		//this-> = "0";
}
string Address::getZip() {
	return zip;
}

// Print Method for Address
string Address::print() {
	stringstream s;
	// Use setprecision, and formatting with escape characters here
	s << "\t" << street << "\n\t" << city << ", " << state << " " << zip;
	return s.str();
}





Address::~Address()
{
}
