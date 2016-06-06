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
/*
 * Calculate(const size_t commandIndex,size_t *calcultionCount) -
 * The Constructor
 *
 * @param commandIndex - sets the numeric index of the command
 * @param calcultionCount - a pointer to the variable in SigiMapper
 * which holds the count of the calculations
 *
 */
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

#include "SigiCommand.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

class Calculate : public SigiCommand {
public:

	Calculate(const size_t commandIndex,size_t &calcultionCount,string const &name);
	virtual ~Calculate();
	bool execute(size_t &commandIndex,std::vector<string> &input);
	inline int add(const unsigned int numA,const unsigned int numB,const int factor) const
	{
		return numA+(factor*numB);
	}

private:
	size_t &_calcultionCount;
	const string &_name ;
	// Functions
	//enum Results {ok=0};
	//enum Errors {complicated=0};

		// Variables
};

#endif /* CALCULATE_H_ */
