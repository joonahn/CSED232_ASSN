#include "FacultyList.h"
#include "StaffList.h"
#include "StudentList.h"
#include "stdafx.h"


#define BUFFERSIZE 255
enum {FACULTY = 1, STAFF, STUDENT};


int main()
{
	int index = -1;
	//List of data
	FacultyList facultylist;
	StaffList stafflist;
	StudentList studentlist;
	do
	{
		//Print Menu
		cout<<"0. ������ ���� �ε�"<<endl;
		cout<<"1. ��ü ������ ��ȸ"<<endl;
		cout<<"2. �а�(�μ�) ������ ��ȸ"<<endl;
		cout<<"3. �̸����� �˻�"<<endl;
		cout<<"4. ID�� �˻�"<<endl;
		cout<<"5. ������ �߰�"<<endl;
		cout<<"6. ������ ���� ����"<<endl;
		cout<<"7. ������ ���� ����"<<endl;
		cout<<"8. ������ ��� ����"<<endl;
		cout<<"9. ���α׷� ����"<<endl;
		cout<<">>";
		cin>>index;
		
		switch(index)
		{
		case 0:
			{
				string filename, name, id, dept, position, mail;
				char inputstring[BUFFERSIZE], *ptr;
				int party = 0, people = 0;

				//Input
				cout<<"���� �̸� �Է� : ";
				cin>>filename;

				//File open
				ifstream infile(filename.c_str(), ios::in);
				if(!infile)
				{
					cout<<"������ �������� �ʽ��ϴ�!"<<endl;
					break;
				}

				//Init Lists
				facultylist.RemoveAll();
				stafflist.RemoveAll();
				studentlist.RemoveAll();

				//Parsing
				while(infile.getline(inputstring, BUFFERSIZE-1))
				{	
					//To remove carrage return caracter in linux
					if(strlen(inputstring)>0 && inputstring[strlen(inputstring)-1]=='\r')
						inputstring[strlen(inputstring)-1]=0;
					if(strcmp(inputstring,"-����")==0)
					{
						party = FACULTY;
						continue;
					}
					else if(strcmp(inputstring,"-����")==0)
					{
						party = STAFF;
						continue;
					}
					else if(strcmp(inputstring,"-�л�")==0)
					{
						party = STUDENT;
						continue;
					}
					else
					{
						//Parsing Data & Copy
						ptr = strtok(inputstring," ");
						name.assign(ptr);
						ptr = strtok(NULL," ");
						id.assign(ptr);
						ptr = strtok(NULL," ");
						dept.assign(ptr);
						ptr = strtok(NULL," ");
						position.assign(ptr);
						ptr = strtok(NULL," ");
						mail.assign(ptr);
						if(party == FACULTY)
							facultylist.Add(id, name, dept, position, mail);
						else if (party == STAFF)
							stafflist.Add(id, name, dept, position, mail);
						else if(party == STUDENT)
							studentlist.Add(id, name, dept, position, mail);
						people++;
					}

				}
				//print Results
				cout<<people<<"���� ������ �ε��Ͽ����ϴ�!"<<endl;
				infile.close();
			}
			break;
		case 1:
			//query entire member
			facultylist.InquireAll();
			cout<<endl;
			stafflist.InquireAll();
			cout<<endl;
			studentlist.InquireAll();
			break;
		case 2:
			//Search by dept name
			{
				string dept;
				int people = 0;
				cout<<"�а�(�μ�) �Է� : ";
				cin>>dept;
				people = facultylist.InquireByDept(dept);
				people += stafflist.InquireByDept(dept);
				people += studentlist.InquireByDept(dept);
				if(people==0) cout<<"�ش� �а�(�μ�)�� ����� �������� �ʽ��ϴ�!"<<endl;
			}
			break;
		case 3:
			//Search by name
			{
				string name;
				int people = 0;
				cout<<"�̸� �Է� : ";
				cin>>name;
				people = facultylist.InquireByName(name);
				people += stafflist.InquireByName(name);
				people += studentlist.InquireByName(name);
				if(people==0)
					cout<<"�ش� �̸��� ����� �������� �ʽ��ϴ�!"<<endl;
			}
			break;
		case 4:
			//Search by id
			{
				string id;
				int people = 0;
				cout<<"ID �Է� : ";
				cin>>id;
				people = facultylist.InquireByID(id);
				people += stafflist.InquireByID(id);
				people += studentlist.InquireByID(id);
				if(people==0)
					cout<<"�ش� ID�� ����� �������� �ʽ��ϴ�!"<<endl;
			}
			break;
		case 5:
			//Add member data
			{
				int party;
				string  id, name, dept, position, mail;
				cout<<"������ �Ҽ� ����(1.���� 2.���� 3.�л�): ";
				cin>>party;
				cout<<"ID �Է�: ";
				cin>>id;
				cout<<"�̸� �Է�: ";
				cin>>name;
				cout<<"�а�(�μ�) �Է�: ";
				cin>>dept;
				cout<<"���� �Է�: ";
				cin>>position;
				cout<<"���� �Է�: ";
				cin>>mail;
				if(party == FACULTY)
				{
					if(!facultylist.Add(id, name, dept, position, mail))
						cout<<"�̹� ���� ID�� �����մϴ�!"<<endl;
				}
				else if(party == STAFF)
				{
					if(!stafflist.Add(id, name, dept, position, mail))
						cout<<"�̹� ���� ID�� �����մϴ�!"<<endl;
				}
				else if(party == STUDENT)
				{
					if(!studentlist.Add(id, name, dept, position, mail))
						cout<<"�̹� ���� ID�� �����մϴ�!"<<endl;
				}
				else
				{
					cout<<"�߸��� �Ҽ��Դϴ�!"<<endl;
				}
			}
			break;
		case 6:
			//Modify member data
			{
				string  id, name, dept, position, mail;
				cout<<"ID �Է�: ";
				cin>>id;
				cout<<"�̸� �Է�: ";
				cin>>name;
				cout<<"�а�(�μ�) �Է�: ";
				cin>>dept;
				cout<<"���� �Է�: ";
				cin>>position;
				cout<<"���� �Է�: ";
				cin>>mail;
				if(facultylist.Modify(id, name, dept, position, mail))
					cout<<"���� �Ϸ�!"<<endl;
				else if(stafflist.Modify(id, name, dept, position, mail))
					cout<<"���� �Ϸ�!"<<endl;
				else if(studentlist.Modify(id, name, dept, position, mail))
					cout<<"���� �Ϸ�!"<<endl;
				else
					cout<<"��ġ�ϴ� ID�� ã�� �� �����ϴ�"<<endl;
			}
			break;
		case 7:
			//delete member data
			{
				string id;
				cout<<"ID �Է�: ";
				cin>>id;
				if(facultylist.Delete(id))
					cout<<"���� �Ϸ�!"<<endl;
				else if(stafflist.Delete(id))
					cout<<"���� �Ϸ�!"<<endl;
				else if(studentlist.Delete(id))
					cout<<"���� �Ϸ�!"<<endl;
				else
					cout<<"��ġ�ϴ� ID�� ã�� �� �����ϴ�"<<endl;
				
			}
			break;
		case 8:
			//saving to file
			{
				string filename;
				cout<<"���� �̸� �Է�: ";
				cin>>filename;
				ofstream outfile(filename.c_str());
				if(!outfile)
				{
					cout<<"File Open Error"<<endl;
					break;
				}
				outfile<<"-����"<<endl;
				facultylist.SaveFile(outfile);
				outfile<<"-����"<<endl;
				stafflist.SaveFile(outfile);
				outfile<<"-�л�"<<endl;
				studentlist.SaveFile(outfile);
				cout<<"���� �Ϸ�!"<<endl;
				outfile.close();
			}
			break;
		case 9:
			break;
		default:
			{
				//Wrong input
				cout<<"�߸��� �Է��Դϴ�!"<<endl;
			}
			break;
		}
		cout<<endl;
	}while(index!=9);
	return 0;
}
