#include "Faculty.h"
#include "stdafx.h"

//Print Member Data
void Faculty::inquire()
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
void Faculty::setname(const string &name)
{
	this->name = name;
}
void Faculty::setid(const string &id)
{
	this->id = id;
}
void Faculty::setdept(const string &dept)
{
	this->dept = dept;
}
void Faculty::setpos(const string &pos)
{
	this->position = pos;
}
void Faculty::setmail(const string &mail)
{
	this->mail = mail;
}


//Implements of getter methods
string Faculty::getname()
{
	return name;
}
string Faculty::getid()
{
	return id;
}
string Faculty::getdept()
{
	return dept;
}
string Faculty::getpos()
{
	return position;
}
string Faculty::getmail()
{
	return mail;
}
