#include <iostream>
#include "Customer.h"
#include "linkedList.h"

using namespace std;

ostream& operator<<(ostream& osObject, const Customer& customer)
{
    osObject << setw(10) << left << "Name:";
    osObject << setw(50) << left << customer.name << endl;
    osObject << setw(10) << left << "Address:";
    osObject << setw(50) << left << customer.address << endl;
    osObject << setw(10) << left << "Email:";
    osObject << setw(50) << left << customer.email << endl << endl;
    osObject << "---------- Book Orders ---------- :" << endl;
    osObject << customer.orders;
    return osObject;
}

Customer::Customer() 
{
    name = "";
    address = "";
    email = "";
}

Customer::Customer(string customerName, string addr, string customerEmail,OrderList customerOrders)
{
    name = customerName;
    address = addr;
    email = customerEmail;
    orders = customerOrders;
}

OrderList Customer::getOrders()
{
    return orders;
}

void Customer::AddOrder(Order newOrder)
{
    orders.AddOrder(newOrder); 
}

void Customer::updateOrders(string title, int number) 
{
    orders.UpdateOrder(title, number);
}

void Customer::cancelOrder(string title) 
{
    orders.CancelOrder(title);
}

string Customer::getCustomerName()
{
    return name; 
}

string Customer::getAddress() 
{ 
    return address; 
}

string Customer::getEmail() 
{ 
    return email;
}

double Customer::checkoutOrders() 
{ 
    return orders.CalculateSubtotal();
}

bool Customer::operator==(const Customer& otherCustomer) const
{
    return (name == otherCustomer.name && address == otherCustomer.address && email == otherCustomer.email);
}

bool Customer::operator!=(const Customer& otherCustomer) const {
    return (name != otherCustomer.name || address != otherCustomer.address ||
        email != otherCustomer.email);
}

/*void Customer::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{
    found = false;
    while (current != nullptr && !found)
    {
        if (current->info.getTitle() == title)
            found = true;
        else
            current = current->link;
    }
}*/
