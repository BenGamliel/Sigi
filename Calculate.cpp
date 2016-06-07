/*
 * Calculate.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */

#include "Calculate.h"

bool Calculate::execute(size_t &printIndex,std::vector<string> &input)
{
	if((input[1].empty())||(input[3].empty())||(input[2].size()!=1)||input.size()!=4)
	{
		printIndex=0;
		return false;
	}

	int numA=atoi((input[1].c_str()));
	int numB=atoi((input[3].c_str()));

	std::cout<<"A= "<< numA << std::endl;
	std::cout<<"B= "<< numB << std::endl;


	int sign = getSign(input[2]);
	if(sign!=0)
	{
		_calcultionCount++;
		std::cout<<_name<<", the result is "<< add(numA,numB,sign) << std::endl;
		return true;
	}

	printIndex=0;
	return false;
}

int Calculate::getSign(const string &stringSign)
{
	if(stringSign=="+")
	{
		return 1;
	}
	else if (stringSign=="-")
	{
		return -1;
	}

	return false;
}
