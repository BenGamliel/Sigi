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
	SigiCommand(bool isAwake, string name);
	virtual ~SigiCommand();

	virtual bool execute()=0;


protected:
//	virtual size_t getCommandIndex() const {return _commandIndex;}
//	virtual string getName() const {return _name;}




private:
	//const size_t _commandIndex;
    bool* _isAwake;
	string _name;
	//SigiCommand():_commandIndex(0),_name(""){} // TODO: Make it work
};

#endif /* SIGICOMMAND_H_ */
