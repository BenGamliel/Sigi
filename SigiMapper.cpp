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
	_commands[calculate] = new Calculate(calculate,_calcultionCount,_name);
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

void SigiMapper::command(const string command)
{
	size_t printIndex;

	std::vector<string> input = *new std::vector<string>;
	split(input,command);
	size_t commandIndex=this->getCommandIndex(input[0]);
//	std::cout<<this->getCommandIndex(input[0])<<std::endl;

	if (isReadyToLaunch(commandIndex))
	{
		bool activate=_commands[commandIndex]->execute(printIndex,input);

		if(!activate)
		{
			std::cerr << _errors[commandIndex][printIndex] << std::endl;
		}
	}
}

bool SigiMapper::isReadyToLaunch(size_t commandIndex)
{
	if ((_isAwake)&&(commandIndex>end))
	{
		std::cerr << _errors[end+1][1] << std::endl;
	}
	else if(((!_isAwake)&&(commandIndex==start))||(_isAwake))
	{
		return true;
	}
	else
	{
		std::cerr << _errors[end+1][0] << std::endl;
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

void SigiMapper::split(std::vector<string> &tempVec,string command)
{
	 size_t pos;
	 size_t startpos=0;
	 while(startpos<command.size())
	 {
		 pos=command.find ("<<",startpos);
		 if(pos==string::npos)
		 {
			 tempVec.push_back(command.substr(startpos));
			 break;
		 }
		 else
		 {
			 tempVec.push_back(command.substr(startpos,pos));
			 startpos=pos+2;
		 }
	 }
//Temp printing
//	 for (size_t i=0;i<tempVec.size();i++)
//		 std::cout<<tempVec[i]<<std::endl;
}

size_t SigiMapper::getCommandIndex(const string inCommand)
{
//	std::cout<<inCommand<<std::endl;
	for(size_t index=start; index<=end; index++)
	{
		if(inCommand.compare(_commandList[index])==0)
		{
			return index;
		}
	}
	return end+1;

}

string const SigiMapper::_commandList[] =
{"Hey Sigi! ","Sigi Calculate Please: ","How are you Sigi?","I want to hear ","Good Bye Sigi!"};

string const SigiMapper::_errors[end+2][4] =
{
		{"YOUR NAME IS MISSING YOUR", "YOUR NAME IS TOO LONG","I AM UP"}, //start
		{"TOO COMPLICATED FOR ME"}, //calculate
		{}, //talk
		{"YOUR SONG NAME IS MISSING","I AM NOT FAMILIAR WITH THIS SONG"}, //sing
		{}, //end
		{"SIGI IS ON SLEEP MODE","I DO NOT KNOW, ASK SHIRI"}, //general
};

