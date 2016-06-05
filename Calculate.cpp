/*
 * Calculate.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Calculate.h"

Calculate::Calculate(const size_t commandIndex, size_t &calcultionCount,string const &name):
SigiCommand(commandIndex),_calcultionCount(calcultionCount),_name(name)
{
	std::cout << "Calculate::Calculate(size_t *calcultionCount)" << std::endl;
}

Calculate::~Calculate() {
	// TODO Auto-generated destructor stub
}

int Calculate::add(const unsigned int numA,const unsigned int numB,const int factor) const
{
	return numA+(factor*numB);
}

bool Calculate::execute(size_t &printIndex,std::vector<string> &input)
{
	input.clear();
	unsigned int numA=5,numB=3;
	std::cout << _name <<", the result is "<< this->add(numA,numB) <<"." << std::endl;
//	"
	_calcultionCount++;
	return true;
}
