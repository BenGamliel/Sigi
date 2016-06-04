/*
 * StartCommand.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef STARTCOMMAND_H_
#define STARTCOMMAND_H_

#include "SigiCommand.h"
using namespace std;
enum startstatus {isok,nametoolong,nametooshort,alreadyawake};

class StartCommand : public SigiCommand {
public:
	//StartCommand(size_t commandIndex, string name = "");
	StartCommand(bool isAwake,string name);
	virtual ~StartCommand();

	bool execute();
	startstatus wakeUp();



private:
	//enum GoodMorning {ok=0};
//	enum Errors {};
	// Variables
	// Functions

};

#endif /* STARTCOMMAND_H_ */
