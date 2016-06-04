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
#include "Sing.h"
using std::string;

class SigiMapper {
public:
		// Constructors
	SigiMapper();
	SigiMapper()
	virtual ~SigiMapper();

		// Functions
	string command(std::string command);
	void findCommand(string command);
	std::vector <string> split (string command);


private:
	enum Commands {start,talk,sing,calculate,end};
		// Variables
	SigiCommand** _commands;
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
