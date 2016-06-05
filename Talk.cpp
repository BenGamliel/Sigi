/*
 * Talk.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Talk.h"

Talk::Talk(const size_t commandIndex, const size_t &calcultionCount, const string &name) :
	SigiCommand(commandIndex), _calcultionCount(calcultionCount), _name(name)
	{
		std::cout << "Talk::Talk(const size_t commandIndex)" << std::endl;
	}

Talk::~Talk() {
	// TODO Auto-generated destructor stub
}

bool Talk::execute(size_t &printIndex, std::vector<string> &input)
{
	std::cout << _prints[this->checkMood()] << std::endl;

	return true;
}

const size_t Talk::checkMood() const
{
	if (_calcultionCount!=0)
	{
		return (_name.size()%2)+2;
	}

	return (_name.size()%2);
}
string const Talk::_prints[] =
{"Great!","I am feeling lucky!","I have a bad day!","I am bored!"};
