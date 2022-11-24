#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <iostream>
#include <fstream>
#include "Order.h"
#include <string>
#include "linkedList.h"

using namespace std;

class OrderList :public linkedListType<Order>
{
	friend ostream& operator<<(ostream&, const OrderList&);

public:
	void AddOrder(Order&);
	void UpdateOrder(string, int);
	void CancelOrder(string);
	double CalculateSubtotal();
	void UpdateDataFile(ofstream&);

private:
	void SearchOrderList(string title, bool& found, nodeType<Order>*& current) const;
};

#endif