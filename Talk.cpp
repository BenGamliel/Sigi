/*
 * Talk.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Talk.h"
/*
Talk::Talk(const size_t commandIndex, const size_t &calcultionCount, const string &name) :
	SigiCommand(commandIndex), _calcultionCount(calcultionCount), _name(name)
	{
		std::cout << "Talk::Talk(const size_t commandIndex)" << std::endl;
	}

Talk::~Talk() {
	// TODO Auto-generated destructor stub
}

bool Talk::execute(size_t &commandIndex,size_t &printIndex, std::vector<string> &input)
{
	commandIndex=this->getCommandIndex();
	printIndex=this->checkMood();

	//std::cout << "_calcultionCount=" << _calcultionCount << std::endl;
	return true;
}

const size_t Talk::checkMood() const
{
	if (_calcultionCount!=0)
	{
		return (_name.size()%2)+2;
	}

	return (_name.size()%2);
}
*/
