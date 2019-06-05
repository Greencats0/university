#include <iostream>
#include <string>
using namespace std;

struct Student{
  char letterGrade;
  int totalScore;
};

int main(){
  const int S = 5;
  string names[S] = {"John Smith", "Jared Dyreson", "Mary Doe", "Jack Anderson", "Joe Smith"};
  char letterGrades[S] = {'A', 'B', 'C', 'D', 'F'};
  int scores[S] = {100, 80, 70, 60, 50};
  for (int i = 0; i < S; i++){
    string var = names[i];
    Student s1;
    cout << var << endl;
    //letterGrades[i] = s1.letterGrade;
    //scores[i] = s1.totalScore;
    //cout << names[i] << s1.letterGrade << s1.totalScore << endl;
    //letterGrades[i] = s1.letterGrade;
  }
  for (int i = 0; i < S; i++){
    cout << letterGrades[i] << scores[i] << names[i] << endl;
  }
  //Student jared;
  //jared.letterGrade = 'B';
  //jared.totalScore = 85;
  //cout << jared.letterGrade << endl;
}
