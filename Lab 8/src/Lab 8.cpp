//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <iostream>
#include "Polynomial.h"
#include "Complex.h"
using namespace std;

void exercise1() {
	for(int i = 0; i<125;i++){
		cout<<"_";
	}
	cout<<endl;
	double cf1[4] = { 1, 2, 3, 4 };
	double cf2[6] = { 6, 5, 4, 3, 2, 1 };

	Polynomial p1(cf1, 3), p2(cf2, 5);

	cout << "Given the polynomials of \n"<< p1 << "and\n"<< p2 << "we can perform the following calculations.\n"<<endl;


	Polynomial pAdded = p1 + p2;
	cout << "Polynomial + polynomial: " << pAdded;

	Polynomial pAdded1 = p1 + 4.0;
	cout << "Polynomial + constant: " << pAdded1;

	Polynomial pAdded2 = 4.0 + p1;
	cout << "Constant + polynomial: " << pAdded2;

	Polynomial pSubtracted = p1 - p2;
	cout << "Polynomial - polynomial: " << pSubtracted;

	Polynomial pSubtracted1 = p1 - 3.0;
	cout << "Polynomial - constant: " << pSubtracted1;

	Polynomial pSubtracted2 = 2.0 - p2;
	cout << "Constant - polynomial: " << pSubtracted2;

	Polynomial pMultiplied = p1 * p2;
	cout << "Polynomial * polynomial: " << pMultiplied;

	Polynomial pMultiplied1 = p2 * 2.0;
	cout << "Polynomial * constant: " << pMultiplied1;

	Polynomial pMultiplied2 = 3.0 * p2;
	cout << "Constant * polynomial: " << pMultiplied2;

	for(int i = 0; i<125;i++){
		cout<<"_";
	}
	cout<<endl;
}
void exercise2() {

	vector<string>names;
names.resize(19);
	names.reserve(20);
cout<<names.capacity()<<endl;
cout<<names.size()<<endl;
names.push_back("myname");
names[18]="anothername";
cout<<names.capacity()<<endl;
cout<<names.size()<<endl;
cout<<names[19]<<endl;
cout<<names[18];


	double real1 = 2;
	double complex1 = -4;
	double real2 = 6;
	double complex2 = -8;

for(int i = 0; i<50;i++){
	cout<<"_";
}
cout<<endl;
	Complex comp1(real1, complex1), comp2(real2, complex2);
	cout << "Given the values of \n"<< comp1 << "and\n"<< comp2 << "we can perform the following calculations.\n"<<endl;

	Complex compAdd = comp1 + comp2;
	cout << "Complex + complex: " << compAdd;

	Complex compSubtract = comp1 - comp2;
	cout << "Complex - complex: " << compSubtract;

	Complex compMultiply = comp1 * comp2;
	cout << "Complex * complex: " << compMultiply;

	for(int i = 0; i<50;i++){
		cout<<"_";
	}
	cout<<endl;
}

int main() {
	while (true) {
		int choice = 0;

		cout << "\nPlease enter a number from the menu:" << endl;
		cout << "1. Exercise 1\n2. Exercise 2\n3. Exit" << endl;
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

	return 0;
}
