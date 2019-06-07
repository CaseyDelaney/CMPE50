/*
 * administrator.cpp
 *
 *  Created on: May 7, 2019
 *      Author: caseydelaney
 */

#include <iostream>
#include <string>
#include "administrator.h"
using namespace std;

Administrator::Administrator() : SalariedEmployee ()
{

}
void Administrator::set_supervisor(string name){
supervisorname = name;
}
void Administrator::adminInput(istream& input){
	cout << "Please input your name:"<<endl;
	input >> name;

	cout <<"Please input your SSN:"<<endl;
	input >> ssn;

	cout <<"Please input your title:"<<endl;
	input >> title;

	cout <<"Please input your responsibility:\n";
	input >> responsibility;

	cout << "Please input your supervisor's name:\n";
	input >> supervisorname;

	cout << "Please input your annual salary"<<endl;
	input >> net_pay;

}
void Administrator::print(ostream& output){
output <<"Name: "<<name<<endl;
output <<"Title: "<<title<<endl;
output <<"Responsibility: "<<responsibility<<endl;
output<<"Supervisor's Name: "<<supervisorname<<endl;
output << "Annual Pay: $"<< net_pay <<endl;

}
void Administrator::print_check(ostream& output){
output <<"Pay to the order of: "<<name<<"______________________________  $"<<net_pay/24<<endl;
output <<"SSN: "<<ssn<<"________________"<<endl;
}

