/*
 * SigiMapper.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "SigiMapper.h"

SigiMapper::SigiMapper() :
_commands(new SigiCommand*[END+1]),_isAwake(false),_name(""),_calcultionCount(0)
{
	_commands[START] = new Start(START,&_isAwake,_name);
	_commands[CALCULATE] = new Calculate(CALCULATE,_calcultionCount,_name);
	_commands[TALK] = new Talk(TALK,_calcultionCount,_name);
	_commands[SING] = new Sing(SING,_calcultionCount);
	_commands[END] = new GoodBye(SING,&_isAwake,_name);
}

SigiMapper::~SigiMapper()
{
	for(size_t commandIndex=0;commandIndex<END;commandIndex++)
	{
		delete _commands[commandIndex];
	}
	delete[] _commands;
}

void SigiMapper::command(const string command)
{
	if (isEmpty(command))
	{
		return;
	}

	size_t printIndex;

	std::vector<string> input = *new std::vector<string>;
	split(input,command);
	size_t commandIndex=this->getCommandIndex(input[0]);

	if (isReadyToLaunch(commandIndex,input.size()))
	{
		bool activate=_commands[commandIndex]->execute(printIndex,input);

		if(!activate)
		{
			std::cerr << _errors[commandIndex][printIndex] << std::endl;
		}
	}
}

bool SigiMapper::isReadyToLaunch(size_t commandIndex,size_t inputSize)
{
	if (((_isAwake)&&(commandIndex>END))||
			((inputSize>1)&&((commandIndex==END)||(commandIndex==TALK)))||
			((commandIndex==CALCULATE)&&(inputSize!=4)))
	{
		std::cerr << _errors[END+1][1] << std::endl;
	}
	else if(((!_isAwake)&&(commandIndex==START))||(_isAwake))
	{
		return true;
	}
	else
	{
		std::cerr << _errors[END+1][0] << std::endl;
	}
	return false;
}

void SigiMapper::split(std::vector<string> &input,const string &command)
{
	 size_t pos;
	 size_t startPos=0;
	 while(startPos<command.size())
	 {
		 pos=command.find ("<<",startPos);
		 if(pos==string::npos)
		 {
			 input.push_back(command.substr(startPos));
			 break;
		 }
		 else
		 {
			 input.push_back(command.substr(startPos,pos));
			 startPos=pos+2;
		 }
	 }
}

size_t SigiMapper::getCommandIndex(const string &inCommand)
{
	size_t index=START;
	for(; index<=END; index++)
	{
		if(inCommand.compare(_commandList[index])==0)
		{
			return index;
		}
	}

	return END+1;
}

bool SigiMapper::isEmpty(const string &command)
{
	return (command=="" || command=="\n")?true:false;
}


string const SigiMapper::_commandList[] =
{
		"Hey Sigi! ",
		"Sigi Calculate Please: ",
		"How are you Sigi? ",
		"I want to hear ",
		"Good Bye Sigi! "
};

string const SigiMapper::_errors[END+2][3] =
{
		{"YOUR NAME IS MISSING YOUR", "YOUR NAME IS TOO LONG","I AM UP"},//Start
		{"TOO COMPLICATED FOR ME"}, //Calculate
		{}, //Talk
		{"YOUR SONG NAME IS MISSING","I AM NOT FAMILIAR WITH THIS SONG"}, //Sing
		{}, //End
		{"SIGI IS ON SLEEP MODE","I DO NOT KNOW, ASK SHIRI"}, //General
};

