/*
 * SigiMapper.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "SigiMapper.h"

SigiMapper::SigiMapper() : _commands(new SigiCommand*[end]),_isAwake(false),_name(""),_calcultionCount(0)
{
	//std::cout << "SigiMapper::SigiMapper()" << std::endl;

	_commands[start] = new Start(start,&_isAwake);
	_commands[calculate] = new Calculate(calculate,&_calcultionCount);
	_commands[talk] = new Talk(talk,_calcultionCount);
}

SigiMapper::~SigiMapper() {
	// TODO Auto-generated destructor stub
}

void SigiMapper::command(std::string command)
{
	std::cout << "SigiMapper::command(std::string command)" << std::endl;

	bool activate=false;
	unsigned int commandIndex, printIndex;

	//activate=_commands[start]->execute(commandIndex,printIndex);
	activate=_commands[talk]->execute(commandIndex,printIndex);

	if(activate)
	{
		std::cout << _prints[commandIndex][printIndex] << std::endl;
	}

	//std::cout << commandIndex << " " << printIndex << std::endl;
}


string const SigiMapper::_commandList[] =
{"Hey Sigi!","Sigi Calculate Please:","Good Bye Sigi!","How are you Sigi?","I want to hear"};

string const SigiMapper::_errors[end+1][4] =
{
		{"YOUR NAME IS MISSING YOUR\n", "YOUR NAME IS TOO LONG\n","I AM UP\n"},
		{},
		{},
		{"TOO COMPLICATED FOR ME"},
		{},
		{"SIGI IS ON SLEEP MODE"}
};

string const SigiMapper::_prints[end+1][4] =
{
		{},
		{"Hey <Name>!\n"},
		{"Great!","I have a bad day!","I am feeling lucky!","I am bored!"},
		{},
		{"<Name>, the result is <Number>."},
		{}
};
