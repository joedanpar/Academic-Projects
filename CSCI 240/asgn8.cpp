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
string caption;

int numScores;

double mean;
int median;
int hi;
int lo;
	
int ar[200];

/* Function Prototypes */

int buildArray( int[] );

void showArray( string, int[], int );

void sortArray( int[], int );

void doStatsRef( int[], int, double&, int&, int&, int& );

void meanAndMedianRef( int[], int, double&, int& );

void hiAndLoRef( int[], int, int&, int& );

double calcAverage( int[], int );

int calcMedian( int[], int );

int calcLo( int[], int );

int calcHi( int[], int);

void getScores(int[], int, int[]);

int main()
  {
  int counts[6] = {0,0,0,0,0};
  
  numScores = buildArray( ar );
  
  showArray( "*** Scores ***", ar, numScores );
  
  doStatsRef( ar, numScores, mean, median, hi, lo );
  
  getScores( ar, numScores, counts );
  
  cout << "Mean = " << mean << endl;
  cout << "Median = " << median << endl;
  cout << "Highest Score = " << hi << endl;
  cout << "Lowest Score = " << lo << endl;
  cout << endl;
  cout << "Number of A's = " << counts[0] << endl;
  cout << "Number of B's = " << counts[1] << endl;
  cout << "Number of C's = " << counts[2] << endl;
  cout << "Number of D's = " << counts[3] << endl;
  cout << "Number of E's = " << counts[4] << endl;
  cout << "Number of F's = " << counts[5] << endl;
  }

/**********  Code your Functions below this line  **********/

int buildArray( int ar[] )
  {
  ifstream inFile;
  
  int i = 0,
  	  num;
  
  inFile.open("scores.txt");
  if (inFile.fail())
    {
    cout << "Unable to open scores.txt file\n";
    exit(1);
    }
  inFile >> num;
   
  while ( inFile )
    {
	ar[i] = num;
	i++;
	inFile >> num;
	}
	
  inFile.close();
  return i;
  }

void showArray( string caption, int ar[], int numScores )
  {
  int temp_int = 0,
  	  i;
  
  cout << caption << endl << endl;
  
  while ( temp_int < numScores )
    {
	for (i = 1; i <= 8; i++ )
      {
	  if ( ar[temp_int] != 0 )
	  {
	  cout << ar[temp_int] << ' ';
	  temp_int ++;
	  }
	  }
	  cout << endl;
	}
  cout << endl << temp_int + 1 << " Scores" << endl << endl;
  }

void sortArray(int ar[], int numScores)
  {
  int i, j;
  int max;
  int temp;

  for (i = 0; i <= numScores; i++)
  {
    max = i;
    for (j = i+1; j <= numScores; j++)
    {
      if (ar[j] > ar[max])
        max = j;
    }
    temp = ar[i];
    ar[i] = ar[max];
    ar[max] = temp;
    }
  }
  
void doStatsRef( int ar[], int numScores, double & mean, int & median, int & hi, int & lo )
  {
  int sortedAr[200],
  i;
  
  for (i = 0; i <= 200; i++)
    {
	sortedAr[i] = ar[i];
	}
  sortArray( sortedAr, numScores );
  
  meanAndMedianRef( sortedAr, numScores, mean, median );
  
  hiAndLoRef( sortedAr, numScores, hi, lo );
  }
  
void meanAndMedianRef( int sortedAr[], int numScores, double & mean, int & median )
  {
  mean = calcAverage(sortedAr, numScores);
  
  median = calcMedian(sortedAr, numScores);  
  }
  
void hiAndLoRef( int sortedAr[], int numScores, int& hi, int& lo )
  {
  hi = calcHi( sortedAr, numScores );
  
  lo = calcLo( sortedAr, numScores );
  }
  
double calcAverage( int sortedAr[], int numScores )
  {
  int i;
  
  int temp_int = 0;
  
  for ( i = 1; i <= numScores; i ++ )
    {
    temp_int += sortedAr[i];
	}
	return ((double) temp_int / (double) numScores);
  }
  
int calcMedian( int sortedAr[], int numScores )
  {
  return sortedAr[(( numScores / 2 ) + 1)];
  }

int calcHi( int ar[], int numScores )
  {
  int i,
      j = 1;
  
  int temp_int = 0;
  
  for ( i = 0; i <= numScores; i ++ )
    {
    if (ar[j] < ar[i])
	  {
	  ar[j] = ar[i];
	  }
	}
  return ar[j];
  }

int calcLo( int ar[], int numScores )
  {
  int i,
      j = 1;
  
  double temp_int = 0;
  
  for ( i = 0; i <= numScores; i ++ )
    {
    if (ar[j] > ar[i])
	  {
	  ar[j] = ar[i];
	  }
	}
  return ar[j];
  }  

void getScores ( int sortedAr[], int numScores, int counts[] )
  {
  int i;
  for (i = 0; i <= numScores; i++)
    {
	if ( sortedAr[i] >= 90 )
	  {
	  counts[0]++;
	  }
	  else if ( sortedAr[i] < 90 && sortedAr[i] >= 80 )
	    {
		counts[1]++;
		}
		else if ( sortedAr[i] < 80 && sortedAr[i] >= 70 )
	      {
	  	  counts[2]++;
	  	  }
		  else if ( sortedAr[i] < 70 && sortedAr[i] >= 60 )
	        {
	    	counts[3]++;
	    	}
		    else if ( sortedAr[i] < 60 && sortedAr[i] >= 50 )
	          {
	      	  counts[4]++;
	      	  }
		      if ( sortedAr[i] < 50 )
	            {
	            counts[5]++;
	            }
    }
  }

