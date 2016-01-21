#include "StaffList.h"


//Constructor & Destructor
StaffList::StaffList()
{
	num = 0;
	length = 10;
	head = new Staff[length];
}

StaffList::~StaffList()
{
	delete []head;
}	

//Increase
bool StaffList::Increase()
{
	length *= 2;
	Staff *tmpStaff = new Staff[length];
	//Copy Data one-by-one
	for(int i=0;i<num;i++)
	{
		tmpStaff[i] = head[i];
	}
	delete []head;
	head = tmpStaff;
	return true;
}

//Remove All the data
void StaffList::RemoveAll()
{
	num = 0;
	length = 10;
	delete []head;
	head = new Staff[length];
}

//Show All the Data
int StaffList::InquireAll()
{
	for(int i=0;i<num;i++)
	{
		head[i].inquire();
	}
	return 0;
}

//Search by dept name
int StaffList::InquireByDept(const string& dept)
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
int StaffList::InquireByName(const string& name)
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
int StaffList::InquireByID(const string& id)
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
bool StaffList::Add(const string& id, const string& name, const string& dept, const string& pos, const string& mail)
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
			= StaffList::Increase();
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
bool StaffList::Modify(const string& id, const string& name, const string& dept, const string& pos, const string& mail)
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
bool StaffList::Delete(const string& id)
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
bool StaffList::SaveFile(ofstream& of)
{
	for(int i=0;i<num;i++)
	{
		of<<head[i].getname()<<" "<<head[i].getid()<<" "<<head[i].getdept()<<" "<<head[i].getpos()<<" "<<head[i].getmail()<<endl;
	}
	return true;
}
