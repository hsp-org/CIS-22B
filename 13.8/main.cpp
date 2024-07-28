#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename TheType>
class OrderedList {
public:
    int Size();
    TheType At(int index);
    int Find(TheType value);
    void Insert(TheType value);
    bool Remove(TheType value);
    void Print();

private:
    vector<TheType> list;
};

template<typename TheType>
int OrderedList<TheType>::Size() {
    return list.size();
}

template<typename TheType>
TheType OrderedList<TheType>::At(int index) {
    return list.at(index);
}

template<typename TheType>
int OrderedList<TheType>::Find(TheType value) {
    for (unsigned int i = 0; i < list.size(); ++i) {
        if (list.at(i) == value) {
            return i;
        }
    }
    return -1;
}

template<typename TheType>
void OrderedList<TheType>::Insert(TheType newItem) {
    unsigned int j;
    if (list.size() == 0) {
        list.push_back(newItem);
        return;
    }

    j = 0;
    while (j < list.size() && newItem > list.at(j)) {
        ++j;
    }

    if (j == list.size()) {
        list.push_back(newItem);
    }
    else {
        list.insert(list.begin() + j, newItem);
    }
}

template<typename TheType>
bool OrderedList<TheType>::Remove(TheType oldItem) {
    int index = Find(oldItem);
    if (index != -1) {
        list.erase(list.begin() + index);
        return true;
    }
    return false;
}

template<typename TheType>
void OrderedList<TheType>::Print() {
    for (unsigned int j = 0; j < list.size(); ++j) {
        cout << list.at(j);
        if (j < list.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    OrderedList<int> intList;

    intList.Insert(11);
    intList.Insert(3);
    intList.Insert(7);

    if (intList.Size() == 3) {
        cout << "Size is correct" << endl;
    }
    else {
        cout << "Size should be 3" << endl;
    }

    if (intList.At(0) == 3 && intList.At(1) == 7 && intList.At(2) == 11) {
        cout << "List is in correct order: ";
    }
    else {
        cout << "List is out of order: ";
    }
    intList.Print();
    cout << endl;

    int indx = intList.Find(11);
    if (indx == 2) {
        cout << "Index of 11 is correct -- " << indx << endl;
    }
    else {
        cout << "Index of 11 is incorrect -- " << indx << endl;
    }

    intList.Remove(7);
    if (intList.At(0) == 3 && intList.At(1) == 11) {
        cout << "7 was removed correctly" << endl;
    }
    else {
        cout << "7 was not removed correctly" << endl;
    }
}
