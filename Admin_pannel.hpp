#include<iostream>
#include"USER.h"

using namespace std;

//***************************************************************
//           FUNCTION FOR ADMIN PANNEL TO MODIFY USERS DATA
//****************************************************************

void admin_pannel(User &A)
{
    char Password[11];
    int tries=0;

    while(1)
    {
        tries++;
        system("cls");
    cout<<"Enter The admin Password To get access:";
    cout<<"Enter your password(Max length 10):";
		char ch;
		int characterposition=0;
			while(1)
            {
			    ch= getch();
			if(ch==32||ch==9)
            {
				continue;
			}
            else if(ch==13)
            {
				break;
			}
            else if(ch==8)
            {
				if(characterposition>0)
                {
				  characterposition--;
				  Password[characterposition]='\0';
				  cout<<"\b \b";
                }
			}
            else if(characterposition<10)
                {
					Password[characterposition]=ch;
					characterposition++;
					cout<<"*";
				}
            else 
                {
					cout<<"\n Your password length exceeds max password length so only first 10 characters will be stored";
					break;
				}
			}
		
		Password[characterposition]='\0';
        if((strcmp(Password,A.retadminpass()))==0)
        {
            break;
        }
        else
        {
            cout<<"\n\t\t Wrong Password...."<<endl;
            system("pause");
            if(tries>=3)
            {
                return;
            }
        }
    }
    system("cls");
    char a;
    while(a!=4)
    {
        system("cls");
    cout << "\t\t\t Welcome To Admin Pannel:" << endl;    
    cout << "\t\t\t 1.Show All User Data" << endl;
    cout << "\t\t\t 2.Modify Any n User" << endl;
    cout << "\t\t\t 3.Change Admin Password" << endl;
    cout << "\t\t\t 4.Go Back" << endl;
    
    a=getch();
    system("cls");
    
    if(a=='1')
    {
       Display_all(A);
       system("pause");
    }
    else if(a=='2')
    {
        char s[20];
        cin >> s;
        Modify_User(s,A);
    }
    else if(a=='3')
    {
        Modify_adminpass(A);
        system("pause");
    }
    else
    {
        break;
    }
    
}}