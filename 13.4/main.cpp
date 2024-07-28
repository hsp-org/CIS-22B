#include <string>
#include <iostream>

using namespace std;

template <typename T>
int CheckOrder(T arg1, T arg2, T arg3, T arg4) {
    if (arg1 < arg2 && arg2 < arg3 && arg3 < arg4) {
        return -1;
    }
    else if (arg1 > arg2 && arg2 > arg3 && arg3 > arg4) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    string stringArg1, stringArg2, stringArg3, stringArg4;
    cin >> stringArg1;
    cin >> stringArg2;
    cin >> stringArg3;
    cin >> stringArg4;
    cout << "Order: " << CheckOrder(stringArg1, stringArg2, stringArg3, stringArg4) << endl;

    double doubleArg1, doubleArg2, doubleArg3, doubleArg4;
    cin >> doubleArg1;
    cin >> doubleArg2;
    cin >> doubleArg3;
    cin >> doubleArg4;
    cout << "Order: " << CheckOrder(doubleArg1, doubleArg2, doubleArg3, doubleArg4) << endl;

    return 0;
}
