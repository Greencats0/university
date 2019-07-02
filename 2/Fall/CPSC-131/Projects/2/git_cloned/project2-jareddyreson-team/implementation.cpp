#include "Webpage.h"
#include "BrowserHistory.h"
#include <iostream>
#include <string>
int main() {
  BrowserHistory history;
  std::cout << std::endl;
  std::cout << "Reading mobile" << std::endl;
  history.readHistory("mobile.txt");
  history.print();

  std::cout << std::endl;

  std::cout << "First element: " << history.back() << std::endl;
  // std::cout << "\n";
  // std::cout << "Reading desktop" << std::endl;
  // history.readHistory("desktop.txt");
  // history.print();
  return 0;
}
