/*
 * Start.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef START_H_
#define START_H_
/*
 * This Module is responsible for turning On the system and starting the
 * conversation with the user.
 *
 * Start(const size_t commandIndex, bool* isAwake, string &name) -
 * The Constructor
 *
 *  bool execute(size_t &printIndex,std::vector<string> &input) -
 * Responsible to the execution of the Start command.
 *
 *
 */
#include "SigiCommand.h"

class Start : public SigiCommand {
public:
/*
 * Start(const size_t commandIndex, bool* isAwake, string &name) -
 * The Constructor
 *
 * @param commandIndex - sets the numeric index of the command
 * @param isAwake - a pointer to the variable in SigiMapper
 * which holds the On/Off Mode of the system.
 * @param name - a string reference to the user's name variable
 */
	Start(const size_t commandIndex, bool* isAwake, string &name) :
		SigiCommand(commandIndex), _isAwake(isAwake),_name(name){}
	virtual ~Start(){}

/*
 * bool execute(size_t &printIndex,std::vector<string> &input) -
 * Responsible to the execution of the command.
 *
 * @param printIndex - Then function updates this reference variable to hold the
 *  numeric index of the relevant print string in case of error.
 * Will not change it in case of success.
 * @param input - A vector which holds the command in index 0
 * and the relevant input for the command, (meaning the name) in index 1.
 *
 * @ return - true for success, false for error.
 */
	bool execute(size_t &printIndex,std::vector<string> &input);

private:
	enum Errors {NO_NAME=0,NAME_TOO_LONG,ALREADY_AWAKE};
	// Variables
	bool *_isAwake;
	string &_name;

	// Functions
	void wakeUp(const string &name);

	// Constructors that shall not be used
	Start():SigiCommand(0),_isAwake(NULL),_name(*new string){}
};

#endif /* START_H_ */
