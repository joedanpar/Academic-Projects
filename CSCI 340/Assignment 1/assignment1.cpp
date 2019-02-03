/*************************************************************
* CSCI 340                                       Spring, 2009
* Name: Joe Daniel Parker
* Assignment 1
* Due Date: 01/26/2009
* Purpose: Take input about some information on a student,
* then print it all out.
*************************************************************/

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include "person.h"
#include "student.h"
#include "courseinfo.h"

using std::cin;
using std::cout;
using std::endl;

int main()
	{
    //variables, mostly temporaries
	Student s;
	string tempstring,
           tempgrade,
           tempID,
           tempyear,
           tempsemester;
    int    count = 0;
	
	//have the user enter in certain information about the student,
    //including name, ssn, date of birth, gender, and Z-ID number.
    cout	<< "Welcome to the Student Information Gathering System:" << endl
			<< endl
			<< "Please enter the student's full name: ";
	getline(cin, tempstring);
	s.set_name(tempstring);
	
	cout	<< endl
			<< "Please enter the student's Social Security Number: ";
	cin		>> tempstring;
	s.set_ssn(tempstring);
	
	cout	<< endl
			<< "Please enter the student's Date of Birth (MM/DD/YY): ";
	cin 	>> tempstring;
	s.set_DOB(tempstring);
	
	cout	<< endl
			<< "Please enter the student's Gender (M/F): ";
	cin		>> tempstring;
	while (tempstring != "M" && tempstring != "F" && tempstring != "m" && tempstring != "f")
			{
			cout	<< endl
					<< "Please enter a correct respons (M/F): ";
			cin		>> tempstring;
			}
	s.set_gender(tempstring);
	
	cout	<< endl
			<< "Please enter the student's Z-id Number: ";
	cin		>> tempstring;
	s.set_Zid(tempstring);
	
	//Since the student can have multiple classes, have the user input
    //information about each class they have taken, until they select 'N'
    //at the end of the loop.
    do
		{
		cout	<< endl
				<< "Please enter one of the student's course's Course-ID: ";
		cin		>> tempID;
		//s.add_class();
		//s.classes.set_ID(tempstring);
		
		cout	<< endl
				<< "Please enter this course's Year taken (YYYY): ";
		cin 	>> tempyear;
		//s.classes.set_year(tempstring);
	
		cout	<< endl
				<< "Please enter this course's Semester taken: ";
		cin		>> tempsemester;
		//s.classes.set_semester(tempstring);
	
		cout	<< endl
				<< "Please enter this course's Grade earned: ";
		cin		>> tempgrade;
		//s.classes.set_grade(tempstring);
		
        s.update_class(tempID, tempyear, tempsemester, tempgrade, count);
		
		cout	<< endl
				<< "Does this student have any more classes? (Y/N): ";
		cin		>> tempstring;
		
		while (tempstring != "Y" && tempstring != "N" && tempstring != "y" && tempstring != "n")
			{
			cout	<< endl
					<< "Please enter a correct respons (Y/N): ";
			cin		>> tempstring;
			}
		count ++;
		}
		while (tempstring == "Y" || tempstring == "y");
	
    //at this point, the program will print out the information given to it thus far.
    tempstring = s.get_Zid();
	s.infoPrint(tempstring);
	
    system("PAUSE");
	return 0;
	}
