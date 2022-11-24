#include "Customer.h"
#include "CustomerList.h"
#include "Order.h"
#include "OrderList.h"
#include "linkedList.h"

using namespace std;

void LoadCustomers(ifstream&, CustomerList&);
int selectMenu();
void PlaceOrder(CustomerList&);
void UpdateOrder(CustomerList&);
void CancelOrder(CustomerList&);
void PrintOrders(CustomerList&);
void CheckoutOrders(CustomerList&);
void UpdateDatafile(CustomerList&);

int main()
{

	return 0;
}