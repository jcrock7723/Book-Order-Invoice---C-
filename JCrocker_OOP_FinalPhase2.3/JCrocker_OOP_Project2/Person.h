#pragma once
#include <string>
#include "Address.h"

using namespace std;

class Person
{
public:
	Person();
	Person(string firstName, string lastName, int age, Address address);

private:
	string firstName;
	string lastName;
	int age;
	Address address;

public:
	void setFirstName(string firstName);
	string getFirstName();

	void setLastName(string lastName);
	string getLastName();

	void setAge(int age);
	int getAge();

	void setAddress(Address address);
	Address getAddress();

	string print();










	~Person();
};

