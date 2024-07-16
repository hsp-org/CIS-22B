#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ratings;
vector<int> jersey_numbers;

vector<int> get_ratings(vector<int> ratings) {
    return ratings;
}
vector<int> get_jersey_numbers(vector<int> jersey_numbers) {
    return jersey_numbers;
}

void add_player() {
    int num;
    int rating;
    cout << "Enter a new player's jersey number:" << endl;
    cin >> num;
    jersey_numbers.push_back(num);
    cout << "Enter the player's rating:" << endl;
    cin >> rating;
    ratings.push_back(rating);

    return;
}
void output_roster() {
    cout << "ROSTER" << endl;
    int j = 0;
    for (int i = 0; i < jersey_numbers.size(); i++) {
        cout << "Player " << j + 1 << " -- Jersey number: " << jersey_numbers[i] << ", Rating: " << ratings[i] << endl;
        j++;
    }
    return;
}
void remove_player() {
    int match;
    int index = 0;
    vector<int>::iterator it;
    cout << "Enter a jersey number:" << endl;
    cin >> match;
    for (int i = 0; i < ratings.size(); i++) {
        if (match == jersey_numbers[i]) {
            index = i;
            ratings.erase(ratings.begin() + index);
            jersey_numbers.erase(jersey_numbers.begin() + index);
        }
    }
    output_roster();

    return;

}
void update_rating() {
    int jersey;
    int rating;
    int index;
    cout << "Enter a jersey number:" << endl;
    cin >> jersey;
    cout << "Enter a new rating for player:" << endl;
    cin >> rating;
    for (int i = 0; i < ratings.size(); i++) {
        if (jersey_numbers[i] == jersey) {
            index = i;
        }
    }
    replace(ratings.begin(), ratings.end(), ratings[index], rating);
    for (int x : ratings) {
        cout << x << " ";

    }
}

void above_rating() {
    int input;
    int j = 0;
    cout << "Enter a rating:" << endl;
    cin >> input;
    cout << "ABOVE " << input << endl;

    for (int i = 0; i < ratings.size(); i++) {
        if (ratings[i] > input) {
            cout << "Player " << i + 1 << " -- Jersey number: " << jersey_numbers[i] << ", Rating: " << ratings[i] << endl;
            j++;
        }
    }

    return;
}


void menu(vector<int> ratings, vector<int> jersey_numbers) {
    char input;
    do {
        cout << "" << endl;
        cout << "MENU" << endl;
        cout << "a - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n" << endl;
        cout << "Choose an option:" << endl;
        cin >> input;


        switch (input)
        {
        case 'a':
            //working
            add_player();
            break;
        case 'd':
            //working
            remove_player();
            break;
        case 'u':
            //working
            update_rating();
            break;
        case 'r':
            //method
            above_rating();
            break;
        case 'o':
            output_roster();
            break;
        case 'q':
            //method
            break;

        default:
            cout << "Please enter a valid letter" << endl;
            break;
        }
    } while (input != 'q');
}
int main() {

    int jersey;
    int rating;
    int j = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Enter player " << j + 1 << "'s jersey number:" << endl;
        cin >> jersey;
        jersey_numbers.push_back(jersey);
        cout << "Enter player " << j + 1 << "'s rating:" << endl;
        cin >> rating;
        cout << "" << endl;
        ratings.push_back(rating);
        j++;
    }

    output_roster();
    menu(ratings, jersey_numbers);
    return 0;
}