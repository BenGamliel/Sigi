/*
 * Start.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Start.h"

Start::Start(const size_t commandIndex,bool* isAwake, string& name) : SigiCommand(commandIndex), _isAwake(isAwake),_name(name)
{
	std::cout << "Start::Start(size_t commandIndex, string name)" << std::endl;
}

Start::~Start() {
	// TODO Auto-generated destructor stub
}

bool Start::execute(size_t &commandIndex,size_t &printIndex,std::vector<string> &input)
{
	this->wakeUp();

	commandIndex=this->getCommandIndex();
	printIndex=this->ok;

	return true;
}

void Start::wakeUp()
{
	*_isAwake=true;
	_name="Noam";

	std::cout << "Hey " << _name << "!"<< std::endl;
}
