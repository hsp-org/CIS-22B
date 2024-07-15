#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
	ItemToPurchase item1;
	ItemToPurchase item2;
	string name;
	int price;
	int quantity;

	// Input for item 1
	cout << "Item 1" << endl;
	cout << "Enter the item name:" << endl;
	getline(cin, name);
	item1.SetName(name);

	cout << "Enter the item price:" << endl;
	cin >> price;
	item1.SetPrice(price);

	cout << "Enter the item quantity:" << endl;
	cin >> quantity;
	item1.SetQuantity(quantity);

	cin.ignore(); // Ignore the newline character left in the input buffer

	// Input for item 2
	cout << "Item 2" << endl;
	cout << "Enter the item name:" << endl;
	getline(cin, name);
	item2.SetName(name);

	cout << "Enter the item price:" << endl;
	cin >> price;
	item2.SetPrice(price);

	cout << "Enter the item quantity:" << endl;
	cin >> quantity;
	item2.SetQuantity(quantity);

	// Output the total cost
	cout << "TOTAL COST" << endl;
	cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << (item1.GetPrice() * item1.GetQuantity()) << endl;
	cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << (item2.GetPrice() * item2.GetQuantity()) << endl;
	cout << "Total: $" << ((item1.GetPrice() * item1.GetQuantity()) + (item2.GetPrice() * item2.GetQuantity())) << endl;

	return 0;
}
