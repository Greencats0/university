// Project Number One written by Jared Dyreson
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <array>
#include <boost/algorithm/string/trim.hpp>
using namespace std;
/*
  --Pseudocode begin--
    - This is all done at first so all information is easily accessed without having to run certain options <NOTE>
    - grab the lines and make a counter to see how many we have to iterate over <countLines>
    - initialize arrays and variables inside main <main>
    - read the file with the alotted amount of lines, [find names (first and last), calculate score, assign correct letter grade], append them to their respective arrays <sendInfoToArrays>
    - select from menu
      - 'A': report all iformation about students
      - 'H': Tell who has the highest grade
        - will need to be redone for Project Two to account for multiple same high scores
      - 'S': Search for a student
        - Report if the student is in the records
          - If so, print high score along with their name
      - run until the selection is 'Q'
         - save to "StudentData.txt" and quit
  --Pseudocode end--
Changelog
  - Removed grep function. We don't need it as we extracted the information and sent it to a string array so we can access it in tandum with the other arrays. Thank God for parallel arrays <allScoresArray>
  - removed temporary arrays, they are not needed any more
  - removed external library "boost", not needed at the moment. Also improved compile time by one second.
  - fixed returnLetterGrade to return the proper letter grade, the check for A grades had a weird range
    - Used data from Project Two to test because of a much larger sample size
    - Three checks for 'A' grade [100%, less than 100%, greater than or equal to 90]
*/
int calculatePercentGrade(double scoreOfStudent) {
  double curve = 90;
  double percentOfStudent = (scoreOfStudent / curve)*100;
  // my own version of rounding, since we get the accuracy from double but minus the headache of decimals
  return percentOfStudent;
}

char returnLetterGrade(double percentage){
  // we can simplify indexing the grade for every student with a function and return the char at the end
  char grade;
  if (percentage == 100 || percentage < 100 && percentage >= 90){
    grade = 'A';
  }
  else if (percentage < 89 && percentage >= 80){
    grade = 'B';
  }
  else if (percentage < 79 && percentage >= 70){
    grade = 'C';
  }
  else if (percentage < 69 && percentage >= 60){
    grade = 'D';
  }
  else {
    grade = 'F';
  }
  return grade;
}

int countLines(ifstream &stream){
  // report how much we need to iterate through
  // stringstream would not work as we would need to parse out that cash sign
  string line;
  int counter = 0;
  while (getline(stream, line)){
    // no one likes $ or blank lines...maybe $ cause I'm broke
    if (isalpha(line[0])){
      counter++;
    }
    else{
      continue;
    }
  }
  return counter;
}

int sumOfScores(string countMe){
  int sum = 0;
  stringstream ss(countMe);
  string var;
  while(ss >> var){
    int countMeIn = stoi(var);
    sum+=countMeIn;
  }
  return sum;
}

int sendInfoToArrays(const int SIZE, ifstream &fileStreamingService, string studentNameArray[], char studentLetterGradeArray[], int studentTotalGradeArray[], string allScoresArray[]){
  string line, firstName, lastName, fullName, var;
  string allScores;
  for (int i = 0; i < SIZE; i++){
    getline(fileStreamingService, line);
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
  return 0;
}

string findHighestGrade(const int SIZE, int gradeArray[], string studentArray[], string multipleHighestScores[]){
  int largest = '\0';
  string student, exportStudent;
  for (int i = 0; i < SIZE; i++){
    if(largest < gradeArray[i]){
      largest = gradeArray[i];
      student = studentArray[i];
    }
    else if(largest == gradeArray[i]){
      exportStudent = "Student: " + student + "\n" + "Grade: " + to_string(largest);
      multipleHighestScores[i] = exportStudent;
    }
  }
int n = 0;
string p;
while (p!='\0'){
  n++;
  p = multipleHighestScores[n];
}
cout << "There are: " << n-1 << " of elements in this array" << endl;
  // my way of avoiding spaces and multiple different temp arrays, all in one line :3
  student = "Student: " + student + "\n" + "Grade: " + to_string(largest);
  // able to iterate this string via stringstream for further parsing
  return student;
}

void clear(){
  // this clears the screen and I did not create this, credits -> https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
  // achives the same funcitonality of "cls" and "clear" <UNIX>
  cout << "\033[2J\033[1;1H";
}

void findStudent(const int SIZE, string student, string studentArray[], string allScoresArray[]){
  bool found = false;
  string grades;
  for (int i = 0; i < SIZE; i++){
    if (student == studentArray[i]){
      found = true;
      grades = allScoresArray[i];
      break;
    }
    else{
      continue;
    }
  }
  if (found){
    clear();
    cout << "Student: " << student <<  "\n" << "Grades: " << grades << endl;
  }
  else{
    cerr << "Error: Not in our records" << endl;
  }
}

int main(){
  ifstream stream;
  stream.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project Two/CPSC121dataUpdated.txt");
  if (!stream.is_open()){
    cerr << "Unable to open the file" << endl;
    exit(1);
  }
  const int AMOUNT = countLines(stream);
  // this line saved me because I was needing to reopen the file a second time
  stream.clear();
  stream.seekg(0, ios::beg);
  string studentNameArray[AMOUNT] = {};
  char studentLetterGradeArray[AMOUNT] = {};
  int studentTotalGradeArray[AMOUNT] = {};
  string allScoresArray[AMOUNT] = {};
  string line, firstName, lastName, fullName;
  string multipleHighestScores[AMOUNT] = {};
  char selection;
  sendInfoToArrays(AMOUNT, stream, studentNameArray, studentLetterGradeArray, studentTotalGradeArray, allScoresArray);
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
        clear();
        for (int i = 0; i < AMOUNT; i++){
          cout << "Student: " << studentNameArray[i] << endl;
          cout << "Grade: " << studentLetterGradeArray[i] << endl;
          cout << "Percent: " << studentTotalGradeArray[i] << endl;
          cout << "All scores: " << allScoresArray[i] << endl;
          cout << "\n";
         }
        break;
      }
      case 'H':
      {
        clear();
        string studentWithHighestGrade = findHighestGrade(AMOUNT, studentTotalGradeArray, studentNameArray, allScoresArray);
        cout << studentWithHighestGrade << endl;
        // display series of higest scores
        break;
      }
      case 'S':
      {
        clear();
        string student;
        cout << "Student name: ";
        cin.ignore();
        getline(cin, student);
        findStudent(AMOUNT, student, studentNameArray, allScoresArray);
        break;
      }
      case 'Q':
      {
        clear();
        cout << "Saving..." << endl;
        ofstream saveRecords;
        saveRecords.open("StudentData.txt");
        for (int i = 0; i < AMOUNT; i++){
          saveRecords << "Student: " << studentNameArray[i] << "\n" << "Letter Grade: " << studentLetterGradeArray[i] << "\n" << "Percentage: " << studentTotalGradeArray[i] << "\n" << endl;
        }
        saveRecords.close();
        cout << "Saved to StudentData.txt" << endl;
        break;
      }
      default:
      {
        clear();
        cerr << "Not a valid option" << endl;
      }
    }
  } while (selection != 'Q');
  return 0;
}
