/*
 * SigiMapper.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "SigiMapper.h"

SigiMapper::SigiMapper() : _commands(new SigiCommand*[END]),_isAwake(false),_name(""),_calcultionCount(0)
{
	//std::cout << "SigiMapper::SigiMapper()" << std::endl;

	_commands[START] = new Start(START,&_isAwake,_name);
	_commands[calculate] = new Calculate(calculate,_calcultionCount,_name);
	_commands[talk] = new Talk(talk,_calcultionCount,_name);
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

//	delete _commands[END];

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
//	std::cout<<this->getCommandIndex(input[0])<<std::endl;

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
			((inputSize>1)&&((commandIndex==END)||(commandIndex==talk))))
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

void SigiMapper::split(std::vector<string> &tempVec,const string &command)
{
	 size_t pos;
	 size_t STARTpos=0;
	 while(STARTpos<command.size())
	 {
		 pos=command.find ("<<",STARTpos);
		 if(pos==string::npos)
		 {
			 tempVec.push_back(command.substr(STARTpos));
			 break;
		 }
		 else
		 {
			 tempVec.push_back(command.substr(STARTpos,pos));
			 STARTpos=pos+2;
		 }
	 }
//Temp printing
//	 for (size_t i=0;i<tempVec.size();i++)
//		 std::cout<<tempVec[i]<<std::endl;
}

size_t SigiMapper::getCommandIndex(const string &inCommand)
{
//	std::cout<<inCommand<<std::endl;
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
	if (command=="" || command=="\n")
	{
		return true;
	}

	return false;
}


string const SigiMapper::_commandList[] =
{"Hey Sigi! ","Sigi Calculate Please: ","How are you Sigi?","I want to hear ","Good Bye Sigi!"};

string const SigiMapper::_errors[END+2][3] =
{
		{"YOUR NAME IS MISSING YOUR", "YOUR NAME IS TOO LONG","I AM UP"}, //START
		{"TOO COMPLICATED FOR ME"}, //calculate
		{}, //talk
		{"YOUR SONG NAME IS MISSING","I AM NOT FAMILIAR WITH THIS SONG"}, //sing
		{}, //END
		{"SIGI IS ON SLEEP MODE","I DO NOT KNOW, ASK SHIRI"}, //general
};

