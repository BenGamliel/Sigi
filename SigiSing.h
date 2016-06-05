/*
 * SigiSing.h
 *
 *  Created on: Jun 3, 2016
 *      Author: liron_s
 */

#ifndef SIGISING_H_
#define SIGISING_H_
enum Songstatus {mammaMiaEven,mamaMiaNoteven,saysaysayEven,saysaysayNoteven};

#include "SigiCommand.h"
#include <iostream>
using namespace std;

class SigiSing : public SigiCommand {
public:
//SigiSing(const size_t commandIndex, const size_t &calcultionCount);
	SigiSing(bool isAwake,string songName,size_t calcultionCount);
	virtual ~SigiSing();

		// Functions
	bool execute();
	Songstatus getSong();
protected:
	string _songList = {"Say Say Say","Mamma Mia"};
	string const _theSongs
	{
		"Mamma mia, does it show again\n My my, just how much I've missed you",

		"Mamma mia, here I go again\n My my, how can I resist you",

		"Say, say, say what you want\n But don't play games with my affection"

		"What can I do\nGirl to get through to you\n Cause I love you, baby",

	}
private:

	string _songName;
	size_t _calcultionCount;
};

#endif /* SIGISING_H_ */
