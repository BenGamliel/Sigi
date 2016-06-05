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
	enum Songs {MAMMA_MIA=0,SAY,NUMBER_OF_SONGS};
	enum Errors {NO_SONG_NAME=0,DONT_KNOW};
		// Variables
	const size_t &_calcultionCount;

		// String Arrays
	static string const _prints[];
	static string const _songList[];

		// Functions
	size_t getSong(const string name);
};

#endif /* SING_H_ */
