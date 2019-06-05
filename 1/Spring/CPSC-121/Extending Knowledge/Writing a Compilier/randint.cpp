// random integers
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

size_t randomNumber(const int min, const int max){
  size_t num = rand() % min + max;
  return num;
}
int main(){
  srand(time(0));
  for(int i = 0; i < 10; i++){
    cout << randomNumber(0, 9) << endl;
  }
  return 0;
}
