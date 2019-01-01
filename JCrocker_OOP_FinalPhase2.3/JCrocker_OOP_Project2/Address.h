#pragma once
#include <string>
using namespace std;

// Address Class
class Address
{
	
	// Address Constructor Headers
public:
	Address();
	Address(string street, string city, string state, string zip);

	// Private Method Prototypes
private:
	string street;
	string city;
	string state;
	string zip;

	// Public Method Prototypes
public:
	void setStreet(string street);
	string getStreet();

	void setCity(string city);
	string getCity();

	void setState(string state);
	string getState();

	void setZip(string zip);
	string getZip();

	string print();








	~Address();
};

