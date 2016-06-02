/*
 * SigiMapper.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef SIGIMAPPER_H_
#define SIGIMAPPER_H_

#include <iostream>
#include <string>
#include <vector>
#include "SigiCommand.h"
#include "Start.h"
#include "Calculate.h"
#include "Talk.h"
using std::string;

namespace Mapper
{

}

class SigiMapper {
public:
		// Constructors
	SigiMapper();
	virtual ~SigiMapper();

		// Functions
	void command(std::string command);


private:
	enum COMMANDS {start=1,talk,sing,calculate,end};
		// Variables
	SigiCommand** _commands;
	bool _isAwake;
	string _name;
	unsigned int _calcultionCount;

		// String Arrays
	static string const _commandList[];
	static string const _errors[end+1][4];
	static string const _prints[end+1][4];

		// Functions
	unsigned int findCommand(string command){return start;}
	//unsigned int getCalcultionCount() const {return _calcultionCount;}

};

#endif /* SIGIMAPPER_H_ */
