/******************************************************************************
CSCI 240 - Program 5 - Spring 2008

Name:
Z-Number:
Section:
TA:

Purpose:
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
  string userChoice;
  
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

    userChoice = Menu();
    }//end of the while loop

//  system("pause");     //un-comment this line if you are using Dev
  return 0;
  }

/**********  Code your Functions below this line  **********/

