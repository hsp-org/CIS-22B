#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include "StatePair.h"
using namespace std;

int main() {
    ifstream inFS;
    int zip;
    int population;
    string abbrev;
    string state;
    unsigned int i;

    vector<StatePair<int, string>> zipCodeState;
    vector<StatePair<string, string>> abbrevState;
    vector<StatePair<string, int>> statePopulation;

    inFS.open("zip_code_state.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file zip_code_state.txt." << endl;
        return 1;
    }
    while (!inFS.eof()) {
        StatePair<int, string> temp;
        inFS >> zip;
        if (!inFS.fail()) {
            temp.SetKey(zip);
        }
        inFS >> abbrev;
        if (!inFS.fail()) {
            temp.SetValue(abbrev);
        }
        zipCodeState.push_back(temp);
    }
    inFS.close();

    inFS.open("abbreviation_state.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file abbreviation_state.txt." << endl;
        return 1;
    }
    while (!inFS.eof()) {
        StatePair<string, string> temp;
        inFS >> abbrev;
        if (!inFS.fail()) {
            temp.SetKey(abbrev);
        }
        getline(inFS, state);
        getline(inFS, state);
        state = state.substr(0, state.size() - 1);
        if (!inFS.fail()) {
            temp.SetValue(state);
        }
        abbrevState.push_back(temp);
    }
    inFS.close();

    inFS.open("state_population.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file state_population.txt." << endl;
        return 1;
    }
    while (!inFS.eof()) {
        StatePair<string, int> temp;
        getline(inFS, state);
        state = state.substr(0, state.size() - 1);
        if (!inFS.fail()) {
            temp.SetKey(state);
        }
        inFS >> population;
        if (!inFS.fail()) {
            temp.SetValue(population);
        }
        getline(inFS, state);
        statePopulation.push_back(temp);
    }
    inFS.close();

    cin >> zip;

    for (i = 0; i < zipCodeState.size(); ++i) {
        if (zipCodeState[i].GetKey() == zip) {
            abbrev = zipCodeState[i].GetValue();
            break;
        }
    }

    for (i = 0; i < abbrevState.size(); ++i) {
        if (abbrevState[i].GetKey() == abbrev) {
            state = abbrevState[i].GetValue();
            break;
        }
    }

    for (i = 0; i < statePopulation.size(); ++i) {
        if (statePopulation[i].GetKey() == state) {
            statePopulation[i].PrintInfo();
            break;
        }
    }

    return 0;
}
