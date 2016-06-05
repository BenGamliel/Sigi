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
	//Start(size_t commandIndex, string name = "");
	Start(const size_t commandIndex, bool* isAwake, string &name);
	virtual ~Start();

	bool execute(size_t &printIndex,std::vector<string> &input);
	void wakeUp(const string name);


private:
	enum Errors {NO_NAME=0,NAME_TOO_LONG,ALREADY_AWAKE};
	// Variables
	bool *_isAwake;
	string &_name;

	// Functions

};

#endif /* START_H_ */
