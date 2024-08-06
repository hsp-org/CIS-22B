#include <iostream>
#include <deque>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string line;
    bool result = true;
    deque<char> chars;

    getline(cin, line);

    for (char ch : line) {
        if (isalpha(ch)) {
            chars.push_back(tolower(ch));
        }
    }

    while (chars.size() > 1) {
        if (chars.front() != chars.back()) {
            result = false;
            break;
        }
        chars.pop_front();
        chars.pop_back();
    }

    if (result) {
        cout << "Yes, \"" << line << "\" is a palindrome." << endl;
    }
    else {
        cout << "No, \"" << line << "\" is not a palindrome." << endl;
    }

    return 0;
}
