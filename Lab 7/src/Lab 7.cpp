//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <fstream>
#include<string>
#include <cstring>
using namespace std;

void input(istream& in, char seat[]);
bool rowValid(char seat[], int rowSize);
bool columnValid(char seat[]);
bool columnValid(char seat[]) {
	bool bColumn = true;
	if (seat[1] < 'A' || seat[1] > 'D') {
		cout << "Error. " << seat[1] << " is not a valid seat option." << endl;
		return bColumn = false;
	} else {
		return bColumn = true;
	}
}
bool rowValid(char seat[], int rowSize) {
	bool bRow = true;
	if (seat[0] < '1' || seat[0] > '0' + rowSize) {
		cout << "Error. " << seat[0] << " is not a valid seat option." << endl;
		return bRow = false;
	} else {
		return bRow = true;
	}
}
bool checkseats(char *seats[], int row, int column);

bool checkseats(char *seats[], int row, int column) {
	bool seatTaken = false;
	if (seats[row][column] == 'X') {
		cout << "That seat is already taken. Please choose another." << endl;
		return seatTaken = true;
	} else {
		return seatTaken = false;
	}
}

void input(istream& in, char seat[]) {
	in >> seat;

}

void output(ostream& outs, int size, char *seats[]);
void output(ostream& outs, int size, char *seats[]) {
	for (int i = 0; i < size; i++) {

		{
			cout << i + 1 << " " << seats[i] << endl;
		}
	}
}


void exercise1();
void exercise2();
void exercise1() {
	int rowSize;
	char **seats;
	cout << "Please enter the rowsize" << endl;
	cin >> rowSize;

	seats = new char*[rowSize];

	for (int i = 0; i < rowSize; i++) {
		seats[i] = new char[4];
	}
	for (int i = 0; i < rowSize; i++) {
		cout << seats[i];
	}

	seats = new char*[rowSize];
	for (int i = 0; i < rowSize; i++) {
		seats[i] = new char[4];
		seats[i][0] = 'A';
		seats[i][1] = 'B';
		seats[i][2] = 'C';
		seats[i][3] = 'D';
	}
	for (int i = 0; i < rowSize; i++) {

		{
			cout << i + 1 << " " << seats[i] << endl;
		}
	}

	cout
			<< "Please choose an option:\n1. Enter my own seat choices\n2. Enter seat choices from a file"
			<< endl;
	int choice1 = 0;
	cin >> choice1;
	if (choice1 == 1) {
		bool exit = true;
		bool bRow = true;
		bool bColumn = true;
		bool seatTaken = false;

		while (exit) {

			int row = 0;
			int column = 0;
			char seat[5];
			cout
					<< "Please enter which seat you would like. Type 'Exit' to stop entering seats."
					<< endl;
			input(cin, seat);
			row = seat[0] - 49;
			column = seat[1] - 65;
			if (seat[0] == 'E' || seat[0] == 'e') {
				delete[] seats; //return to freestore
				exit = false;
				continue;
			}

			bRow = rowValid(seat, rowSize);
			bColumn = columnValid(seat);

			if (bRow) {
				if (seats[row][column] == 'X') {
					cout << "That seat is already taken. Please choose another."
							<< endl;
					seatTaken = true;
				} else {
					seatTaken = false;
				}
			}

			if (bRow && bColumn && !seatTaken) {
				seats[row][column] = 'X';
			}
			output(cout, rowSize, seats);
		}
	} else if (choice1 == 2) {

		ifstream ifs;
		ifs.open("seatnumbers.txt");
		if (ifs.fail()) {
			cout << "Error. File not found" << endl;
			exit(1);
		}
		bool exit = true;

		bool bRow = true;
		bool bColumn = true;
		bool seatTaken = false;
		while (exit) {

			int row = 0;
			int column = 0;
			char seat[5];

			input(ifs, seat);
			row = seat[0] - 49;
			column = seat[1] - 65;
			if (seat[0] == 'E' || seat[0] == 'e') {
				delete[] seats; //return to freestore
				exit = false;
				continue;
			}

			bRow = rowValid(seat, rowSize);
			bColumn = columnValid(seat);

			if (bRow) {
				if (seats[row][column] == 'X') {
					cout << "That seat is already taken. Please choose another."
							<< endl;
					seatTaken = true;
				} else {
					seatTaken = false;
				}
			}

			if (bRow && bColumn && !seatTaken) {
				seats[row][column] = 'X';
			}
			output(cout, rowSize, seats);
		}
	}
}
typedef char* NoRepeat;
NoRepeat delete_repeats(char s1[], int s);
NoRepeat delete_repeats(char s1[], int s) {
	int count = 0;
	bool repeat = false;
	NoRepeat temp = new char[s + 1];
	for (int i = 0; i < s; i++) {
		repeat = false;
		for (int j = 0; j < i; j++) {
			if (s1[j] == s1[i]) {
				repeat = true;
				break;
			}
		}
		if (!repeat) {
			temp[count] = s1[i];
			count++;
		}
	}
	temp[count + 1] = '\0';
	return temp;
	delete[] temp;

}
void exercise2() {
	char str[100] = "to be or not to be";
	int size = strlen(str);

	NoRepeat noRepeat;

	noRepeat = delete_repeats(str, size);

	cout << noRepeat <<endl;
	delete[] noRepeat;
}

int main() {
	while (true) {
		int choice = 0;
		cout << "Please enter an number from the menu." << endl;
		cout << "\nExercise 1.\nExercise 2.\nExit 3." << endl;
		cin >> choice;
		if (choice == 1) {
			exercise1();
		} else if (choice == 2) {
			exercise2();
		} else if (choice == 3) {
			break;
		} else {
			cout << "Error, " << choice << " is not an option." << endl;
		}
	}

}
