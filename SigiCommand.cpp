/*
 * SigiCommand.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "SigiCommand.h"

SigiCommand::SigiCommand(unsigned int commandIndex, string name):_commandIndex(commandIndex),_name(name)
{
	//std::cout << "SigiCommand::SigiCommand(unsigned int commandIndex, string name)" << std::endl;
}

SigiCommand::~SigiCommand() {
	// TODO Auto-generated destructor stub
}

