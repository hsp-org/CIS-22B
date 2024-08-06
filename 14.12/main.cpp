#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string personName = "";
    int counter = 0;
    int youPosition = 0;

    queue<string> peopleInQueue;

    getline(cin, personName);
    while (personName != "-1") {
        peopleInQueue.push(personName);
        counter++;
        if (personName == "You") {
            youPosition = counter;
        }
        getline(cin, personName);
    }

    cout << "Welcome to the ticketing service... " << endl;
    cout << "You are number " << youPosition << " in the queue." << endl;

    while (!peopleInQueue.empty()) {
        if (peopleInQueue.front() == "You") {
            cout << "You can now purchase your ticket!" << endl;
            break;
        }
        else {
            cout << peopleInQueue.front() << " has purchased a ticket." << endl;
            peopleInQueue.pop();
            youPosition--;
            if (youPosition > 0) {
                cout << "You are now number " << youPosition << endl;
            }
        }
    }

    return 0;
}
