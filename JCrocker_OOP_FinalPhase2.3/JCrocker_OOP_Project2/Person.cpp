#include "Person.h"
#include <sstream>



Person::Person()
{
}
Person::Person(string firstName, string lastName, int age, Address address) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age; // Validate ??
	this->address = address;
}


// get / set
void Person::setFirstName(string firstName) {
	this->firstName = firstName;
}
string Person::getFirstName() {
	return firstName;
}

void Person::setLastName(string lastName) {
	this->lastName = lastName;
}
string Person::getLastName() {
	return lastName;
}

void Person::setAge(int age) {
	this->age = age;
}
int Person::getAge() {
	return age;
}

void Person::setAddress(Address address) {
	this->address = address;
}
Address Person::getAddress() {
	return address;
}


// Print Method for the class!! Every class needs a print method!!
string Person::print() {
	stringstream s;
	// Use setprecision, and formatting with escape characters here
	s << firstName << " " << lastName << " age:" << age << endl;
	s << address.print(); //Go create this print method in the address class!!
	s << "\n";
	return s.str();

}








Person::~Person()
{
}
