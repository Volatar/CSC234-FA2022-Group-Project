#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "linkedList.h"
#include "Order.h"
#include "OrderList.h"
#include <iomanip>
#include <iostream>
#include <string>

class Customer {
	friend ostream& operator<<(ostream&, const Customer&);

private:
	string name;
	string address;
	string email;
	OrderList orders;
	void SearchOrderList(string title, bool& found, nodeType<Order>*& current) const;

public:
	Customer();
	Customer(string, string, string, OrderList);
	OrderList getOrders();
	void AddOrder(Order);
	void updateOrders(string, int);
	void cancelOrder(string);
	string getCustomerName();
	string getAddress();
	string getEmail();
	void setCustomedetails(string,string,string);
	double checkoutOrders();
	bool operator==(const Customer&) const;
	bool operator!=(const Customer&) const;
};
#endif
