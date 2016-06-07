/*
 * Talk.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef TALK_H_
#define TALK_H_
/*
 * This Module is responsible for answering the user about Sigi's Mood.
 *
 * Talk(const size_t commandIndex, const size_t &calcultionCount,
 * const string &name) -The Constructor
 *
 * bool execute(size_t &printIndex,std::vector<string> &input) -
 * Responsible to the execution of the Talk command.
 */
#include "SigiCommand.h"

class Talk : public SigiCommand {
public:
/*
 * Talk(const size_t commandIndex, const size_t &calcultionCount,
 * const string &name) -The Constructor
 *
 * @param commandIndex - sets the numeric index of the command
 * @param calcultionCount - a reference to the variable in SigiMapper
 * which holds the count of the calculations.
 * @param name - a string reference to the user's name variable
 */
	Talk(const size_t commandIndex, const size_t &calcultionCount,
			const string &name) : SigiCommand(commandIndex),
			_calcultionCount(calcultionCount), _name(name){}

	virtual ~Talk(){}

/*
 * bool execute(size_t &printIndex,std::vector<string> &input) -
 * Responsible to the execution of the Talk command.
 *
 * @param printIndex - Then function updates this reference variable to hold the
 *  numeric index of the relevant print string in case of error.
 * Will not change it in case of success.
 * @param input - A vector which holds only the command in index 0.
 *
 * @ return - true for success, false for error.
 */
	bool execute(size_t &printIndex, std::vector<string> &input);

private:
	enum Moods {GOOD=0,LUCKY,BAD,BORED};

		// Variables
	const size_t &_calcultionCount;
	const string &_name;

		// String Arrays
	static string const _prints[];

		// Functions
	const size_t checkMood() const;

		// Constructors that shall not be used
	Talk() : SigiCommand(0),_calcultionCount(*new size_t), _name(*new string){}

};

#endif /* TALK_H_ */
