/*
 * Calculate.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Calculate.h"

Calculate::Calculate(const size_t commandIndex, size_t *calcultionCount):
SigiCommand(commandIndex),_calcultionCount(calcultionCount)
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
