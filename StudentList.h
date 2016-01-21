#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "stdafx.h"
#include "Student.h"

class StudentList
{
private:
	Student *head;
	//# of items
	int num;
	//length of array
	int length;
	bool Increase();
public:
	//Constructor & Destructor
	StudentList();
	~StudentList();

	//Inquire Functions
	int InquireAll();
	int InquireByDept(const string &dept);
	int InquireByName(const string &dept);
	int InquireByID(const string &dept);

	//Add member Data
	bool Add(const string& id, const string& name, const string& dept, const string& pos, const string& mail);
	//Modify Member Data
	bool Modify(const string& id, const string& name, const string& dept, const string& pos, const string& mail);
	//Delete Member Data
	bool Delete(const string& id);
	//Remove all data
	void RemoveAll();

	//Saving to file
	bool SaveFile(ofstream& of);
};
#endif
