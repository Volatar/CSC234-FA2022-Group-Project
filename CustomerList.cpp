#include "CustomerList.h"
#include "linkedList.h"

using namespace std;

ostream& operator<<(ostream& osObject, const CustomerList& customerList)
{
	nodeType<Customer>* current = customerList.first;

	while (current != nullptr)
	{
		osObject << "**********************************************" << endl;
		osObject << current->info;
		current = current->link;
		osObject << "**********************************************" << endl;
	}

	

	return osObject;
}

void CustomerList::AddCustomer(Customer& newCustomer) 
{
	bool found = false;
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

	return found;
}

Customer& CustomerList::getCustomerByName(string customerName) const
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

	return current->info;
}

void CustomerList::UpdateCustomer(Customer& newCustomer)
{
	bool found = false;
	nodeType<Customer>* current;

	current = first;

	while (current != nullptr && !found)
	{
		if (current->info.getCustomerName() == newCustomer.getCustomerName())
			found = true;

		else
			current = current->link;
	}

	if (found)
	{
		current->info = newCustomer;
	}
	else
		cout << "Customer not found." << endl;
}

void CustomerList::UpdateDataFile(ofstream& outFile)
{
	nodeType<Customer>* current = first;

	while (current != nullptr)
	{
		outFile << "%" << current->info.getCustomerName() << endl;
		outFile << current->info.getAddress() << endl;
		outFile << current->info.getEmail() << endl;
		current->info.getOrders().UpdateDataFile(outFile);
		current = current->link;
	}

}
