/*
 * CurlWrapper.cpp
 *
 *  Created on: 05-Aug-2015
 *      Author: prathik.raj
 */

#include "CurlWrapper.h"
#include <curl/curl.h>
#include <map>

using std::string;
using std::map;

CurlWrapper::CurlWrapper() {
	// TODO Auto-generated constructor stub
}

CurlWrapper::~CurlWrapper() {
	// TODO Auto-generated destructor stub
}

httpResponse CurlWrapper::base(std::string url,
		std::map<string, string>* data,
		std::string type) {
	httpResponse response;

	CURL *curl;

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		if(type == "POST") {
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS,
							this->buildPayloadString(data).c_str());
		} else if(type == "PUT" || type == "DELETE") {
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, type.c_str());
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS,
					this->buildPayloadString(data).c_str());
		}
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, this->WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.data);

		response.responseCode = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}

	return response;
}

httpResponse CurlWrapper::get(std::string url) {
	return this->base(url, NULL, "GET");
}

httpResponse CurlWrapper::post(std::string url,
		std::map<string, string> data) {
	return this->base(url, &data, "POST");
}

httpResponse CurlWrapper::put(std::string url,
		std::map<string, string> data) {
	return this->base(url, &data, "PUT");
}

httpResponse CurlWrapper::del(std::string url,
		std::map<string, string> data) {
	return this->base(url, &data, "DELETE");
}

