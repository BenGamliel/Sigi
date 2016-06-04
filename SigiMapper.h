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
#include "StartCommand.h"
#include "Calculate.h"
#include "Talk.h"
#include "Sing.h"
using std::string;
enum Commands {start,talk,sing,calculate,end};

class SigiMapper {
public:

		// Constructors
	SigiMapper();
	virtual ~SigiMapper();

		// Functions

	Commands getCommand(string inCommand);
	void findCommand(string command);
	std::vector <string> split (string command);


private:

		// Variables
	//SigiCommand** _commands;
	bool _isAwake;
	string _name;
	size_t _calcultionCount;

		// String Arrays
	static string const _commandList[];
	static string const _errors[end+1][4];
	static string const _prints[end+1][4];

		// Functions
	//size_t getCalcultionCount() const {return _calcultionCount;}
	bool isReadyToLaunch(size_t commandIndex);

};

#endif /* SIGIMAPPER_H_ */
