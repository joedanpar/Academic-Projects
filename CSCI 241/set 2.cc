/************************************************************
* CSCI 241                                       Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 5
* Due Date: 10/23/2008
* Purpose: Develop a class to represent finite sets of
           integers.
************************************************************/
#include "set.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::ostream;

class Set
{
  public:
  Set();
  Set(const & Set);
  ~Set();
  
  friend Set operator ^ (const & Set, const & Set);
  friend ostream & operator << (ostream &, const & Set);
  Set operator = (const & Set);
  bool operator == (const & Set) const;
  bool operator < (const & Set) const;
  Set operator + (const & Set) const;
  Set operator + (const & int);
  Set operator - (const & Set) const;
  Set operator - (const & int);
  int & operator [] (const int &);
  int operator [] (const int &) const;
  bool IsIn();
  bool IsEmpty();
  int Size(); 
  
  private:
  int size;
  int * ptr;
};

Set::Set()
  {
  size = 0;
  ptr = 0;
  }
  
Set::Set(const & Set OldSet)
  {
  size = OldSet.size;
  ptr = new int[size];
  for (i = 0; i < size; i ++)
    {
    ptr[i] = OldSet.ptr[i];
    }
  }
  
Set::~Set()
  {
  delete ptr;
  ptr = NULL;
  }

Set operator ^ (const & Set set1, const & Set set2)
  {
  Set NewSet;
  for (i = 0; i < set1.size; i ++)
    {
    for (j = 0; j < set2.size; j ++)
      {
      if (set1.ptr[i] == set2.ptr[j])
        NewSet = NewSet + set1.ptr[i];
      }
    }
  return NewSet;
  }

ostream & operator << (ostream &, const & Set set1)
  {
  if(set1.Size()!=0) 
    { 
    cout << "{"; 
    for(int i = 0; i < s.Size(); i++) 
      { 
      cout << s[i] << " "; 
      } 
    cout << "}"; 
    }
  else
    cout << "Set is empty";
  }

Set Set::operator = (const & Set set1)
  {
  if (this != & set1)
    {
    delete ptr;
    size = set1.size;
    ptr = new int[size];
    for (i = 0; i < size; i++)
      { 
      ptr[i] = set1.ptr[i];
      }
  return *this;
  }

bool Set::operator == (const & Set set1) const
  {
  for( i = 0; i < this.Size(); i++) 
    {
    if(!this.IsIn(set1.ptr+i)) 
        return false;
    }
  return true; 
  }

bool Set::operator < (const & Set set1) const
  {
  for(int i = 0; i < this.Size(); i++) 
    { 
    if(!s.IsIn(this[i])) 
      return false; 
    } 
  return true;
  }

const Set & Set::operator + (const Set & set1)
  {
  Set temp;
  int count1,
      count2;
  for (i = 0; i < set1.size; i ++)
    {
    temp.ptr[count1] = ptr[count1];
    count1 = i;
    }
  for (j = 0; j < set2.size; j ++)
    {
    temp.ptr[count1 + count2] = set1.ptr[j];
    count2 = j;
    }
  return temp;
  }

Set Set::Set operator + (const & int x)
  {
  Set temp;
  int tmpcnt = 1;
  temp.size = this.Size()+1;
  for(int i = 0; i < this.Size(); i++)
    {
    temp.pointer+tmpcnt = this[i];
    tempcount++;
    }
  temp.ptr = x;
  return temp;
  }

const Set Set::Set operator - (const & Set set1)
  {
  Set temp;
  int counter = 0;
  
  for (i = 0; i < size; i ++)
    {
    for (j = 0; j < set1.size; j ++)
      {
      if (ptr[i] != set1.ptr[j])
        {
        temp.ptr[counter] = ptr[i];
        counter ++;
        }
      }
    }
  return temp;
  }

Set Set::Set operator - (const & Set set1, const & int x)
  {
  Set temp;
  int counter = 0;
  
  for (i = 0; i < set1.size; i ++)
    {
    if (set1.ptr[i] != x)
      {
      temp.ptr[counter] = x;
      counter ++;
      }
    }
  return temp;
  }

int & Set::operator [] (const int & x)
  {
  return ptr[x];
  }

int Set::operator [] (const int & x) const
  {
  return ptr[x];
  }

bool Set::IsIn(int x)
  {
  for (i = 0; i < this.size; i++)
    {
    if (this.ptr == x)
      return true;
    }
  return false;
  }

bool Set::IsEmpty()
  {
  if(this.Size())
    {
    return false;
    }
  return true;
  }

int Set::Size()
  {
  int i = 0;
  while(this.ptr != NULL)
    {
    i ++;
    }
  return i;
  }
