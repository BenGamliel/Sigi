/*
 * Sing.cpp
 *
 *  Created on: Jun 3, 2016
 *      Author: liron_s
 */

#include "Sing.h"

Sing::Sing(const size_t commandIndex, const size_t &calcultionCount)
:SigiCommand(commandIndex),_calcultionCount(calcultionCount)
{

	std::cout << "Sing::Sing(const size_t commandIndex)" << std::endl;

}

Sing::~Sing() {
	// TODO Auto-generated destructor stub
}

bool Sing::execute(size_t &printIndex, std::vector<string> &input)
{
	Songs song = mammaMia;

	std::cout << _prints[song+(_calcultionCount%2)] << std::endl;

	return true;
}

string const Sing::_prints[] =
{
		"Mamma mia, here I go again\n"
		"My my, how can I resist you",

		"Mamma mia, does it show again\n"
		"My my, just how much I've missed you",

		"What can I do\nGirl to get through to you\n"
		"Cause I love you, baby",

		"Say, say, say what you want\n"
		"But don't play games with my affection"
};
