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
//	SigiCommand(size_t commandIndex, const string &name);
	SigiCommand(size_t commandIndex);
	virtual ~SigiCommand();

	virtual bool execute(size_t &printIndex,std::vector<string> &input)=0;
//	virtual bool execute(size_t &commandIndex,size_t &printIndex,
//			std::vector<string> input)=0;

protected:
	virtual size_t getCommandIndex() const {return _commandIndex;}
//	virtual string getName() const {return _name;}



private:
	const size_t _commandIndex;
//	const string &_name;

	//SigiCommand():_commandIndex(0),_name(""){} // TODO: Make it work
};

#endif /* SIGICOMMAND_H_ */
