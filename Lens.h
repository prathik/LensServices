/*
 * Lens.h
 *
 *  Created on: 05-Aug-2015
 *      Author: prathik.raj
 */

#ifndef LENS_H_
#define LENS_H_

#include <iostream>
using std::string;

class Lens {
public:
	Lens(std::string lensUrl, std::string user,
			std::string password, std::string session);
	virtual ~Lens();
private:
	std::string session;
};

#endif /* LENS_H_ */
