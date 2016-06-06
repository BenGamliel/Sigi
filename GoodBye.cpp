/*
 * GoodBye.cpp
 *
 *  Created on: Jun 5, 2016
 *      Author: liron_s
 */

#include "GoodBye.h"

bool GoodBye::execute(size_t &printIndex, std::vector<string> &input)
{
	std::cout << "Good Bye " << _name << "!"<< std::endl;
	*(_isAwake)=false;
	return true;
}
