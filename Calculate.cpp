/*
 * Calculate.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Calculate.h"

Calculate::Calculate(const size_t commandIndex, size_t &calcultionCount,string const &name):
SigiCommand(commandIndex,name),_calcultionCount(calcultionCount),_name(name)
{
	std::cout << "Calculate::Calculate(size_t *calcultionCount)" << std::endl;
}

Calculate::~Calculate() {
	// TODO Auto-generated destructor stub
}

int Calculate::add(const  int &numA,const  int &numB,const int factor) const
{

	return numA+(factor*numB);
}

bool Calculate::execute(size_t &commandIndex,std::vector<string> &input)
{
	int numA=input[1];
	int numB=input[3];
	if((numA<0)||(numB<0))
	{
		cout<<"TOO COMPLICATED FOR ME"<<endl;
		return false;
	}
	if((input[2]=='+') ||(input[2]=='-'))
	{

		int result=add(numA,numB,input[2]=='+'?1:-1);
			_calcultionCount++;
			cout<<"<"<<"_name"<<"<"<<",the result is"<<result<<endl;
			return true;
	}
	return false;
}


//execute(printIndex,input)
