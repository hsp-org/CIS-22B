#include <iostream>
#include <string>

using namespace std;

int GetMonthAsInt(string month) {
	int monthInt = 0;

	if (month == "January")
		monthInt = 1;
	else if (month == "February")
		monthInt = 2;
	else if (month == "March")
		monthInt = 3;
	else if (month == "April")
		monthInt = 4;
	else if (month == "May")
		monthInt = 5;
	else if (month == "June")
		monthInt = 6;
	else if (month == "July")
		monthInt = 7;
	else if (month == "August")
		monthInt = 8;
	else if (month == "September")
		monthInt = 9;
	else if (month == "October")
		monthInt = 10;
	else if (month == "November")
		monthInt = 11;
	else if (month == "December")
		monthInt = 12;
	return monthInt;
}

int main() {

	string inputDate;
	while (getline(cin, inputDate) && inputDate != "-1") {
		size_t commaPos = inputDate.find(',');

		if (commaPos != string::npos) {
			string month = inputDate.substr(0, inputDate.find(' '));
			string day = inputDate.substr(inputDate.find(' ') + 1, commaPos - (inputDate.find(' ') + 1));
			string year = inputDate.substr(commaPos + 2);

			int dayInt = stoi(day);
			int yearInt = stoi(year);
			int monthInt = GetMonthAsInt(month);

			if (monthInt != 0) {
				cout << monthInt << "-" << dayInt << "-" << yearInt << endl;
			}
		}
	}
	
	return 0;
}
