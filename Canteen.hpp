#include<iostream>
#include"USER.h"
#include<string>
#include<string.h>

using namespace std;

//***************************************************************
//                    CLASS FOR CANTEEN ITEMS
//****************************************************************

class items
{
    private:
    string name;
    float price;
    
    public:
    inline void initialize(string n,float f)
    {
       name=n;
       price=f;
    }
     string getname()
     {
         return name;
     }
     float getprice()
     {
         return price;
     }
    inline void modname()
    {
         cout<<"Enter new name of this item:";
         cin >> name;
    }

     inline void modprice()
     {
         cout <<"Enter new price of this item:";
         cin >> price;
     }
};

//***************************************************************
//                    CLASS FOR CANTEEN
//****************************************************************

class Canteen:public User
{
    items A[10];
    int a;
    int order[20][2];
    public:
    Canteen()
    {
        A[0].initialize("Biryani",100);
        A[1].initialize("Zinger Burger",150);
        A[2].initialize("Beef Burger",110);
        A[3].initialize("Beef Pulao",100);
        A[4].initialize("Zinger Roll",100);
        A[5].initialize("Fries",50);
        A[6].initialize("Shake",100);
        A[7].initialize("Cold Drink(500ml)",50);
        A[8].initialize("TEA",30);
        A[9].initialize("Water Bottle",30);
    }

    void Menu()
    {
        cout << "\n\t Welcome to GEEKZILLA Canteen:" << endl;
        cout << "\n\t\t\tMENU" << endl;
        cout << "\t=======\t\t\t========" << endl;
        cout << "\t ITEMS:\t\t\t PRICE:" << endl;
        cout << "\t=======\t\t\t========" << endl;
        for(int i=0;i<5;i++)
        {
        cout << "\t" << i+1 << "." << A[i].getname() << "\t\t" << A[i].getprice() << " RS" << endl;    
        }
        cout << "\t" << "6." << A[5].getname() << "\t\t\t" << A[5].getprice() << " RS" << endl;
        cout << "\t" << "7." << A[6].getname() << "\t\t\t" << A[6].getprice() << " RS" << endl;
        cout << "\t"<<"8." << A[7].getname() << "\t"<<A[7].getprice() << " RS" << endl;
        cout << "\t"<<"9." << A[8].getname() << "\t\t\t"<<A[8].getprice() << " RS" << endl;
        cout << "\t"<<"10." << A[9].getname() << "\t\t" << A[9].getprice() << " RS" << endl;
        cout << "\tPress 0 to Checkout" << endl;
        cout << "\t=======\t\t\t========" << endl;
        
    }

    void Takeorder()
    {
        int c;
        a=0;
        int quantity;
      while(1)
      {
           cout << "Select Options to start adding to your Cart:";
           cin >> c;
           if(c>=0 && c<=10)
           {
           if(c==0)
           { 
               break;
           }
           order[a][0]=c-1;
           cout << " Enter Quantity of " << A[c-1].getname() << ":";
           cin >> quantity;
           order[a][1]=quantity;
           a++;
      }
      else
      {
          cout << "Wrong Input........:(" << endl;
      }

      }
    }

    void Printreceipt(User name)
    {
        float total;
         cout << "\n\t\t\t Thanks for choosing GEEKZILLA Canteen:" << endl;
         cout << "\n\t NAME:" << name.retname() << endl;
         if(a==0)
         {
             system("pause");
             return;
         }
         cout << "\t =========\t\t=========\t\t ========" << endl;
         cout << "\t Youritems\t\t Quantity\t\t Price:" << endl;
         for(int i=0;i<a;i++)
         {
             int x=order[i][0];
             cout << "\t " << A[x].getname() << "\t\t " << order[i][1] << "\t\t\t " << A[x].getprice() << " RS" << endl;
             total+=A[x].getprice();
         }
          cout << "\t =========\t\t=========\t\t ========" << endl;
          cout << "\t\t\t Total="<<total<<" RS" << endl;
          cout << "\t =========\t\t=========\t\t ========" << endl;
          cout << "Now you can Pick your order by showing this receipt to the canteen:" << endl;
          cout << "\t =======\t\t THANK YOU :)\t\t======" << endl;
          system("pause");
    }
};