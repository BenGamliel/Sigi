/*
 * SigiMapper.h
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#ifndef SIGIMAPPER_H_
#define SIGIMAPPER_H_

#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include "SigiCommand.h"
#include "Start.h"
#include "Calculate.h"
#include "Talk.h"
#include "Sing.h"
#include "GoodBye.h"
using std::string;

class SigiMapper {
public:
		// Constructors
	SigiMapper();
	virtual ~SigiMapper();

		// Functions
	void command(const string command);
	bool isOn(){return ((!_isAwake)&&(_name.size()>0))?false:true;}


private:
	enum Commands {START=0,CALCULATE,TALK,SING,END};
		// Variables
	SigiCommand** _commands;
	bool _isAwake;
	string _name;
	size_t _calcultionCount;

		// String Arrays
	static string const _commandList[];
	static string const _errors[END+2][3];

		// Functions
	bool isReadyToLaunch(size_t commandIndex,size_t inputSize);
	void split(std::vector<string> &tempVec,const string &command);
	size_t getCommandIndex(const string &inCommand);
	bool isEmpty(const string &command);

};

#endif /* SIGIMAPPER_H_ */
