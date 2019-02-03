/************************************************************
* CSCI 340 section 2                           Spring, 2009	*
* Name: Joe Daniel Parker                           z158012	*
* Assignment 6												*
* Due Date: 04/03/2009										*
* Purpose:	Take input about some information on a student,	*
* 			then print it all out.							*
************************************************************/

#include <iomanip>
#include <iostream>
#include <fstream>
#include "registrationsystem.h"

using namespace std;

int main()
	{
    //variables
   	RegistrationSystem s;
	fstream inFile;
	
	cout	<< "Welcome to the Student Information Gathering System:" << endl << endl;

	inFile.open("students.txt");
	s.readStudentsFromFile(inFile);
	
	cout << "Displaying a sorted list of students who have taken CSCI340 in the Fall of 2008" << endl << endl;
	s.testSort("CSCI340", "2008", "Fall");
	
	system("PAUSE");
	return 0;
	}

