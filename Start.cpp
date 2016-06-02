/*
 * Start.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Start.h"

Start::Start(const unsigned int commandIndex,bool* isAwake, string name) : SigiCommand(commandIndex,name), _isAwake(isAwake)
{
	std::cout << "Start::Start(unsigned int commandIndex, string name)" << std::endl;
}

Start::~Start() {
	// TODO Auto-generated destructor stub
}

bool Start::execute(unsigned int &commandIndex,unsigned int &printIndex)
{
	this->wakeUp();

	commandIndex=this->getCommandIndex();
	printIndex=this->ok;

	return true;
}
