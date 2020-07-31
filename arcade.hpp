#include <iostream>
#include"snake.hpp"
#include"pong.hpp"
#include<conio.h>
using namespace std;
//***************************************************************
//                    FUNCTION FOR ARCADE HOMEPAGE
//****************************************************************

void arcade()
{
     while(1)
     {
         system("cls");
         cout<<"\t\t\t Welcome To GEEKZILLA Arcade:"<<endl;
         cout<<"\t\t 1.Play Snake Game:"<<endl;
         cout<<"\t\t 2.Play Pong Game"<<endl;
         cout<<"\t\t 3.Exit"<<endl;
         char a;
         a=getch();
         if(a=='1')
         {
            system("cls");
            game1();
         }
         else if(a=='2')
         {
             system("cls");
             pong();
         }
         else
         {
             break;
         }
     }
     
   return;
}