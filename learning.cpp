/*
From W3Schools' C++ tutorial: https://w3schools.com/cpp
I am using GNU C/C++ Compiler (gcc/g++) on the Crostini Debian x86_64 VM on ChromeOS

*/
#include <iostream> //allows I/O -- input/output
#include <string> //there is a built in type `string`, but this allows better use. to use C's <string.h>, include <cstring>. they have some different functions.
#include <cmath>
using namespace std; //we're using the standard library -- without this it would be std::cout and std::cin, etc
//if leaving `namespace` out, `std::` before string declaration is required

/*
  Comments use this convention
  C++ ignores whitespace
  Compile file:
    g++ -o <compiled file> <source file>
      `g++` ----------- Run the GNU C++ Compiler
      `-o` -----------  Put the output of compilation into another file
      <compiled file> --  Name of file to output compiled computer code to (run this one later)
      <source file> -- Name of file to compile (Code in this one, compile to and run the other one)
    g++ <source file> -o <compiled file>
      `g++` ----------- Run the GNU C++ Compiler
      <source file> -- Name of file to compile (Code in this one, compile to and run the other one)
      `-o` -----------  Put the output of compilation into another file
      <compiled file> --  Name of file to output compiled computer code to (run this one later)
  Run file:
    ./<compiled file>
      Executes compiled file from command
      MUST MATCH NAME OF <compiled file> FROM PREVIOUS COMMAND
      <compiled file> is executable, and will be green in `ls`
*/


/*
There are some parts of the program that must be declared above `main()`.
I highly suggest you start from the beginning of `main()`, and return here when you get to that part of the tutorial
*/


//functions! yay
//*must* be above declared `main()` or else error
void myFunction() {
  cout << "`myFunction()` was executed!\n";
}
void mySecondFunction(); //functions can be  declared above and defined below
void functionWithParams(string stringParam, int integerParam); //params must be specified in both places
void functionWithDefaultParam(string parameter = "this is the default"); //default must be in declaration and not filling
string functionThatReturns();
//overloading!
int overloaded(int x, int y);
string overloaded(string x, string y);


//OOP
class myFirstClass {
  public:
    int myNum;
    string myString;
    

    //methods
    //inside class method
    int printAttributes() {
      cout << myNum << "\n";
      cout << myString << "\n";
      return 0;
    }
    //outside class method
    int printAttributesReversed();
    //methods can have args, etc
};
class anotherClass {
  public:
    int someAttribute;

    //constructor
    anotherClass() {
      //must have same name as class
      //always public
      //no return -- `void` method
      cout << "You have created an Object of type `anotherClass`, and it has the attribute `someAttribute` of type Int\n";
    }
};
//constructors can also be declared outside of the class, like normal methods -- needs to be investigated
class cstructWithArgs {
  public:
    int iNeedAValue;
    string iCantThinkOfNames;

    int printAttributes() {
      cout << iNeedAValue << "\n";
      cout << iCantThinkOfNames << "\n";
      return 0;
    }

    cstructWithArgs(int x = 0, string y = "") {
      iNeedAValue = x;
      iCantThinkOfNames = y;
      cout << "`iNeedAValue has been given the value " << x << " and `iCantThinkOfNames` has been initialized with \"" << y << "\".\n";
    }
};
class accesses {
  //attributes are private by default
  public:
    int x = 200;
  private:
    int y = 200;
  protected:
    int z = 200;
  //best practice: keep as many variables private as possible

  //access workaround/protector (depends how you look at it)
  public:
    //hey references!
    int printPrivates(int &variable) {
      cout << variable << "\n";
      return 0;
    }
    int modifyPrivates(int &variable, int newVal) {
      //doesnt work how i wish
      variable = newVal;
      return 0;
    }
    int printY() {
      cout << y << "\n";
      return 0;
    }
    int modifyY(int newVal) {
      y = newVal;
      return 0;
    }
};
//copied:
// Base class
class Vehicle {
  public:
    string brand = "Ford";
    void honk() {
      cout << "Toot, toot! \n" ;
    }
};
// Derived class
class Car: public Vehicle {
  public:
    string model = "Mustang";
};
//end copy
class Performance: private Car { //private: cannot access `model`, `honk()`
  public:
    string usage = "Racing";
};
class twoParents: public Car, public accesses {
};
//polymorphism --- copied
// Base class
class Animal {
  public:
    void animalSound() {
    cout << "The animal makes a sound \n" ;
  }
};
// Derived class
class Pig : public Animal {
  public:
    void animalSound() {
    cout << "The pig says: wee wee \n" ;
  }
};
// Derived class
class Dog : public Animal {
  public:
    void animalSound() {
    cout << "The dog says: bow wow \n" ;
  }
};
//end copy



int main(int argc, char** argv) { //start function -- main() runs on file execution | `argc` is number of command line args, `argv` is list of args. --  `$ ./learningcpp these are args` would make argc = 4 and argv be {"./learningcpp", "these", "are", "args"}

  //intro:
  cout << "1) Hello World!\n"; // prints "Hello World!" and new line to console. "\n" preferred or more popular than `<< endl`
  cout << "2) Hello World!" << endl; //outputs the same thing as previous line
  cout << "You may find this sometimes:"; //no new line
  cout << endl << "3) Hello World"; //new line then print -- used like this for input
  cout << "\n";


  cout << "\n";

  //creating variables
  /*
  -- Names are case sensitive
  -- No whitespace or special characters in names
  -- No reserved words (like `int`, etc.)
  */
  int intVar = 123; //integers, no decimal |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|- 4 bytes -whole number, positive or negative
  int intVarNeg = -123; //negative int  
  float floatVar = 9448.943; //float variable |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|- 4 bytes -fractional number, one or more decimals, positive or negative -- UP TO 7 DECIMAL PLACES
  float floatVarNeg = -9448.943; //negative float variable
  double doubleVar = 19.23593; //floating point |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|- 8 bytes -fractional number, one or more decimals, positive or negative -- UP TO 15 DECIMAL PLACES
  double doubleVarNeg = -19.23593; //negative floating point
  char charVar = 'N'; //character variable -- REMEMBER SINGLE QUOTE |-|-|-|-|-|- 1 byte -character, letter, number or ASCII value
  string stringVar = "stringVar"; //string -- REMEMBER DOUBLE QUOTE |-|-|-|-|-|- string literals are built in, to work with them, `#include <string>`
  bool boolVar = true; //boolean |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|- 1 byte -true or false
  int valueLater; //declare variable valueLater
  valueLater = 76; //assign valueLater value 76
  cout << "valueLater = " << valueLater << "\n"; //print `valueLater` and label to console to show that previous two lines work
  int a = 7, b = 9, c = 41; //declare and assign values to multple variables in one line
  const int constantIntVar = 4; //constant variables are declared like other variables, but with `const` keyword in front of type
  //`constantIntVar = 9;` would throw an error because constant variables *cannot* be changed 
  const char constantCharVar = 'Z'; //constant variables can be any type

  cout << "\n";

  //messing with variables and `cout`
  int changeValue = 3; //declare and assign value `3` to variable `changeValue`
  cout << "changeValue = " << changeValue << "\n"; //print `changeValue` and label to console
  changeValue = 942; //assign value 942 to variable `changeValue`, overwriting previous value
  cout << "changeValue = " << changeValue << "\n"; //print `changeValue` and label to console
  string concatenatedString = "string"; //declare and assign value "string" to variable `concatenatedString`
  cout << "i can concatenate " << concatenatedString << " variables and text\n"; //print concatenatedString to console, with label before and after
  cout << (char)72 << (char)101 << (char)108 << (char)108 << (char)111 << "\n"; //output a character with code 119
  
  cout << "\n";

  //operators
  int x = 4; //declare and assign `x`
  int y = 8; //declare and assign `y`, yadda yadda
  int sumxy = x + y; //declare and assign `sumxy` -- is the sum of `x` and `y`
  cout << "sumxy = " << sumxy << "\n"; //print `sumxy` and label
  //arithmetic operators: `+`, `-`, `*`, `/`, `%`, `++`, `--`
  cout << "addition operator: `+`: 24+3 =" << 24+3 << "\n";
  cout << "subtraction operator: `-`: 24-3 = " << 24-3 << "\n";
  cout << "multiplication operator: `*`: 24*3 = " << 24*3 << "\n";
  cout << "division operator: `/`: 24/3 = " << 24/3 << "\n";
  cout << "modulus (remainder) operator: `%`: 25%3 = " << 25%3 << "\n";
  int l = 25;
  int k = 25;
  cout << "increment operator: `++`: (l = 25): ++l = " << ++l << "\n";
  cout << "decrement operator: `--`: (k = 25): --k = " << --k << "\n";
  //assignment operators: `=`, `+=`, `-=`, `*=`, `/=` `%=`, (bitwise -->) `&=`, `|=`, `^=`, `>>=`, `<<=` (wikipedia cpp operators for bitwise, or edit this again later)
  cout << "assignment operators work how you expect: \n";
  cout << "varA += varB\n";
  cout << "varA now equals old varA value + varB\n";
  //comparison operators: `==`, `!=`, `>`, `<`, `>=`, `<=`
  cout << "comparison operators are what you expect\n";
  //logical operators: `&&`, `||`, `!`
  cout << "logical operators:\n";
  cout << "logical `and`: `&&`\n";
  cout << "logical `or`: `||`\n";
  cout << "logical negation: `!`\n";
  
  cout << "\n";

  //strings
  string firstName = "Neriya";
  string lastName = "Rosenthal";
  string fullName = firstName + " " + lastName;
  cout << "Concatenated name: " << fullName << "\n";
  //strings are actually objects
  firstName.append(" ");
  string fullName2 = firstName.append(lastName); //append is faster than `+`
  cout << "fullName2: " << fullName2 << "\n";
  string longString = "this is a very long string which i plan to use for a couple things";
  cout << longString << "\n";
  cout << "longString.length() = " << longString.length() << "\n";
  cout << "longString.size() = " << longString.size() << " ---`.size()` is an alias of `.length()`\n";
  cout << "longString[8] = '" << longString[8] << "'\n";
  longString[8] = 'N';
  cout << longString << "\n";

  cout << "\n";
  
  //math
  cout << "max: " << max(393, 194854095) << "\n"; //only takes two values
  cout << "min: " << min(393, 194854095) << "\n"; //only takes two values
  //to use `sqrt()`, `round()`, etc, `#include <cmath>`
  //look up math methods, not going to write them all now, or probably use them for a long time
  int n = 3+6*10; //returns 63, NOT 90! ORDER OF OPERATIONS!
  cout <<"n = " << n << "\n";

  cout << "\n";

  //booleans
  bool boolTestingVar1 = true;
  bool boolTestingVar2 = false;
  cout << "true is: " << boolTestingVar1 << "\n";
  cout << "false is: " << boolTestingVar2 << "\n";
  //bool expressions: uses comparison operator to return 1 or 0
  cout << "(intVar > intVarNeg): " << (intVar > intVarNeg) << "\n"; //parentheses required always -- `intVar` and `intVarNeg` are from first chunk

  cout << "\n";

  //conditions, conditional statements, etc
  //`if`, `else`, `else if`, `switch`
  cout << "------ conditions!\n";
  if (intVar > intVarNeg) {
    cout << "first `if` statement passed\n";
  } else if (floatVar > floatVarNeg) {
    cout << "`else if` statement passed\n";
  } else {                                      //else can be on new line
    cout << "else statement ran\n";
  }
  //ternary operator, shorthand `if` statement:
  //variable = (condition) ? resultiftrue : resultiffalse
  string result = (doubleVar > doubleVarNeg) ? "positive in ternary is greater\n" : "negative in ternary is greater\n";
  cout << result;

  cout << "\n";

  //`switch` statement
  /*
  switch(expression) {
    case a;
      //code
      break;
    case b;
      //code
      break;
    default;
      //code
  }
  */
  int day = 2;
  cout << "The entered day is: ";
  switch(day) {
    case 1:
      cout << "Sunday";
      break;
    case 2:
      cout << "Monday";
      break;
    case 3:
      cout << "Tuesday";
      break;
    case 4:
      cout << "Wednesday";
      break;
    case 5:
      cout << "Thursday";
      break;
    case 6:
      cout << "Friday";
      break;
    case 7:
      cout << "Saturday. Why are you on the computer?";
      break;
  }
  cout << "\n";

  cout << "\n";

  //still kind of conditionals, but its a new section
  //iteration!
  //`while` loop -- will only execute if condition is met
  cout << "`while`:\n";
  int i = 0;
  while(i < 5) {
    cout << "i: " << i << "\n";
    i++; //imperative to increase
  }
  //`do-while` loop -- executes at least one time before checking condition
  cout << "`do-while`:\n";
  i = 0;
  do {
    cout << "i: " << i << "\n";
    i++; //imperative to increase
  }
  while(i < 5);
  //`for` loop:
  /*
  for (statement 1; statement 2; statement 3) {
    //code
  }
  statement 1 runs once on first execution
  statement 2 is condition for execution
  statement 3 runs after every execution
  */
  cout << "`for` loop:";
  for(int h = 0; h < 25; h+=3) { //use `h++` for increment by 1
    cout << "h = " << h << "\n";
  }

  //break and continue
  cout << "`break` and `continue`\n";
  cout << "iterates up to 13, `break`s at 8";
  for(int e = 0; e < 13; e++) { //variable declaration required as statement 1
    cout << "e = " << e << "\n";
    if(e == 8) {
      break; //`break` exits loop
    }
  }
  cout << "iterates up to 13, `continues` at 8";
  for(int u = 0; u < 13; u++) {
    cout << "u = " << u << "\n";
    if(u == 8) {
      continue; //`continue` exits current iteration
    }
  }
  //`break` and `continue` work for all kinds of loops

  cout << "\n";

  //arrays
  /*
  these are complicated
  -all values must be same type
  -declare type
  -access with [index]
  -you _can_, but do not have to, limit length on declaration inside brackets
  --if you do not declare length, *you must* declare values. [[reserved memory is based on either |length on declaration| or |declared length|]]
  */
  int intArray[] = {498593, 5984902, 239484, 23945829}; //limit is not set -- length is based on length on declaration
  string strArray[3] = {"value1", "value2", "value3"};
  int emptyArray[3]; //you can declare arrays and add values later, but size is required
  intArray[2] = 9792357; //you can change values
  strArray[2] = "new value2"; //even for set length arrays
  //intArray[4] = 6543984; //this throws error at garbage collection/end of execution -- length is set
  cout << intArray <<"\n";
  //loop through array:
  cout << "loop through array:\n";
  cout << "length of array: " << sizeof(intArray)/sizeof(intArray[0]) << "\n";
    for(int t = 0; t < sizeof(intArray)/sizeof(intArray[0]); t++) { //this is pretty complex for a learning file, but whatever. it takes full size of array and divides by size at [0]. each value is the same amount of space -- all `int`s are 4 bytes
    cout << "t = " << t << "\n";
    cout << "intArray[t] = " << intArray[t] << "\n";
  }
  //to add to an array that does not have a size defined, overwrite necessary
  //arrays with size declared reserve space, even for values that are not declared

  cout << "\n";

  //structures
  struct {
    //member values:
    int structInt;
    string structString;
  } firstStruct; //can declare more than one using commas
  //cout << firstStruct << "\n"; //yeah no
  firstStruct.structInt = 25;
  firstStruct.structString = "I am a string in a structure, and I am happy as a bug in a rug";
  cout << firstStruct.structInt << "\n";
  cout << firstStruct.structString << "\n";
  //int firstStruct.newValue = 99; //this is not how you add values
  //cout << firstStruct.newValue << "\n";
  struct myOwnType {
    int myTypeHasInt;
    string myTypeHasString;

    int printMembers() {
      cout << myTypeHasInt << "\n";
      cout << myTypeHasString << "\n";
      return 1;
    }
  }; //can declare variables here too
  myOwnType thisIsMyOwn; //but this is easier
  thisIsMyOwn.myTypeHasInt = 5;
  thisIsMyOwn.myTypeHasString = "Hey, this is my own type! It has a string!";
  cout << thisIsMyOwn.myTypeHasInt << "\n";
  cout << thisIsMyOwn.myTypeHasString << "\n";
  cout << "Printing members of `thisIsMyOwn`:\n";
  thisIsMyOwn.printMembers();
  //obviously i can make more with the same type

  cout << "\n";

  //references
  //declared with `&`
  //simplifies to referenced variable instead of value
  //referenced variable then simplifies to value
  string food = "Pizza";
  string meal = food; //value is "Pizza"
  string* mealRef = &food; //value is `food`
  //string mealRef2 = &food; //doesnt work
  string& mealRef3 = food;
  cout << "food: " << food << "\n";
  cout << "meal: " << meal << "\n";
  cout << "mealRef: " << mealRef << "\n";
  //cout << mealRef2 << "\n";
  cout << "mealRef3: " << mealRef3 << "\n";
  //all return "Pizza"
  //not sure the use but ill find one
    //see last line of chunk
    //not entirely helpful but kind of is
  //eventually
  //---
  //Memory address
  //& operator used to declare references and find memory address
  cout << "   memory address of food: " << &food << "\n";
  cout << "   memory address of meal: " << &meal << "\n";
  cout << "memory address of mealRef: " << &mealRef << "\n";
  //memory addresses let you manipulate memory!
  //-----
  food = "Burger";
  cout << "food: " << food << "\n";
  cout << "meal: " << meal << "\n";
  cout << "mealRef: " << mealRef << "\n";
  cout << "mealRef3: " << mealRef3 << "\n";
  cout << "memory address of meal: " << meal << "\n";

  //pointers
  //references store variables
  //pointers have memory address
  string* foodPointer = &food; //asterisk makes variable a pointer
  cout << foodPointer << "\n";
  //three ways to make pointer:
  string* pointer;
  string *Pointer = &food;
  string * pointerthing;
  //^first method is preferred
  cout << *Pointer << "\n"; //reference - returns value at memory address
  cout << Pointer << "\n"; //dereference - returns memory address
  //modifying pointer
  string pointedVar = "specific value";
  string* pointedVarPointer = &pointedVar;
  cout << "pointedVar = " << pointedVar << "\n";
  cout << "pointedVarPointer = " << pointedVarPointer << "\n";
  *pointedVarPointer = "differentvalue";
  cout << "-|----changed `pointedVarPointer`\n";
  cout << "pointedVar = " << pointedVar << "\n";
  cout << "pointedVarPointer = " << pointedVarPointer << "\n";
  //pointer stays the same, modifies value of variable

  cout << "\n";

  //functions
  myFunction();
  mySecondFunction();
  functionWithParams("this is a parameter sent to the function!", 4983); //both are required
  functionWithDefaultParam("fWDP ran once");
  functionWithDefaultParam();
  functionWithDefaultParam("fWDP ran a third time");
  string holierThanThou = functionThatReturns();
  cout << holierThanThou << "\n";
  cout << overloaded(5, 7) << "\n";
  cout << overloaded("first, ", "second") << "\n";

  cout << "\n";

/* to skip to OOP, remove asterisk -->*/
  //input yay
  //`cin` considers whitespace to be termination and will ignore everything after - use `getline()`
  int inputNumber; //declare variable `inputNumber`
  string inputString; //declare variable `inputString`
  string getlineVar;
  cout << "Input a number:\n";
  cin >> inputNumber; //get input, and assign value to `inputNumber`
  // |||||| --> inputting wrong type causes next line to print `0`, print the rest of `cout` statements and quit execution
  cout << "YOUR NUMBER: " << inputNumber << "\n"; //output `inputNumber`
  cout << "Input a string:\n";
  cin >> inputString; //get input, and assign value to `inputString`
  cout << "YOUR STRING: \"" << inputString << "\"\n"; //output `inputNumber
  /*
  experiment with this stuff, but works weird if after cin i think ---delete/add asterisk here to run `getline()`, etc. -->/
  getline(cin, getlineVar);
  cout << "getlineVar: " << getlineVar << "\n";
  /**/

  cout << "\n";
/**/

  //OOP
  myFirstClass myFirstObject;
  //you can obviously make more than one object from a class
  myFirstObject.myNum = 19;
  myFirstObject.myString = "A string from an object!";
  cout << myFirstObject.myNum << "\n";
  cout << myFirstObject.myString << "\n";
  cout << "Print attributes with a method:\n";
  myFirstObject.printAttributes();
  /* supposedly you can make functions like this? investivate further -->/
  int myFirstClass::printAttributesReversed() {
    cout << myString << "\n";
    cout << myNum << "\n";
    return 0;
  }
  /**/
  anotherClass anotherObject;
  anotherObject.someAttribute = 87;
  cout << anotherObject.someAttribute << "\n";
  cstructWithArgs theseAttributesWillBeInitialized(9, "Yeah, I think so");
  cstructWithArgs theseAttributesWIllBeDefault; //iNeedAValue will be 0 because *I* did that
  theseAttributesWillBeInitialized.printAttributes();
  theseAttributesWIllBeDefault.printAttributes();
  accesses testAccess;
  testAccess.x = 29;
  //testAccess.y = 97; //private -- cannot modify
  //testAccess.z = 65; //protected -- cannot modify
  cout << testAccess.x << "\n";
  //cout << testAccess.y << "\n"; //private -- cannot access at all
  //cout << testAccess.z << "\n"; //protected -- cannot access at all
  //workaround!:
  testAccess.printPrivates(y);
  testAccess.modifyPrivates(y,77); //doesnt work how i wish
  testAccess.printPrivates(y);
  testAccess.modifyY(55);
  testAccess.printY();
  //testAccess.printPrivates(z); //its protected!
  //copied:
  Car myCar;
  myCar.honk();
  cout << myCar.brand + " " + myCar.model << "\n";
  //end copy
  Performance fordGTO;
  //fordGTO.honk(); //private -- see class declaration
  cout << fordGTO.usage << "\n";
  twoParents twoParentClasses;
  twoParentClasses.honk();
  twoParentClasses.printPrivates(y); //hmmm, printing 77
  //polymorphism
  Animal myAnimal;
  Pig myPig;
  Dog myDog;
  myAnimal.animalSound();
  myPig.animalSound();
  myDog.animalSound();

  cout << "\n";
  //in the tutorial, file access comes here. that's a whole thing i'm not going to include here

  //error handling
  //copied
  try {
    int age = 15;
    if (age >= 18) {
      cout << "Access granted - you are old enough.";
    } else {
      throw (age); //cause an error
    }
  }
  catch (int myNum) { //error manually thrown above caught here
    cout << "Access denied - You must be at least 18 years old.\n";
    cout << "Age is: " << myNum << "\n";
  }
  //end copy
  try {
    if (longString.length() > 20) {
      throw 20;
    }
    if (longString.length() < 5) {
      throw 5;
    }
  } catch (int stringLength) {
    if (stringLength == 20) { //this is not good code, i know. just an example
      cout << "Your string is too long!\n";
      cout << "(Your string is greater than 20 characters)\n";
    }
    if (stringLength == 5) { //not good code because the number should be more specific
      cout << "Your string is too short!\n";
      cout << "(Your string is shorter than 5 characters)\n";
    }
  }



  //outro i guess
  return 0; //end function
}

void mySecondFunction() {
  cout << "a second function was executed\n";
}

void functionWithParams(string stringParam, int integerParam) { //params must be specified in both places
  cout << "this function has a parameter! it is:\n";
  cout << stringParam << "\n";
  cout << integerParam << "\n";
}

void functionWithDefaultParam(string parameter) { //default param must be defined in declaration and not here
  cout << parameter << "\n";
}

string functionThatReturns() {
  cout << "this function returns a string\n";
  cout << "the variable that you used this on now has the value `i was given a value by a function and you werent so therefore im better`\n";
  return "i was given a value by a function and you werent so therefore im better";
}

int overloaded(int x, int y) {
  return x + y;
}

string overloaded(string x, string y) {
  return x + y;
}