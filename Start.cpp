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

bool Start::execute(size_t &printIndex,std::vector<string> &input)
{
	if (*_isAwake)
	{
		printIndex=ALREADY_AWAKE;
		return false;
	}

	if((input.size()==2)&&(input[1].size()<10))
	{
		this->wakeUp(input[1]);
		return true;
	}

	input.size()<2?printIndex=NO_NAME:printIndex=NAME_TOO_LONG;

	return false;
}

void Start::wakeUp(const string name)
{
	*_isAwake=true;
	_name=name;

	std::cout << "Hey " << _name << "!"<< std::endl;
}

