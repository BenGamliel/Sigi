/*
 * Talk.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Talk.h"

Talk::Talk(const unsigned int commandIndex, const unsigned int &calcultionCount) :
	SigiCommand(commandIndex), _calcultionCount(calcultionCount)
	{
		std::cout << "Talk::Talk(unsigned int commandIndex)" << std::endl;
	}

Talk::~Talk() {
	// TODO Auto-generated destructor stub
}

bool Talk::execute(unsigned int &commandIndex,unsigned int &printIndex)
{
	commandIndex=this->getCommandIndex();
	printIndex=this->checkMood();

	//std::cout << "_calcultionCount=" << _calcultionCount << std::endl;
	return true;
}
