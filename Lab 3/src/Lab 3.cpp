//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void sortintarray(int a[], int number_used);
int index_of_smallest(const int a[], int start_index, int number_used);
void swapvalues(int& a, int& b);

//Exercise1:
//	step1: Open Labinput3-1.txt
//	step2: Check if it found the file. If it did, input everything into an array
//	step3: toupper(array) to change verything to capital letters
//	Step4: ofs.open(.txt) and then ofs <<array to input everything to the .txt file

//Excerise2:
//	step1: Menu choice to enter your own numbers or a file
//	step2: sortintarray() to sort the numbers from lowest to greatest
//	step3: Make a uniquearray. Check if the array entry is in the unique
//		   array. If not, then enter into unique array and add 1 to count array.
//		   If it is, then do not enter but add a +1 to the corrensponding entry in the count array.
//	step4: Whilst making arrays, make a count for unique numbers
//	step5: Use setw() to format .txt file format and then ofs.close();
//	step6: ifstream to open the txt file and read contents to the console
//
//Exercise3:
//	Step1: ifstream in3 and ifstream in4
//	Step2: in3.open and in4.open
//	Step3: while (in3 >> array3[count3++]) and while (in3 >> array4[count3++]) count3-- to remove extra 0
//	Step4: ofstream exp3 and exp3.open
//	Step5: exp3 << array3[i]<<'\n';
//	Step6: string myline;
//	ifstream exp31;
//	exp31.open("LabOutput3-3.txt");
//	cout<<'\n';
//	cout <<"Files 1 and 2 combined give the following output which is stored in LabOutput3-3.txt:" <<'\n';
//	while(getline(exp31, myline)){
//		cout << myline<<'\n';
//	}

void Exercise1() {

	cout << "Exercise 1" << endl;
	ifstream ifs;

	ifs.open("LabInput3-1.txt");

	if (ifs.fail()) {
		cout << "File not found." << endl;
		exit(1);
	}
	char iarray[1000];

	ofstream ofs;
	ofs.open("LabOutput3-1.txt");

	int count = 0;

	while (ifs >> iarray[count++]) {

	}

	for (int i = 0; i < count; i++) {
		iarray[i] = toupper(iarray[i]);
	}

	for (int i = 0; i < count - 1; i++) {
		ofs << iarray[i];
	}

	cout << "End of Exercise 1.\n\n\n\n" << endl;
}
void Exercise2() {
	int const size = 6;
	int count = 0;
	int inputarray[6];
	int menuchoice;
	cout << "Exercise 2\n\n" << endl;
	cout << "Choose a number\n\n1. Enter your own values\n2. Use a file"
			<< endl;
	cin >> menuchoice;
	cout << "Your Choice was " << menuchoice << endl;

	if (menuchoice == 1) {
		cout << "Please enter 6 numbers" << endl;
		for (int i = 0; i < 6; i++) {
			cin >> inputarray[i];
		}
		sortintarray(inputarray, size);
		for (int i = 0; i < 6; i++) {
			cout << inputarray[i];
		}

	} else if (menuchoice == 2) {
		ifstream ifs;
		ifs.open("LabInput3-2.txt");

		while (ifs >> inputarray[count++]) {

		}
		sortintarray(inputarray, size);
		for (int i = 0; i < 6; i++) {
			cout << inputarray[i];
		}

	}

	int uniquearray[size];
	for (int i = 0; i < size; i++) {
		uniquearray[i] = 0;
	}

	int countarray[size];
	for (int i = 0; i < size; i++) {
		countarray[i] = 0;
	}

	int uniquecount = 0;
	int copycount = 0;
	int arraycopies[5];
	for (int i = 0; i < size; i++) {
		arraycopies[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		if (inputarray[i] != uniquearray[0] && inputarray[i] != uniquearray[1]
				&& inputarray[i] != uniquearray[2]
				&& inputarray[i] != uniquearray[3]
				&& inputarray[i] != uniquearray[4]
				&& inputarray[i] != uniquearray[5]) {

			uniquearray[uniquecount] = inputarray[i];
			countarray[uniquecount] = countarray[uniquecount] + 1;
			uniquecount++;

		} else if (inputarray[i] == uniquearray[0]
				|| inputarray[i] == uniquearray[1]
				|| inputarray[i] == uniquearray[2]
				|| inputarray[i] == uniquearray[3]
				|| inputarray[i] == uniquearray[4]
				|| inputarray[i] == uniquearray[5]) {

			arraycopies[copycount] = inputarray[i];
			copycount++;
		}

	}

	for (int i = 0; i < copycount; i++) {
		if (arraycopies[i] == uniquearray[0]) {
			countarray[0]++;
		} else if (arraycopies[i] == uniquearray[1]) {
			countarray[1]++;
		} else if (arraycopies[i] == uniquearray[2]) {
			countarray[2]++;
		} else if (arraycopies[i] == uniquearray[3]) {
			countarray[3]++;
		} else if (arraycopies[i] == uniquearray[4]) {
			countarray[4]++;
		} else if (arraycopies[i] == uniquearray[5]) {
			countarray[5]++;
		}
	}

//	cout << " uniquearray ";
//	for (int i = 0; i < size; i++) {
//		cout << uniquearray[i];
//	}
//	cout << " and uniquecount:" << uniquecount;
//	cout << " and countarray is ";
//	for (int i = 0; i < size; i++) {
//		cout << countarray[i];
//	}
	string line;
	ofstream ofs;
	ofs.open("LabOutput3-2.txt");
	ofs << setw(8) << "N" << setw(10) << "Count" << '\n';
	for (int i = uniquecount - 1; i > -1; --i) {
		ofs << setw(8) << uniquearray[i] << setw(8) << countarray[i];
		ofs << '\n';
	}
	ofs.close();

	ifstream print;
	print.open("LabOutput3-2.txt");
	if (print.fail()) {
		cout << "File not found." << endl;
		exit(1);
	}

	cout << '\n' << '\n';

//Only prints the lines in the file up until the uniquecount+1
//because I dont want the extra 0's in the array
	for (int i = 0; i < uniquecount + 1; i++) {
		getline(print, line);
		cout << line << '\n';
	}

}
void Exercise3() {

	ifstream in3;
	in3.open("LabInput3-3.txt");
	if (in3.fail()) {
		cout << "File not found." << endl;
		exit(1);
	}
	ifstream in4;
	in4.open("LabInput3-4.txt");
	if (in4.fail()) {
		cout << "File not found." << endl;
		exit(1);
	}

	int array3[100];
	for (int i = 0; i < 100; i++) {
		array3[i] = 0;
	}

	int count3 = 0;

	while (in3 >> array3[count3++]) {

	}
	count3--;
	while (in4 >> array3[count3++]) {

	}
//Testing to see if it works
//	for (int i = 0; i < count3; i++) {
//		cout << array3[i] << ' ';
//	}
	count3--;
	sortintarray(array3, count3);

//Testing to see if it works
//		for(int i = 0; i<count3; i++){
//cout<<array3[i]<<' ';
//		}

	ofstream exp3;
	exp3.open("LabOutput3-3.txt");

	for (int i = 0; i < count3; i++) {
		exp3 << array3[i] << '\n';

	}
	exp3.close();

/////////////////////////////

	string myline;

	ifstream exp31;
	exp31.open("LabOutput3-3.txt");

	cout << '\n';

	cout	<< "Files 1 and 2 combined give the following output which is stored in LabOutput3-3.txt:"
			<< '\n';

	while (getline(exp31, myline)) {
		cout << myline << '\n';
	}

/////////////////////////////


}

int main() {
	int ch = 0;
	while (1) {

		cout << "Please choose a menu option." << '\n' << "1. Exercise 1"
				<< '\n' << "2. Exercise 2" << '\n' << "3. Exercise 3" << endl;
		cin >> ch;
		if (ch == 1) {
			Exercise1();

		} else if (ch == 2) {
			Exercise2();
		} else if (ch == 3) {
			Exercise3();
		} else {
			cout << "Please enter a valid choice" << endl;
		}
	}

//	Exercise1();
//	Exercise2();
//	Exercise3();

	return 0;
}

void sortintarray(int a[], int number_used) {

	int index_of_next_smallest;
	for (int index = 0; index < number_used - 1; index++) {
		index_of_next_smallest = index_of_smallest(a, index, number_used);
		swapvalues(a[index], a[index_of_next_smallest]);
	}

}
void swapvalues(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int index_of_smallest(const int a[], int start_index, int number_used) {
	int min = a[start_index];
	int index_of_min = start_index;

	for (int index = start_index + 1; index < number_used; index++) {
		if (a[index] < min) {
			min = a[index];
			index_of_min = index;

		}

	}

	return index_of_min;

}
