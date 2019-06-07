/*
 * triangle.h
 *
 *  Created on: May 7, 2019
 *      Author: caseydelaney
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include "figure.h"

class Triangle: public Figure {
public:
	 void erase();
	 void draw();
	 void center();
};

#endif /* TRIANGLE_H_ */
