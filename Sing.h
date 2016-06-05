/*
 * Sing.h
 *
 *  Created on: Jun 3, 2016
 *      Author: liron_s
 */

#ifndef SING_H_
#define SING_H_

#include "SigiCommand.h"

class Sing : public SigiCommand {
public:
	Sing(const size_t commandIndex, const size_t &calcultionCount);
	virtual ~Sing();

		// Functions
	bool execute(size_t &printIndex, std::vector<string> &input);

private:
	enum Songs {mammaMia=0,saysaysay=2};
		// Variables
	const size_t &_calcultionCount;

		// String Arrays
	static string const _prints[];
};

#endif /* SING_H_ */
