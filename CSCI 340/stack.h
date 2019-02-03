/************************************************************
* CSCI 340 section 2                           Spring, 2009	*
* Name: Joe Daniel Parker                           z158012	*
* Assignment 3												*
* Due Date: 02/20/2009										*
* Purpose:	Take input about some information on a student,	*
* 			then print it all out.							*
************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "courseinfo.h"
#include "list.h"

using namespace std;

/********************************************************
* Class:		Stack (Template Class)					*
* Data Members:	List<T> (body of the stack)				*
*				count (number of items in stack)		*
*				MAXSIZE (max number of items in stack)	*
* Methods:		Constructor								*
*				Destructor								*
*				push									*
*				pop										*
*				printStack								*
*				isInStack								*
********************************************************/
template <class T>
class Stack
	{
	private:
	List<T> stackSpace;
	int count;
	static const int MAXSIZE = 10;
	
	public:
	Stack();
	virtual ~Stack();
	void push(const T &);
	T * pop();
	bool isFull();
	void printStack();
	bool isInStack(const T &) const;
	};
	
/********************************************
* Function:		Constructor					*
* Useage:		Stack()						*
* Logic:		Instantiates the count to 0	*
********************************************/
template <class T>
Stack<T>::Stack()
	{
	count = 0;
	}
	
/************************************************************************
* Function:		Destructor												*
* Useage:		delete Stack											*
* Logic:		uses the standard means of deletion to remove the Stack	*
************************************************************************/
template <class T>
Stack<T>::~Stack()
	{
	}
	
/****************************************************************************
* Function:		push														*
* Useage:		push(datatype)												*
* Logic:		adds an object of the template data dtyp onto the stack.	*
****************************************************************************/
template <class T>
void Stack<T>::push(const T & input)
	{
	stackSpace.Insert(input);
	count++;
	}
	
/*template <class T>
T * Stack<T>::pop()
	{
	Node<T> * tempnode;
	T * temp;
	tempnode = stackSpace.get_headptr();
	temp = tempnode.get_data();
	stackSpace.deleteNode(*temp);
	return temp;
	}*/
	
/********************************************************************************
* Function:		isFull															*
* Useage:		isFull()														*
* Logic:		if the count of the stack is equal to the max size, it's full.	*
********************************************************************************/
template <class T>
bool Stack<T>::isFull()
	{
	if(count == MAXSIZE)
		return true;
	return false;
	}

/********************************************************************
* Function:		printStack											*
* Useage:		printStack()										*
* Logic:		calls the linked list method to print the stack.	*
********************************************************************/
template <class T>
void Stack<T>::printStack()
     {
     stackSpace.print(stackSpace.get_headptr());
     }

/************************************************************************************
* Function:		isInStack															*
* Useage:		isInStack(datatype)													*
* Logic:		calls the linked list method to check if the passed in data type	*
*					is in the list/stack.											*
************************************************************************************/
template <class T>
bool Stack<T>::isInStack(const T & input) const
     {
     stackSpace.isInList(input);
     }

#endif