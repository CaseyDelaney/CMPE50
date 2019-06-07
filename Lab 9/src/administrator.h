/*
 * administrator.h
 *
 *  Created on: May 7, 2019
 *      Author: caseydelaney
 */

#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_


#include "salariedemployee.h"

using namespace std;

class Administrator : public SalariedEmployee
{
public:
	Administrator();
	void set_supervisor(string name);
	void adminInput(istream& input);
	void print(ostream& output);
	void print_check(ostream& output);
private:
	string title;
	string responsibility;
	string supervisorname;

};



#endif /* ADMINISTRATOR_H_ */
