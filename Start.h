/*
 * Start.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef START_H_
#define START_H_

#include "SigiCommand.h"

class Start : public SigiCommand {
public:
	//Start(unsigned int commandIndex, string name = "");
	Start(const unsigned int commandIndex, bool* isAwake, string name = "");
	virtual ~Start();

	bool execute(unsigned int &commandIndex,unsigned int &printIndex);
	void wakeUp() { *_isAwake=true;}


private:
	enum prints {ok=0};
	enum errors {};
	// Variables
	bool *_isAwake;

	// Functions

};

#endif /* START_H_ */
