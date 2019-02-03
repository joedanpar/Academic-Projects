/************************************************************
* CSCI 241                                       Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 7
* Due Date: 11/18/2008
* Purpose: This is the queue for the parking lot program.
************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#define SIZE 12

using std::cout;
using std::endl;

/****************************************************************************************
*  Queue class:                                                                         *
*  Variables: ar[]                 = The queue itself (an array of type T)              *
*             count                = The number of elements actually filling the array  *
*  Methods:   Queue()              = The basic constructor                              *
*             void Push(T &)       = Pushes the passed argument into the queue          *
*             T Pop()              = Takes out the first element and readjusts the queue*
*             bool IsEmpty() const = Checks to see if the queue is empty                *
*             bool IsFull() const  = Checks to see if the queue is full                 *
****************************************************************************************/
template <class T>
class Queue
  {
  private:
  T ar[SIZE];
  int count;
  
  public:
  Queue();
  void Push(T &);
  T Pop();
  bool IsEmpty() const;
  bool IsFull() const;
  };

/***********************************************************************************
*  Basic constructor:                                                              *
*  Process: initialize the counter to 0, meaning that the 12-slot queue is "empty" *
***********************************************************************************/
template <class T>
Queue<T>::Queue()
  {
  count = 0;
  }
  
/******************************************************************
*  Push Method:                                                   *
*  Process: Pushes the passed argument into rear end of the queue *
******************************************************************/
template <class T>
void Queue<T>::Push(T & input)
  {
  ar[count] = input;
  count ++;
  }
  
/*********************************************************************************************************
*  Pop Method:                                                                                           *
*  Process: Takes out the first element and readjusts the queue by moving each element forward one space *
*********************************************************************************************************/
template <class T>
T Queue<T>::Pop()
  {
  T temp;
  temp = ar[0];
  count --;
  for (int x = 0; x < count; x++)
    ar[x] = ar[x + 1];
  return temp;
  }
    
/**************************************************************************************
*  IsEmpty Method:                                                                    *
*  Process: Checks to see if the queue is empty, and returns the appropriate response *
**************************************************************************************/
template <class T>
bool Queue<T>::IsEmpty() const
  {
  if (count == 0)
    return true;
  else
    return false;
  }
  
/**************************************************************************************
*  IsFull Method:                                                                     *
*  Process: Checks to see if the queue is full, and returns the appropriate response  *
**************************************************************************************/
template <class T>
bool Queue<T>::IsFull() const
  {
  if (count == SIZE)
    return true;
  else
    return false;
  }
  
#endif
