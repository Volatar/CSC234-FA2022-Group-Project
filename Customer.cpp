#include <iostream>
#include "Customer.h"
#include "linkedList.h"
ostream& operator<<(ostream&, const Customer&) {}
Customer::Customer() {
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
        orders.insertLast(newOrder); 
}
void Customer::updateOrders(string title, int number) 
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
void Customer::cancelOrder(string title) 
{
    bool found = false;
    nodeType<Order>* location;

    SearchOrderList(title, found, location);

    if (found)
    {
        orders.deleteNode(location->info);
    }
    else
        cout << "Book not found." << endl;

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

}
bool Customer::operator==(const Customer& otherCustomer) const
{
    return (name == otherCustomer.name && address == otherCustomer.address && email == otherCustomer.email);
}
bool Customer::operator!=(const Customer& otherCustomer) const {
    return (name != otherCustomer.name || address != otherCustomer.address ||
        email != otherCustomer.email);
}
std::ostream& operator<<(std::ostream& osObject,
    const Customer& customerObject) {
    osObject << setw(20) << left << "Name: " << customerObject.name << "\n";
    osObject << setw(20) << left << "Address: " << customerObject.address << "\n";
    osObject << setw(20) << left << "Email: " << customerObject.email << "\n";
    return osObject;
}
void Customer::SearchOrderList(string title, bool& found, nodeType<Order>*& current) const
{
    found = false;
    while (current != nullptr && !found)
    {
        if (current->info.getTitle() == title)
            found = true;
        else
            current = current->link;
    }
}
