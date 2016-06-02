/*
 * Calculate.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Calculate.h"

Calculate::Calculate(const unsigned int commandIndex, unsigned int *calcultionCount):
SigiCommand(commandIndex),_calcultionCount(calcultionCount)
{
	std::cout << "Calculate::Calculate(unsigned int *calcultionCount)" << std::endl;
}

Calculate::~Calculate() {
	// TODO Auto-generated destructor stub
}

