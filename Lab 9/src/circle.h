/*
 * circle.h
 *
 *  Created on: May 7, 2019
 *      Author: caseydelaney
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
#include "figure.h"

using namespace std;

class Circle: public Figure {
public:
		void erase();
	 void draw();
	 void center();
};

#endif /* CIRCLE_H_ */
