#include "Webpage.h"
#include "BrowserHistory.h"
#include <string>

int main() {
  BrowserHistory desktop;
  desktop.readHistory("mobile.txt");
  // desktop.readFileDummy("desktop.txt");
  // desktop.print();
  return 0;
}
