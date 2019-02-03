/************************************************************
* CSCI 340 section 2						   Spring, 2009	*
* Name: Joe Daniel Parker						    z158012	*
* Assignment 6												*
* Due Date: 03/06/2009										*
* Purpose:	Take input about some information on a student,	*
* 			then print it all out.							*
************************************************************/

#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

/****************************************************
* Class:		CourseInfo							*
* Data Members:	Course ID# (ABCD###)				*
*				Year taken (YYYY)					*
*				Semester taken (Fall/Spring)		*
*				Grade earned (A)					*
* Methods:		Constructor							*
*				Destructor							*
*				Accessor methods for data members	*
*				Operator overloaders				*
****************************************************/
class CourseInfo
	{
	protected:
	//data members
	string	ID,
			year,
			semester,
			grade;
	
	public:
	//prototypes
	CourseInfo();
	virtual ~CourseInfo();
	string get_ID() const;
	string get_year() const;
	string get_semester() const;
	string get_grade() const;
	void set_ID(const string &);
	void set_year(const string &);
	void set_semester(const string &);
	void set_grade(const string &);
	void printcourse();

	CourseInfo & operator= (const CourseInfo &);
	bool operator== (const CourseInfo &) const;
	bool operator!= (const CourseInfo &) const;
	};

/********************************************************************
* Function:		Constructor											*
* Useage:		CourseInfo()										*
* Logic:		Initialize the data members in the class to NULL	*
********************************************************************/
CourseInfo::CourseInfo()
	{
	ID = "";
	year = "";
	semester = "";
	grade = "";
	}

/************************************************************************
* Function:		Destructor												*
* Useage:		delete CourseInfo										*
* Logic:		Nothing special needs to be done, so the				*
*				standard way of freeing up memory is sufficient enough.	*
************************************************************************/
CourseInfo::~CourseInfo()
	{
	}

/********************************************************
* Function:		get ID#									*
* Useage:		get_ID()								*
* Logic:		returns the private data member "ID".	*
********************************************************/
string CourseInfo::get_ID() const
	{
	return ID;
	}
	
/********************************************************
* Function:		get year								*
* Useage:		get_year()								*
* Logic:		returns the private data member "year".	*
********************************************************/
string CourseInfo::get_year() const
	{
	return year;
	}

/************************************************************
* Function:		get semester								*
* Useage:		get_semester()								*
* Logic:		returns the private data member "semester".	*
************************************************************/
string CourseInfo::get_semester() const
	{
	return semester;
	}

/************************************************************
* Function:		get grade									*
* Useage:		get_grade()									*
* Logic:		returns the private data member "grade".	*
************************************************************/
string CourseInfo::get_grade() const
	{
	return grade;
	}

/********************************************************
* Function:		set ID#									*
* Useage:		set_ID(input)							*
* Logic:		modifies the private data member "ID".	*
********************************************************/
void CourseInfo::set_ID(const string & newID)
	{
	ID = newID;
	}

/************************************************************
* Function:		set year									*
* Useage:		set_year(input)								*
* Logic:		modifies the private data member "year".	*
************************************************************/
void CourseInfo::set_year(const string & newyear)
	{
	year = newyear;
	}

/****************************************************************
* Function:		set semester									*
* Useage:		set_semester(input)								*
* Logic:		modifies the private data member "semester".	*
****************************************************************/
void CourseInfo::set_semester(const string & newsemester)
	{
	semester = newsemester;
	}

/************************************************************
* Function:		set grade									*
* Useage:		set_grade(input)							*
* Logic:		modifies the private data member "grade".	*
************************************************************/
void CourseInfo::set_grade(const string & newgrade)
	{
	grade = newgrade;
	}

bool CourseInfo::operator== (const CourseInfo & CI) const
	{
	if(ID == CI.get_ID() &&
	year == CI.get_year() &&
	semester == CI.get_semester() &&
	grade == CI.get_grade())
		return true;
	else
		return false;
	}

bool CourseInfo::operator!= (const CourseInfo & CI) const
	{
	if(ID == CI.get_ID() &&
	year == CI.get_year() &&
	semester == CI.get_semester() &&
	grade == CI.get_grade())
		return false;
	else
		return true;
	}

CourseInfo & CourseInfo::operator= (const CourseInfo & CI)
	{
	if (this != & CI)
		{
		//delete this;
		ID = CI.get_ID();
		year = CI.get_year();
		semester = CI.get_semester();
		grade = CI.get_grade();
		}
	return *this;
	}

void CourseInfo::printcourse()
     {
     cout << get_ID() << " "
          << get_year() << " "
          << get_semester() << " "
          << get_grade() << endl;
     }

#endif
