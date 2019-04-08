#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class acc
{
    int n;
    char name[100];
    int dep;
    char type;
public:
    void create_account();
    void depo(int);
    int return_acc() const;
};

void acc::create_account()
{
    cout<<"\nEnter The Account Number :";
    cin>>n;
    cout<<"\n\nEnter Name of The Account Holder : ";
    cin.ignore();
    cin.getline(name,100);
    cout<<"\nEnter Type of Account(c-Current/s-Savings) : ";
    cin>>type;
    cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
    cin>>dep;
    cout<<"\n\n\nCongrats Account Has Been Created..";
}
int acc::return_acc() const
{
    return n;
}

void write_acc()
{
    acc ac;
    ofstream x;
    x.open("info.dat",ios::binary|ios::app);
    ac.create_account();
    x.write(reinterpret_cast<char *> (&ac), sizeof(acc));
    x.close();
}


void acc::depo(int x)
{
    dep+=x;
}

//void intro()
//{
//    cout<<"\n\n\n\tWelcome To AB BANK MANAGEMENT SYSTEM";
//    cout<<"\nPress Enter To Continue........";
//    cin.get();
//}

int main()
{

    cout<<"\n\n\n\tWelcome To AB BANK MANAGEMENT SYSTEM";
    cout<<"\nPress Enter To Continue........";
    cin.get();
    char ch;
    int num;
    do
    {
        system("cls");
        cout<<"\n\n\n\t MENU";
        cout<<"\n\n\t01. NEW ACCOUNT";
        cout<<"\n\n\t02. DEPOSIT";
        cout<<"\n\n\t03. WITHDRAW";
        cout<<"\n\n\t04. BALANCE ENQUIRY";
        cin>>ch;
        switch(ch)
        {
        case '1':
            system("cls");
            write_acc();
            break;
        case '2':
            system("cls");
            cout<<"\n\n\tEnter The Account Number : ";
            cin>>num;
            //dep_withdraw(num, 1);
            break;
        case '3':
            system("cls");
            cout<<"\n\n\tEnter The Account Number : ";
            cin>>num;
            //dep_withdraw(num, 2);
            break;
        }
        cin.ignore();
        cin.get();
    }
    while(ch!='8');
    return 0;
}
