/******************************************************************************
CSCI 240 - Program 5 - Spring 2008

Name: Joe Dan Parker
Z-Number: 158012
Section: 8
TA: Kalpana Mangalarapu

Purpose: Create an interactive menu-driven program that will perform various
         calculations and operations. A menu of calculation types will be
		 shown to a user at the beginning of the program (and again after
		 each calculation).
******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;
	

/* Function Prototypes */

string Menu();

int getValue( string, int, int );

void doAverage();
double calcAverage( int, int );

void doFactorial();
int calcFactorial( int );

void doMtoNth();
int calcMtoNth( int, int );

void doRange();
int calcRange( int, int, int, int );

int main()
  {
  string userChoice,
         prompt;
  int	 value,
	  	 lowerBound,
	     upperbound;
  
  cout << "Special Purpose Calculator" << endl << endl
       << "1) Average" << endl
	   << "2) Factorial" << endl
	   << "3) M to the Nth Power" << endl
	   << "4) Range" << endl << endl
	   << "Q) Quit" << endl << endl;
  	   	     
  userChoice = Menu();
  
  while ( userChoice != "Q" && userChoice != "q" )
    {
    if ( userChoice == "1" )
      {
      doAverage();
      }
    else if ( userChoice == "2" )
      {
      doFactorial();
      }
    else if ( userChoice == "3" )
      {
      doMtoNth();
      }
    else //option "4" was selected
      {
      doRange();
      }
 
    cout << "Special Purpose Calculator" << endl << endl
         << "1) Average" << endl
  	     << "2) Factorial" << endl
  	     << "3) M to the Nth Power" << endl
  	     << "4) Range" << endl << endl
  	     << "Q) Quit" << endl << endl;
	   
    userChoice = Menu();
    }//end of the while loop

//  system("pause");     //un-comment this line if you are using Dev
  return 0;
  }

/**********  Code your Functions below this line  **********/

// This funciton takes a "string" of either 1, 2, 3, 4, or Q/q from the user, if it is not any of those,
// the user has to re-enter their choice.

string Menu()
  {
  string temp_string;
    cout << "Enter your choice: ";
    cin >> temp_string;
  
// Check to see if the entered string is not any of these, if the loop doesn't apply, return the entered string.

  while ( temp_string != "1" && temp_string != "2"  && temp_string != "3" && temp_string != "4" & temp_string != "Q" && temp_string != "q" )
    {
	cout << "ERROR: " << temp_string << "is invalid.  Try again: ";
	cin >> temp_string;
	}
	 
  return temp_string;
  }
  
// This funciton takes an integer from the user and checks to see if it is within the specified boundaries.
// The function then returns the value to the calling function.

int getValue( string prompt, int lowerBound, int upperBound )
  {
  int temp_integer;
  
  do
    {
    cout << prompt << "between " << lowerBound << " and " << upperBound << ": ";
    cin >> temp_integer;
	}
  while (temp_integer <= lowerBound && temp_integer >= upperBound );
  
  return temp_integer;
  }

// This funciton takes two integers from the function "getValue" and passes them onto the calculation function.
// One integer is a sum of numbers, and the other is the total amount of numbers being averaged.

void doAverage()
  {
  int sum,
      count;
  
  sum = getValue( "Enter the sum the numbers being averaged ", -1000, 1000 );
  
  count = getValue( "Enter the amount of numbers being averaged ", 1, 1000 );
  
  cout << endl << "The average of the numbers given is: " << setprecision(3) << fixed << calcAverage ( sum, count ) <<endl << endl;
  }
  
// This funciton takes the integers given from the previous function and calculates an average from them.

double calcAverage( int sum, int count )
  {
  double temp_double;
  
  temp_double = (double) sum / (double) count;
  
  return temp_double;
  }
  
// This funciton takes an integer from the function "getValue" and passes them onto the calculation function.

void doFactorial()
  {
  int number;
  
  number = getValue( "Please enter a number between ", 0, 10 );
  
  cout << "The factorial of the number entered is: " << calcFactorial( number ) << endl << endl;
  }
  
// This funciton takes the integer from the previous function and calculates its factorial.

int calcFactorial( int number )
  {
  int temp_integer,
      factorial = number;

// Since "Factorial" was set to the first number in the series, the counter is set to one number below,
// and it is then counted down, until it reaches 1.  Each time the loops counts, it multiplies "Factorial"
// by the counter, creating the entered number's factorial.
  
  for ( temp_integer = number - 1; temp_integer >0; temp_integer -- )
    {
	factorial *= temp_integer;
	}
  return factorial;
  }

// This funciton takes two integers from the function "getValue" and passes them onto the calculation function.

void doMtoNth()
  {
  int M,
      N;
  
  M = getValue( "Please enter a number for the base of an exponent: ", 1, 10 );
  
  N = getValue( "Please enter a number for the exponent itself: ", 1, 8 );
  
  cout << M << "raised to the " << N << "th power equals: " << calcMtoNth( M, N ) << endl << endl;
  }

// This funciton takes the integers from the previous function, and calculates the exponential expression.
  
int calcMtoNth( int M, int N )
  {
  int temp_integer,
      exponent = M;

// Since "exponent" was set to the first the entered number already, the counter is set to one number below,
// and it is then counted up, until it reaches the exponent entered.  Each time the loops counts,
// it multiplies "exponent" by the counter, creating the entered number's exponential answer.
  
  for ( temp_integer = M - 1; temp_integer < N; temp_integer ++ )
    {
	exponent *= M;
	}
	
  return exponent;
  }

// This funciton takes four integers from the function "getValue" and passes them onto the calculation function.

void doRange()
  {
  int    number1,
	 	 number2,
    	 number3,
	  	 number4;
  
  number1 = getValue ( "Please enter a number ", 0, 1000 );
  
  number2 = getValue ( "Please enter a number ", 0, 1000 );
  
  number3 = getValue ( "Please enter a number ", 0, 1000);
  
  number4 = getValue ( "Please enter a number ", 0, 1000);
  
  cout << "The range of the numbers entered is: " << calcRange( number1, number2, number3, number4 ) << endl << endl;
  }

// This funciton calculates the four.integers from the previous function's range.

int calcRange( int number1, int number2, int number3, int number4 )
  {
  int highest,
      lowest,
	  range;

// Check to see which number is the largest of the four
	  
  if ( number1 > number2 && number1 > number3 && number1 > number4 )
    {
	highest = number1;
	}
  else if ( number2 > number1 && number2 > number3 && number2 > number4 )
    {
	highest = number2;
	}
  else if ( number3 > number1 && number3 > number2 && number3 > number4 )
    {
	highest = number3;
	}	   
  else if ( number4 > number1 && number4 > number3 && number4 > number2 )
    {
	highest = number4;
	}

// Check to see which number is the smallest of the four

  if ( number1 < number2 && number1 < number3 && number1 < number4 )
    {
	lowest = number1;
	}
  else if ( number2 < number1 && number2 < number3 && number2 < number4 )
    {
	lowest = number2;
	}
  else if ( number3 < number1 && number3 < number2 && number3 < number4 )
    {
	lowest = number3;
	}	   
  else if ( number4 < number1 && number4 < number3 && number4 < number2 )
    {
	lowest = number4;
	}
  range = highest - lowest;
  
  return range;
  }

