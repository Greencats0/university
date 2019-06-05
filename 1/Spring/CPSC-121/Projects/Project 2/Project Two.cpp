// Written by Jared Dyreson
// Days bug free: -1
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

// https://stackoverflow.com/questions/14548753/passing-a-multidimensional-variable-length-array-to-a-function
// passing 2-D array like <int (*scores)[6]> . Which looks cleaner than <int scores[][6]> in my opinion

// all my prototypes, in alphabetical order
char getInput();
char returnLetterGrade(int percentage);
int calculatePercentGrade(double scoreOfStudent);
int removeDuplicates(string array[], int SIZE);
void clear();
void findHighestGrade(int NAMES, int GRADES, int (*scores)[6], string* names);
void findStudent(string* names, int (*scores)[6], const int numberOfScores, const int numberOfStudents);
void printAllInformation(int (*scores)[6], string* names, char* letterGrades, const int numberOfScores, const int numberOfStudents);
void printMenu();
void saveInformation(string* names, char* grades, int (*scores)[6], const int numberOfStudents, const int numberOfScores);
void sendToArray(ifstream &stream, int studentSize, const int numberOfScores, int (*scores)[6], string* names, char* letterGrades, string* catchAll);

int main(){

  const int numberOfScores = 6;
  const int numberOfStudents = 23;

  ifstream stream;
  stream.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project Two/CPSC121dataUpdated.txt");
  if (!stream.is_open()){
    cerr << "Could not open file, cowardly refusing" << endl;
    exit(1);
  }

  // send all data to array named catchAll, find duplicates from there and parse non duplicates to respective arrays
  // much easier than trying to parse out the duplicate lines like "cat CPSC121dataUpdated.txt | uniq | sort - n" which was the first idea but I quickly realized I was in over my head after reading -> https://opensource.apple.com/source/text_cmds/text_cmds-71/uniq/uniq.c.auto.html
  char letterGrades[numberOfStudents] = {};
  char selection;
  int scores[numberOfStudents][numberOfScores] = {0};
  int totalScores[numberOfStudents] = {0};
  string catchAll[numberOfStudents] = {};
  string names[numberOfStudents] = {};

  sendToArray(stream, numberOfStudents, numberOfScores, scores, names, letterGrades, catchAll);
  // my cleanest switch case in a long time
  do
  {
    printMenu();
    cin >> selection;
    switch (selection)
    {
      case 'A':
      {
        clear();
        printAllInformation(scores, names, letterGrades, numberOfScores, (numberOfStudents - 1));
        break;
      }
      case 'H':
      {
        clear();
        findHighestGrade(numberOfStudents, numberOfScores, scores, names);
        break;
      }
      case 'S':
      {
        clear();
        findStudent(names, scores, numberOfScores, numberOfStudents);
        break;
      }
      case 'G':
      {
        clear();
        saveInformation(names, letterGrades, scores, numberOfStudents, numberOfScores);
        break;
      }
      case 'Q':
      {
        break;
      }
    }
  } while (selection != 'Q');
  return 0;
}

void printAllInformation(int (*scores)[6], string* names, char* letterGrades, const int numberOfScores, int trimmedAmount){
  for (int i = 0; i < trimmedAmount; i++){
    cout << "Student: " << names[i] << endl;
    cout << "Grade: " << letterGrades[i] << endl;
    for (int j = 0; j < numberOfScores; j++){
      // formatting
      if (j == (numberOfScores - 1)){
        cout << scores[i][j] << endl;
      }
      else{
        cout << scores[i][j] << " ";
      }
    }
  }
}

int removeDuplicates(string array[], int SIZE){
  // index of the previous element in the array we are trying to compare
  int prev = 0;
  // loop through all the elements
  for (int i = 0; i < SIZE; i++){
    // if the current element is not equal to the previous element
    if (array[i] != array[prev]){
      // increment the previous counter to keep up with the loop
      array[++prev] = array[i];
    }
  }
  int count = prev + 1;
  // return the amount of elements that are not duplicates
  return count;
}

void printMenu(){
  // display options and selection prompt
  cout << "+------+" << endl;
  cout << "| Menu |" << endl;
  cout << "+ -----+" << endl;
  cout << "A) Display all information about students" << endl;
  cout << "H) Highest grade in the class" << endl;
  cout << "S) Search for a student" << endl;
  cout << "G) Save Student information to StudentData.txt" << endl;
  cout << "Q) Quit" << endl;
  cout << "Selection: ";
}

char returnLetterGrade(int percentage){
  // we can simplify indexing the grade for every student with a function and return the char at the end
  char grade;
  if (percentage == 100 && percentage < 100 && percentage >= 90){
    grade = 'A';
  }
  else if (percentage <= 89 && percentage >= 80){
    grade = 'B';
  }
  else if (percentage <= 79 && percentage >= 70){
    grade = 'C';
  }
  else if (percentage <= 69 && percentage >= 60){
    grade = 'D';
  }
  else {
    grade = 'F';
  }
  return grade;
}

void sendToArray(ifstream &stream, int studentSize, const int numberOfScores, int (*scores)[6], string* names, char* letterGrades, string* catchAll){
  string line;
  // I am aware that there are two student sizes under different aliases but I wanted to keep the parameters for sendToArray as low as possible as
  int counter = 0, number, sum = 0;
  while(getline(stream, line)){
    catchAll[counter] = line;
    counter++;
  }
  sort(catchAll, catchAll+studentSize);
  int count = removeDuplicates(catchAll, studentSize);
  string firstName, lastName, fullName;
  stream.close();
  for (int i = 0; i < count; i++){
    string var;
    // this was a major breakthrough. In project one, we already had a ifstream available at our disposal and in this project we needed to recreate it
    // once we recreate it, we treat the array that stores our parsed name list as a file in running memory, allowing to eliminate the need to write and open a separate file
    istringstream ss(catchAll[i]);
    getline(ss, line, ',');
    // now we grab the name
    stringstream namesStream(line);
    while (namesStream  >> firstName >> lastName){
      fullName = firstName + " " + lastName;
      // send it to the array
      names[i] = fullName;
    }
    for (int j = 0; j < numberOfScores; j++){
      getline(ss, line, ',');
      stringstream scoresStream(line);
      //replaces stoi <poor man's version or pre c++11>
      // converting string to int
      while (scoresStream >> number){
        scores[i][j] = number;
      }
    }
  }
  // prevents the need for another array, hence more memory efficient
  // calculating it on the fly
  for (int i = 0; i < (studentSize - 1); i++){
    for (int j = 0; j < numberOfScores; j++){
      sum+=scores[i][j];
    }
    // since this is a part of the for loop, we can call the returnLetterGrade function to assign the correct letter grade and send it to the array
    char grade = returnLetterGrade(sum);
    letterGrades[i] = grade;
    // reset the counter
    sum = 0;
  }
}

void clear(){
  // this was not created by me -> https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
  // works just like /usr/bin/clear !
  cout << "\033[2J\033[1;1H";
}

void findStudent(string* names, int (*scores)[6], const int numberOfScores, const int numberOfStudents){
  string studentSelection;
  cout << "Enter name: ";
  cin.ignore();
  getline(cin, studentSelection);
  bool studentIsFound;
  for (int i = 0; i < numberOfStudents; i++) {
    // we found them
    if (names[i] == studentSelection){
      cout << studentSelection << " is in our records" << endl;
      // this is so we can check after this loop ends if the student is not found
      studentIsFound = true;
      for (int k = 0; k < numberOfScores; k++){
        // display all of the scores
        // when we reach the end of the loop, we change the formatting, printing a newline and allowing the rest of the menu to be displayed
        if (k == (numberOfScores - 1)){
          cout << scores[i][k] << endl;
        }
        else{
          // print all in one line while it is not the last
          cout << scores[i][k] << " ";
        }
      }
      // no need to continue going through the loop since we found them
      break;
    }
    else{
      // continue to say that we cannot find the student
      studentIsFound = false;
    }
  }
  // this is where having that extra boolean assignment comes in handy
  // if we did find the student, this condition is false and will not be executed
  // this will allow us not to prematurely spout out that we could not find the student because a certain index returned false
  if (!studentIsFound) {
    cerr << "We could not find " << studentSelection << " in our records" << endl;
  }
}

void saveInformation(string* names, char* grades, int (*scores)[6], const int numberOfStudents, const int numberOfScores){
  cout << "Saving...." << endl;
  // open a new file to write to
  ofstream write;
  write.open("StudentData.txt");
  for (int i = 0; i < (numberOfStudents - 1); i++){
    // all names and grades
    write << "Student: " << names[i] << endl;
    write << "Letter Grade: " << grades[i] << endl;
    for (int j = 0; j < numberOfScores; j++){
      // scores
      if (j == (numberOfScores - 1)){
        write << scores[i][j] << endl;
        write << "\n";
      }
      else{
        write << scores[i][j] << " ";
      }
    }
  }
  write.close();
  cout << "Successfully wrote data to StudentData.txt" << endl;
}

void findHighestGrade(const int NAMES, const int GRADES, int (*scores)[6], string* names){
  // these are temporary varibales used for comparision
  int counter = 0, largest = 0;
  // store the student witht the highest grade in this string
  string studentName;
  for (int i = 0; i < NAMES; i++){
    for (int j = 0; j < GRADES; j++){
      // calculate the score for a given student
      counter+=scores[i][j];
      }
      // if your sum is bigger than the largest, obviously should be denoted as largest
      // since it is in a loop, it can be overriden for a new student
    if(counter > largest){
      largest = counter;
      studentName = names[i];
    }
    // reset the counter
    counter = 0;
  }
  cout << "Student with the Highest Score: " << studentName << endl;
  cout << "Grade: " << largest << "%" << endl;
}
