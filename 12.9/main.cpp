#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

string FindID(string name, ifstream& infoFS) {
    string sName, sID;

    while (infoFS >> sName >> sID) {
        if (sName.compare(name) == 0)
            return sID;
    }

    throw runtime_error("Student ID not found for " + name);
}

string FindName(string ID, ifstream& infoFS) {
    string sName, sID;

    while (infoFS >> sName >> sID) {
        if (sID.compare(ID) == 0)
            return sName;
    }

    throw runtime_error("Student name not found for " + ID);
}

int main() {
    int userChoice;
    string studentName;
    string studentID;

    string studentInfoFileName;
    ifstream studentInfoFS;

    cin >> studentInfoFileName;

    studentInfoFS.open(studentInfoFileName);

    cin >> userChoice;

    try {
        if (userChoice == 0) {
            cin >> studentName;
            studentID = FindID(studentName, studentInfoFS);
            cout << studentID << endl;
        }
        else {
            cin >> studentID;
            studentName = FindName(studentID, studentInfoFS);
            cout << studentName << endl;
        }
    }
    catch (const runtime_error& err) {
        cout << err.what() << endl;
    }

    studentInfoFS.close();
    return 0;
}