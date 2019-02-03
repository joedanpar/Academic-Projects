/****************************************************************
* CSCI 340 section 2                             Spring, 2009	*
* Name: Joe Daniel Parker                             z158012	*
* Assignment 2													*
* Due Date: 02/06/2009											*
* Purpose:	Take input about some information on a student,		*
* 			then print it all out.								*
****************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include <iomanip>
#include <iostream>
#include <string>
#include "person.h"
#include "list.h"
#include "courseinfo.h"

using namespace std;

/****************************************************************************
* Class:		Student (inherited publicly from Person)					*
* Data Members:	Student's Z-ID number (z######)								*
*				List of Classes (Singly Linked List)						*
* Methods:		Constructor													*
*				Destructor													*
*				Accessor methods for data members							*
*				infoPrint (prints out the Student's information				*
*				add_class (inserts a new node into the class list)			*
*				update_class (updates the Class node from within the class)	*
****************************************************************************/
class Student: public Person
	{
	protected:
    //data members
	string Zid;
	List<CourseInfo> classes;
	
	public:
    //prototypes
	Student();
	virtual ~Student();
	string get_Zid() const;
	void set_Zid(const string &);
	void infoPrint();
	void add_class(const CourseInfo &);
	//void remove_class(const CourseInfo &);
	void update_class(const string &, const string &, const string &, const string &);
	};

/************************************************************************************
* Function:		Constructor															*
* Useage:		Student()															*
* Logic:		Initialize the data member in the class to NULL						*
************************************************************************************/
Student::Student(): Person()
	{
	Zid = "";
	}

/************************************************************************************
* Function:		Destructor															*
* Useage:		delete student														*
* Logic:		Nothing special needs to be done, so the standard way of freeing up	*
*				memory is sufficient enough.  This function is virtual so that it	*
*				is called dynamically.												*
************************************************************************************/
Student::~Student()
	{
	}


/************************************************************************************
* Function:		get Z-ID															*
* Useage:		get_Zid()															*
* Logic:		returns the private data member "Zid".								*
************************************************************************************/
string Student::get_Zid() const
	{
	return Zid;
	}

/************************************************************************************
* Function:		set Z-ID															*
* Useage:		set_Zid(input)														*
* Logic:		modifies the private data member "Zid".								*
************************************************************************************/
void Student::set_Zid(const string & newZid)
	{
	Zid = newZid;
	}

/************************************************************************************
* Function:		info print															*
* Useage:		infoPrint()															*
* Logic:		Print out all the information for the Student.						*
************************************************************************************/
void Student::infoPrint()
	{
	cout	<< endl
			<< get_name() << " " << get_ssn() << " " << get_DOB() << " "
            << get_gender() << " " << get_Zid() << endl;
    classes.print(classes.get_headptr());
	}

/************************************************************************************
* Function:		add class															*
* Useage:		add_class(classname)													*
* Logic:		Inserts a new node into the linked list of CourseInfo objects.		*
************************************************************************************/
void Student::add_class(const CourseInfo & newclass)
	{
	classes.Insert(newclass);
	}

/*void Student::remove_class(const CourseInfo & input)
	{
	for (int i; i < classes.Length(); i++)
		{
		if (input == classes.at(i))
			classes.erase(i);
		}
	}*/

/************************************************************************************
* Function:		update class														*
* Useage:		update_class(ID#, year, semester, grade)							*
* Variables:	temporary CourseInfo object											*
* Logic:		set all the passed in variables into a temporary CourseInfo object,	*
*				then add that temporary class to the linked list.					*
************************************************************************************/
void Student::update_class(const string & newID, const string & newyear, const string & newsemester, const string & newgrade)
    {
	CourseInfo temp;
	
    temp.set_ID(newID);
    temp.set_year(newyear);
    temp.set_semester(newsemester);
    temp.set_grade(newgrade);
	
	add_class(temp);
    }

#endif
