/************************************************************
* CSCI 241                                       Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 7
* Due Date: 11/18/2008
* Purpose: Process a queue of cars to simulate an alleyway
*          parking lot.
************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue.h" 
  
using std::cout;
using std::endl;
using std::ifstream;
using std::setprecision;
using std::fixed;
using std::setw;
   
/************************************************************************
*  Automobile Structure:                                                *
*  Variables: license  = the license plate (string of 8 chars)          *
*             parktime = the time the car was parked (floating decimal) *
************************************************************************/
struct Auto
  {
  char license[10];
  float parktime;
  }; 

/* Function Prototypes */   
void park (int &, int &, Queue<Auto> &, Auto &);
void find (Queue<Auto> &, Auto &);
void claim (int &, int &, Queue<Auto> &, Auto &, float &);

int main()
  {
  /* Print header */
  cout << "Log of Transactions for Q Brothers Parking Co." << endl << endl; 
   
  /* Variables */
  Auto tempcar,
       currentcar;
  Queue<Auto> Q,
              tempQ;
  
  int totalparked = 0,
      totalclaimed = 0,
      totalerrors = 0,
      count = 0;
  float totalincome = 0;
  char option;
  
  ifstream inFile;
  inFile.open("assign7.dat");
  
  /* If the file cannot open, exit the program */
  if(inFile.fail())
    {
    cout << "Unable to open assign7.dat" << endl;
    exit(1);
    }
  
  inFile >> option;
  inFile >> currentcar.license;
  inFile >> currentcar.parktime;
  /* As long as the program has not reached the end of the file,
  check to see if the input values are valid, and  call the appropriate
  functions*/
  while(!inFile.eof())
   {
    if (currentcar.parktime >= 0 && currentcar.parktime < 24)
      {
      if (option == 'P')
        park(totalparked, totalerrors, Q, currentcar);
      else if (option == 'F')
        find(Q, currentcar);
      else if (option == 'C')
        claim(totalclaimed, totalerrors, Q, currentcar, totalincome);
      else
        {
        cout << "ERROR: invalid selection" << endl;
        totalerrors++;
        }
      }
    inFile >> option;
    inFile >> currentcar.license;
    inFile >> currentcar.parktime;
   }
  /* Print out cars remaining in alleyway */
  cout << endl << "------------- Cars Remaining -------------" << endl; 
  while (!Q.IsEmpty())
    {
    tempcar = Q.Pop();
    count ++;
    cout << "Car " << count << ": " << tempcar.license << endl;
    }
  inFile.close();
  
  /* Print out totals for the day's processing */
  cout << endl << "----------------- Totals -----------------" << endl;
  cout << "Total number of cars parked:       " << setw(3) << fixed << totalparked << endl;
  cout << "Total number of cars claimed:      " << setw(3) << fixed << totalclaimed << endl;
  cout << "Total number of errors processed:  " << setw(3) << fixed << totalerrors << endl;
  cout << "Total income earned:              $" << setprecision(2) << fixed << totalincome << endl;

  std::cin >> option;
  return 0;
 } 

/**************************************************************************************************
*  Park function:                                                                                 *
*  Arguments: ttlpark  = The total amount of cars parked (referring to an integer)                *
*             ttlerr   = The total amount of errors processed (referring to an integer)           *
*             Q        = The queue of the alleyway being processed (referring to the Queue class) *
*             curcar   = the current car being processed (referring to the Auto structure)        *
*  Process: Pop out each auto in the queue.  If the current car is already in the alley, print out*
*           an error.  If not, push the car into the last slot in the alleyway                    *
**************************************************************************************************/
void park(int & ttlprk, int & ttlerr, Queue<Auto> & Q, Auto & curcar)
  {
  Auto tempauto;
  Queue<Auto> temp;
  if(!Q.IsFull())
    {
    while (!Q.IsEmpty())
      {
      tempauto = Q.Pop();
      temp.Push(tempauto);
      if (strcmp(tempauto.license, curcar.license) == 0)
        {
        cout << "ERROR: License " << curcar.license << " is already in the alley" << endl;
        ttlerr++;
        while (!temp.IsEmpty())
          {
          tempauto = temp.Pop();
          Q.Push(tempauto);
          }
          //Q.Push(temp.Pop());
          return;
        }
      }
  while (!temp.IsEmpty())
    {
    tempauto = temp.Pop();
    Q.Push(tempauto);
    }
    //Q.Push(temp.Pop());
  Q.Push(curcar);
  cout << "License " << curcar.license << " was successfully parked at " << curcar.parktime << "." << endl;
  ttlprk++;
    }
  else
    cout << "ERROR: alley is already full" << endl;
  //ttlerr++;
  }

/**************************************************************************************************
*  Find function:                                                                                 *
*  Arguments: Q        = The queue of the alleyway being processed (referring to the Queue class) *
*             curcar   = the current car being processed (referring to the Auto structure)        *
*  Process: Pop out each auto in the queue.  If the current car is already in the alley, print out*
*           a confirmation message.  If not, print out that it has not been found.                *
**************************************************************************************************/
void find (Queue<Auto> & Q, Auto & curcar)
  {
  //cout << "FIND" << endl;
  Auto tempauto;
  Queue<Auto> temp;
  while (!Q.IsEmpty())
    {
    tempauto = Q.Pop();
    temp.Push(tempauto);
    if (strcmp(tempauto.license, curcar.license) == 0)
      {
      cout << "License " << curcar.license << " has been found" << endl;
      while (!temp.IsEmpty())
        {
        tempauto = temp.Pop();
        Q.Push(tempauto);
        }
        //Q.Push(temp.Pop());
      return;
      }
    }
  while (!temp.IsEmpty())
    {
    tempauto = temp.Pop();
    Q.Push(tempauto);
    }
    //Q.Push(temp.Pop());
  cout << "ERROR: License " << curcar.license << " has not been found" << endl;
  }

/***************************************************************************************************
*  Claim function:                                                                                 *
*  Arguments: ttlclm   = The total amount of cars claimed (referring to an integer)                *
*             ttlerr   = The total amount of errors processed (referring to an integer)            *
*             Q        = The queue of the alleyway being processed (referring to the Queue class)  *
*             curcar   = The current car being processed (referring to the Auto structure)         *
*             ttlchrg  = The total amount charged to the customers so far (referring to an integer)*
*  Process: Pop out each auto in the queue.  If the current car is already in the alley, calculate *
*           the amount to be charged.  If the times are incorrect, print out an error.  if the car *
*           could not be found at all, print out an error message.                                 *
***************************************************************************************************/
void claim (int & ttlclm, int & ttlerr, Queue<Auto> & Q, Auto & curcar, float & ttlchrg)
  {
  //cout << "CLAIM" << endl;
  Auto tempauto;
  Queue<Auto> temp;
  while (!Q.IsEmpty())
    {
    tempauto = Q.Pop();
    if (strcmp(tempauto.license, curcar.license) == 0)
      {
      //cout << curcar.license << endl;
      if (tempauto.parktime < curcar.parktime)
        {
        ttlchrg += ((curcar.parktime - tempauto.parktime) * 8);
        
        cout << "License " << curcar.license << " was successfully claimed at " << curcar.parktime << " for "
             << ((curcar.parktime - tempauto.parktime) * 8) << " dollars." << endl;
        ttlclm++;
        }
      else
        {
        temp.Push(tempauto);
        ttlerr++;
        cout << "ERROR: Car does not exist at time of claim" << endl;
        }
      while (!temp.IsEmpty())
        {
        tempauto = temp.Pop();
        Q.Push(tempauto);
        }
        //Q.Push(temp.Pop());
        return;
      }
    temp.Push(tempauto);
    }
  while (!temp.IsEmpty())
    {
    tempauto = temp.Pop();
    Q.Push(tempauto);
    }
    //Q.Push(temp.Pop());
  //Q.Push(curcar);
  cout << "ERROR: License " << curcar.license << " could not be found in alley." << endl;
  ttlerr++;
  }
