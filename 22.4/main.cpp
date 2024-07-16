#include <iostream>
#include <iomanip>              // For setprecision
#include <vector>
using namespace std;

int main() {
    cout << fixed << setprecision(2);

    vector<double> weights;
    double weight;
    double totalWeight = 0;
    double maxWeight = 0;

    for (int i = 1; i <= 5; ++i) {
        cout << "Enter weight " << i << ":" << endl;
        cin >> weight;
        weights.push_back(weight);
        totalWeight += weight;
        if (i == 1) {
            maxWeight = weight;
        }
        else {
            if (weight > maxWeight) {
                maxWeight = weight;
            }
        }
    }

    cout << "You entered: ";
    for (int i = 0; i < weights.size(); ++i) {
        cout << weights[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Total weight: " << totalWeight << endl;
    cout << "Average weight: " << totalWeight / weights.size() << endl;
    cout << "Max weight: " << maxWeight << endl;

    return 0;
}