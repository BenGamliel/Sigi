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

	_commands[start] = new Start(start,&_isAwake,_name);
	_commands[calculate] = new Calculate(calculate,&_calcultionCount);
	_commands[talk] = new Talk(talk,_calcultionCount,_name);
	_commands[sing] = new Sing(sing,_calcultionCount);
}

SigiMapper::~SigiMapper()
{
//	for(size_t commandIndex=0;commandIndex<end;commandIndex++)
//	{
//		delete _commands[commandIndex];
//	}
//	delete[] _commands;

}

void SigiMapper::command(std::string command)
{
	size_t printIndex, commandIndex=this->findCommand(command);
	std::vector<string> input;

	std::cout << _isAwake << std::endl;

	if (isReadyToLaunch(commandIndex))
	{
		bool activate=_commands[commandIndex]->execute(commandIndex,printIndex,input);
		if(activate)
		{
			std::cout << _prints[commandIndex][printIndex] << std::endl;
		}
		else
		{
			std::cout << _errors[commandIndex][printIndex] << std::endl;
		}
	}
}

bool SigiMapper::isReadyToLaunch(size_t commandIndex)
{
	if(((!_isAwake)&&(commandIndex==start))||(_isAwake))
	{
//		if ((_isAwake)&&(commandIndex!=start))
		return true;
	}
	else
	{
		std::cerr << _errors[0][0] << std::endl;
	}
	return false;
}

size_t SigiMapper::findCommand(string command)
{
	if (command=="hi")  return start;
	if (command=="sing") return sing;
	if (command=="calc") return calculate;
	if (command=="talk") return talk;

	return end+1;
}


string const SigiMapper::_commandList[] =
{"Hey Sigi!","Sigi Calculate Please:","Good Bye Sigi!","How are you Sigi?","I want to hear"};

string const SigiMapper::_errors[end+1][4] =
{
		{"SIGI IS ON SLEEP MODE","I DO NOT KNOW, ASK SHIRI"},
		{"YOUR NAME IS MISSING YOUR", "YOUR NAME IS TOO LONG","I AM UP"},
		{},
		{},
		{"TOO COMPLICATED FOR ME"},
		{}
};

string const SigiMapper::_prints[end+1][4] =
{
		{},
		{"Hey <Name>!"},
		{"Great!","I have a bad day!","I am feeling lucky!","I am bored!"},
		{
				"Mamma mia, here I go again\n"
				"My my, how can I resist you",

				"Mamma mia, does it show again\n"
				"My my, just how much I've missed you",

				"What can I do\nGirl to get through to you\n"
				"Cause I love you, baby",

				"Say, say, say what you want\n"
				"But don't play games with my affection"
		},
		{"<Name>, the result is <Number>."},
		{}
};
