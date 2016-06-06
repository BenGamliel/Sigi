/*
 * main.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: liron_s
 */
#include "SigiMapper.h"


int main()
{
	SigiMapper sigi;
	string n;

	while ((sigi.isOn())&&(getline(std::cin,n)))
	{
		sigi.command(n);
	}

	return 0;
}

