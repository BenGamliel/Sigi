/*
 * Error.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Ben
 */

#ifndef ERROR_H_
#define ERROR_H_

class Error : public SigiCommand
{
public:
	Error();
	virtual ~Error();
	void virtual print();
	void virtual error();
};

#endif /* ERROR_H_ */
