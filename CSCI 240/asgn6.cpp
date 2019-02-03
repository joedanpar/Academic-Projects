/******************************************************************************
CSCI 240 - Program 6 - Spring 2008

Name: Joe Dan Parker
Z-Number: 158012
Section: 8
TA: Kalpana Mangalarapu

Purpose: Create a program that will count each of the characters and present
		 a total of each, along with a total payment amount (in dollars and
		 cents).
******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;
	
// I initialized these variables outside of any function, so that they are available to the entire program, not just within any one scope.
int upperTotal,
    lowerTotal,
	punctTotal,
	digitTotal,
	errorTotal;
	
double payment;

char prevChar;  //used in finding out whether or not there are more than 1 capital letters or punctuation marks in a row.

/* Function Prototypes */

int isDigit( char );

int isUpper( char );

int isLower( char );

int isPunct(char );

double calctotal( int, int, int, int, int );

int main()
  {
  char ch; 
  
  cout << "**** Welcome to Purple Prose Press payment calculator!***" << endl << endl
       << "Enter characters, ! at beginning of line to quit" << endl << endl;
  
  cin.get( ch );

  while ( ch != '!' )
    {

    while ( ch != '\n' )       // 10 or '\n' is the ASCII code for newline
      {
      upperTotal += isUpper( ch );
	  
	  lowerTotal += isLower( ch );
	  
	  digitTotal += isDigit( ch );
	  
	  punctTotal += isPunct( ch );
	  
	  cout << ch;
	  
	  cin.get( ch );
	  
	  if (ch == '!' )
	    break;
      }
	if (ch == '\n' )
	  {
	  cout << endl;
	  cin.get( ch );
	  }
    }
  payment = calctotal( upperTotal, lowerTotal, digitTotal, punctTotal, errorTotal );
  
  cout << endl << endl
       << "You Typed " << ( upperTotal + lowerTotal + digitTotal + punctTotal ) << " characters." << endl << endl
	   << "Legal punctuation marks" << setw(7) << fixed << punctTotal << endl
	   << "Upper case letters" << setw(12) << fixed << upperTotal << endl
	   << "Lower case letters" << setw(12) << fixed << lowerTotal << endl
	   << "Digits" << setw(24) << fixed << digitTotal << endl
	   << "Total errors" << setw(18) << fixed << errorTotal << endl << endl
	   << "Total payment           $" << setprecision(2) << fixed << payment;
  }

/**********  Code your Functions below this line  **********/

int isDigit( char ch )
  {
  if ( ch >= 48 && ch <= 57 )
    {
	digitTotal ++;
	
	prevChar = ch;
	
	return 1;
	}
  else
  return 0;
  }

// If the previous character is within the same bounds as the current one, (an upper case letter) then the error counter will go up.
int isUpper( char ch )
  {
  int errorCount = 0; //the counter for the number of copies in order to cause it to be an error, which is at least 2 in a row.
  
  if ( ch >= 65 && ch <= 90 )
    {
	upperTotal ++;
	
	if ( prevChar >= 65 && prevChar <= 90 )
	  {
	  errorCount++;
	  if ( errorCount >= 1 )
	    {
		errorTotal ++;
		errorCount = 0;
		}
	  }
	  
	prevChar = ch;
	
	return 1;
	}
  else
  return 0;
  }
  
int isLower( char ch )
  {
  if ( ch >= 97 && ch <= 121 )
    {
	lowerTotal ++;
	
	prevChar = ch;
	
	return 1;
	}
  else
  return 0;
  }
  
int isPunct(char ch )
 {
  int errorCount = 0; //the counter for the number of copies in order to cause it to be an error, which is at least 3 in a row.
  
  if ( ( ch >= 34 && ch <= 47 ) || ( ch >= 58 && ch <= 64 ) || ( ch >= 91 && ch <= 96 ) || ( ch >= 123 && ch <= ch <= 126 ) )
    {
	punctTotal ++;

// If the previous character is within the same bounds as the current one, (a punctuation mark of some sort) then the error counter will go up.	   
	if ( ( prevChar >= 34 && prevChar <= 47 ) || ( prevChar >= 58 && prevChar <= 64 ) || ( prevChar >= 91 && prevChar <= 96 ) || ( ch >= 123 && ch <= ch <= 126 ) )
	  {
	  errorCount++;
	  if ( errorCount >= 2 )
	    {
		errorTotal ++;
		errorCount = 0;
		}
	  }
	  
	prevChar = ch;
	
	return 1;
	}
  else
  return 0;
  }
  
double calctotal( int upperTotal, int lowerTotal, int digitTotal, int punctTotal, int errorTotal )
  {
  payment = (( 0.05 * digitTotal ) + ( 0.07 * lowerTotal ) + ( 0.10 * upperTotal ) + ( 0.12 * punctTotal )) - ( 0.10 * errorTotal );

  return payment;
  }

