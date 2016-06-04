/*
 * Calculate.h
 *
 * This class is responsible of the execution of the command calculate.
 * It is responsible to update the calculation count at SigiMapper.
 *
 * Calculate(const size_t commandIndex,size_t *calcultionCount) -
 * The Constructor
 *
 * bool execute(size_t &commandIndex,size_t &printIndex) -
 * Responsible to the execution of the calculation.
 *
 */

#ifndef CALCULATE_H_
#define CALCULATE_H_

#include "SigiCommand.h"

class Calculate : public SigiCommand {
public:
/*
 * Calculate(const size_t commandIndex,size_t *calcultionCount) -
 * The Constructor
 *
 * @param commandIndex - sets the numeric index of the command
 * @param calcultionCount - a pointer to the variable in SigiMapper
 * which holds the count of the calculations
 *
 */
	Calculate(const size_t commandIndex,size_t &calcultionCount);
	virtual ~Calculate();

		// Functions

/*
 *
 * bool execute(size_t &commandIndex,size_t &printIndex) -
 * Responsible to the execution of the calculation.
 *
 * @param commandIndex - The function updates this variable to hold
 * the numeric index of the command.
 * @param printIndex - Then function updates this variable to hold the numeric
 * index of the relevant print string both for success and error.
 *
 * @ return - true for success, false for error.
 */
	bool execute(size_t &commandIndex,size_t &printIndex,std::vector<string> &input);

private:
	enum Results {ok=0};
	enum Errors {complicated=0};

		// Variables
	size_t &_calcultionCount;

	// Functions
	int add(const unsigned int numA,const unsigned int numB,const int factor) const;
};

#endif /* CALCULATE_H_ */
