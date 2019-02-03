/************************************************************
* CSCI 340 section 2						   Spring, 2009	*
* Name: Joe Daniel Parker						    z158012	*
* Assignment 6												*
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
#include <vector>
#include "student.h"
#include "courseinfo.h"
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
	string* courseIDList;
	list<string> * prereqLists;
	int numCourses;
	//List<Student>::iterator studentItr;
    //List<CourseInfo>::iterator courseItr;
	
	public:
	//prototypes
	RegistrationSystem();
	virtual ~RegistrationSystem();
	void readStudentsFromFile(fstream &);
	void printList();
	void quicksort(vector<StudentGrade> &, int, int);
	void quicksort(vector<StudentGrade> &, int);
	void swap(StudentGrade &, StudentGrade &);
	void testSort(const string &, const string &, const string &);
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
	}

void RegistrationSystem::printList()
    {
    list<Student>::iterator studentItr;
    list<CourseInfo>::const_iterator courseItr;
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

void RegistrationSystem::quicksort(vector<StudentGrade> & data, int first, int last)
	{
    int lower = first+1,
		upper = last;
    swap(data[first],data[(first+last)/2]);
    StudentGrade bound = data[first];
    while (lower <= upper) {
        while (data[lower] < bound)
             lower++;
        while (bound < data[upper])
             upper--;
        if (lower < upper)
             swap(data[lower++],data[upper--]);
        else lower++;
    }
    swap(data[upper],data[first]);
    if (first < upper-1)
        quicksort (data,first,upper-1);
    if (upper+1 < last)
        quicksort (data,upper+1,last);
}

void RegistrationSystem::quicksort(vector<StudentGrade> & data, int n)
	{
    int i,
		max;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++)// find the largest
        if (data[max] < data[i])    // element and put it
            max = i;                // at the end of data[];
    swap(data[n-1],data[max]); // largest el is now in its
    quicksort(data,0,n-2);     // final position;
}

void RegistrationSystem::swap(StudentGrade & data1, StudentGrade & data2)
	{
	StudentGrade temp;
	temp = data1;
	data1 = data2;
	data2 = temp;
	}

void RegistrationSystem::testSort(const string & courseTaken, const string & yearTaken, const string & semesterTaken)
	{
	vector<StudentGrade> v;
	int count = 0;
	
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
				v.push_back(gradeFound);
				count++;
				}
            }
        }
	
	quicksort(v, count);
	
	for(int i = 0; i < count; i++)
		{
		cout << v[i] << ", " << courseTaken << ", " << semesterTaken << endl;
		}
    cout << endl;
	}

#endif
