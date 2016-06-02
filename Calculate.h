/*
 * Calculate.h
 *
 * This class is responsible of the execution of the command calculate.
 * It is responsible to update the calculation count at SigiMapper.
 *
 * Calculate(const unsigned int commandIndex,unsigned int *calcultionCount) -
 * The Constructor
 *
 * bool execute(unsigned int &commandIndex,unsigned int &printIndex) -
 * Responsible to the execution of the calculation.
 *
 */

#ifndef CALCULATE_H_
#define CALCULATE_H_

#include "SigiCommand.h"

class Calculate : public SigiCommand {
public:
/*
 * Calculate(const unsigned int commandIndex,unsigned int *calcultionCount) -
 * The Constructor
 *
 * @param commandIndex - sets the numeric index of the command
 * @param calcultionCount - a pointer to the variable in SigiMapper
 * which holds the count of the calculations
 *
 */
	Calculate(const unsigned int commandIndex,unsigned int *calcultionCount);
	virtual ~Calculate();

		// Functions

/*
 *
 * bool execute(unsigned int &commandIndex,unsigned int &printIndex) -
 * Responsible to the execution of the calculation.
 *
 * @param commandIndex - The function updates this variable to hold
 * the numeric index of the command.
 * @param printIndex - Then function updates this variable to hold the numeric
 * index of the relevant print string both for success and error.
 *
 * @ return - true for success, false for error.
 */
	bool execute(unsigned int &commandIndex,unsigned int &printIndex){return true;}

private:
		// Variables
	unsigned int *_calcultionCount;
};

#endif /* CALCULATE_H_ */
