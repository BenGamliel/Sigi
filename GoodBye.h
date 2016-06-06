/*
 * GoodBye.h
 *
 *  Created on: Jun 5, 2016
 *      Author: liron_s
 */

#ifndef GOODBYE_H_
#define GOODBYE_H_

#include "SigiCommand.h"

class GoodBye : public SigiCommand {
public:
	GoodBye(const size_t commandIndex, bool *isAwake,const string &name) :
		SigiCommand(commandIndex) , _isAwake(isAwake), _name(name){}
	virtual ~GoodBye(){}

		// Functions
	bool execute(size_t &printIndex, std::vector<string> &input);

private:
		// Variables
	bool *_isAwake;
	const string &_name;

};

#endif /* GOODBYE_H_ */
