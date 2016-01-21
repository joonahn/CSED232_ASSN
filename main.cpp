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
		cout<<"0. 구성원 파일 로드"<<endl;
		cout<<"1. 전체 구성원 조회"<<endl;
		cout<<"2. 학과(부서) 구성원 조회"<<endl;
		cout<<"3. 이름으로 검색"<<endl;
		cout<<"4. ID로 검색"<<endl;
		cout<<"5. 구성원 추가"<<endl;
		cout<<"6. 구성원 정보 수정"<<endl;
		cout<<"7. 구성원 정보 삭제"<<endl;
		cout<<"8. 구성원 목록 저장"<<endl;
		cout<<"9. 프로그램 종료"<<endl;
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
				cout<<"파일 이름 입력 : ";
				cin>>filename;

				//File open
				ifstream infile(filename.c_str(), ios::in);
				if(!infile)
				{
					cout<<"파일이 존재하지 않습니다!"<<endl;
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
					if(strcmp(inputstring,"-교원")==0)
					{
						party = FACULTY;
						continue;
					}
					else if(strcmp(inputstring,"-직원")==0)
					{
						party = STAFF;
						continue;
					}
					else if(strcmp(inputstring,"-학생")==0)
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
				cout<<people<<"명의 정보를 로드하였습니다!"<<endl;
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
				cout<<"학과(부서) 입력 : ";
				cin>>dept;
				people = facultylist.InquireByDept(dept);
				people += stafflist.InquireByDept(dept);
				people += studentlist.InquireByDept(dept);
				if(people==0) cout<<"해당 학과(부서)의 사람이 존재하지 않습니다!"<<endl;
			}
			break;
		case 3:
			//Search by name
			{
				string name;
				int people = 0;
				cout<<"이름 입력 : ";
				cin>>name;
				people = facultylist.InquireByName(name);
				people += stafflist.InquireByName(name);
				people += studentlist.InquireByName(name);
				if(people==0)
					cout<<"해당 이름의 사람이 존재하지 않습니다!"<<endl;
			}
			break;
		case 4:
			//Search by id
			{
				string id;
				int people = 0;
				cout<<"ID 입력 : ";
				cin>>id;
				people = facultylist.InquireByID(id);
				people += stafflist.InquireByID(id);
				people += studentlist.InquireByID(id);
				if(people==0)
					cout<<"해당 ID의 사람이 존재하지 않습니다!"<<endl;
			}
			break;
		case 5:
			//Add member data
			{
				int party;
				string  id, name, dept, position, mail;
				cout<<"구성원 소속 선택(1.교수 2.직원 3.학생): ";
				cin>>party;
				cout<<"ID 입력: ";
				cin>>id;
				cout<<"이름 입력: ";
				cin>>name;
				cout<<"학과(부서) 입력: ";
				cin>>dept;
				cout<<"직급 입력: ";
				cin>>position;
				cout<<"메일 입력: ";
				cin>>mail;
				if(party == FACULTY)
				{
					if(!facultylist.Add(id, name, dept, position, mail))
						cout<<"이미 같은 ID가 존재합니다!"<<endl;
				}
				else if(party == STAFF)
				{
					if(!stafflist.Add(id, name, dept, position, mail))
						cout<<"이미 같은 ID가 존재합니다!"<<endl;
				}
				else if(party == STUDENT)
				{
					if(!studentlist.Add(id, name, dept, position, mail))
						cout<<"이미 같은 ID가 존재합니다!"<<endl;
				}
				else
				{
					cout<<"잘못된 소속입니다!"<<endl;
				}
			}
			break;
		case 6:
			//Modify member data
			{
				string  id, name, dept, position, mail;
				cout<<"ID 입력: ";
				cin>>id;
				cout<<"이름 입력: ";
				cin>>name;
				cout<<"학과(부서) 입력: ";
				cin>>dept;
				cout<<"직급 입력: ";
				cin>>position;
				cout<<"메일 입력: ";
				cin>>mail;
				if(facultylist.Modify(id, name, dept, position, mail))
					cout<<"수정 완료!"<<endl;
				else if(stafflist.Modify(id, name, dept, position, mail))
					cout<<"수정 완료!"<<endl;
				else if(studentlist.Modify(id, name, dept, position, mail))
					cout<<"수정 완료!"<<endl;
				else
					cout<<"일치하는 ID를 찾을 수 없습니다"<<endl;
			}
			break;
		case 7:
			//delete member data
			{
				string id;
				cout<<"ID 입력: ";
				cin>>id;
				if(facultylist.Delete(id))
					cout<<"삭제 완료!"<<endl;
				else if(stafflist.Delete(id))
					cout<<"삭제 완료!"<<endl;
				else if(studentlist.Delete(id))
					cout<<"삭제 완료!"<<endl;
				else
					cout<<"일치하는 ID를 찾을 수 없습니다"<<endl;
				
			}
			break;
		case 8:
			//saving to file
			{
				string filename;
				cout<<"파일 이름 입력: ";
				cin>>filename;
				ofstream outfile(filename.c_str());
				if(!outfile)
				{
					cout<<"File Open Error"<<endl;
					break;
				}
				outfile<<"-교원"<<endl;
				facultylist.SaveFile(outfile);
				outfile<<"-직원"<<endl;
				stafflist.SaveFile(outfile);
				outfile<<"-학생"<<endl;
				studentlist.SaveFile(outfile);
				cout<<"저장 완료!"<<endl;
				outfile.close();
			}
			break;
		case 9:
			break;
		default:
			{
				//Wrong input
				cout<<"잘못된 입력입니다!"<<endl;
			}
			break;
		}
		cout<<endl;
	}while(index!=9);
	return 0;
}
