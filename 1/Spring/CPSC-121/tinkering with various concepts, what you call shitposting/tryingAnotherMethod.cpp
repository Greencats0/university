#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
  // sizes of the array
  const int NAMES = 5;
  const int SCORES = 6;

  // to store all of the scores that they have earned
  int scoresArray[NAMES][SCORES] = {0};

  // store their names
  string studentNames[NAMES] = {};

  // store their letter grade
  char studentLetterGrades[NAMES] = {'\0'};

  ifstream stream;

  stream.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project One/CPSC121data");
  if (!stream.is_open()){
    cerr << "Unable to open, cowardly refusing" << "\n";
    exit(1);
  }
  // for some reason, using this other method instead of using the comma as the delimeter is yielding more successful results
  // I flat-out remove the commas as they alter the data for some reason when they are used a delimeter
  // I rely on stringstream to grab the first and last name. Whatever is leftover gets globbed into another variable that is then parsed
  /*
  for (int i = 0; i < AMOUNT; i++){
    getline(stream, line);
    line.erase(remove(line.begin(), line.end(), ','), line.end());
    stringstream ss(line);
    ss >> firstName >> lastName;
    fullName = firstName + " " + lastName;
    getline(ss, allScores);
    int scores = sumOfScores(allScores);
    int calculatedScore = calculatePercentGrade(scores);
    char letterGrade = returnLetterGrade(calculatedScore);
    studentNameArray[i] = fullName;
    studentLetterGradeArray[i] = letterGrade;
    studentTotalGradeArray[i] = calculatedScore;
    allScoresArray[i] = allScores;
    }
  */
  string line, firstName, lastName, fullName, allScores, var;
  int layerOne = 0, layerTwo = 0;
  for (int i = 0; i < NAMES; i++){
    getline(stream, line);
    // traverse through the string and where-ever there is a comma, delete it
    line.erase(remove(line.begin(), line.end(), ','), line.end());
    stringstream ss(line);
    ss >> firstName >> lastName;
    fullName = firstName + " " + lastName;
    // starting point for new variable in the stream
    getline(ss, allScores);
    stringstream parsingScores(allScores);
    while(parsingScores >> var){
      int countMeIn = stoi(var);
      scoresArray[layerOne][layerTwo] = countMeIn;
      layerOne+=1;
      layerTwo+=1;
    }
    layerOne = 0;
    layerTwo = 0;
  }
  return 0;
}
