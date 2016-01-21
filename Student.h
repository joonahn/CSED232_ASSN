#ifndef STUDENT_H
#define STUDENT_H
#include "stdafx.h"

class Student
{
private:
	//Member variables
	string name;
	string id;
	string dept;
	string position;
	string mail;
public:
	void inquire();

	//setter method
	void setname(const string &name);
	void setid(const string &id);
	void setdept(const string &dept);
	void setpos(const string &pos);
	void setmail(const string &mail);


	//getter method
	string getname();
	string getid();
	string getdept();
	string getpos();
	string getmail();

};

#endif
