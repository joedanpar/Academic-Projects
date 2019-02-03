/************************************************************
* CSCI 340 section 2                           Spring, 2009	*
* Name: Joe Daniel Parker                           z158012	*
* Assignment 4												*
* Due Date: 03/06/2009										*
* Purpose:	Take input about some information on a student,	*
* 			then print it all out.							*
************************************************************/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
#include "list.h"
#include "person.h"
#include "courseinfo.h"
#include "registrationsystem.h"

using namespace std;

//void readStudentsFromFile(fstream &);

int main()
	{
    //variables
   	RegistrationSystem s;
	string input;
	fstream inFile;
	
	cout	<< "Welcome to the Student Information Gathering System:" << endl
			<< endl
			<< "Please enter the path to the file to be opened: ";
	cin	>> input;
	inFile.open(input.c_str());
	
	while (inFile.fail())
		{
		cout	<< "Filename Incorrect" << endl
				<< "Please enter the path to the file to be opened: ";
		cin	>> input;
		inFile.open(input.c_str());
		}
	
	s.readStudentsFromFile(inFile);
	
	system("PAUSE");
	return 0;
	}

