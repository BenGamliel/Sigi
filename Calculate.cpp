/*
 * Calculate.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Calculate.h"


Calculate::Calculate(const size_t commandIndex, size_t &calcultionCount,string const &name):
	SigiCommand(commandIndex),_calcultionCount(calcultionCount), _name(name)
{
	//std::cout << "Calculate::Calculate(size_t *calcultionCount)" << std::endl;
}

Calculate::~Calculate() {

	// TODO Auto-generated destructor stub
}

bool Calculate::execute(size_t &printIndex,std::vector<string> &input)
{
	bool flag=false;
	int sign;
	int numA=atoi((input[1].c_str()));
	int numB=atoi((input[3].c_str()));
	if( (input[1].empty()) || (input[3].empty()) || (input[2]=="<+") || (input[2]=="<-"))
	{
		printIndex=0;
		return false;
	}

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
		cout<<_name<<", the result is "<<result;
		return true;
	}
	printIndex=0;
	return false;
}

//<Name>, the result is <Number>
