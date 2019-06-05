// Project Number Two written by Jared Dyreson
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
Highly detailed notes inbound

How to compile me on Linux: g++ -std=c++11 Individual_Project_One.cpp -o Individual_Project_One
Quick bonus [run program, save results and see them in one command]: echo "Q" | ./Individual_Project_One && cat StudentData.txt

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
  if (percentage == 100 && percentage < 100 && percentage >= 90){
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

// use a pointer to tell our program where in the stream we are
int countLines(ifstream &stream){
  // report how much we need to iterate through
  // just make sure that the first character in each string is in the alphabet
  // parses out the $ sign and blank lines
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


void clear(){
  // this clears the screen and I did not create this, credits -> https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
  // achives the same funcitonality of "cls" <WIN32/x86_64> and "clear" <UNIX>
  cout << "\033[2J\033[1;1H";
}


int main(){
  // goal for next project is to add command line arguments to test if it retroactively works with other files without having to hardcode values like below
  // ooh another idea, command line parsing for these values in the menu? PoC -> ./Individual_Project_One -f /home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project One/CPSC121data -h (-f -> file, -h -> indicates that we want the largest value)
  ifstream stream;
  stream.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project One/CPSC121data");
  if (!stream.is_open()){
    cerr << "Unable to open the file, cowardly refusing" << endl;
    exit(1);
  }

  const int AMOUNT = countLines(stream);
  // this line saved me because I was needing to reopen the file a second time but since we clear the stream, we in essence open the file again, in two lines
  stream.clear();
  stream.seekg(0, ios::beg);

  string studentNameArray[AMOUNT] = {};
  char studentLetterGradeArray[AMOUNT] = {};
  int studentTotalGradeArray[AMOUNT] = {};
  // I am keeping this fourth function because I need it to store student grades as strings and I am able to more easily access their records
  // To access their records and do stuff to them [find the sum, mean, etc], use stringstream and stoi in unision to break the barrier of trying to add strings/chars
  // Another note, using stringstream will allow us to access digits that are larger than one [20 for example] because a for loop [any loop actually] will treat everything as a char and will not yield correct results
  string allScoresArray[AMOUNT] = {};
  char selection;
  string allScores, line, firstName, lastName, fullName, var;
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
  do{
    cout << "+------+" << endl;
    cout << "| Menu |" << endl;
    cout << "+ -----+" << endl;
    cout << "A) Display all information about students" << endl;
    cout << "H) Highest grade in the class" << endl;
    cout << "S) Search for a student" << endl;
    cout << "G) Save to grades to StudentData.txt" << endl;
    cout << "Q) Quit" << endl;
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
          cout << "All scores:" << allScoresArray[i] << endl;
          cout << "\n";
         }
        break;
      }
      case 'H':
      {
        clear();
        int largest = '\0';
        string student;
        for (int i = 0; i < AMOUNT; i++){
          if(largest < studentTotalGradeArray[i]){
            largest = studentTotalGradeArray[i];
            student = studentNameArray[i];
          }
        }
        // my way of avoiding spaces and multiple different temp arrays, all in one line :3
        cout << "Student: " << student << "\n" << "Grade: " << to_string(largest) << endl;
        break;
      }
      case 'S':
      {
        clear();
        string student;
        cout << "Student name: ";
        cin.ignore();
        getline(cin, student);
        bool found = false;
        string grades;
        for (int i = 0; i < AMOUNT; i++){
          if (student == studentNameArray[i]){
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
        break;
      }
      case 'G':
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
      case 'Q':
      {
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
