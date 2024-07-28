#include <string>
#include <iostream>

using namespace std;

int main() {
    string inputName;
    int age;
    cin.exceptions(ios::failbit);

    cin >> inputName;
    while (inputName != "-1") {
        try {
            cin >> age;
            cout << inputName << " " << (age + 1) << endl;
        }
        catch (ios_base::failure& e) {
            cout << inputName << " 0" << endl;
            cin.clear();
            string garbage;
            getline(cin, garbage);
        }

        cin >> inputName;
    }

    return 0;
}
