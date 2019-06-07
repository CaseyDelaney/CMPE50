/*
 * Complex-definitions.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: caseydelaney
 */

#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

void Complex::setReal(double r) {
	real = r;
}
void Complex::setComplex(double c) {
	complex = c;
}
double Complex::getReal() {
	return real;
}
double Complex::getComplex() {
	return complex;
}
Complex::Complex() {
	real = 0;
	complex = 0;
}
Complex::Complex(double r, double c) {
	real = r;
	complex = c;
}
Complex::Complex(double real_part) {
	real = real_part;
	complex = 0;
}

Complex operator+(const Complex &comp1, const Complex &comp2) {
	Complex complexreturn;
	complexreturn.setReal(comp1.real + comp2.real);
	complexreturn.setComplex(comp1.complex + comp2.complex);

	return complexreturn;

}
Complex operator-(const Complex &comp1, const Complex &comp2) {
	Complex complexreturn;
	complexreturn.setReal(comp1.real - comp2.real);
	complexreturn.setComplex(comp1.complex - comp2.complex);

	return complexreturn;
}
Complex operator*(const Complex &comp1, const Complex &comp2) {
	Complex complexreturn;
		complexreturn.setReal((comp1.real * comp2.real) - (comp1.complex*comp2.complex));
		complexreturn.setComplex((comp1.complex * comp2.real) + (comp1.real * comp2.complex));

		return complexreturn;
}
ostream& operator <<(ostream& ost, const Complex &comp1) {

	if(comp1.real != 0){ // only output if it is not equal to 0, otherwise continue
		if(comp1.real >0){
					ost << comp1.real;
				}
				else if(comp1.real <0){
					double tempout = abs(comp1.real);
					ost << "- " << tempout;
				}
	}

	if(comp1.complex != 0){
		if(comp1.complex >0){
			ost <<	" + "<< comp1.complex <<"i"<<endl;
		}
		else if(comp1.complex <0){
			double tempout = abs(comp1.complex);
			ost << " - " << tempout<<"i"<<endl;
		}


	}

	return ost;
}
