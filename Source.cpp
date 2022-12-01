//*************************************************************
// Comments are scattered throughout several files documenting // items.
// 
// How to fix this? Issue in main


#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include "CustomerList.h"
#include "Customer.h"
#include "OrderList.h"
#include "Order.h"

using namespace std;

void UpdateDatafile(CustomerList& clist);
void PrintOrders(CustomerList& clist);

// Load customers and orders into CustomerList
void LoadCustomers(ifstream& bookorderfile, CustomerList& clist) {
    string line;
    string name;
    string address;
    string email;
    string booktitle;
    string price;
    string quanity;


    // Read in first line and start processing file
    getline(bookorderfile, line);
    while (!bookorderfile.eof()) {

        // Process if starting customer record
        if (line[0] == '%') {

            // Read in customer info and create customer object
            getline(bookorderfile, address);
            getline(bookorderfile, email);
            Customer newcust(line.substr(1), address, email, OrderList());

            // Loop over customer book orders
            while (true) {
                getline(bookorderfile, line);
                // If starting customer record or eof
                if (line[0] == '%' || bookorderfile.eof()) {
                    clist.AddCustomer(newcust);
                    break;
                }
                else {
                    // Read in book order and add to customer
                    getline(bookorderfile, price);
                    getline(bookorderfile, quanity);
                    newcust.AddOrder(Order(line, stof(price), stoi(quanity)));
                }
            }
        }
        else {
            // Read in another line if not a starting customer record
            getline(bookorderfile, address);
        }
    }
}

// Show menu and get selection
int selectMenu() {
    cout << endl << "Please select one of the following action:" << endl;
    cout << "1: Place an order." << endl;
    cout << "2: Update an order." << endl;
    cout << "3: Cancel an order." << endl;
    cout << "4: Print all orders." << endl;
    cout << "5: Checkout orders." << endl;
    cout << "6: Exit" << endl;
    int iselect = 0;
    cin >> iselect;
    return iselect;
}

// Place an order for new/existing customer 
void PlaceOrder(CustomerList& clist) {
    // Create book orders
    // Repeat steps from CancelOrder
    // getline, cin >> ws
    while (true) {
        Customer c;
        string name;
        cout << "Enter Customer Name:";
        string dummy;
        getline(cin, dummy);
        getline(cin, name);

        // Get an existing customer
        if (clist.SearchCustomerByName(name)) {
            c = clist.getCustomerByName(name);
            cout << "Existing customer." << endl;
        }
        else {
            // Or create a new customer
            string address;
            string email;
            cout << "New Customer" << endl;
            cout << "Enter Customer Address:";
            getline(cin, address);
            cout << "Enter Customer Email:";
            getline(cin, email);
            c = Customer(name, address, email, OrderList());
            //*
            clist.AddCustomer(c);
        }

        // Now add book orders to customer
        string title;
        double price;
        int quanity;
        cout << "Enter the book title:";
        cin >> title;
        cout << "Enter the price:";
        cin >> price;
        cout << "Enter the number of books:";
        cin >> quanity;

        c.AddOrder(Order(title, price, quanity));
        cout << "New Order added for " << name << endl;

        // Save changes
        // Doesn't work
        UpdateDatafile(clist);

        // Add another order? 
        string choice;
        cout << "Place another order? (Y/N)";
        cin >> choice;
        if (choice == "Y") {
            continue;
        }
        else {
            break;
        }
    }
}

// Adjust order quantity
void UpdateOrder(CustomerList& clist) {
    //**************(((((((((((*************
    // Repeat steps in CancelOrder
    string name;
    cout << "Enter Customer Name:";
    cin >> name;

    if (clist.SearchCustomerByName(name)) {
        //*******************************************
        // Logic is incomplete for clist->getCustomerByName(name)
        //
        // Need to adjust following code after.
        //*******************************************
        Customer c = clist.getCustomerByName(name);
        string title;
        cout << "Enter the book title to be updated:";
        cin >> title;
        int quanity;
        cout << "Enter the number of book to be updated:";
        cin >> quanity;

        //********************************************
        // Calling c.getOrders().UpdateOrder(title, number)
        // with invalid title displays error message.
        //
        // Should c.getOrders().UpdateOrder(title, number)
        // with valid title display a message?
        //
        // What to do with a 0 quantity?
        //********************************************
        c.updateOrders(title, quanity);

        UpdateDatafile(clist);
    }
    else {
        cout << "Customer does not exist." << endl;
    }
}

// Cancel existing order
void CancelOrder(CustomerList& clist) {
    //Broken until fixed
    string name;
    cout << "Enter Customer Name:";
    cin >> ws;
    getline(cin, name);


    if (clist.SearchCustomerByName(name)) {
        //*******************************************
        // Logic is incomplete for clist->getCustomerByName(name)
        //
        // Need to adjust following code after.
        //*******************************************
        Customer c = clist.getCustomerByName(name);
        string title;
        cout << "Enter the book title to be canceled:";
        cin >> ws;
        getline(cin, title);
        //********************************************
        // Calling c.CancelOrder(title)
        // with invalid title displays error message.
        //
        // Should c.CancelOrder(title)
        // with valid title display a message?
        //********************************************
        //
        //********************************************
        //Doesn't work
        c.cancelOrder(title);
        //********************************************
        //Doesn't work
        UpdateDatafile(clist);
    }
    else {
        cout << "Customer does not exist." << endl;
    }
}

// Print orders
void PrintOrders(CustomerList& clist) {
    //************************************************* 
    // Customerlist and OrderList derive from linkedlistType
    // and have the print() function. Have to verify 
    // CustomerList.print() displays all customers and orders 
    // correctly.
    //
    // Example comments added to 
    //    operator<<(ostream&, const Customer&)
    //************************************************* 
    cout << clist;

}

// Checkout customer order
void CheckoutOrders(CustomerList& clist) {
    string name;
    cout << "Enter Customer Name:";
    cin >> name;

    if (clist.SearchCustomerByName(name)) {
        //*******************************************
        // Logic is incomplete for clist->getCustomerByName(name)
        //
        // Need to adjust following code after.
        //*******************************************
        Customer c = clist.getCustomerByName(name);

        //*******************************************
        // Logic is incomplete for c.checkoutOrders()
        //
        // Need to adjust following code after.
        //*******************************************
        double subtotal = c.checkoutOrders();
        double tax = subtotal * 0.07;
        double total = subtotal + tax;

        // print the normal Customer and Order
        cout << c << endl;

        // print the checkout calculations
        // Requires Formating
        cout << "subtotal: $" << subtotal << endl;
        cout << "tax: $" << tax << endl;
        cout << "total payment: $" << total << endl;
    }
    else {
        cout << "Customer does not exist." << endl;
    }
}

// Update the customers and orders data file
void UpdateDatafile(CustomerList& clist) {
    //************************************************* 
    // Customerlist and OrderList have UpdateDataFile() 
    // functions. Have to verify Customerlist.UpdateDataFile()  
    // saves all customers and orders correctly. 
    // 
    // CustomerList.UpdateDataFile() should internally call 
    // OrderList.UpdateDataFile() to ensure Customer and Orders // match.
    //
    // CustomerList.UpdateDataFile() should also add '%'
    // delimiter to Customer name for use when Loading data.
    //
    // Example comments added to 
    //    CustomerList.UpdateDataFile()
    //************************************************* 
    ofstream bookdatastream("BookOrders.txt");
    clist.UpdateDataFile(bookdatastream);
    bookdatastream.close();
}

// We have to do this
int main() {
    // Create CustomerList
    CustomerList clist = CustomerList();

    // Load Customer and Orders
    ifstream bookdatastream("BookOrders.txt");
    LoadCustomers(bookdatastream, clist);
    bookdatastream.close();

    // Do Menu
    cout << "Welcome to Wake Bookstore!" << endl;
    cout << "All customer orders are loaded." << endl;
    bool quit = false;
    while (!quit) {
        int iselect = selectMenu();
        switch (iselect) {
        case 1:
            PlaceOrder(clist);
            continue;

        case 2:
            UpdateOrder(clist);
            continue;

        case 3:
            CancelOrder(clist);
            continue;

        case 4:
            PrintOrders(clist);
            continue;

        case 5:
            CheckoutOrders(clist);
            continue;

        case 6:
            cout << "Thanks for shopping at Wake Bookstore!" << endl;
            quit = true;
            break;

        default:
            break;
        }
    }

    return 0;
}
