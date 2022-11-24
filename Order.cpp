#include "Order.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ostream& operator<<(ostream& osObject, const Order& order)
{
	osObject << setw(20) << left << "Title:";
	osObject << setw(30) << right << order.bookTitle << endl;
	osObject << setw(20) << left << "Unit Price: $";
	osObject << setw(30) << right << fixed << setprecision(2) << order.unitPrice << endl;
	osObject << setw(20) << left << "Number:";
	osObject << setw(30) << right << setprecision(0) << order.number << endl;
	return osObject;
}

Order::Order()
{
	bookTitle = "";
	unitPrice = 0.0;
	number = 0;
}

Order::Order(string _title, double _price, int _number)
{
	bookTitle = _title;
	unitPrice = _price;
	number = _number;
}

bool Order::checkTitle(string name)
{
	if (name == bookTitle)
		return true;
	else
		return false;
}

double Order::CalculateCost()
{
	double cost = unitPrice * number;
	return cost;
}

void Order::setNumber(int _number)
{
	number = _number;
}

string Order::getTitle()
{
	return bookTitle;
}

double Order::getPrice()
{
	return unitPrice;
}

int Order::getNumber()
{
	return number;
}

bool Order::operator==(const Order& compare) const
{
	if (bookTitle == compare.bookTitle)
		return true;
	else
		return false;
}

bool Order::operator!=(const Order& compare) const
{
	if (bookTitle != compare.bookTitle)
		return true;
	else
		return false;
}
