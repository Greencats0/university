#include <iostream>
#include <string>

using namespace std;

// resuing code bases with template when they vary by data type and it is not crucial that we have variable data type


template <class T>
T printSomething(T thing){
  cout << thing << endl;
  return thing;
}

#define SIZE(array) (sizeof(array)/sizeof(int))
int GLOABL = 100;
class Foo{
  private:
    string operatingSystem = "Linux Mint";
    bool isOpenSource = true;
  public:
    void setOS(string os){ this->operatingSystem = os; }
    string getOS() { return operatingSystem; }
};

void aggregation();
void annikaOverloading();
void array();
void composition();
void howPointersWork();
void howPointersWork();
void inheritence();
void operatorOverloading();
void polyMorphism();
void usingVirtual();

int main(){
  cout << "Welcome to Hell" << endl;
  howPointersWork();
  return 0;
}

// one base class that is used to extend functionality across multiple other related classess
void inheritence(){
  class Person{
    private:
      string name;
    public:
      string getName() { return name; };
      void setName(string n) { this->name = n; }
  };

  class Student: public Person{
    private:
      double GPA = 4.0;
    public:
      void setGPA(double g) { this->GPA = g; }
      double getGPA() { return GPA; }
  };
  Student s;
  // no explicit declaration of setName in the Student class but is now available when the class is inherited from the other base class
  s.setName("Jared");
  cout << s.getName() << endl;
}

// engine cannot exist outside of a car and function properly
void composition(){
  class Engine{
  private:
    double horsePower;
  public:
    double getHorsePower() { return horsePower; }
    void setHorsePower(double h) { this->horsePower = h; }
  };

  class Car{
    private:
      string color;
    public:
      string getColor(){ return color; }
      void setColor(string c) { this->color = c; }
      Car(){
        Engine e;
        e.setHorsePower(1000.00);
      }
  };
}

// both objects are interactable but are not tied to any lifetime of an object
void aggregation(){

class Telephony{
  private:
    int number = 100;
  public:
    void setNumber(int n) { this->number = n; }
    int getNumber(){ return number; }
  };
  class Man{
    private:
      string name;
      Telephony* tele;
    public:
      Man(Telephony *phone = nullptr) : tele(phone){}
      string getName(){ return name; }
      void setName(string n) { this->name = n; }
  };
  Telephony *phony = new Telephony;
  Man man(phony);
  man.setName("Jared");
  cout << man.getName() << endl;
  cout << phony->getNumber() << endl;
  delete phony;
  phony = nullptr;
  cout  << "Bonkers" << endl;
}


// the area function can pull double duty based on which class is being called
// this will allow us to use the same function name for each class, reducing overall confusion
void polyMorphism(){
  class Shape{
    protected:
      int height, width;
    public:
      void setValues(int a, int b) { this->height = a; this->width = b; }
  };
  class Rectangle: public Shape{
    public:
      int area() { return (width*height); }
  };
  class Triangle: public Shape{
    public:
      int area() { return ((width*height)*0.5); }
  };
  Rectangle rect;
  Triangle tri;
  rect.setValues(4, 5);
  tri.setValues(4, 5);
  cout << rect.area() << endl;
  cout  << tri.area() << endl;
}

void operatorOverloading(){
  class Food{
    public:
      string name;
      int calories, fat, carbs;
      // constructor
      Food(int calories = 0 , int fat = 0 , int carbs = 0){
        this->calories = calories;
        this->fat = fat;
        this->carbs = carbs;
      }
      Food operator+(Food const &object) {
        Food result;
        result.calories = this->calories + object.calories;
        result.carbs = this->carbs + object.carbs;
        result.fat = this->fat + object.fat;
        // return *this will only return the given instance of an object
        return Food(result);
      }
  };
  Food steak(200, 15, 1), rice(100, 1, 20);
  Food result = steak + rice;
  cout << result.calories << endl;
}

void array(){
  int SIZE = 10;
  int array[SIZE] = {0}; // oh no, the linter is retarded
  for(int i = 0; i < SIZE; i++){
    cout << array[i] << endl;
  }
}

int returningValue(){
  int foo = 10, bar = 10, tux;
  tux = foo + bar;
  return tux; // will return 20
}

void scope(){
  static int foo = 10;
  int bar = 1;
  if(foo == 10){
    cout << "First time through, foo is: " << foo << endl;
    cout << "bar will never change because it is stuck in this scope forever: " << bar << endl;
  }
  else{
    cout << "Next time, foo is: " << foo << endl;
    cout << "bar will never change because it is stuck in this scope forever: " << bar << endl;
  }
  // not recommended to use global but are not illegal
  cout << "GLOBAL is: " << GLOABL << endl;
}

void defaultArgs(string name = "Jared", int age = 19){
  cout << name << endl;
  cout << age << endl;
}

void passingByReference(Foo &bar){
  // I have a copy of bar that I can now modify or display information about
  bar.setOS("FreeBSD");
  cout << bar.getOS() << endl;
}

void overloadedFunction(string name){ cout << name << endl; }
void overloadedFunction(int number) { cout << number << endl; }

void danglingPointer(){
  Foo *bar = new Foo[10];
  for(int i = 0; i < 10; i++){
    cout << bar[i].getOS() << endl;
  }
  delete [] bar;
  // I need to set the pointer to null
}

void memoryLeak(){
  Foo *bar = new Foo[10];
  for(int i = 0; i < 10; i++){
    cout << bar[i].getOS() << endl;
  }
  bar = nullptr;
  // I have not properly deallocated the array as I have prematurely cleared the pointer
}

void function(int& a, int* b, int c){
  a = 4;
  *b = 5;
  c = 6; // will not be preserved as it deallocated when the stack frame is cleared
}

void myFunction(int* arr){
  // arrays decay to pointers so sizeof is not the best idea
  for(size_t i = 0; i < sizeof(arr); i++){
    cout << arr[i] << endl;
  }
}

void howPointersWork(){
  int x = 10, y = 20, z = 30;
  function(x, &y, z);
  cout << x + y + z << endl; //39
  int abc;
  int &foo = abc;
  foo = 100;
  cout << "abc: " << abc << endl;
  cout << "foo: " << foo << endl;
  //int arr[10] = {0};
  // myFunction(&arr[0]); // memory location of the base address
  //myFunction(arr);
  //cout << SIZE(arr) << endl;
  //cout << sizeof(string) << endl;
  int *j, *k;
  int l = 3;
  j=&l;
  k=&l;
  if(j == k){
    cout << "They are the same" << endl;
  }
  else{
    cerr << "Not the same" << endl;
  }
  int vals[5] = {10, 20, 30, 40, 50};
  int *ptr;
  ptr = vals;
  ptr+=1;

  cout << *ptr << endl;

}

void annikaOverloading(){
  class Message{
    private:
      string content;
    public:
      void setContent(string c) { this->content = c; }
      string retrieveContent() { return content; }
    bool operator==(Message const& message){
      if(this->content == message.content){ return true; }
      else { return false; }
    }
  };
  class Snap: public Message{
    private:
      string imageLocation;
    public:
      void setPath(string imageLocation) { this->imageLocation = imageLocation; }
      string retrievePath() { return imageLocation; }
  };
  class iMessage: public Message{
    private:
      bool isSecure = true;
    public:
      bool retrieveSecurityStatus() { return isSecure; }
      void setSecurity(bool isSecure) { this->isSecure = isSecure; }
  };
  Snap snapchat;
  iMessage mensaje;
  snapchat.setContent("This is a test message from Philz");
  mensaje.setContent("This is a test message from Philz");
  if(snapchat == mensaje){
    cout << "The same" << endl;
  }
}

void usingVirtual(){
  class Car{
    public:
      virtual void Create(){ cout << "Parent Class: Car" << endl; }
  };
  class Sedan: public Car{
    public:
      void Create() { cout << "Dervied class: Sedan" << endl; }
  };
  Car car;
  Sedan sedan;
  car.Create();
  sedan.Create();
}
