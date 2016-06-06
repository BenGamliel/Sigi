/*
 * SigiMapper.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "SigiMapper.h"
#include "StartCommand.h"
using namespace std;
/*
SigiMapper::SigiMapper() : _commands(new SigiCommand*[end]),_isAwake(false),_name(""),_calcultionCount(0)
{
	//std::cout << "SigiMapper::SigiMapper()" << std::endl;

	_commands[start] = new Start(start,&_isAwake,_name);
	_commands[talk] = new Talk(talk,_calcultionCount,_name);
	_commands[sing] = new Sing(sing,_calcultionCount);
	_commands[calculate] = new Calculate(calculate,_calcultionCount);
}

*/
SigiMapper::SigiMapper()
{
	_calcultionCount=0; //  when end change the value to zero again
	//
}

SigiMapper::~SigiMapper()
{
//	for(size_t commandIndex=0;commandIndex<end;commandIndex++)
//	{
//		delete _commands[commandIndex];
//	}
//	delete[] _commands;

}
/*
void SigiMapper::command(string command)
{
	size_t printIndex, commandIndex=this->findCommand(command);
	std::vector<string> input;

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
*/
Commands SigiMapper ::getCommand(string inCommand)
{
	for(Commands index=start; index<=end; index++)
	{
		if(inCommand.find(_commandList[index]))
		{
			return index;
		}
	}
	return end;

}

void SigiMapper::findCommand(string command) //will find the command it self and make
{
	std::vector <string> tempVec=split(command);
	Commands inCommand=getCommand(tempVec[0]);
	switch (inCommand)
	{
			case(start):
				StartCommand *commandstart= new StartCommand (_isAwake,tempVec[1]);
				_isAwake=commandstart.execute();
				if(_isAwake)// no else the execute already handle it if _isawake = false
				{
				_name=tempVec[1];
			//	_calcultionCount++;
				}

			case(sing):
				SigiSing sigising(_isAwake,_calcultionCount,tempVec[1]);
				if(_isAwake)
				{
					bool temp=sigising.execute();
					if(temp)
					{
						_calcultionCount++;
					}

				}
				else
				{
					cout <<"SIGI IS ON SLEEP MODE"<< endl:
				}
			case(talk):
			case(calculate):
			case(end):

	}

}


 // can't match a command -> going to error with 0- to print unknow command
}
std::vector <string> SigiMapper::split(string command)
{
	 vector<string> tempVec;
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

	 return tempVec;
}


/*
bool SigiMapper::isReadyToLaunch(size_t commandIndex)
{
	if(((!_isAwake)&&(commandIndex==start))||(_isAwake)) //verify the command if awake continue if not see if awake
	{
		return true;
	}
	else
	{
		std::cerr << _errors[0][0] << std::endl;
	}
	return false;
}
*/

string const SigiMapper::_commandList[] =
{		"Hey Sigi!",
		"Sigi Calculate Please:",
		"Good Bye Sigi!",
		"How are you Sigi?",
		"I want to hear"
};

string const SigiMapper::_errors[end][4] =
{
		{"SIGI IS ON SLEEP MODE",
		"I DO NOT KNOW, ASK SHIRI"
		},
		{"YOUR NAME IS MISSING YOUR",
		"YOUR NAME IS TOO LONG","I AM UP"
		},
		{},
		{},
		{"TOO COMPLICATED FOR ME"},
		{}
};

string const SigiMapper::_prints[end][4] =
{
		{},
		{"Hey <Name>!"},
		{
		"Great!",
		"I am feeling lucky!",
		"I have a bad day!","I am bored!"
		},
		{"<Name>, the result is <Number>."},
		{}
};

