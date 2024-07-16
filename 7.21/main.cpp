#include <iostream>

#include "VendingMachine.h"
using namespace std;

int main() {
    VendingMachine vendingMachine;

    int purchase, restock, purchaseAfterward;
    cin >> purchase >> restock >> purchaseAfterward;

    vendingMachine.Purchase(purchase);
    vendingMachine.Restock(restock);
    vendingMachine.Purchase(purchaseAfterward);
    vendingMachine.Report();

    return 0;
}