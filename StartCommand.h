/*
 * StartCommand.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef STARTCOMMAND_H_
#define STARTCOMMAND_H_

#include "SigiCommand.h"

class StartCommand : public SigiCommand {
public:
	//StartCommand(size_t commandIndex, string name = "");
	StartCommand(bool* isAwake, string &name)
	virtual ~StartCommand();

	bool execute(size_t &commandIndex,size_t &printIndex,std::vector<string> &input);
	void wakeUp();


private:
	enum GoodMorning {ok=0};
	enum Errors {};
	// Variables
	bool *_isAwake;
	string &_name;

	// Functions

};

#endif /* STARTCOMMAND_H_ */
