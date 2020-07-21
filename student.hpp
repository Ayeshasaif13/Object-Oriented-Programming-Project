#include<conio.h>
#include <iomanip>
#include <iostream>
#include"USER.h"
using namespace std;
# pragma once
//***************************************************************
//             	CLASS FOR STUDENT
//****************************************************************
class student:public User
{
	char Roll_number[6];
	char stbno[6];
	int token;
public:
	void create_student()
	{
		system("cls");
	 	cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter Roll number: ";
		cin>>Roll_number;
		fflush(stdin);
		cout<<"\n\nEnter The Name of The Student:";
		cin>>(name);
		token=0;
		stbno[0]='\0';
		cout<<"\n\nStudent Record Created..";
	}

	void show_student()
	{
		cout<<"\n Roll number : "<<Roll_number;
		cout<<"\nStudent Name : ";
		puts(name);
		cout<<"\nNo of Book issued : "<<token;
		if(token==1)
			cout<<"\nBook No "<<stbno;
	}

	void modify_student()
	{
		cout<<"\n Roll number : "<<Roll_number;
		cout<<"\nModify Student Name : ";
		gets(name);
	}

	char* retRoll_number()
	{
		return Roll_number;
	}

	char* retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token=1;}

	void resettoken()
	{token=0;}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{cout<<"\t"<<Roll_number<<setw(20)<<name<<setw(10)<<token<<endl;}

};         
//***************************************************************
//                    END
//****************************************************************