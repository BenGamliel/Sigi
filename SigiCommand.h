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
	SigiCommand(unsigned int commandIndex, string name = "");
	virtual ~SigiCommand();

	virtual bool execute(unsigned int &commandIndex,unsigned int &printIndex)=0;
//	virtual bool execute(unsigned int &commandIndex,unsigned int &printIndex,
//			std::vector<string> input)=0;

protected:
	virtual unsigned int getCommandIndex() const {return _commandIndex;}
	virtual string getName() const {return _name;}



private:
	const unsigned int _commandIndex;
	string _name;

	//SigiCommand():_commandIndex(0),_name(""){} // TODO: Make it work
};

#endif /* SIGICOMMAND_H_ */
