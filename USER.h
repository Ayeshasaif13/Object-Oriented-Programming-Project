#include<iostream>
#include<string.h>
#include<conio.h>
#include <fstream>
#include <cstdio>

using namespace std;

# pragma once

fstream fp,fp1;

//***************************************************************
//                    CLASS FOR USER
//****************************************************************
class User
{
	private:
	 char Password[11];

	protected:
	 char name[20];
     char admin_pass[20];
 

    public:
	 void create_User()
	 {
		 system("cls");
	 	 cout << "\nNEW User ENTRY...\n";
         cout << "\n\nEnter The Name of The User:";
		 cin >> name;
		 cout << "Enter your password(Max length 10):";
		 char ch;
		int characterposition=0;
			while(1)
			{
			   ch= getch();
			  if(ch==32 || ch==9) 
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
					cout << "*";
				}
				 else  
				 {
					cout << "\n Your password length exceeds max password length so only first 10 characters will be stored";
					break;
				 }
			}
		//encryption
		 Password[characterposition]='\0';
		 int len=strlen(Password);
		 for(int i=0;i<len;i++)
		  {
			Password[i]=Password[i]-45;
		  } 
	
		 fflush(stdin);
		 strcpy(admin_pass,"Haris");
		
	}

	inline void show_User()
	{
		cout << "User Name : ";
		puts(name);
		cout << "Password : "<< Password << endl;
		
	}

	void modify_User()
	{
		cout << "\nModify User Name : ";
		cin >> name;
		cout << "Modify Password : ";
		cin >> Password;
	}

	char* retPassword()
	{
		return Password;
	}
    
	char* retname()
	{
        return name;
    }

    char* retadminpass()
	{
		return admin_pass;
	}

	void decrypt()
	{
        int len=strlen(Password);
        for(int i=0;i<len;i++)
		{
			Password[i]=Password[i]+45;
            
		}
		
    }
	
	void encrypt()
	{
		int len=strlen(Password);
		for(int i=0;i<len;i++)
		{
			Password[i]=Password[i]-45;
		}	
	}

	void modify_admin(char* a)
	{
		strcpy(admin_pass,a);
	}
	
};     //class ends here


//***************************************************************
//                    Some Filing Functions
//****************************************************************

void Modify_adminpass(User st)
{
	   char c[20];
	   cout<<"Enter New admin Password:";
	   cin>>c;
	   fp.open("User.dat",ios::in);
	   fp1.open("temp.dat",ios::out|ios::app);
	while(fp.read((char*)&st,sizeof(User)))
	{
			st.modify_admin(c);
		    fp1.write((char*)&st,sizeof(User));
	}
	
	fp.close();
	fp1.close();
	remove("User.dat");
	rename("temp.dat","User.dat");
	cout<<"Modified Admin pass Sucessfully:"<<endl;
	
	}

void write_User(User st)
{
	int check=0;
	char ch;
	User A;
    fp.open("User.dat",ios::in);
	while(fp.read((char*)&A,sizeof(User)))
	{
		if((strcmp(A.retname(),st.retname())==0))
		{
			
			check=1;
            break;
		}
	}
	
	fp.close();
	if(check==1)
    		{
				cout << "\t\t\nUser name already exist" << endl;
			    return;
			}
 	
    cout << "\n\nUser ID Created.." << endl;
	fp.open("User.dat",ios::out|ios::app);
	fp.write((char*)&st,sizeof(User));
    fp.close();
}


void Compare(char n[],User &st)
{
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
    		cout<<"\t\t\\nUser name does not exist"<<endl;
 	
}


void Display_all(User st)
{
    fp.open("User.dat",ios::in);
	while(fp.read((char*)&st,sizeof(User)))
	{
			st.decrypt();
			st.show_User();	
	}
	
	fp.close();
}


void Modify_User(char n[],User st)
{
	int flag=0;
	fp.open("User.dat",ios::in);
	fp1.open("temp.dat",ios::out|ios::app);
	while(fp.read((char*)&st,sizeof(User)))
	{
		if((strcmp(st.retname(),n)==0))
		{
			st.decrypt();
			st.modify_User();
			flag=1;
			st.encrypt(); 
		}
		
		fp1.write((char*)&st,sizeof(User));
	}
	
	fp.close();
	fp1.close();
	remove("User.dat");
	rename("temp.dat","User.dat");
	
	if(flag==0)
    	 cout << "\n\nUser name does not exist" << endl;
    else
	{
		 cout << "Modified Details Sucessfully:" << endl;
	}
	
}
//***************************************************************
//                    END
//****************************************************************