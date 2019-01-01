#include "LineItem.h"
#include "Book.h"
#include "Customer.h"
#include <sstream>
#include <string>
#include <iomanip>



LineItem::LineItem()
{
}

LineItem::LineItem(Book b, int q)
{
	this->book = b;
	this->quantity = q;
	setSale();
	setTax();
	setSubtotal();
	setFee(book.getIsFiction(), book.getGenre());
	setTotal();

}

void LineItem::setSale() {
	this->sale = book.getPrice()*quantity;
}

double LineItem::getSale() {
	return sale;
}

void LineItem::setTax() {
	this->tax = sale*.07;
}

double LineItem::getTax() {
	return tax;
}

void LineItem::setSubtotal() {
	this->subtotal = sale+tax;
}

double LineItem::getSubtotal() {
	return subtotal;
}

void LineItem::setFee(bool fiction, string genre) {
	if (fiction == false && genre == "Romance")
		this->fee =  0;
	else if (quantity > 20)
		this->fee = 50;
	else if (quantity > 14)
		this->fee = 40;
	else if (quantity > 9)
		this->fee = 30;
	else if (quantity > 4)
		this->fee = 20;
	else
		this->fee = 10;
}

double LineItem::getFee() {
	return fee;
}

int LineItem::getQuantity() {
	return quantity;
}

void LineItem::setTotal() {
	this->total = subtotal+fee;
}

double LineItem::getTotal() {
	return total;
}

Book LineItem::getBook() {
	return book;
}

string LineItem::print() {
	stringstream ss;
	ss << "\n________________________________________________________________________\n";
	ss << book.sprint() << endl;
	ss << "	Order Quantity: " << quantity << " @ $" << fixed << setprecision(2) << book.getPrice();
	ss << "\t\tTotal: $" << fixed << setprecision(2) << sale << endl << endl;
	ss << setw(25) << left << "Total Book Sales: " << setw(10) << right << fixed << setprecision(2)<< sale << endl;
	ss << setw(25) << left << "Tax: " << setw(10) << right << fixed << setprecision(2) << tax  << endl;
	ss << setw(25) << left << "Subtotal: " << setw(10) << right << fixed << setprecision(2) << subtotal << endl;
	ss << setw(25) << left << "Extra Fee: " << setw(10) << right << fixed << setprecision(2) << fee << endl;
	ss << setw(25) << left << "Total Book Sales: " << setw(10) << right << fixed << setprecision(2) << total << endl << endl;
	return ss.str();
}



LineItem::~LineItem()
{
}
