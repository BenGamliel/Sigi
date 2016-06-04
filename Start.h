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

	bool execute(size_t &commandIndex,size_t &printIndex,std::vector<string> &input);
	void wakeUp() { *_isAwake=true;}


private:
	enum GoodMorning {ok=0};
	enum Errors {};
	// Variables
	bool *_isAwake;
	string &_name;

	// Functions

};

#endif /* START_H_ */
