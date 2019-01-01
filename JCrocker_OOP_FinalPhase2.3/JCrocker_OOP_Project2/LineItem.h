#pragma once
#include "Book.h"
#include "Customer.h"
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

//  LineItem Class
class LineItem
{

	// Public constructor headers
public:
	LineItem();
	LineItem(Book b, int q);

private:
	Book book;
	int quantity;
	double sale;
	double tax;
	double subtotal;
	double fee;
	double total;

private:
	void setSale();
	void setTax();
	void setSubtotal();
	void setFee(bool fiction, string genre);
	void setTotal();

public:
	double getSale();
	double getTax();
	double getSubtotal();
	int getQuantity();
	double getFee();
	double getTotal();
	Book getBook();
	string print();









	// Deconstructor
	~LineItem();
};

