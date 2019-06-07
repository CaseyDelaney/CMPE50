/*
 * Complex.h
 *
 *  Created on: Apr 24, 2019
 *      Author: caseydelaney
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

//Class to implement complex operations
class Complex {
public:
	Complex();
	Complex(double r, double c);
	Complex(double real_part);

	void setReal(double r);
	void setComplex(double c);
	double getReal();
	double getComplex();

	friend Complex operator+(const Complex &comp1, const Complex &comp2);
	friend Complex operator-(const Complex &comp1, const Complex &comp2);
	friend Complex operator*(const Complex &comp1, const Complex &comp2);
	friend ostream& operator <<(ostream& ost, const Complex &comp1);

private:
	double real;
	double complex;
};

#endif /* COMPLEX_H_ */
