#pragma once

#include <string>

class Webpage {
public:
    Webpage();
    Webpage(const std::string& webpageUrl, const time_t& timeVisited);
    std::string getUrl();
    time_t getTime();

private:
    std::string url;
    time_t time;
};
Webpage::Webpage(){}
Webpage::Webpage(const std::string& webpageUrl, const time_t& timeVisited){
	url = webpageUrl;
	time = timeVisited;
}

std::string Webpage::getUrl(){ return url; }

time_t Webpage::getTime() { return time; }
