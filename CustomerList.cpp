#include "customerList.h"
#include "linkedList.h"

using namespace std;

ostream& operator<<(ostream& osObject, const CustomerList& customerList)
{
	nodeType<Customer>* current = customerList.first;

	while (current != nullptr)
	{
		osObject << current->info;
		current = current->link;
	}

	return osObject;
}

void CustomerList::AddCustomer(Customer& newCustomer) 
{
	bool found = false;
	nodeType<Order>* location;
	SearchCustomerByName(newCustomer.getCustomerName());
	if (found)
		cout << "Customer already in CustomerList." << endl;
	else
	{
		this->insertLast(newCustomer);
	}

}
bool CustomerList::SearchCustomerByName(string customerName) const
{
	nodeType<Customer>* current;
	bool found = false;
	current = first;

	while (current != nullptr && !found)
	{
		if (current->info.getCustomerName() == customerName)
			found = true;
		else
			current = current->link;
	}
}
Customer getCustomerByName(string customerName)
{   
	//need some work and rethink the logic 
	Customer newCustomer;
	nodeType<Customer>* location;
	if (location->info.getCustomerName() == customerName)
	{
		return newCustomer;
	}
}
void CustomerList::UpdateCustomer(Customer& newCustomer)
{
	bool found = false;
	nodeType<Customer>* location;

	found=SearchCustomerByName(newCustomer.getCustomerName());

	if (found)
	{
		location->info.setCustomedetails(newCustomer.getCustomerName(), newCustomer.getAddress(),newCustomer.getEmail());
	}
	else
		cout << "Customer not found." << endl;
}

void CustomerList::UpdateDataFile(ofstream& outFile)
{
	nodeType<Customer>* current = first;

	while (current != nullptr)
	{
		outFile << current->info.getCustomerName() << endl;
		outFile << current->info.getAddress() << endl;
		outFile << current->info.getEmail() << endl;
		current = current->link;
	}

}
