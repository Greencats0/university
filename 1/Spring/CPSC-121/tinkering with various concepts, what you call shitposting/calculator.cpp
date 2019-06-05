#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "recipes.h"
using namespace std;

int main(){
  const int NAMES = 5;
  const int SCORES = 6;

  int scoresArray[NAMES][SCORES] = {0};
  string studentNames[NAMES] = {};
  char studentLetterGrade[NAMES] = {};

  ifstream stream;
  stream.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project One/CPSC121data");
  if (!stream.is_open()){
    cerr << "Unable to open the file, exiting now" << endl;
    exit(1);
  }
  // function to send to array
  string line;
  for (int i = 0; i < NAMES; i++){
    getline(stream, line, ',');
    studentNames[i] = line;
    for (int j = 0; j < SCORES; j++){
      getline(stream, line, ',');
      scoresArray[i][j] = stoi(line);
    }
  }

  //add up the integers
  // function to do this
  int count = 0;
  // used to calculate grade, make it interesting

  for (int i = 0; i < NAMES; i++){
    cout << studentNames[i] << endl;
    for (int j = 0; j < SCORES; j++){
      //cout << scoresArray[i][j] << endl;
      count+=scoresArray[i][j];
    }
    cout << count << endl;
    double curve = 90;
    int percentOfStudent = (count / curve)*100;
    char grade;

    // determine what their letter grade would be
    // function to replace this
    if (percentOfStudent == 100 || percentOfStudent < 100 && percentOfStudent >= 90){
      grade = 'A';
    }
    else if (percentOfStudent < 89 && percentOfStudent >= 80){
      grade = 'B';
    }
    else if (percentOfStudent < 79 && percentOfStudent >= 70){
      grade = 'C';
    }
    else if (percentOfStudent < 69 && percentOfStudent >= 60){
      grade = 'D';
    }
    else {
      grade = 'F';
    }
    studentLetterGrade[i] = grade;
    cout << percentOfStudent << " " << grade << endl;
    count = 0;
  }
  char selection;
  do{
    cout << "+------+" << endl;
    cout << "| Menu |" << endl;
    cout << "+ -----+" << endl;
    cout << "A) Display all information about students" << endl;
    cout << "H) Highest grade in the class" << endl;
    cout << "S) Search for a student" << endl;
    cout << "Q) Save to file and quit" << endl;
    cout << "Selection: ";
    cin >> selection;
    switch(selection){
      case 'A':
      {
        // currently breaking for no reason
        // this clears the screen and I did not create this, credits -> https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
        //cout << "\033[2J\033[1;1H";
        for (int a = 0; a < NAMES; a++){
          cout << flush;
          cout<< "Student Name:" << studentNames[a] << endl;
          cout << "Letter Grade:" << studentLetterGrade[a] << endl;
          for (int b = 0; b < SCORES; b++){
            if (b == (SCORES -1)){
              cout << scoresArray[a][b] << endl;
              //cout << "\n";
            }
            else{
              cout << scoresArray[a][b] << endl;
            }
          }
          //cout << endl;
        }
        break;
      }
      case 'H':
      {
        const int temp = NAMES;
        int totalScores[temp] = {};
        for (int i = 0; i < NAMES; i++){
          for (int j = 0; j < SCORES; j++){
            count+=scoresArray[i][j];
          }
          double curve = 90;
          int percentOfStudent = (count / curve)*100;
          totalScores[i] = percentOfStudent;
      }
      int largest = 0;
      for (int i = i; i < NAMES; i++){
        if (totalScores[i] > largest){
          largest = totalScores[i];
        }
      }
      cout << largest << endl;
      break;
    }
  }
} while (selection != 'Q');
}
