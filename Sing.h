/*
 * Sing.h
 *
 *  Created on: Jun 3, 2016
 *      Author: liron_s
 */

#ifndef SING_H_
#define SING_H_
/*
 * This Module is responsible for the Sing command.
 *
 * Sing(const size_t commandIndex, const size_t &calcultionCount) -
 * The Constructor
 *
 * bool execute(size_t &commandIndex,std::vector<string> &input) -
 * Responsible for Singing.
 *
 */
#include "SigiCommand.h"

class Sing : public SigiCommand {
public:
/*
* Sing(const size_t commandIndex, const size_t &calcultionCount) -
* The Constructor
*
* @param commandIndex - sets the numeric index of the command
* @param calcultionCount - a reference to the variable in SigiMapper
* which holds the count of the calculations
*/
	Sing(const size_t commandIndex, const size_t &calcultionCount) :
		SigiCommand(commandIndex),_calcultionCount(calcultionCount){}
	virtual ~Sing(){}

/*
 * bool execute(size_t &commandIndex,std::vector<string> &input) -
 * Responsible for Singing.
 *
 * @param printIndex - Then function updates this reference variable to hold the
 *  numeric index of the relevant print string in case of error.
 * Will not change it in case of success.
 * @param input - A vector which holds the command in index 0
 * and the relevant input for the command, (the song's name) in index 1.
 *
 * @ return - true for success, false for error.
 *
 */
	bool execute(size_t &printIndex, std::vector<string> &input);

private:
	enum Songs {MAMMA_MIA=0,SAY,SCOTTY,NUMBER_OF_SONGS};
	enum Errors {NO_SONG_NAME=0,DONT_KNOW};
		// Variables
	const size_t &_calcultionCount;

		// String Arrays
	static string const _prints[];
	static string const _songList[];

		// Functions
	size_t getSong(const string &name) const;

		// Constructors that shall not be used
	Sing() : SigiCommand(0),_calcultionCount(*new size_t){}
};

#endif /* SING_H_ */
