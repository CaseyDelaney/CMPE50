/*
 * Polynomial.cpp
 *
 *  Created on: Oct 24, 2013
 *      Author: cltarng
 */


#include <iostream>
#include <cmath>
#include "Polynomial.h"
using namespace std;


Polynomial::Polynomial()
{
	degree = 10;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}
Polynomial::Polynomial(double cons)
{
	degree = 0;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
	coeff[0]+=cons;
}
Polynomial::Polynomial(int degr)
{
	degree = degr;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial &poly)
{
	degree = poly.get_degree();
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = poly.get_coeff(i);
	}
}

Polynomial::Polynomial(double cf[], int deg)
{
	degree = deg;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = cf[i];
	}
}

Polynomial::~Polynomial()
{
	delete [] coeff;
}

int Polynomial::get_degree() const
{
	return degree;
}

double Polynomial::get_coeff(int deg) const
{
	if (degree < deg)
	{
		return 0;
		// The input degree is larger than the polynomial degree
	}
	return coeff[deg];
}

void Polynomial::set_coeff(int degr, double val)
{
	if (degree < degr)
	{
		cout << "Degree exceeded." << endl;
		return;
	}
	coeff[degr] = val;
}

// Evaluate the polynomial
double Polynomial::evaluate(double val)
{
return 0.0;
}

// Assignment operator
void Polynomial::operator =(const Polynomial &poly)
{
	if (this == &poly)
	{

		// Copy to itself. Nothing to be done.
		return;
	}


}

// Overloaded operator +
Polynomial operator+(const Polynomial &pola, const Polynomial &polb)
{
bool AisMax = false;
	int thedeg = 0;
	int themin = 0;
	int dega = pola.degree;
	int degb = polb.degree;
	if (dega > degb){
		AisMax = true;
		thedeg = dega;
		themin = degb;
	}
	else if(degb>dega){
		thedeg = degb;
		themin = dega;
		AisMax = false;
	}
	else{
		thedeg = dega;
		themin = dega;

	}

	Polynomial Temp(thedeg);

for(int i = 0; i<=themin; i++){
	Temp.set_coeff(i,pola.coeff[i]+polb.coeff[i]);
}
for(int i = themin+1;i<=thedeg;i++){
if(AisMax){
	Temp.set_coeff(i,pola.coeff[i]);
}
else if(!AisMax){
	Temp.set_coeff(i,polb.coeff[i]);
}
}
	return Temp;
}
//Overloaded operator -
Polynomial operator-(const Polynomial &polya, const Polynomial &polyb){
	bool AisMax = false;
		int thedeg = 0;
		int themin = 0;
		int dega = polya.degree;
		int degb = polyb.degree;
		if (dega > degb){
			AisMax = true;
			thedeg = dega;
			themin = degb;
		}
		else if(degb>dega){
			thedeg = degb;
			themin = dega;
			AisMax = false;
		}
		else{
			thedeg = dega;
			themin = dega;

		}

		Polynomial Temp(thedeg);

	for(int i = 0; i<=themin; i++){
		Temp.set_coeff(i,polya.coeff[i]-polyb.coeff[i]);
	}
	for(int i = themin+1;i<=thedeg;i++){
	if(AisMax){
		Temp.set_coeff(i,polya.coeff[i]);
	}
	else if(!AisMax){
		Temp.set_coeff(i,polyb.coeff[i]*-1);
	}
	}
		return Temp;
}
//Overloaded * operator
Polynomial operator*(const Polynomial &polya, const Polynomial &polyb){
//pseudocode
	//Step 1. Determine the degree of each polynomial.
		//Create the new class object with degree of largest in a + largest in b
	//Step 2. Find algorithm for multiplying polynomials.
		//
	int degA = polya.degree;
	int degB = polyb.degree;
	int degreeTotal = degA + degB;

	Polynomial TempMultiply(degreeTotal);

	//Two for loops. One loops the first object from degree 0 to degree max.
	//Second loop multiplys the first loop of degree i to each of its objects from degree 0 to degree max
		//Then it adds the constant onto the appropriate degree
	double tempcoA = 0;
	double tempcoB = 0;
	double tempMultiplied = 0;

	for (int polyA = 0; polyA <= degA; polyA++){
		for(int polyB = 0; polyB <= degB; polyB++){
				tempcoA = polya.coeff[polyA];
				tempcoB = polyb.coeff[polyB];
				int newDegree = polyA + polyB;
//				cout << "\nPolyA is = " << tempcoA << " and PolyB is = " << tempcoB << " New degree:  " << newDegree;
//Above line was to test that the degree was correct
				tempMultiplied = tempcoA * tempcoB;
				TempMultiply.set_coeff(newDegree,tempMultiplied + TempMultiply.coeff[newDegree]);

		}
	}

return TempMultiply;

}
// Overloaded << operator
ostream& operator << (ostream& ost, const Polynomial &pol)
{
bool notfirst = false;
//bool equalto0 = true;
for (int i = pol.degree;i>=0;i--){
	if(pol.get_coeff(i)==0){
		continue;
	}
	else{

	}
	if(notfirst){

			ost << " + ";

	}
	notfirst = true;
	ost <<"("<< pol.get_coeff(i)<<"*x^"<<i<<")";

}
ost << endl;
return ost;
}

