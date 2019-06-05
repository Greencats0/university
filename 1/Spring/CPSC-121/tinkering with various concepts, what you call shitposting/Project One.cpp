#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <boost/algorithm/string/trim.hpp>
#include <sstream>
using namespace std;
using namespace boost;

void clear(){
  cout << "\033[2J\033[1;1H";
}

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
  string firstName, lastName, line, allScores, fullName, var;
  for (int i = 0; i < NAMES; i++){
    getline(stream, line);
    line.erase(remove(line.begin(), line.end(), ','), line.end());
    stringstream ss(line);
    ss >> firstName >> lastName;
    fullName = firstName + " " + lastName;
    studentNames[i] = fullName;

    for (int j = 0; j < SCORES; j++){
      getline(ss, allScores);
      trim(allScores);
      stringstream scores(allScores);
      while (scores >> var){
        int countMeIn = stoi(var);
        cout << countMeIn << endl;
      }
    }
  }
  // quickly calculate their letter grades
  int counter, percent;
  double curve = 90;
  for (int i = 0; i < NAMES; i++) {
    for (int j = 0; j < SCORES; j++) {
      counter+=scoresArray[i][j];
    }
    int percent = (counter / curve)*100;
    cout << percent << endl;
    char grade;
    // determine what their letter grade would be
    // function to replace this
    if (percent == 100 || percent < 100 && percent >= 90){
      grade = 'A';
    }
    else if (percent < 89 && percent >= 80){
      grade = 'B';
    }
    else if (percent < 79 && percent >= 70){
      grade = 'C';
    }
    else if (percent < 69 && percent >= 60){
      grade = 'D';
    }
    else if (percent >= 59) {
      grade = 'F';
    }
    studentLetterGrades[i] = grade;
    counter = 0;
  }
  char selection;
  do {
    cout << "+------+" << endl;
    cout << "| Menu |" << endl;
    cout << "+ -----+" << endl;
    cout << "A) Display all information about students" << endl;
    cout << "H) Highest grade in the class" << endl;
    cout << "S) Search for a student" << endl;
    cout << "G) Save Student information to StudentData.txt" << endl;
    cout << "Q) Quit" << endl;
    cout << "Selection: ";
    cin >> selection;
    switch(selection){
      case 'A':
      {
        clear();
        // for some reason the first element of the array can either contain the correct percent or stores garbage after consecuative executions of the program
        // happens even if I set all of the values of char array to '\0'
        for (int i = 0; i < NAMES; i++){
          cout << "Student Name: " << studentNames[i] << endl;
          cout << "Grade: " << studentLetterGrades[i] << endl;
          for (int j = 0; j < SCORES; j++) {
            if (j == (SCORES - 1)){
              cout << scoresArray[i][j] << endl;
            }
            else{
              cout << scoresArray[i][j] << " ";
            }
          }
          cout << endl;
        }
        break;
      }
      case 'H':
      {
        clear();
        int tempScoresArray[SCORES] = {};
        int largest = 0;
        string studentWithHighestGrade;
        for (int i = 0; i < NAMES; i++){
          for (int j = 0; j < SCORES; j++){
            counter+=scoresArray[i][j];
          }
          percent = (counter / curve)*100;
          tempScoresArray[i] = percent;
          counter = 0;
        }

        for (int i = 0; i < NAMES; i++) {
          if (tempScoresArray[i] > largest){
            largest = tempScoresArray[i];
            studentWithHighestGrade = studentNames[i];
          }
        }
        cout << "Student with Highest Score: " << studentWithHighestGrade << "\n";
        cout << "Overall grade: " << largest << endl;
        break;
      }
      case 'S':
      {
        clear();
        string studentSelection;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, studentSelection);
        bool studentIsFound;
        for (int i = 0; i < NAMES; i++) {
          if (studentNames[i] == studentSelection){
            cout << studentSelection << " is in our records" << endl;
            studentIsFound = true;
            break;
          }
          else{
            studentIsFound = false;
          }
        }
        if (!studentIsFound) {
          cerr << "We could not find " << studentSelection << " in our records" << endl;
        }
        break;
      }
      case 'G':
      {
        clear();
        cout << "Saving...." << endl;
        ofstream write;
        write.open("StudentData.txt");
        for (int i = 0; i < NAMES; i++){
          write << "Student: " << studentNames[i] << "\n" << "Letter Grade: " << studentLetterGrades[i] << endl;
        }
        write.close();
        cout << "Successfully wrote data to StudentData.txt" << endl;
        break;
      }
      case 'Q':
      {
        break;
      }
      default:
      {
        clear();
        cerr << "Invalid option" << endl;
        break;
      }
    }
  } while (selection != 'Q');

  return 0;
}
