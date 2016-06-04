/*
 * Sing.cpp
 *
 *  Created on: Jun 3, 2016
 *      Author: liron_s
 */

#include "Sing.h"

Sing::Sing(const size_t commandIndex, const size_t &calcultionCount)
:SigiCommand(commandIndex),_calcultionCount(calcultionCount)
{

	std::cout << "Sing::Sing(const size_t commandIndex)" << std::endl;

}

Sing::~Sing() {
	// TODO Auto-generated destructor stub
}

bool Sing::execute(size_t &commandIndex,size_t &printIndex, std::vector<string> &input)
{
	commandIndex=this->getCommandIndex();
	printIndex=0+(_calcultionCount%2);

	return true;
}
