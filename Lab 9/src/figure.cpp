/*
 * figure.cpp
 *
 *  Created on: May 7, 2019
 *      Author: caseydelaney
 */

#include <iostream>

#include "figure.h"
using namespace std;

void Figure::erase() {
	cout << "Calling  erase (figure)" << endl;
}
void Figure::draw() {
	cout << "Calling draw (figure)" << endl;
}

void Figure::center() {
	cout << "Calling center (figure)" << endl;
	erase();
	draw();

}

