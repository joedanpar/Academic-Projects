/****************************************************************
* CSCI 340 section 2                             Spring, 2009	*
* Name: Joe Daniel Parker                             z158012	*
* Assignment 2													*
* Due Date: 02/06/2009											*
* Purpose:	Take input about some information on a student,		*
* 			then print it all out.								*
****************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace::std;

/************************************************************
* Class:		Person										*
* Data Members:	Person's name (first and last)				*
*				Person's social security number (#########)	*
*				Person's date of birth (MM/DD/YYYY)			*
*				Person's gender (M/F)						*
* Methods:		Constructor									*
*				Destructor									*
*				Accessor methods for data members			*
************************************************************/
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

/************************************************************************************
* Function:		Constructor															*
* Useage:		Person()															*
* Logic:		Initialize the data members in the class to NULL					*
************************************************************************************/
Person::Person()
	{
	name = "";
	ssn = "";
	date_of_birth = "";
	gender = "";
	}
	
/************************************************************************************
* Function:		Destructor															*
* Useage:		delete person														*
* Logic:		Nothing special needs to be done, so the standard way of freeing up	*
*				memory is sufficient enough											*
************************************************************************************/
Person::~Person()
	{
	}

/************************************************************************************
* Function:		get name															*
* Useage:		get_name()															*
* Logic:		returns the private data member "name".								*
************************************************************************************/
string Person::get_name() const
	{
	return name;
	}

/************************************************************************************
* Function:		get social security number											*
* Useage:		get_ssn()															*
* Logic:		returns the private data member "ssn".								*
************************************************************************************/
string Person::get_ssn() const
	{
	return ssn;
	}

/************************************************************************************
* Function:		get date of birth													*
* Useage:		get_DOB()															*
* Logic:		returns the private data member "date_of_birth".					*
************************************************************************************/
string Person::get_DOB() const
	{
	return date_of_birth;
	}

/************************************************************************************
* Function:		get gender															*
* Useage:		get_gender()														*
* Logic:		returns the private data member "gender".							*
************************************************************************************/
string Person::get_gender() const
	{
	return gender;
	}

/************************************************************************************
* Function:		set name															*
* Useage:		set_name(input)														*
* Logic:		modifies the private data member "name".							*
************************************************************************************/
void Person::set_name(const string & newname)
	{
	name = newname;
	}

/************************************************************************************
* Function:		set social security number											*
* Useage:		set_ssn(input)														*
* Logic:		modifies the private data member "ssn".								*
************************************************************************************/
void Person::set_ssn(const string & newssn)
	{
	ssn = newssn;
	}

/************************************************************************************
* Function:		set date of birth													*
* Useage:		set_DOB(input)														*
* Logic:		modifies the private data member "date_of_birth".					*
************************************************************************************/
void Person::set_DOB(const string & newDOB)
	{
	date_of_birth = newDOB;
	}

/************************************************************************************
* Function:		set gender															*
* Useage:		set_gender(input)													*
* Logic:		modifies the private data member "gender".							*
************************************************************************************/
void Person::set_gender(const string & newgender)
	{
	gender = newgender;
	}

#endif
