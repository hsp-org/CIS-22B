
#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") {}

ShoppingCart::ShoppingCart(string name, string date) : customerName(name), currentDate(date) {}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name) {
    for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
        if (it->GetName() == name) {
            cartItems.erase(it);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    bool found = false;
    for (auto& it : cartItems) {
        if (it.GetName() == item.GetName()) {
            found = true;
            if (item.GetDescription() != "none") it.SetDescription(item.GetDescription());
            if (item.GetPrice() != 0) it.SetPrice(item.GetPrice());
            if (item.GetQuantity() != 0) it.SetQuantity(item.GetQuantity());
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() {
    int totalQuantity = 0;
    for (auto& item : cartItems) {
        totalQuantity += item.GetQuantity();
    }
    return totalQuantity;
}

double ShoppingCart::GetCostOfCart() {
    double totalCost = 0;
    for (auto& item : cartItems) {
        totalCost += item.GetPrice() * item.GetQuantity();
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        for (auto& item : cartItems) {
            item.PrintItemCost();
        }
    }
    cout << "\nTotal: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "\nItem Descriptions" << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        for (auto& item : cartItems) {
            item.PrintItemDescription();
        }
    }
}