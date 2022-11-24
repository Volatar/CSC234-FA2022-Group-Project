#include "OrderList.h"
#include <iostream>
#include <fstream>
#include "Order.h"
#include <string>
#include "linkedList.h"

using namespace std;

ostream& operator<<(ostream& osObject, const OrderList& orderList)
{
	nodeType<Order>* current = orderList.first;

	while (current != nullptr)
	{
		osObject << current->info;
		current = current->link;
	}

	return osObject;
}

void OrderList::AddOrder(Order& order)
{
	bool found = false;
	nodeType<Order>* location;

	SearchOrderList(order.getTitle(), found, location);

	if (found)
		cout << "Book already in order." << endl;
	else
	{
		this->insertLast(order);
	}
}

void OrderList::UpdateOrder(string title, int number)
{
	bool found = false;
	nodeType<Order>* location;

	SearchOrderList(title, found, location);

	if (found)
	{
		location->info.setNumber(number);
	}
	else
		cout << "Book not found." << endl;
}

void OrderList::CancelOrder(string title)
{
	bool found = false;
	nodeType<Order>* location;

	SearchOrderList(title, found, location);

	if (found)
	{
		this->deleteNode(location->info);
	}
	else
		cout << "Book not found." << endl;
}

double OrderList::CalculateSubtotal()
{
	double subtotal = 0.0;

	nodeType<Order>* current = first;

	while (current != nullptr)
	{
		subtotal += current->info.getPrice() * current->info.getNumber();
		current = current->link;
	}
		
	
}

void OrderList::UpdateDataFile(ofstream& outFile)
{
	nodeType<Order>* current = first;

	while (current != nullptr)
	{
		outFile << current->info.getTitle() << endl;
		outFile << current->info.getPrice() << endl;
		outFile << current->info.getNumber() << endl;
		current = current->link;
	}
}

void OrderList::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{
	found = false;

	current = first;

	while (current != nullptr && !found)
	{
		if (current->info.getTitle() == title)
			found = true;
		else
			current = current->link;
	}
}
