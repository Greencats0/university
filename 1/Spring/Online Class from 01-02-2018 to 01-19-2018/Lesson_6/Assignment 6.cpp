// this is an inventory collector written by 2spoopyforyou (Jared Dyreson)
// Under the GNU General Public License (GNU GPL)
// Free for anyone to repurpose, dismantle or overhaul
#include <iostream>
#include <string>
using namespace std;

int main() {
  // interesting note, extern cannot be used in a switch case as c++/compiler needs to know all values before runtime
  // we have initialized an array with size of 4 and gave it to the models
  int const CAR_MODELS = 4;
  // we have initialized an array with size of 5 and gave it the colors
  int const COLOR_SIZE = 5;
  // we set sum as extern to use outside for loop to clean up code base
  int sum = 0;
  int canIHasSearchAgain;
  int searchMenuSelection;

  string models[CAR_MODELS] = { "Toyota", "Kia", "Lincoln", "Ford" }; // , "Ford", "Honda"
  string colors[COLOR_SIZE] = { "Red", "White", "Blue", "Black", "Green" };

  int cars[CAR_MODELS][COLOR_SIZE];
  // allow this be acessed outside of the loop too
  int mostAmountOfCars;
  mostAmountOfCars = cars[0][0];

  string nameForMostAmountOfCars;
  string colorForMostAmountOfCars;


  do{
    // let's make a menu layer to make this pretty
    cout<< "+-----------------------------------------------+" << endl;
    cout<< "| California State University Fullerton Car Lot | " << endl;
    cout<< "+-----------------------------------------------+" << endl;
    cout<< '\n';
    cout<< "*Quick note - options 1 through 4 will not work if you do not take inventory*" << endl;
    cout<< '\n';
    cout<< "0) Take Inventory" << endl;
    cout<< "1) Display inventory" << endl;
    cout<< "2) Total Amount of Cars in Lot" << endl;
    cout<< "3) The greatest amount inventory of any model" << endl;
    cout<< "4) Search if car is stock" << endl;
    cout<< "5) Quit menu" << endl;
    cin >> searchMenuSelection;
    switch (searchMenuSelection) {
      case 0:{
        // let's get our inventory numbers
        cout<< "+-----------------+" << endl;
        cout<< "| Inventory Input | " << endl;
        cout<< "+-----------------+" << endl;
        cout<< endl;
        // these two for loops will ask for user input and will output them to the screen
        for (int a = 0; a < CAR_MODELS; a++){
          for (int c = 0; c < COLOR_SIZE; c++){
            cout<< colors[c] << " " << models[a] << endl;
            cout<< "How many: ";
            cin >> cars[a][c];
          }
        }
        // this clears the screen  :) and I did not create this, credits -> https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
        cout << "\033[2J\033[1;1H";
        break;
      }

      case 1:{
        // finally able to give a nice format, gonna test if awk compatible
          // I have to have this for loop to be outside of the other two because it conflicts with trying to access memory that is out of bounds. These comments are probably only helpful to me....
          for (int a = 0; a < COLOR_SIZE; a++){
            cout<< "\t" << colors[a];
          }
          cout<< endl;
          // actually outputs all the things
          for (int a = 0; a < CAR_MODELS; a++){
            cout<< models[a] << "\t";
            for (int c = 0; c < COLOR_SIZE; c++){
              cout<< cars[c][a] << "\t";
            }
            cout<< endl;
          }
          break;
      }

      case 2:{
        // total amount of cars in the dealership
        for (int a =0; a < CAR_MODELS; a++){
          for (int c = 0; c < COLOR_SIZE; c++){
            sum+=cars[a][c];
          }
        }
        cout<< "The total amount of cars in the dealership is: " << sum << endl;
        break;
      }
      case 3:{
        // the greatest amount inventory of any model
        for (int a =0; a < CAR_MODELS; a++){
          for (int c = 0; c < COLOR_SIZE; c++){
            if (cars[a][c] > mostAmountOfCars){
              mostAmountOfCars = cars[a][c];
            }
            if (cars[a][c] == mostAmountOfCars){
              nameForMostAmountOfCars = models[a];
              colorForMostAmountOfCars = colors[c];
            }
          }
        }
          cout<< "Greatest amount of inventory is the " << mostAmountOfCars << " for " << nameForMostAmountOfCars << " in color " << colorForMostAmountOfCars << endl;
          break;
      }
      case 4:{
        // just a simple check to see what cars we have in stock
        // menu dis boi
          int modelQuery, colorQuery;
          do{
            cout<< "Please select a number for which car model you wish to see is in stock" << endl;
            for (int a = 0; a < CAR_MODELS; a++){
              cout<< a << ") " << models[a] << endl;
            }
            cin >> modelQuery;
            while (modelQuery > 3){
              cerr<< "Invalid response recieved, try again: " << endl;
              cin >> modelQuery;
            }
            cout<< "Please select a number for the color type you wish to see is in stock" << endl;
            for (int c = 0; c < COLOR_SIZE; c++){
              cout<< c << ") " << colors[c] << endl;
            }
            cin >> colorQuery;
            while (colorQuery > 4){
              cerr<< "Invalid response recieved, try again: " << endl;
              cin >> colorQuery;
            }

            if (cars[modelQuery][colorQuery]){
              cout<< "It is in stock!" << endl;
              cout<< "Model: " << models[modelQuery] << endl;
              cout<< "Color: " << colors[colorQuery] << endl;
              cout<< "Amount: " << cars[modelQuery][colorQuery] << endl;
            }
            else{
              cout<< "All out!" << endl;
            }
            cout<< "0) Quit Search" << endl;
            cout<< "1) Search again" << endl;
            cout<< "Wanna do another search?: ";
            cin >> canIHasSearchAgain;
          } while (canIHasSearchAgain == 1);
          break;
      }
    }
  } while (searchMenuSelection != 5);
  return 0;
}
