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
#include <string>
#include "registrationsystem.h"

using namespace std;

//void readStudentsFromFile(fstream &);

int main()
	{
    //variables
   	RegistrationSystem s;
	string	input,
			input2,
            input3;
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
	
	s.readPrereqsFromFile();
	s.readStudentsFromFile(inFile);
	
	cout	<< "Now checking if Linda Ray can take CSCI340..." << endl;
	
	if(s.checkEligibility("CSCI340", "z112030"))
        cout << endl << "This student is eligible to take this course." << endl;
    else
        cout << endl << "This student is not eligible to take this course." << endl;
	
	system("PAUSE");
	return 0;
	}

