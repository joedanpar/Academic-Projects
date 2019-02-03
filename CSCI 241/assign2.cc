/************************************************************
* CSCI 241                                       Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 2
* Due Date: 09/23/2008
* Purpose: Take information about a number of customers from
           a data file, find and display those whom have a
           phone number with a specified prefix, sort them
           all ascending by their phone numbers, and then
           descending by their balance.
************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

/* Namespaces used */
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::ifstream;

/* The Subscriber Structure */	
struct Subscriber
  {
  char     initial1,
           initial2;
  int      phonenumber,
           year,
           month,
           day;
  double   balance;
  };
  
/* Global Variables */
Subscriber ar[30];
  
/* Function Prototypes */
int FillArray(Subscriber []);
int GetPrefix(int);
void PrintPrefix(Subscriber [], int, int);
void SortByTelephone(Subscriber [], int);
void SortByBalance(Subscriber [], int);
void PrintArray(Subscriber [], int);

/* Main Function */
int main()
  {
  int num,
      test;
  num = FillArray( ar );
  PrintPrefix(ar, num, 758);
  SortByTelephone(ar, num);
  cout << "                      Hot Stuff Subscribers\n\n                    In order by telephone number"
       << "\n\n   Initials    Telephone            Renewal Date              Balance\n";
  PrintArray(ar, num);
  
  SortByBalance(ar, num);
  cout << "                      Hot Stuff Subscribers\n\n                    In order by account balance"
       << "\n\n   Initials    Telephone            Renewal Date              Balance\n";
  PrintArray(ar, num);
  
  cin >> test;
  return 0;
  }

/* Other Functions */

/* This Function takes the subscriber array, and using the data file given, will go through each
   element of the file and insert it into their respective variables within each structure of the array */
int FillArray( Subscriber ar[] )
  {
  ifstream inFile;
  
  int i = 0;
  char temp;
  
  inFile.open("hw2.dat");
  if (inFile.fail())
    {
    cout << "Unable to open hw2.dat file\n";
    exit(1);
    }
   
  while ( inFile )
    {
	inFile >> ar[i].initial1;
    inFile >> ar[i].initial2;
    inFile >> ar[i].phonenumber;
    inFile >> ar[i].year;
    inFile >> ar[i].month;
    inFile >> ar[i].day;
    inFile >> ar[i].balance;
    inFile.get(temp);
	i++;
	}
	
  inFile.close();
  return i-1;
  }

/* This function takes the phone number passed to it, and by dividing the integer by 10,000, the
   remainder of the phone number is removed, leaving the first three digits of the phone number,
   or rather, the phone number's prefix */
int GetPrefix( int X )
  {
  return (X / 10000);
  }

/* This function takes the array of subscriber structures, the max amount of subscribers within the
   array, and a desired prefix.  It then goes through each element in the array's phone number variable,
   gets its prefix, and compares it to the desired variable.  If they match, the function displays the
   contents of that element of the array. */
void PrintPrefix(Subscriber ar[], int i, int prefix)
  {
  int X = 0;
  
  cout << "                      Hot Stuff Subscribers\n\n                     With telephone prefix "
       << prefix << "\n\n   Initials    Telephone            Renewal Date              Balance\n";

  for ( X = 0; X < i; X++)
    {
    if (GetPrefix(ar[X].phonenumber) == prefix)
      {
      cout << "    " << ar[X].initial1 << "    " << ar[X].initial2 << "      " << ar[X].phonenumber << "              "
           << setw(2) << ar[X].month << "/" << setw(2) << ar[X].day << "/" << ar[X].year << "              $"
           << setprecision(2) << fixed << setw(6) << ar[X].balance << endl;
      }
    }
  
  cout << endl << endl;
  }

/* This function takes the subscriber array, and the maximum amount of elements in the array.  It then
   compares each element's phone number variable against the rest of the array's elements to sort each
   susbcriber in the array from smallest phone number to largest. */
void SortByTelephone(Subscriber ar[], int num)
  {
  int i, j;
  int max;
  Subscriber temp;

  for (i = 0; i < num; i++)
    {
    max = i;
    for (j = i+1; j < num; j++)
      {
      if (ar[j].phonenumber < ar[max].phonenumber)
        max = j;
      }
    temp = ar[i];
    ar[i] = ar[max];
    ar[max] = temp;
    }
  }
/* This function takes the subscriber array, and the maximum amount of elements in the array.  It then
   compares each element's balance variable against the rest of the array's elements to sort each susbcriber
   in the array from largest balance to smallest. */
void SortByBalance(Subscriber [], int num)
  {
  int i, j;
  int min;
  Subscriber temp;

  for (i = 0; i < num; i++)
    {
    min = i;
    for (j = i+1; j < num; j++)
      {
      if (ar[j].balance > ar[min].balance)
        min = j;
      }
    temp = ar[i];
    ar[i] = ar[min];
    ar[min] = temp;
    }
  }

/* This function takes the subscriber array, and the maximum amount of elements in the array.  It then prints
   each of the array's elements in a specific format, in order from start to finish. */
void PrintArray(Subscriber ar[], int i)
  {
  int X = 0;
  
  for ( X = 0; X < i; X++)
    {
    cout << "    " << ar[X].initial1 << "    " << ar[X].initial2 << "      " << ar[X].phonenumber << "              "
         << setw(2) << ar[X].month << "/" << setw(2) << ar[X].day << "/" << ar[X].year << "              $"
         << setprecision(2) << fixed << setw(6) << ar[X].balance << endl;
    }
  cout << endl;
  }
