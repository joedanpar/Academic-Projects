/*************************************************************
* CSCI 340                                       Spring, 2009
* Name: Joe Daniel Parker
* Assignment 1
* Due Date: 01/26/2009
* Purpose: Take input about some information on a student,
* then print it all out.
*************************************************************/

#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>

using namespace std;

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
	};

//constructor, sets the data members to NULL
CourseInfo::CourseInfo()
	{
	ID = "";
	year = "";
	semester = "";
	grade = "";
	}
//destructor	
CourseInfo::~CourseInfo()
	{
	}

//gets the private data member 'ID' and returns it
string CourseInfo::get_ID() const
	{
	return ID;
	}
	
//gets the private data member 'year' and returns it
string CourseInfo::get_year() const
	{
	return year;
	}

//gets the private data member 'semester' and returns it
string CourseInfo::get_semester() const
	{
	return semester;
	}

//gets the private data member 'grade' and returns it
string CourseInfo::get_grade() const
	{
	return grade;
	}

//sets the private data member 'ID' to the input value
void CourseInfo::set_ID(const string & newID)
	{
	ID = newID;
	}

//sets the private data member 'year' to the input value
void CourseInfo::set_year(const string & newyear)
	{
	year = newyear;
	}

//sets the private data member 'semester' to the input value
void CourseInfo::set_semester(const string & newsemester)
	{
	semester = newsemester;
	}

//sets the private data member 'grade' to the input value
void CourseInfo::set_grade(const string & newgrade)
	{
	grade = newgrade;
	}

#endif
