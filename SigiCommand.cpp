/*
 * SigiCommand.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "SigiCommand.h"

SigiCommand::SigiCommand(bool isAwake, string name)
{
	_isAwake=isAwake;
	_name=name;
	//std::cout << "SigiCommand::SigiCommand(size_t commandIndex, string name)" << std::endl;
}

//SigiCommand::SigiCommand(size_t commandIndex, const string &name) : _commandIndex(commandIndex), _name(name)
//{
//
//}

SigiCommand::~SigiCommand() {
	// TODO Auto-generated destructor stub
}

