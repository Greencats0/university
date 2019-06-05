#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int calculatePercentGrade(double scoreOfStudent) {
  double curve = 90;
  double percentOfStudent = (scoreOfStudent / curve)*100;
  return percentOfStudent;
}

char returnLetterGrade(double percentage){
  // we can simplify indexing the grade for every student with a function and return the char at the end
  char grade;
  if (percentage == 100 && percentage >= 90){
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

// this will allow us to break free from the restrictions of exporting arrays outside of functions
int findLargestGrade(int gradeArray[]){
  // this is how you use an index as an input for a function; whatever the data type is for the array then a set of square brackets
  const int SIZE = 5;
  // found that garbage was being stored in largest after previous runs, set it to NULL
  int largest ='\0';
  const int TEMP_SIZE = 1;
  int temp[TEMP_SIZE] = {};
    for (int i = 0; i < SIZE; i++){
      if (gradeArray[i] > largest){
        largest = gradeArray[i];
      }
    }
  return largest;
}

// so we can save the position in the array
// used in finding the name of the student of the highest grade
int findGradePostion(int newArray[], int valueToSearch){
  const int TEMP_SIZE = 1;
  int temp[TEMP_SIZE] = {};
  const int SIZE = 5;
    for (int i = 0; i < SIZE; i++){
      if (newArray[i] == valueToSearch){
        temp[0] = i;
      }
    }
  return temp[0];
  // found that garbage was being collected in this array after mulitple executions in other program, resetting it to NULL alieviates it
  temp[0] = '\0';
}

// inspiration came from this post -> https://www.daniweb.com/programming/software-development/threads/152550/how-can-i-grep-a-file-using-c
string grep(ifstream &input, string pattern){
  // if we did not clear the stream, we would be starting from the middle and that is no bueno
  input.clear();
  input.seekg(0, ios::beg);
  string patternFound;
  if (input.is_open()){
    string line;
    while (getline(input, line)){
      line.erase(remove(line.begin(), line.end(), ','), line.end());
      if (line.find(pattern) != string::npos){
        // only accounts for one line of finding
        patternFound = line;
        return patternFound;
      }
    }
  }
  else{
    cerr << "Unable to open file" << endl;
  }
}

void reportInfo(ifstream &fileStreamingService, string studentName){
  string returnedString;
  const int TEMPARRAYSIZE = 6;
  int tempArray[TEMPARRAYSIZE] = {};
  int currentPositionInStream = fileStreamingService.tellg();
  returnedString = grep(fileStreamingService, studentName);
  fileStreamingService.seekg(currentPositionInStream, ios::beg);
  stringstream ss(returnedString);
  string firstName, lastName, fullName, outputFORME;
  int scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive, scoreSix;
  ss >> firstName >> lastName >> scoreOne >> scoreTwo >> scoreThree >> scoreFour >> scoreFive >> scoreSix;
  // not the prettiest but it does the job
  tempArray[0] = scoreOne;
  tempArray[1] = scoreTwo;
  tempArray[2] = scoreThree;
  tempArray[3] = scoreFour;
  tempArray[4] = scoreFive;
  tempArray[5] = scoreSix;
  for (int i = 0; i < TEMPARRAYSIZE; i++){
    // just for neatness
    if  (i == TEMPARRAYSIZE-1){
      cout << tempArray[i] << endl;
    }
    else{
      cout << tempArray[i] << ",";
    }
  }
}
int parseAndAppend(ifstream &fileStreamingService) {
	int const SIZE = 5;
  int const SCORES = 6;
	string data;
	string namesOfStudents[SIZE];
  int studentScores[SIZE];
  char studentLetterGrades[SIZE];
  int studentRawScores[SIZE][SCORES];
  for (int i = 0; i < SIZE; i++){
    string line;
    getline(fileStreamingService, line);
    // achive same functionality of sed in UNIX enviornment [ example : sed "jared, is, awesome" | sed 's/\,//g' -> "jared is awesome"]
    line.erase(remove(line.begin(), line.end(), ','), line.end());
    stringstream ss(line);
    string firstName;
    string lastName;
    float percent;
    char letterGrade;
    int score0, score1, score2, score3, score4, score5;
    ss >> firstName >> lastName >> score0 >> score1 >> score2 >> score3 >> score4 >> score5;
    //read datafrom file
    string fullName = firstName + " " + lastName;
    int totalScore = score0 + score1 + score2 + score3 + score4 + score5;
    percent = calculatePercentGrade(totalScore);
    letterGrade = returnLetterGrade(percent);
    namesOfStudents[i] = fullName;
    studentScores[i] = percent;
    studentLetterGrades[i] = letterGrade;
    }

    char selection;
    do {
      cout << "+------+" << endl;
      cout << "| Menu |" << endl;
      cout << "+ -----+" << endl;
      cout << "A) Display all information about students" << endl;
      cout << "H) Highest grade in the class" << endl;
      cout << "S) Search for a student" << endl;
      cout << "Q) Save to file and quit" << endl;
      cout << "Selection: ";
      cin >> selection;
      switch (selection){
        // display everything
        case 'A':
        {
          // this clears the screen  :) and I did not create this, credits -> https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
          cout << "\033[2J\033[1;1H";
          for (int i = 0; i < SIZE; i++)	{
            cout<< "Name: " <<  namesOfStudents[i] << endl;
            cout<< "Percent: " << studentScores[i] << endl;
            cout<< "Letter Grade: " << studentLetterGrades[i] << endl;
            cout<< "\n";
          }
          break;
        }
        // display highest grade in the class
        case 'H':
        {
          int value = findLargestGrade(studentScores);
          int grade = findGradePostion(studentScores, value);
          // this clears the screen  :) and I did not create this, credits -> https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
          cout << "\033[2J\033[1;1H";
          cout << "Name of student: " << namesOfStudents[grade] << endl;
          cout << "Grade: " << value << endl;
          break;
        }
        // search for a student
        case 'S':
        {
          string studentName;
          // this clears the screen  :) and I did not create this, credits -> https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
          cout << "\033[2J\033[1;1H";
          FILE* debug;
          // the nice advantage of fprintf over cout is that we can more efficiently report errors to the user
          cout<< "Please enter a student's name: ";
          // I had to include this because it was terminating the getline function before execution
          // c++ needed the stream to be either flushed or ignored, so ignored it is
          cin.ignore();
          getline(cin, studentName);
          for (int i = 0; i < SCORES; i++){
            if (namesOfStudents[i] == studentName){
              cout << "\n";
              cout << "Student Name: " << studentName << endl;
              cout << "\n";
              cout << "+--------+" << endl;
              cout << "| Scores |" << endl;
              cout << "+--------+" << endl;
              cout << "\n";
              reportInfo(fileStreamingService, studentName);
              cout << "\n";
              break;
            }
            else{
              // I love /dev/null
              debug = fopen("/dev/null", "w");
              fprintf(debug, "Errors, errors everywhere\n");
            }

          }
          break;
        }
        // save and quit
        case 'Q':
        {
          // we need to take the information and display send it to an output file
          ofstream myFile ("./StudentGrades.txt");
          if (myFile.is_open()){
            for (int i = 0; i < SIZE; i++){
              myFile<< "Name: " <<  namesOfStudents[i] << endl;
              myFile<< "Percent: " << studentScores[i] << endl;
              myFile<< "Letter Grade: " << studentLetterGrades[i] << endl;
              myFile<< "\n";
            }
          }
            myFile.close();
          break;
        }
        default:
        {
          cout<< "Invalid option!" << endl;
          break;
        }
      }
    } while (selection != 'Q');
  }

int main(){
	ifstream myFile;
	myFile.open("./CPSC121data");
  if (myFile.is_open()){
    parseAndAppend(myFile);
    myFile.close();
  }
	else {
    cerr<< "Sorry, cannot open the file" << endl;
	}
}
