/*
 * Lens.cpp
 *
 *  Created on: 05-Aug-2015
 *      Author: prathik.raj
 */

#include "Lens.h"
#include <iostream>
#include "CurlWrapper.h"
#include <map>
using std::string;
using std::cout;
using std::map;
using std::pair;

Lens::Lens(std::string lensUrl, std::string user,
		std::string password, std::string session) {
	CurlWrapper curl;
	std::map<string,string> data;
	data.insert(std::pair<string,string>("name", "prathik"));
	data.insert(std::pair<string,string>("data", "data"));
	httpResponse response = curl.post("http://posttestserver.com/post.php",
			data);
	std::cout << response.data;
}

Lens::~Lens() {
	// TODO Auto-generated destructor stub
}

