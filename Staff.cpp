#include "Staff.h"

void Staff::inquire()
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
void Staff::setname(const string &name)
{
	this->name = name;
}
void Staff::setid(const string &id)
{
	this->id = id;
}
void Staff::setdept(const string &dept)
{
	this->dept = dept;
}
void Staff::setpos(const string &pos)
{
	this->position = pos;
}
void Staff::setmail(const string &mail)
{
	this->mail = mail;
}


//Implements of getter methods
string Staff::getname()
{
	return name;
}
string Staff::getid()
{
	return id;
}
string Staff::getdept()
{
	return dept;
}
string Staff::getpos()
{
	return position;
}
string Staff::getmail()
{
	return mail;
}
