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
	Talk(const unsigned int commandIndex, const unsigned int &calcultionCount);

	virtual ~Talk();

		// Functions
	bool execute(unsigned int &commandIndex,unsigned int &printIndex);

private:
	enum prints {good=0,bad,lucky,bored};
	enum errors {};

		// Variables
	const unsigned int &_calcultionCount;

		// Functions
	const unsigned int checkMood() {return bad;} // TODO: write the function


};

#endif /* TALK_H_ */
