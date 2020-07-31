
#include <fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include <iomanip>
#include <iostream>
#include<windows.h>
#include"USER.h"
#include"student.hpp"
#include"book.hpp"
#include"filing.hpp"

using namespace std;

//***************************************************************
//                    FUCTION TO CALL LIBRARY
//****************************************************************
void library()
{
	char ch;
	system("cls");
	cout <<"                                                 ******" << endl;
    cout <<"                                                *********" << endl;
    cout <<"                                               ***********" << endl;
    cout <<"                                              ****    ****" << endl;
    cout <<"                                              ***"        << endl;
    cout <<"                                              ***"     << endl;
    cout <<"                                              ***      ******************" << endl;
    cout <<"                                              ***      ******************" << endl;
    cout <<"                                              ***         **      ******" << endl;
    cout <<"                                              ****       ***     ******" << endl;
    cout <<"                                               ***********    ******" << endl;
    cout <<"                                                  ******    *******"  << endl;
    cout <<"                                                          ***************" << endl;
    cout <<"                                                          ***************" <<  endl;
    cout << endl;
    cout << "                                            WELCOME TO GEEKZILLA LIBRARY MANAGEMENT SYSTEM!" << endl;

	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. BOOK ISSUE";
		cout<<"\n\n\t02. BOOK DEPOSIT";
	  	cout<<"\n\n\t03. ADMINISTRATOR MENU";
		cout<<"\n\n\t04. LIST ALL BOOKS";
	  	cout<<"\n\n\t05. EXIT";
	  	cout<<"\n\n\tPlease Select Your Option (1-5) ";
	  	ch=getche();
	  	switch(ch)
	  	{ 
			case '1':system("cls");
				 book_issue();
			   	 break;
		  	case '2':book_deposit();
			    	 break;
		  	case '3':
			  system("cls");
			  cout<<"Enter your admin password(Max length 10):";
		     char ch;
		     int characterposition;
			 characterposition=0;
		     char Password[10];
			while(1){
			ch= getch();
			if(ch==32||ch==9){
				continue;
			}else if(ch==13){
				break;
			}else if(ch==8){
				if(characterposition>0){
				characterposition--;
				Password[characterposition]='\0';
				cout<<"\b \b";}
			}else if(characterposition<10){
					Password[characterposition]=ch;
					characterposition++;
					cout<<"*";
				}else {
					cout<<"\n Your password length exceeds max password length so only first 10 characters will be stored";
					break;
				}
			}
			Password[characterposition]='\0';
			
			
			if(Password==pass){
				admin_menu();
			}else{
				cout<<endl<<"Wrong Password.......";
				system("pause");
			}
				 break;
		  	case '4':display_allb();
			    break;
			case '5':return;
		  	default :cout<<"\a";
		}
    	}while(ch!='5');
		return ;
}

//***************************************************************
//    		            	END 
//***************************************************************
