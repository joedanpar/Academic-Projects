/************************************************************
* CSCI 241										 Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 5
* Due Date: 10/23/2008
* Purpose:	Develop a class to represent finite sets of
*			integers.
************************************************************/
#ifndef SET_H
#define SET_H

#include <iostream>

using std::ostream;

class Set
	{
	friend Set operator ^ (const Set &, const Set &);
	friend ostream & operator << (ostream &, const Set &);
	friend Set operator - (const Set &, const int &);
	
	public:
	Set();
	Set(const Set &);
	~Set();
	
	Set & operator = (const Set &);
	bool operator == (const Set &) const;
	bool operator < (const Set) const;
	const Set & operator + (const Set &);
	Set operator + (const int &);
	Set operator - (const Set &) const;
	int & operator [] (const int &);
	int operator [] (const int &) const;
	bool IsIn(int) const;
	bool IsEmpty();
	int Size(); 
	
	private:
	int size;
	int * ptr;
	};


#endif
