/*
 * Talk.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef TALK_H_
#define TALK_H_

#include "SigiCommand.h"

class Talk : public SigiCommand {
public:
	Talk(const size_t commandIndex, const size_t &calcultionCount, const string &name);

	virtual ~Talk();

		// Functions
	bool execute(size_t &commandIndex,size_t &printIndex, std::vector<string> &input);

private:
	enum Moods {good=0,bad,lucky,bored};
	enum Errors {};

		// Variables
	const size_t &_calcultionCount;
	const string &_name;

		// Functions
	const size_t checkMood() {return bad;} // TODO: write the function


};

#endif /* TALK_H_ */
