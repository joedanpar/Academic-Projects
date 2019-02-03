/******************************************************************************
CSCI 240 - Program 7 - Spring 2008

Name: Joe Dan Parker
Z-Number: 158012
Section: 8
TA: Kalpana Mangalarapu

Purpose: Create a program that will analyze three types of household utility
         expenses (gas, electricity and water) over 12 months.
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
	
// I initialized these variables outside of any function, so that they are available to the entire program, not just within any one scope.
const int NUM_MON = 12;

string caption;

int size;

//I used an array size of 13 so I can start January on element one, not zero.	 
double gas[13],
	   electricity[13],
	   water[13],
	   sums[13],
	   array[13];
	   
/* Function Prototypes */

void buildArrays( double[], double[], double[] );

void printUtilityStat( string, double[], int );

void getSumArray( double[], double[], double[], double[] );

void printArray( string, double[], int );

double mean( double[], int );

double sum( double[], int );

double low( double[], int );

double high( double[], int );

void sortArray( double[], int );

int main()
  {
  int i;
  
  buildArrays( gas, electricity, water );
  
  printUtilityStat( "*** Gas ***", gas, NUM_MON);
  
  printUtilityStat( "*** Electricity ***", electricity, NUM_MON);
  
  printUtilityStat( "*** Water ***", water, NUM_MON);
  
  getSumArray( gas, electricity, water, sums );
  
  sortArray( sums, NUM_MON );
  
  cout << "The highest monthly expense is $" << high( sums, NUM_MON ) << "." << endl << endl;
  
  cout << "The lowest monthly expense is $" << low( sums, NUM_MON ) << "." << endl << endl;
  
  cout << "The average monthly expense is $" << mean( sums, NUM_MON ) << "." << endl << endl;
  
  }

/**********  Code your Functions below this line  **********/

void buildArrays( double gas[], double electricity[], double water[] )
  {
  ifstream inFile;
  
  string temp_string;
  
  char x[4], //gas's string variable
       y[12],//electric's string variable
	   z[6]; //water's strig variable
  
  int i;
  
  inFile.open("expenses.txt");
  if (inFile.fail())
    {
    cout << "Unable to open expenses.txt file\n";
    exit(1);
    }
	
  inFile.getline(x, 4);
  
  for ( i = 1; i <= NUM_MON; i++ )
    {
	inFile >> gas[i];
	}
	
  inFile >> temp_string;
  
  inFile.getline(y, 12);
  
  for ( i = 1; i <= NUM_MON; i++ )
    {
	inFile >> electricity[i];
	}
  inFile >> temp_string;
  
  inFile.getline(z, 6);
  
  for ( i = 1; i <= NUM_MON; i++ )
    {
	inFile >> water[i];
	}
	 
  inFile.close();
  }

void printUtilityStat( string caption, double array[], int size )
  {
  cout << caption << endl << endl;
  cout << "sum over 12 months: $" << sum( array, size ) << endl;
  cout << "average: $" << mean( array, size ) << endl;
  cout << "highest cost: $" << high( array, size ) << endl;
  cout << "lowest cost: $" << low( array, size ) << endl << endl;
  }
  
double sum( double array[], int size )
  {
  int i;
  
  double temp_double = 0;

  for ( i = 1; i <= size; i ++ )
    {
    temp_double += array[i];
	}
  return temp_double;
  }

double mean( double array[], int size )
  {
  int i;
  
  double temp_double = 0;
  
  for ( i = 1; i <= size; i ++ )
    {
    temp_double += array[i];
	}
  return temp_double / size;
  }

double high( double array[], int size )
  {
  int i,
      j = 1;
  
  double temp_double = 0;
  
  for ( i = 1; i <= size; i ++ )
    {
    if (array[j] < array[i])
	  {
	  array[j] = array[i];
	  }
	}
  return array[j];
  }

double low( double array[], int size )
  {
  int i,
      j = 1;
  
  double temp_double = 0;
  
  for ( i = 1; i <= size; i ++ )
    {
    if (array[j] > array[i])
	  {
	  array[j] = array[i];
	  }
	}
  return array[j];
  }

void getSumArray( double gas[], double electricity[], double water[], double sums[] )
  {
  int i;
  
  for ( i = 1; i <= NUM_MON; i ++ )
    {
	sums[i] = ( gas[i] + electricity[i] + water[i] );
	}
  printArray( "*** Monthly Totals ***", sums, 12);
  }
  
void printArray( string caption, double array[], int size )
  {
  int i;
  
  cout << caption << endl << endl;
  for (i = 1; i <= size; i ++ )
    {
    cout << array[i] << endl;
	}
  cout << endl;
  }

void sortArray(double array[], int size)
  {
  int i, j;
  int min;
  double temp;

  for (i = 0; i <= size; i++)
  {
    min = i;
    for (j = i+1; j <= size; j++)
    {
      if (array[j] < array[min])
        min = j;
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
    }
	printArray( "*** Sorted Monthly Totals ***", sums, 12);
  }

