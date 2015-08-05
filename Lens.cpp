/*
 * Lens.cpp
 *
 *  Created on: 05-Aug-2015
 *      Author: prathik.raj
 */

#include "Lens.h"
#include <iostream>
#include "CurlWrapper.h"

using std::string;
using std::cout;

Lens::Lens(std::string lensUrl, std::string user,
		std::string password, std::string session) {
	CurlWrapper curl;
	httpResponse response = curl.get("http://www.yahoo.com");
	std::cout << response.data;
}

Lens::~Lens() {
	// TODO Auto-generated destructor stub
}

