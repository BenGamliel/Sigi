/*
 * GoodBye.h
 *
 *  Created on: Jun 5, 2016
 *      Author: liron_s
 */

#ifndef GOODBYE_H_
#define GOODBYE_H_
/*
 * This Module is responsible for turning Off the system and ending the
 * conversation with the user.
 *
 * GoodBye(const size_t commandIndex, bool *isAwake,const string &name) -
 * The Constructor
 *
 * bool execute(size_t &commandIndex,size_t &printIndex) -
 * Responsible to the execution of the command.
 *
 */
#include "SigiCommand.h"

class GoodBye : public SigiCommand {
public:
/*
 * GoodBye(const size_t commandIndex, bool *isAwake,const string &name) -
 * The Constructor
 *
 * @param commandIndex - sets the numeric index of the command
 * @param isAwake - a pointer to the variable in SigiMapper
 * which holds the On/Off Mode of the system.
 * @param name - a string reference to the user's name variable.
 * Will not change it.
 */
	GoodBye(const size_t commandIndex, bool *isAwake,const string &name) :
		SigiCommand(commandIndex) , _isAwake(isAwake), _name(name){}
	virtual ~GoodBye(){}

/*
 * bool execute(size_t &commandIndex,size_t &printIndex) -
 * Responsible to the execution of the command.
 *
 * @param printIndex - Then function updates this reference variable to hold the
 *  numeric index of the relevant print string in case of error.
 * Will not change it in case of success.
 * @param input - A vector which holds only the command in index 0.
 * The rest of the vector must be empty.
 *
 * @ return - true for success, false for error.
 *
 */
	bool execute(size_t &printIndex, std::vector<string> &input);

private:
		// Variables
	bool *_isAwake;
	const string &_name;

		// Constructors that shall not be used
	GoodBye() :	SigiCommand(0) , _isAwake(new bool), _name(*new string){}
};

#endif /* GOODBYE_H_ */
