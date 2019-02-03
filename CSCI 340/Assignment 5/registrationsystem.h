/************************************************************
* CSCI 340 section 2						   Spring, 2009	*
* Name: Joe Daniel Parker						    z158012	*
* Assignment 4												*
* Due Date: 03/06/2009										*
* Purpose:	Take input about some information on a student,	*
* 			then print it all out.							*
************************************************************/

#ifndef REGISTRATIONSYSTEM_H
#define REGISTRATIONSYSTEM_H

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "student.h"
#include "courseinfo.h"
#include "avl.h"
#include "studentgrade.h"

using namespace std;

/****************************************************
* Class:		RegistrationSystem					*
* Data Members:	Course ID# (ABCD###)				*
*				Year taken (YYYY)					*
*				Semester taken (Fall/Spring)		*
*				Grade earned (A)					*
* Methods:		Constructor							*
*				Destructor							*
*				Accessor methods for data members	*
*				Operator overloaders				*
****************************************************/
class RegistrationSystem
	{
	private:
	//data members
	list<Student> studentlist;
	//List<Student>::iterator studentItr;
    //List<CourseInfo>::iterator courseItr;
	
	public:
	//prototypes
	RegistrationSystem();
	virtual ~RegistrationSystem();
	void readStudentsFromFile(fstream &);
	void printScoreList(const string &, const string &, const string &);
	void printList();
	};

/********************************************************************
* Function:		Constructor											*
* Useage:		RegistrationSystem()								*
* Logic:		Initialize the data members in the class to NULL	*
********************************************************************/
RegistrationSystem::RegistrationSystem()
	{
	}

/************************************************************************
* Function:		Destructor												*
* Useage:		delete RegistrationSystem								*
* Logic:		Nothing special needs to be done, so the				*
*				standard way of freeing up memory is sufficient enough.	*
************************************************************************/
RegistrationSystem::~RegistrationSystem()
	{
	}

/************************************************************************************
* Function:		read Students From File												*
* Useage:		readStudentsFromFile(fstream &)										*
* Variables:	temporary strings for data collection,								*
*				student object,														*
*				Course Info object													*
* Logic:		Take each block of string data from the file and insert them into	*
*				their appropriate variables.  Once this is done, print out the		*
*				information to the user.											*
************************************************************************************/
void RegistrationSystem::readStudentsFromFile(fstream & inFile)
	{
    string tempstring,
		   tempfirst,
		   templast,
           tempgrade,
           tempID,
           tempyear,
           tempsemester,
           coursetaken,
           yeartaken,
           semestertaken;
    CourseInfo tempclass;

	while (!inFile.eof())
		{
        Student s;
		inFile	>> tempfirst;
		inFile	>> templast;
		if (tempfirst == "donedone")
		   break;
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
		inFile	>> tempstring;
		while (tempstring != "done")
			{
            //inFile  >> tempID;
			tempID = tempstring;
			inFile	>> tempyear;
			inFile	>> tempsemester;
			inFile	>> tempgrade;
			//inFile  >> tempstring; 
			//cout << "got Course Info:" << tempID << " " << tempyear << " " << tempsemester << " " << tempgrade << endl;
			tempclass.set_ID(tempID);
			tempclass.set_year(tempyear);
			tempclass.set_semester(tempsemester);
			tempclass.set_grade(tempgrade);
			cout << endl << "Adding Class..." << endl;
			s.add_class(tempclass);
			inFile >> tempstring;
			}
		//inFile >> tempstring;
		studentlist.push_front(s);
        }

	//s.update_class(tempID, tempyear, tempsemester, tempgrade);
	cout << endl << "Current student information:" << endl;
	printList();
	
	/*cout << endl << "Removing Class..." << endl;
	s.remove_class(tempclass);
	
	cout << endl << "Information after class was removed:" << endl;
	s.infoPrint();*/
	cout << "What class do you wish to search for? ";
	cin >> coursetaken;
	
	cout << "What year was this course taken? ";
	cin >> yeartaken;
	
	cout << "What semester was this course taken? ";
	cin >> semestertaken;
	
	printScoreList(coursetaken, yeartaken, semestertaken);
	}

void RegistrationSystem::printList()
    {
    list<Student>::iterator studentItr;
    list<CourseInfo>::const_iterator courseItr;
    //Node<Student> * studentptr = studentlist.get_headptr();
    //Node<CourseInfo> * courseptr = studentptr->get_data().get_courseList().get_headptr();
    for (studentItr = studentlist.begin(); studentItr != studentlist.end(); studentItr++)
	    {
	    cout << studentItr->get_name() << " "
             << studentItr->get_ssn() << " "
             << studentItr->get_DOB() << " "
             << studentItr->get_gender() << " "
             << studentItr->get_Zid() << endl;
	    for(courseItr = studentItr->get_courseList().begin(); courseItr != studentItr->get_courseList().end(); courseItr++)
            {
            cout << courseItr->get_ID() << " "
				 << courseItr->get_year() << " "
				 << courseItr->get_semester() << " "
				 << courseItr->get_grade() << endl;
            }
        cout << endl;
        }
    }
	
void RegistrationSystem::printScoreList(const string & courseTaken, const string & yearTaken, const string & semesterTaken)
	{
	AvlTree<StudentGrade> gradeTree;
	
	list<Student>::iterator studentItr;
    list<CourseInfo>::const_iterator courseItr;
	
	for (studentItr = studentlist.begin(); studentItr != studentlist.end(); studentItr++)
	    {
	    for(courseItr = studentItr->get_courseList().begin(); courseItr != studentItr->get_courseList().end(); courseItr++)
            {
            Student s = *studentItr;
            CourseInfo c = *courseItr;
            if(c.get_ID() == courseTaken && c.get_year() == yearTaken && c.get_semester() == semesterTaken)
				{
				StudentGrade gradeFound(s.get_name(), s.get_Zid(), c.get_grade());
				Comparable<StudentGrade>* newItem = new Comparable<StudentGrade>(gradeFound);
				gradeTree.Insert(newItem);
				}
            }
        }
	cout << "Students that have taken " << courseTaken << " During the " << semesterTaken << " of " << yearTaken << endl;
	gradeTree.DumpTree(cout);
    cout << endl;
	}

#endif
