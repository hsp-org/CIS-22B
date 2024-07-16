#include <iostream>
#include <cctype> 
using namespace std;

string CheckCharacter(string word, int index) {
    if (index < 0 || index >= word.length()) {
        return "Index out of bounds";
    }

    char ch = word.at(index);
    if (isalpha(ch)) {
        return "Letter: '" + string(1, ch) + "'";
    }
    else if (isdigit(ch)) {
        return "Digit: '" + string(1, ch) + "'";
    }
    else if (isspace(ch)) {
        return "Whitespace: ' '";
    }
    else {
        return "Unknown: '" + string(1, ch) + "'";
    }
}

int main() {
    cout << CheckCharacter("happy birthday", 2) << endl;
    cout << CheckCharacter("happy birthday", 5) << endl;
    cout << CheckCharacter("happy birthday 2 you", 15) << endl;
    cout << CheckCharacter("happy birthday!", 14) << endl;

    return 0;
}
