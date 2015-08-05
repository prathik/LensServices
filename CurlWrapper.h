/*
 * CurlWrapper.h
 *
 *  Created on: 05-Aug-2015
 *      Author: prathik.raj
 */

#ifndef CURLWRAPPER_H_
#define CURLWRAPPER_H_

#include <iostream>
#include <curl/curl.h>
#include <map>
using std::string;
using std::map;

struct httpResponseStruct {
	CURLcode responseCode;
	std::string data;
};

typedef httpResponseStruct httpResponse;

class CurlWrapper {
public:
	CurlWrapper();
	virtual ~CurlWrapper();
	httpResponse get(std::string);
	httpResponse post(std::string, std::map<string, string>);
	httpResponse put(std::string, std::map<string, string>);
	httpResponse del(std::string, std::map<string, string>);

private:
	httpResponse base(std::string, std::map<string, string>*,
				std::string type);
	static size_t WriteCallback(void *contents,
			size_t size, size_t nmemb, void *userp)
	{
		/*
		 * Credits to http://stackoverflow.com/a/9786295/1737080
		 */
	    ((std::string*)userp)->append((char*)contents, size * nmemb);
	    return size * nmemb;
	}

	static std::string buildPayloadString(std::map<string, string>* payload) {
		std::string result = "";
		std::map<string, string>::iterator it;
		for(it = payload->begin(); it != payload->end(); it++) {
			if(result == "") {
				result = it->first + "=" + it->second;
			} else {
				result += "&" + it->first + "=" + it->second;
			}
		}
		return result;
	}
};

#endif /* CURLWRAPPER_H_ */
