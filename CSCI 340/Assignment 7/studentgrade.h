#ifndef STUGRADE_H
#define STUGRADE_H

#include <iostream>
#include <string>

using namespace std;

class StudentGrade
	{
	private:
	string name,
           Zid,
           grade;
	
	public:
	StudentGrade();
	StudentGrade(const string &, const string &, const string &);
	virtual ~StudentGrade();
	string get_name() const;
	string get_Zid() const;
	string get_grade() const;
	void set_name(const string &);
	void set_Zid(const string &);
	void set_grade(const string &);
	
	bool operator== (const StudentGrade &) const;	
	friend ostream & operator<< (ostream &, const StudentGrade &);
    bool operator < (StudentGrade) const;
    bool operator > (StudentGrade) const;
	};
	
StudentGrade::StudentGrade()
	{
	name = "";
	Zid = "";
	grade = "";
	}
	
StudentGrade::StudentGrade(const string & newname, const string & newzid, const string & newgrade)
	{	
	name = newname;
	Zid = newzid;
	grade = newgrade;
	}
	
StudentGrade::~StudentGrade()
	{
	}

string StudentGrade::get_name() const
	{
	return name;
	}
	
string StudentGrade::get_Zid() const
	{
	return Zid;
	}
	
string StudentGrade::get_grade() const
	{
	return grade;
	}
	
void StudentGrade::set_name(const string & newname)
	{
	name = newname;
	}
	
void StudentGrade::set_Zid(const string & newZid)
	{
	Zid = newZid;
	}
	
void StudentGrade::set_grade(const string & newgrade)
	{
	grade = newgrade;
	}
	
bool StudentGrade::operator== (const StudentGrade & s) const
	{	
	if(get_name() == s.get_name() &&
	get_Zid() == s.get_Zid() &&
	get_grade() == s.get_grade())
		return true;
	else
		return false;
	}

ostream & operator<< (ostream & cout, const StudentGrade & s)
	{
	cout << s.get_name() << ", " << s.get_Zid() << ", " << s.get_grade();
	return cout;
	}
  
bool StudentGrade::operator< (StudentGrade s) const
	{
	if(get_grade() < s.get_grade())
		return true;
	else if (get_grade() > s.get_grade())
		return false;
	else if (get_grade() == s.get_grade())
		if (get_Zid() < s.get_Zid())
			return true;
		else return false;
	return false;
	}

bool StudentGrade::operator> (StudentGrade s) const
	{
	if(get_grade() > s.get_grade())
		return true;
	else if (get_grade() < s.get_grade())
		return false;
	else if (get_grade() == s.get_grade())
		if (get_Zid() > s.get_Zid())
			return true;
		else return false;
	return false;
	}

#endif
