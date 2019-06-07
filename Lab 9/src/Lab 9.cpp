//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include "employee.h"
#include "salariedemployee.h"
#include "administrator.h"
#include "figure.h"
#include "circle.h"
#include "triangle.h"
using namespace std;


void exercise1(){
	Administrator test;
		test.adminInput(cin);
		test.print(cout);
		test.print_check(cout);

}







void myDraw(Figure *fig)
{
	fig->draw();
	cout << "\n myDraw: Derived class object calling center(). \n";
	fig->center();
}

void exercise2(){
	Figure *fig;
	Triangle *tri = new Triangle;

	fig = tri;
	fig->draw();
	cout << "\n Derived class Triangle object calling center(). \n";
	fig->center();

	myDraw(tri);

	Circle *cir = new Circle;
	fig = cir;
	cir->draw();
	cout << "\n Derived class Circle object calling center(). \n";
	cir->center();

	myDraw(cir);





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
