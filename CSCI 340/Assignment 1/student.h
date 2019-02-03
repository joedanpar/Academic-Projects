/*************************************************************
* CSCI 340                                       Spring, 2009
* Name: Joe Daniel Parker
* Assignment 1
* Due Date: 01/26/2009
* Purpose: Take input about some information on a student,
* then print it all out.
*************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "courseinfo.h"

using namespace std;
//using std::cin;
//using std::cout;
//using std::endl;

class Student: public Person
	{
	protected:
    //data members
	string Zid;
	vector<CourseInfo> classes;
	
	public:
    //prototypes
	Student();
	virtual ~Student();
	string get_Zid() const;
	CourseInfo get_class(const int &) const;
	void set_Zid(const string &);
	void infoPrint(const string &);
	void add_class(const CourseInfo &);
	void remove_class(const CourseInfo &);
	void update_class(const string &, const string &, const string &, const string &, const int &);
	};

//constructor, sets the only data member to NULL
Student::Student(): Person()
	{
	Zid = "";
	}

//destructor	
Student::~Student()
	{
	}

//gets the private data member 'Zid' and returns it
string Student::get_Zid() const
	{
	return Zid;
	}
	
/*CourseInfo Student::get_class(const int & i) const
	{
	return classes.at(i);
	}*/

//sets the private data member 'Zid' to the input value
void Student::set_Zid(const string & newZid)
	{
	Zid = newZid;
	}

//Prints out all the information in an orderly fashion, formatted as well
void Student::infoPrint(const string & Zid)
	{
	cout	<< endl
			<< get_name() << " " << get_ssn() << " " << get_DOB() << " " << get_gender() << " " << get_Zid()
			<< endl;
	for (int i = 0; i < classes.size(); i ++)
		{
		cout	<< classes[i].get_ID() << " " <<  classes[i].get_year() << " " << classes[i].get_semester() << " " << classes[i].get_grade()
				<< endl;
		}
	}

/*void Student::add_class(const CourseInfo & newclass)
	{
	classes.back() = newclass;
	}*/

/*void Student::remove_class(const CourseInfo & input)
	{
	for (int i; i < classes.size(); i++)
		{
		if (input == classes.at(i))
			classes.erase(i);
		}
	}*/

//updates the classes vector from within the student class,
//since they are protected data members
void Student::update_class(const string & newID, const string & newyear, const string & newsemester, const string & newgrade, const int & i)
     {
     classes.resize(i+1);
     classes[i].set_ID(newID);
     classes[i].set_year(newyear);
     classes[i].set_semester(newsemester);
     classes[i].set_grade(newgrade);
     }

#endif
