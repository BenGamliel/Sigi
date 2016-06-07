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
 * Calculate(const size_t commandIndex,size_t &calcultionCount,
 * string const &name) - The Constructor
 *
 * @param commandIndex - sets the numeric index of the command
 * @param calcultionCount - a pointer to the variable in SigiMapper
 * which holds the count of the calculations
 * @param name - a string reference to the user's name variable
 *
 *
 *
 * bool execute(size_t &commandIndex,size_t &printIndex) -
 * Responsible to the execution of the calculation.
 *
 * @param printIndex - Then function updates this reference variable to hold the
 *  numeric index of the relevant print string in case of error.
 * Will not change it in case of success.
 * @param input - holds the relevant input for the command
 *
 * @ return - true for success, false for error.
 *
 */

#include "SigiCommand.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

class Calculate : public SigiCommand {
public:

	Calculate(const size_t commandIndex,size_t &calcultionCount,
			string const &name): SigiCommand(commandIndex),
			_calcultionCount(calcultionCount), _name(name){}
	virtual ~Calculate(){}
	bool execute(size_t &commandIndex,std::vector<string> &input);

private:
	size_t &_calcultionCount;
	const string &_name ;
	inline int add(const unsigned int numA,const unsigned int numB,
			const int factor) const
	{
		return numA+(factor*numB);
	}
	int getSign(const string &stringSign);
	Calculate(): SigiCommand(0), _calcultionCount(*new size_t),
			_name(*new string){}
};

#endif /* CALCULATE_H_ */
