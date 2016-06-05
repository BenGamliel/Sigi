/*
 * Start.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "StartCommand.h"

/*
Start::Start(const size_t commandIndex,bool* isAwake, string& name) : SigiCommand(commandIndex), _isAwake(isAwake),_name(name)
{
	std::cout << "Start::Start(size_t commandIndex, string name)" << std::endl;
}
*/
StartCommand::StartCommand (bool isAwake, std::string name):SigiCommand(isAwake,name)
{


}

StartCommand::~StartCommand()
{
	// TODO Auto-generated destructor stub
}






bool StartCommand::execute() // needs to be modify to match wakeup
{
	startstatus status=wakeUp();// checking what came back from wakeup and prints to exe
	switch (status)
	{
		case isok:
		cout <<"Hey <_name>!"<<endl;
		return true;
		case alreadyawake:
			cout <<"I AM UP"<<endl;
			return true;
		case nametooshort:
			cout <<"YOUR NAME IS MISSING YOUR"<<endl;
			return false;
		case nametoolong:
			cout <<"YOUR NAME IS TOO LONG"<<endl;
			return false;
	}




	return true;
	//commandIndex=this->getCommandIndex();
//	printIndex=this->ok;
}


startstatus StartCommand::wakeUp()
{
	if(_isAwake)
	{
		return alreadyawake;
	}
	if(_name.empty())
	{
		return nametooshort;
	}
	if(_name.size()>10)
	{
		_isAwake=false;
		return nametoolong;
	}
	else
	{
		_isAwake=true;
		return isok;
	}

}

