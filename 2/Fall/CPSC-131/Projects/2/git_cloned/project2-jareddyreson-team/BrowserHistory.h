#ifndef BROWSER_H
#define BROWSER_H

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string>
#include <stdexcept>
#include "Webpage.h"
#include <iomanip>


class BrowserHistory {
public:
    BrowserHistory();

    void visitSite(Webpage newSite);
    std::string back();
    std::string forward();

    void readHistory(std::string fileName);
    void readFileDummy(std::string fileName);

    std::string getUrl();
    size_t getNavSize();
    std::list<Webpage> getSitesVisited();

    void print();

private:
    std::list<Webpage> navHistory;
    std::list<Webpage>::iterator navPos;
    std::list<Webpage> sitesVisited;
    size_t numSites;
};
BrowserHistory::BrowserHistory() : navHistory(std::list<Webpage>()), navPos(navHistory.begin()), sitesVisited(std::list<Webpage>()),numSites(0){};

std::string BrowserHistory::back() {
  // while we're not at the front
  if(navPos != navHistory.begin()){
    auto back = std::prev(navPos, 1);
    navPos--;
    return back->getUrl();
  }
  throw new std::bad_alloc;
}
std::string BrowserHistory::forward(){
  // https://en.cppreference.com/w/cpp/iterator/next
  if(navPos != navHistory.end()){
    auto next = std::next(navPos,1);
    navPos++;
    return next->getUrl();
   }

  else{ throw new std::bad_alloc(); }
}
std::string BrowserHistory::getUrl(){
  if(!navHistory.empty() || !sitesVisited.empty()){ return navPos->getUrl(); }
  else{ throw std::logic_error("site does not exist"); }
}
void BrowserHistory::visitSite(Webpage newSite){
  navHistory.push_back(newSite);
  sitesVisited.push_back(newSite);
  ++numSites;
  if(navHistory.size() > 1){
    while(navPos != std::next(navHistory.end(), -1)){ navHistory.pop_back(); }
    navHistory.push_back(newSite);
    navPos = std::next(navHistory.end(), -1);
  }
  else{ navPos = navHistory.begin(); }
}

void BrowserHistory::readHistory(std::string fileName) {
    std::string directionIndicator, url_;
    long long int newTime;
    Webpage newSite;
    std::ifstream inFile(fileName);
    while(inFile >> directionIndicator) {
        if(directionIndicator == "new") {
          inFile >> url_ >> newTime;
            // was wondering why this is broken, copy constructor not properly constructed...
            newSite = Webpage(url_, time_t(newTime)); // time_t(long long int&) <-- called type casting
            visitSite(newSite);
        } else if(directionIndicator == "back") {
            back();
        } else if(directionIndicator == "forward") {
            forward();
        } else {
            throw new std::logic_error("invalid command");
        }
    }
    inFile.close();
}
size_t BrowserHistory::getNavSize(){ return navHistory.size(); }

void BrowserHistory::print(){
  for(navPos = navHistory.begin(); navPos != navHistory.end(); ++navPos){
    std::cout << navPos->getUrl() << std::endl;
    std::cout << navPos->getTime() << std::endl;
  }
  navPos = navHistory.begin();
}

std::list<Webpage> BrowserHistory::getSitesVisited(){ return sitesVisited; }
#endif
