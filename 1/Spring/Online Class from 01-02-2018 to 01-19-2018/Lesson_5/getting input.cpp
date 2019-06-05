// string::empty
#include <iostream>
#include <string>

int main ()
{
  std::string content;
  std::string line;
  std::cout << "Please introduce a text. Enter an empty line to finish:\n";
  do {
    getline(std::cin,line);
    content += line + '\n';
    if (line == "Q"){
      break;
    }
    if (line != "A" && line != "B"){
      std::cout<< "What!!!!\n";
    }
  } while (!line.empty());
  std::cout << "The text you introduced was:\n" << content;
  return 0;
}
