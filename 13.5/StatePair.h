#ifndef STATEPAIR
#define STATEPAIR

#include <iostream>
using namespace std;

template<typename T1, typename T2>
class StatePair {
private:
    T1 key;
    T2 value;

public:
    // Constructors
    StatePair() {}
    StatePair(T1 userKey, T2 userValue) : key(userKey), value(userValue) {}

    // Mutators
    void SetKey(T1 userKey) {
        key = userKey;
    }

    void SetValue(T2 userValue) {
        value = userValue;
    }

    // Accessors
    T1 GetKey() const {
        return key;
    }

    T2 GetValue() const {
        return value;
    }

    // PrintInfo method
    void PrintInfo() const {
        cout << key << ": " << value << endl;
    }
};

#endif
