/*
 * SigiSing.cpp
 *
 *  Created on: Jun 3, 2016
 *      Author: liron_s
 */

#include "SigiSing.h"




SigiSing::SigiSing(bool isAwake,string songName,size_t calcultionCount) : SigiCommand(isAwake)
{
	_songName(songName);
	_calcultionCount(calcultionCount);
}

Songstatus SigiSing::getSong()
{
	if(_songName!=_songList[0])//Say Say Say
	{
		if(_calcultionCount%2)
		{
			return mamaMiaNoteven;
		}
		else
		{
			return mammaMiaEven;
		}
	}
	else//Mamma Mia
	{
		if(_calcultionCount%2)
		{
			return saysaysayNoteven;
		}
		else
		{
			return saysaysayEven;
		}
	}
}

bool SigiSing::execute()
{
	Songstatus songstatus=getSong();
	switch (songstatus)
	{
		case(mamaMiaNoteven): cout<<"_songList[0]"<<endl;
		return true;
		case(mammaMiaEven): cout <<"_songList[1]"<<endl;
		return true;
		case(saysaysayNoteven): cout<<"_songList[2]"<<endl;
		return true;
		case(saysaysayEven): cout << "_songList[3]"<<endl;
		return true;
	}
	return false;
}
/*
SigiSing::SigiSing(const size_t commandIndex, const size_t &calcultionCount)
:SigiCommand(commandIndex),_calcultionCount(calcultionCount)
{

	std::cout << "SigiSing::SigiSing(const size_t commandIndex)" << std::endl;

}

SigiSing::~SigiSing() {
	// TODO Auto-generated destructor stub
}

bool SigiSing::execute(size_t &commandIndex,size_t &printIndex, std::vector<string> &input)
{
	commandIndex=this->getCommandIndex();
	printIndex=0+(_calcultionCount%2);

	return true;
}
*/
