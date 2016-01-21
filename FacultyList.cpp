#include "FacultyList.h"

//Constructor & Destructor
FacultyList::FacultyList()
{
	num = 0;
	length = 10;
	head = new Faculty[length];
}

FacultyList::~FacultyList()
{
	delete []head;
}

//Increase
bool FacultyList::Increase()
{
	length *= 2;
	Faculty *tmpFaculty = new Faculty[length];
	//Copy Data one-by-one
	for(int i=0;i<num;i++)
	{
		tmpFaculty[i] = head[i];
	}
	delete []head;
	head = tmpFaculty;
	return true;
}

//Remove All the data
void FacultyList::RemoveAll()
{
	num = 0;
	length = 10;
	delete []head;
	head = new Faculty[length];
}

//Show All the Data
int FacultyList::InquireAll()
{
	for(int i=0;i<num;i++)
	{
		head[i].inquire();
	}
	return 0;
}

//Search by dept name
int FacultyList::InquireByDept(const string& dept)
{
	int count = 0;
	for(int i=0;i<num;i++)
	{
		if(head[i].getdept() == dept)
		{
			head[i].inquire();
			count++;
		}
	}
	return count;
}			

//Search by name
int FacultyList::InquireByName(const string& name)
{
	int count = 0;
	for(int i=0;i<num;i++)
	{
		if(head[i].getname() == name)
		{
			head[i].inquire();
			count++;
		}
	}
	return count;
}

//Search by ID
int FacultyList::InquireByID(const string& id)
{
	int count = 0;
	for(int i=0;i<num;i++)
	{
		if(head[i].getid() == id)
		{
			head[i].inquire();
			count++;
		}
	}
	return count;
}

//Add member Data
bool FacultyList::Add(const string& id, const string& name, const string& dept, const string& pos, const string& mail)
{
	for(int i=0;i<num;i++)
	{
		if(head[i].getid() == id)
		{
			return false;
		}
	}

	if(num+1>length)
	{
		bool result
			= FacultyList::Increase();
		if(!result)
			return false;
	}
	head[num].setid(id);
	head[num].setname(name);
	head[num].setdept(dept);
	head[num].setpos(pos);
	head[num].setmail(mail);
	num++;
	return true;
}
//Modify Member Data
bool FacultyList::Modify(const string& id, const string& name, const string& dept, const string& pos, const string& mail)
{
	for(int i=0;i<num;i++)
	{
		if(head[i].getid() == id)
		{
			head[i].setname(name);
			head[i].setdept(dept);
			head[i].setpos(pos);
			head[i].setmail(mail);
			return true;
		}
	}
	return false;
}
//Delete Member Data
bool FacultyList::Delete(const string& id)
{
	for(int i=0;i<num;i++)
	{
		if(head[i].getid() == id)
		{
			for(int j=i;j<num-1;j++)
			{
				head[j] = head[j+1];
			}
			num--;
			return true;
		}
	}
	return false;
}
//Saving to file
bool FacultyList::SaveFile(ofstream& of)
{
	for(int i=0;i<num;i++)
	{
		of<<head[i].getname()<<" "<<head[i].getid()<<" "<<head[i].getdept()<<" "<<head[i].getpos()<<" "<<head[i].getmail()<<endl;
	}
	return true;
}
