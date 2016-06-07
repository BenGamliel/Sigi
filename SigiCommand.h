/*
 * SigiCommand.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef SIGICOMMAND_H_
#define SIGICOMMAND_H_

/*
 * SigiCommand(size_t commandIndex):_commandIndex(commandIndex) -
 * The Constructor
 *
 * virtual bool execute(size_t &printIndex,std::vector<string> &input) -
 * A Pure Virtual function which is responsible to the execution of the command.
 */

#include <iostream>
#include <string>
#include <vector>
using std::string;

class SigiCommand {
public:
/*
 * SigiCommand(size_t commandIndex):_commandIndex(commandIndex) -
 * The Constructor
 *
 * @param commandIndex - sets the numeric index of the command
 */
	SigiCommand(size_t commandIndex):_commandIndex(commandIndex){}
	virtual ~SigiCommand(){}
/*
 *  virtual bool execute(size_t &printIndex,std::vector<string> &input) -
 * A Pure Virtual function which is responsible to the execution of the command.
 *
 * @param printIndex - Then function updates this reference variable to hold the
 *  numeric index of the relevant print string in case of error.
 * Will not change it in case of success.
 * @param input - A vector which holds the relevant input for the command
 *
 * @ return - true for success, false for error.
 */
	virtual bool execute(size_t &printIndex,std::vector<string> &input)=0;

protected:
	virtual size_t getCommandIndex() const {return _commandIndex;}

private:
	const size_t _commandIndex;
};

#endif /* SIGICOMMAND_H_ */
