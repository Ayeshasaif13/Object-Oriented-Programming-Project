#include<iostream>
#include<string.h>
#include<conio.h>
#include "USER.h"

using namespace std;

//***************************************************************
//                FUNCTION TO CHECK USER CREDENTIALS
//****************************************************************

void Login(User &st,int &check)
{    
     char n[20];
        system("cls");
        cout << "\n\t\t\t Welcome to Gekkzilla" << endl;
        cout << "\n\n\t\t\t Username:";
		cin >> n;

	int flag=0;
	fp.open("User.dat",ios::in);

	while(fp.read((char*)&st,sizeof(User)))
	{
		if((strcmp(st.retname(),n)==0))
		{
			st.decrypt();   
			flag=1;
            break;
		}
	}

	
	fp.close();
	if(flag==0)
	{
    	cout << "\n\t\t\tUser name does not exist" << endl;
		system("pause");
 	    return;
	}
    else if(flag==1)
	{ 
        char Password[11];
        cout << "\n\t\t\tEnter your password(Max length 10):";
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
				   cout << "\b \b";
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
				cout << "\n Your password length exceeds max password length so only first 10 characters will be stored";
				break;
			}
			}
		
		Password[characterposition]='\0';

        if((strcmp(st.retPassword(),Password)==0))
		{
			cout << "\n\t\t\t Login Success:" << endl;
            system("pause");
            check=1;
            return;
		}

		else 
		{
			cout << "\n\t\t\t Password is Incorrect" << endl;
			system("pause");
		}
        }

}

//***************************************************************
//                 FUNCTION TO INITIALIZE LOGIN PANNEL
//****************************************************************

void login_panel(User &A)
{
    char c;
	
      start:
      system("cls");
      cout << "\n\t\t\t Welcome to Gekkzilla" << endl;
      cout << "\t\t1.Login" << endl;
      cout << "\t\t2.Register" << endl;
      cout << "\t\t3.Exit" << endl;
      cout << "\t\t\t Enter your choice:";
      c=getch();

	 if(c=='1')
	  {
              int check=0;
              Login(A,check);

            if(check==0)
			{
                 goto start;
            }              
      }

      else if(c=='2')
	  {
          system("cls");
          A.create_User();
          write_User(A);
          system("pause");
		  goto start;
        
      }
	  else 
	  {
		  exit(1);
	  }
}