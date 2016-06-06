/*
 * Calculate.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Calculate.h"


Calculate::Calculate(const size_t commandIndex, size_t &calcultionCount,string const &name):
	SigiCommand(commandIndex),_calcultionCount(calcultionCount), _name(name){}

bool Calculate::execute(size_t &printIndex,std::vector<string> &input)
{
	bool flag=false;
	int sign;
	int numA=atoi((input[1].c_str()));
	int numB=atoi((input[3].c_str()));
	size_t foundplus = input[2].rfind("+");
	size_t foundminus = input[2].rfind("-");
	if((numA<0)||(numB<0))
	{
		printIndex=0;
		return false;
	}
	 if ( (foundminus!=std::string::npos) || (foundplus!=std::string::npos) )
	 {
		 flag=true;
		if(foundplus!=std::string::npos)
		{
			sign=1;
		}
		else
			sign=-1;
	 }
	if(flag)
	{
		int result=add(numA,numB,sign);
		_calcultionCount++;
		std::cout<<_name<<", the result is "<< result << std::endl;
		return true;
	}
	printIndex=0;
	return false;
}

