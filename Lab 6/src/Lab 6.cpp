//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void exercise1();
void exercise2();

class resource {

private:
	int status;
	int writeTo;

public:
	resource(); // constructor
	resource(int writeTo);

	friend bool checkStatus(resource &res1, resource &res2);

	void setStatus(int s); //mutator functions
	void setWriteTo(int w);

	int getStatus(); //accessor functions
	int getWriteTo();

	void output(ostream &stream);

};
//friend function
bool checkstatus(resource &res1, resource &res2) {

	if (res1.getStatus() == res2.getStatus() && res1.getStatus() == 1) {
		cout << "Resource is available." <<endl;
		return true;
	} else if (((res1.getStatus() == res2.getStatus())
			&& (res1.getStatus() == 0 || res2.getStatus() == 0))
			|| (res1.getStatus() == 0 || res2.getStatus() == 0)) {
		cout << "Resource is NOT available." << endl;
		return false;
	} else {
		cout << "Resource is NOT available." << endl;
		return false;
	}
}
//class resource public definitions
void resource::setStatus(int s) {
	status = s;
}
void resource::setWriteTo(int w) {
	writeTo = w;
}
int resource::getStatus() {
	return status;
}
int resource::getWriteTo() {
	return writeTo;
}
void resource::output(ostream &stream) { //Output stream that outputs to either the console or a file.
	stream << status;
}
//constructors
resource::resource() {
	status = 0;
	writeTo = 0;
}
resource::resource(int setWriteTo) {
	status = 0;
	writeTo = setWriteTo;
}
void exercise1() {
	class resource res1, res2;
	int num = 0;
	bool numEntered = false;
	while (!numEntered) {
		cout << "Please enter 0 or 1 for Resource 1.\n" << endl; // Allows user to enter a number for whether the resource
		//is available
		cin >> num;
		if (num == 0 || num == 1) {
			res1.setStatus(num);
			numEntered = true;
		} else {
			cout << "\nError. Please enter 0 or 1" << endl;
		}
	}
	numEntered = false;
	while (!numEntered) {
		cout << "Please enter 0 or 1 for Resource 2.\n" << endl;
		cin >> num;
		if (num == 0 || num == 1) {
			res2.setStatus(num);
			numEntered = true;
		} else {
			cout << "\nError. Please enter 0 or 1" << endl;
		}
	}
	checkstatus(res1, res2);
}
//Please enter 0 or 1 for Resource 1.
//
//1
//Please enter 0 or 1 for Resource 2.
//
//1
//Resource is available.
//Exercise 2
class Rational {
private:
	int numerator;
	int denominator;

public:
	Rational();
	Rational(int n, int d);
	int getnum() const;
	int getden() const;
	void input(istream &stream);
	void output(ostream &stream);
	void changesigns();
	void gcd();

	friend void add(Rational &rat1, Rational &rat2);
	friend void subtract(Rational &rat1, Rational &rat2);
	friend void multiply(Rational &rat1, Rational &rat2);
	friend void divide(Rational &rat1, Rational &rat2);
	friend bool equal(const Rational &rat1, const Rational &rat2);
	friend bool lessthan(const Rational &rat1, const Rational &rat2);
};
//friend function definitions
void add(Rational &rat1, Rational &rat2) {
	int num1 = rat1.getnum();
	int num2 = rat2.getnum();
	int den1 = rat1.getden();
	int den2 = rat2.getden();
	cout << "\nThe input numbers are: " << num1 << "/" << den1 << " and " << num2
			<< "/" << den2 << endl;
	int addnum = 0;
	int addden = 0;
	int temp1 = den1;
	num1 = num1 * den2;
	den1 = den1 * den2;
	num2 = num2 * temp1;

	addnum = num1 + num2;
	addden = den1;

	if (addnum < 0 && addden < 0) {
		addnum = addnum * -1;
		addden = addden * -1;
	} else if (addnum >= 0 && addden < 0) {
		addnum = addnum * -1;
		addden = addden * -1;
	}
	int gcd = 0;
	int temp = 0;
	;
	int num = addnum;
	int den = addden;

	while (den != 0) {
		// cout << "n2 = " << n2 << endl;
		temp = num;
		num = den;
		den = temp % den;
	}

	gcd = abs(num);

	addnum = addnum / gcd;
	addden = addden / gcd;
	cout << "The added number is: " << addnum << "/" << addden << endl;
}
void subtract(Rational &rat1, Rational &rat2) {
	int num1 = rat1.getnum();
	int num2 = rat2.getnum();
	int den1 = rat1.getden();
	int den2 = rat2.getden();

	int subnum = 0;
	int subden = 0;
	int temp1 = den1;
	num1 = num1 * den2;
	den1 = den1 * den2;
	num2 = num2 * temp1;

	subnum = num1 - num2;
	subden = den1;

	if (subnum < 0 && subden < 0) {
		subnum = subnum * -1;
		subden = subden * -1;
	} else if (subnum >= 0 && subden < 0) {
		subnum = subnum * -1;
		subden = subden * -1;
	}
	int gcd = 0;
	int temp = 0;
	;
	int num = subnum;
	int den = subden;

	while (den != 0) {
		// cout << "n2 = " << n2 << endl;
		temp = num;
		num = den;
		den = temp % den;
	}

	gcd = abs(num);

	subnum = subnum / gcd;
	subden = subden / gcd;
	cout << "The subtracted number is: " << subnum << "/" << subden << endl;
}
void multiply(Rational &rat1, Rational &rat2) {
	int num1 = rat1.getnum();
	int num2 = rat2.getnum();
	int den1 = rat1.getden();
	int den2 = rat2.getden();

	int multnum = num1 * num2;
	int multden = den1 * den2;

	if (multnum < 0 && multden < 0) {
		multnum = multnum * -1;
		multden = multden * -1;
	} else if (multnum >= 0 && multden < 0) {
		multnum = multnum * -1;
		multden = multden * -1;
	}
	int gcd = 0;
	int temp = 0;
	;
	int num = multnum;
	int den = multden;

	while (den != 0) {
		// cout << "n2 = " << n2 << endl;
		temp = num;
		num = den;
		den = temp % den;
	}

	gcd = abs(num);

	multnum = multnum / gcd;
	multden = multden / gcd;
	cout << "The multiplied number is: " << multnum << "/" << multden << endl;
}
void divide(Rational &rat1, Rational &rat2) {
	int num1 = rat1.getnum();
	int num2 = rat2.getnum();
	int den1 = rat1.getden();
	int den2 = rat2.getden();

	int divnum = num1 * den2;
	int divden = den1 * num2;

	if (divnum < 0 && divden < 0) {
		divnum = divnum * -1;
		divden = divden * -1;
	} else if (divnum >= 0 && divden < 0) {
		divnum = divnum * -1;
		divden = divden * -1;
	}
	int gcd = 0;
	int temp = 0;
	;
	int num = divnum;
	int den = divden;

	while (den != 0) {
		// cout << "n2 = " << n2 << endl;
		temp = num;
		num = den;
		den = temp % den;
	}

	gcd = abs(num);

	divnum = divnum / gcd;
	divden = divden / gcd;
	cout << "The divided number is: " << divnum << "/" << divden << endl;
}
bool equal(const Rational &rat1, const Rational &rat2){
	if(rat1.getnum() * rat2.getden() ==rat2.getnum() *rat1.getden()){
		return true;
	}
	else{
		return false;
	}
}
bool lessthan(const Rational &rat1, const Rational &rat2){
if(rat1.getnum()<0 && rat2.getnum() >=0){
	return true;
}
if(rat1.getnum()>=0 && rat2.getnum() >=0){
if(rat1.getnum() * rat2.getden() < rat2.getnum() *rat1.getden()){
	return true;
}
else{
	return false;
}
}
if(rat1.getnum()<0 && rat2.getnum() <0){

}
if(rat1.getnum() * rat2.getden() < rat2.getnum() *rat1.getden()){
	return true;
}
else{
	return false;
}
}
//Rational class definitions
void Rational::input(istream &stream) {

	cout << "\nEnter the numerator:" << endl;
	stream >> numerator;
	cout << "\nEnter the denominator:" << endl;
	stream >> denominator;
	cout << "The input is: " << numerator << "/" << denominator;
}
void Rational::output(ostream &stream) {
	cout << "\nThe output is: " << numerator << "/" << denominator << endl;
}
void Rational::changesigns() {
	if (numerator < 0 && denominator < 0) {
		numerator = numerator * -1;
		denominator = denominator * -1;
	} else if (numerator >= 0 && denominator < 0) {
		numerator = numerator * -1;
		denominator = denominator * -1;
	}
}
void Rational::gcd() {
	int gcd = 0;
	int temp = 0;
	;
	int num = numerator;
	int den = denominator;

	while (den != 0) {
		// cout << "n2 = " << n2 << endl;
		temp = num;
		num = den;
		den = temp % den;
	}

	gcd = abs(num);
	numerator = numerator / gcd;
	denominator = denominator / gcd;

}
int Rational::getnum() const {
	return numerator;
}
int Rational::getden() const {
	return denominator;
}

//constructors
Rational::Rational() {
	numerator = 0;
	denominator = 0;		// default
}
Rational::Rational(int n, int d) {
	numerator = n;
	denominator = d;
}
void exercise2() {
	Rational num1, num2;

	num1.input(cin);
	num1.changesigns();
	num1.output(cout);
	num1.gcd();
	num2.input(cin);
	num2.changesigns();
	num2.output(cout);
	num2.gcd();
	add(num1, num2);
	subtract(num1, num2);
	multiply(num1, num2);
	divide(num1,num2);
	if(equal(num1,num2)){
		cout <<"The numbers are equal."<<endl;
	}
	else{
		cout << "The numbers are not equal."<<endl;
	}
	if(lessthan(num1,num2)){
		cout << "Num1 is less than num2"<<endl;
	}
	else{
		cout <<"Num1 is not less than num2"<<endl;
	}
}

//The input numbers are: 1/2 and -1/2
//The added number is: 0/1
//The subtracted number is: 1/1
//The multiplied number is: -1/4
//The divided number is: -1/1
//The numbers are not equal.
//Num1 is not less than num2
int main() {

	int choice = 0;
	while (true) {
		cout
				<< "\nPlease choose a menu option:\n1. Exercise 1\n2. Exercise 2\n3. Exit the Program"
				<< endl;
		cin >> choice;
		if (choice == 1) {
			exercise1();
		} else if (choice == 2) {
			exercise2();
		} else if (choice == 3) {
			break;
		} else {
			cout << "\nPlease enter a valid choice, 1, 2, or 3" << endl;
		}
	}
}
