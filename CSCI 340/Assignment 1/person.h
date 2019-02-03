/*************************************************************
* CSCI 340                                       Spring, 2009
* Name: Joe Daniel Parker
* Assignment 1
* Due Date: 01/26/2009
* Purpose: Take input about some information on a student,
* then print it all out.
*************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace::std;

class Person
	{
	protected:
    //data members
	string	name,
			ssn,
			date_of_birth,
			gender;
	
	public:
    //Prototypes
	Person();
	virtual ~Person();
	string get_name() const;
	string get_ssn() const;
	string get_DOB() const;
	string get_gender() const;
	void set_name(const string &);
	void set_ssn(const string &);
	void set_DOB(const string &);
	void set_gender(const string &);
	};

//constructor, sets each data to NULL
Person::Person()
	{
	name = "";
	ssn = "";
	date_of_birth = "";
	gender = "";
	}
	
//destructor
Person::~Person()
	{
	}

//gets the private data member 'name' and returns it
string Person::get_name() const
	{
	return name;
	}

//gets the private data member 'ssn' and returns it	
string Person::get_ssn() const
	{
	return ssn;
	}

//gets the private data member 'date_of_birth' and returns it	
string Person::get_DOB() const
	{
	return date_of_birth;
	}

//gets the private data member 'gender' and returns it	
string Person::get_gender() const
	{
	return gender;
	}

//sets the private data member 'name' to the input value
void Person::set_name(const string & newname)
	{
	name = newname;
	}

//sets the private data member 'ssn' to the input value
void Person::set_ssn(const string & newssn)
	{
	ssn = newssn;
	}

//sets the private data member 'date_of_birth' to the input value
void Person::set_DOB(const string & newDOB)
	{
	date_of_birth = newDOB;
	}

//sets the private data member 'gender' to the input value
void Person::set_gender(const string & newgender)
	{
	gender = newgender;
	}

#endif
