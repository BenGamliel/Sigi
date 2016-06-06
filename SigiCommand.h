/*
 * SigiCommand.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef SIGICOMMAND_H_
#define SIGICOMMAND_H_

#include <iostream>
#include <string>
#include <vector>
using std::string;

class SigiCommand {
public:
	SigiCommand(size_t commandIndex):_commandIndex(commandIndex){}
	virtual ~SigiCommand(){}

	virtual bool execute(size_t &printIndex,std::vector<string> &input)=0;

protected:
	virtual size_t getCommandIndex() const {return _commandIndex;}

private:
	const size_t _commandIndex;

//	SigiCommand():_commandIndex(0),_name(""){} // TODO: Make it work
};

#endif /* SIGICOMMAND_H_ */
