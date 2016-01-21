#include "Student.h"

void Student::inquire()
{
	cout.width(10);
	cout<<left<<name;
	cout<<"| ";
	cout.width(12);
	cout<<left<<id;
	cout<<"| ";
	cout.width(24);
	cout<<left<<dept;
	cout<<"| ";
	cout.width(14);
	cout<<left<<position;
	cout<<"| ";
	cout.width(30);
	cout<<left<<mail<<endl;
}


//Implements of setter methods
void Student::setname(const string &name)
{
	this->name = name;
}
void Student::setid(const string &id)
{
	this->id = id;
}
void Student::setdept(const string &dept)
{
	this->dept = dept;
}
void Student::setpos(const string &pos)
{
	this->position = pos;
}
void Student::setmail(const string &mail)
{
	this->mail = mail;
}


//Implements of getter methods
string Student::getname()
{
	return name;
}
string Student::getid()
{
	return id;
}
string Student::getdept()
{
	return dept;
}
string Student::getpos()
{
	return position;
}
string Student::getmail()
{
	return mail;
}
