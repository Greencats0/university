#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"

class BrowserHistory {
public:
    BrowserHistory();
    ~BrowserHistory();

    void visitSite(Webpage newSite);
    std::string back();
    std::string forward();

    void readHistory(std::string fileName);

    std::string getUrl();
    size_t getNavSize();
    std::list<Webpage> getSitesVisited();

private:
    std::list<Webpage> navHistory;
    std::list<Webpage>::iterator navPos;
    std::list<Webpage> sitesVisited;
    int numSites;
};

void BrowserHistory::readHistory(std::string fileName) {
    std::string temp;
    int newTime;
    Webpage newSite;
    std::ifstream inFile(fileName.c_str());

    while(inFile >> temp) {
        if(temp == "new") {
            inFile >> temp >> newTime;
            newSite = Webpage(temp, time_t(newTime));
            visitSite(newSite);
        } else if(temp == "back") {
            back();
        } else if(temp == "forward") {
            forward();
        } else {
            throw std::logic_error("invalid command");
        }
    }
}

void BrowserHistory::visitSite(Webpage newSite){ 
	navHistory.push_back(newSite); 
	sitesVisited.push_back(newSite);
	++numSites;
	if(navHistory.size() > 1){
		while(navPos != std::next(navPos, -1)){ navHistory.pop_back(); }
		navHistory.push_back(newSite);
		navPos = std::next(navHistory.end(), -1);
	}
	else { navPos = navHistory.begin(); }
}

std::string BrowserHistory::back(){
	if(navPos != navHistory.begin()){
		auto back = std::prev(navPos, 1);
		navPos--;
		return back->getUrl();
	}
	throw new std::bad_alloc;
}

std::string BrowserHistory::forward(){
	if(navPos != navHistory.end()){
		auto fore = std::next(navPos, 1);
		navPos++;
		return fore->getUrl();
	}
	throw new std::bad_alloc;
}

std::string BrowserHistory::getUrl() {
	if(!navHistory.empty() || !sitesVisited.empty()){
		return navPos->getUrl();
	}
	throw std::logic_error("site does not exists");
	//for(std::list<Webpage>::iterator it = navPos; it != sitesVisited.end();++it){
	//}
}

size_t BrowserHistory::getNavSize(){
	return navHistory.size();
}

std::list<Webpage> BrowserHistory::getSitesVisited(){
	return sitesVisited;
}

BrowserHistory::BrowserHistory(){}
BrowserHistory::~BrowserHistory(){}
