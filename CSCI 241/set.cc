/************************************************************
* CSCI 241																			 Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 5
* Due Date: 10/23/2008
* Purpose: Develop a class to represent finite sets of
					 integers.
************************************************************/

#include <iostream>
#include "set.h"

using std::ostream;

Set::Set()
	{
	size = 0;
	ptr = 0;
	}
	
Set::Set(const Set & OldSet)
	{
	size = OldSet.size;
	ptr = new int[size];
	for (int i = 0; i < size; i ++)
		{
		ptr[i] = OldSet.ptr[i];
		}
	}
	
Set::~Set()
	{
	delete [] ptr;
	ptr = NULL;
	}

Set operator ^ (const Set & set1, const Set & set2)
	{
	Set NewSet;
	for (int i = 0; i < set1.size; i ++)
		{
		for (int j = 0; j < set2.size; j ++)
			{
			if (set1.ptr[i] == set2[j])
				NewSet = NewSet + set1.ptr[i];
			}
		}
	return NewSet;
	}

ostream & operator << (ostream & cout, const Set & set1)
	{
	if(set1.size != 0) 
		{ 
		cout << "{ "; 
		for(int i = 0; i < set1.size; i++) 
			{ 
			cout << set1.ptr[i] << " "; 
			} 
		cout << "}"; 
		}
	else
		cout << "{ }";
	return cout;
	}

Set & Set::operator = (const Set & set1)
	{
	if (this != & set1)
		{
		delete [] ptr;
		size = set1.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++)
			{ 
			ptr[i] = set1.ptr[i];
			}
		}
	return *this;
	}

bool Set::operator == (const Set & set1) const
	{
	 if(& set1 < this && size == set1.size)
	 return true;
	else
	 return false;
	}

bool Set::operator < (const Set set1) const 
	{
	for(int i = 0; i < size; i++)
		{
		if(!set1.IsIn(ptr[i]))
			return false;
		}
	return true;
	}

const Set & Set::operator + (const Set & set1)
	{
	static Set temp;
	int i,
			j;
	for (i = 0; i < size; i ++)
		{
		temp = temp + ptr[i];
		}
	for (j = 0; j < set1.size; j ++)
		{
		temp = temp + set1.ptr[j];
		}
	return temp;
	}

Set Set::operator + (const int & x)
	{
									
	int * temp;
	
	size++;
	temp = new int[size];
	for(int i = 0; i < size - 1; i++)
		{
		temp[i] = ptr[i];
		}
		delete [] ptr;
		ptr = temp;
		ptr[size - 1] = x;
		return *this;
	}

Set Set::operator - (const Set & set1) const
	{
	Set temp;
	int counter = 0;
	
	for (int j = 0; j < set1.size; j ++)
		{
		if (!set1.IsIn(ptr[j]))
			{
			temp = temp + ptr[j];
			counter++;
			}
		}
	return temp;
	}

Set operator - (const Set & set1, const int & x)
	{
	Set temp;
	int counter = 0;
	
	for (int i = 0; i < set1.size; i ++)
		{
		if (set1.ptr[i] != x)
			{
			temp = temp + set1.ptr[i];
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

bool Set::IsIn(int x) const
	{
	for (int i = 0; i < size; i++)
		{
		if (ptr[i] == x)
			return true;
		}
	return false;
	}

bool Set::IsEmpty()
	{
	if(Size())
		return false;
	return true;
	}

int Set::Size()
	{
	return size;
	}

