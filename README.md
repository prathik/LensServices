# LensServices
C++ client for Apache Lens

## CurlWrapper
A simple REST wrapper for CURL written in C++

### Example POST Request
 
	#include "CurlWrapper.h"
	#include <curl/curl.h>
	#include <map>
	...
	std::map<string,string> data;
	data.insert(std::pair<string,string>("name", "prathik"));
	data.insert(std::pair<string,string>("data", "data"));
	httpResponse response = curl.post("http://posttestserver.com/post.php",
			data);
	std::cout << response.data;
	