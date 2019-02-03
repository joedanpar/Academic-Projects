/************************************************************
* CSCI 340 section 2                           Spring, 2009	*
* Name: Joe Daniel Parker                           z158012	*
* Assignment 2												*
* Due Date: 02/06/2009										*
* Purpose:	Take input about some information on a student,	*
* 			then print it all out.							*
************************************************************/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "person.h"
#include "student.h"
#include "courseinfo.h"
#include "list.h"

using namespace std;

void loadInfoFromFile(fstream &);

int main()
	{
    //variables
   	Student s;
	char* input;
	fstream inFile;
	
	cout	<< "Welcome to the Student Information Gathering System:" << endl
			<< endl
			<< "Please enter the path to the file to be opened: ";
	//cin	>> input;
	inFile.open("data.txt");
	
	while (inFile.fail())
		{
		cout	<< "Filename Incorrect" << endl
				<< "Please enter the path to the file to be opened: ";
		cin	>> input;
		inFile.open(input);
		}
	
	loadInfoFromFile(inFile);
	
	/****************************************************************************
	* This was the old way of inserting manually, I only kept it in just in case*
	* we need to use it again.  It is all commented out.						*
	*****************************************************************************
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
	
    at this point, the program will print out the information given to it thus far.
    tempstring = s.get_Zid();*/
	
    system("PAUSE");
	return 0;
	}

/************************************************************************************
* Function:		Load Info From File													*
* Useage:		loadInfoFromFile(fstream &)											*
* Variables:	temporary strings for data collection,								*
*				student object,														*
*				CourseInfo object													*
* Logic:		Take each block of string data from the file and insert them into	*
*				their appropriate variables.  Once this is done, print out the		*
*				information to the user.											*
************************************************************************************/
void loadInfoFromFile(fstream & inFile)
	{
	Student s;
    string tempstring,
		   tempfirst,
		   templast,
           tempgrade,
           tempID,
           tempyear,
           tempsemester;
    CourseInfo tempclass;

	inFile	>> tempfirst;
	inFile	>> templast;
	tempstring = (tempfirst + " " + templast);
	s.set_name(tempstring);
	//cout << "got name" << endl;
	inFile	>> tempstring;
	s.set_ssn(tempstring);
	//cout << "got SSN" << endl;
	inFile	>> tempstring;
	s.set_DOB(tempstring);
	//cout << "got DOB" << endl;
	inFile	>> tempstring;
	s.set_gender(tempstring);
	//cout << "got gender" << endl;
	inFile	>> tempstring;
	s.set_Zid(tempstring);
	//cout << "got Zid" << endl;
	//inFile	>> tempstring;
	while (!inFile.eof())
		{
		inFile	>> tempID;
		inFile	>> tempyear;
		inFile	>> tempsemester;
		inFile	>> tempgrade;
		//inFile  >> tempstring; 
		//cout << "got Course Info" << endl;
		tempclass.set_ID(tempID);
		tempclass.set_year(tempyear);
		tempclass.set_semester(tempsemester);
        tempclass.set_grade(tempgrade);
        cout << endl << "Adding Class..." << endl;
		s.add_class(tempclass);
		}
	cout << endl << "Checking if student has taken a given class..." << endl;
	s.checkClassTaken(tempclass);
	//s.update_class(tempID, tempyear, tempsemester, tempgrade);
	cout << endl << "Current student information:" << endl;
	s.infoPrint();
	
	/*cout << endl << "Removing Class..." << endl;
	s.remove_class();
	
	cout << endl << "Information after class was removed:" << endl;
	s.infoPrint();*/
	}
