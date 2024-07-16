#include <iostream>
#include <iomanip>
#include <string>
#include "ShoppingCart.h"
using namespace std;

void PrintMenu() {
    cout << "\nMENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit\n" << endl;
    //cout << "\nChoose an option:" << endl;
}

char GetMenuOption() {
    cout << "Choose an option:" << endl; 
    char option;
    cin >> option;
    cin.ignore(); 
    return option;
}

void ExecuteMenu(char option, ShoppingCart& cart) {
    string name, description;
    int price, quantity;

    switch (option) {
    case 'a': {
        cout << "\nADD ITEM TO CART" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, name);
        cout << "Enter the item description:" << endl;
        getline(cin, description);
        cout << "Enter the item price:" << endl;
        cin >> price;
        cout << "Enter the item quantity:" << endl;
        cin >> quantity;
        cin.ignore();

        ItemToPurchase newItem(name, description, price, quantity);
        cart.AddItem(newItem);
        break;
    }
    case 'd': {
        cout << "\nREMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove:" << endl;
        getline(cin, name);
        cart.RemoveItem(name);
        break;
    }
    case 'c': {
        cout << "\nCHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, name);
        cout << "Enter the new quantity:" << endl;
        cin >> quantity;
        cin.ignore();

        ItemToPurchase modItem;
        modItem.SetName(name);
        modItem.SetQuantity(quantity);
        cart.ModifyItem(modItem);
        break;
    }
    case 'i':
        cout << "\nOUTPUT ITEMS' DESCRIPTIONS" << endl;
        cart.PrintDescriptions();
        break;
    case 'o':
        cout << "OUTPUT SHOPPING CART" << endl;
        cart.PrintTotal();
        break;
    case 'q':
        break;
    default:
        break;
    }
}

int main() {
    string customerName;
    string date;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, date);

    ShoppingCart shoppingCart(customerName, date);

    cout << "\nCustomer name: " << customerName << endl;
    cout << "Today's date: " << date << endl;

    PrintMenu();

    char menuOption = ' ';
    menuOption = GetMenuOption();
    do {
        if (menuOption == 'a' || menuOption == 'd' || menuOption == 'c' || menuOption == 'i' || menuOption == 'o') {
            ExecuteMenu(menuOption, shoppingCart);
            PrintMenu();
            menuOption = GetMenuOption();
        }
        else {
            menuOption = GetMenuOption();
        }
    } while (menuOption != 'q');

    return 0;
}