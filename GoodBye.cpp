/*
 * GoodBye.cpp
 *
 *  Created on: Jun 5, 2016
 *      Author: liron_s
 */

#include "GoodBye.h"

GoodBye::GoodBye(const size_t commandIndex, bool *isAwake,const string &name) :
SigiCommand(commandIndex) , _isAwake(isAwake), _name(name)
{
//	std::cout << "GoodBye::GoodBye(const size_t commandIndex, bool *isAwake)" << std::endl;
}

GoodBye::~GoodBye() {
	// TODO Auto-generated destructor stub
}

bool GoodBye::execute(size_t &printIndex, std::vector<string> &input)
{
	std::cout << "Good Bye " << _name << "!"<< std::endl;
	*(_isAwake)=false;
	return true;
}
