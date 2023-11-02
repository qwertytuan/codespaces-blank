#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class Person
{
protected:
    string Name[30];
    string Address[40];
    int Phone;

public:
    Person() {}
    Person(string pName, string pAddress, int pPhone)
    {
        strcpy(Name, pName);
        strcpy(Address, pAddress);
        Phone = pPhone;
    }
};

class Officer:virtual public Person{
    protected:
    float Salary;
    public:
    Officer(){}
 
    Officer(string pName,string pAddress,int pPhone ,float pSalary):Person(pName,pAddress,pPhone){
Salary=pSalary;
};
};

class Student:virtual public Person{
    protected:
    float Fee;
    public:
    Student(){}
    Student(string pName,string pAddress,int pPhone,float pFee):Person(pName,pAddress,pPhone){
        Fee=pFee;
    };
};

class OffStudent:public Officer,public Student{
    public:
    OffStudent(string pName,string pAddress,int pPhone,float pSalary,float pFee):Person(pName,pAddress,pPhone)
    {
        Salary=pSalary;
        Fee=pFee;
    };

    void OutScreen()
    {
        cout<<"\n Name:"<<Name;
        cout<<"\n Address:"<<Address;
        cout<<"\n Phone:"<<Phone;
        cout<<"\n Salary:"<<Salary;
        cout<<"\n Fee:"<<Fee;
    }
};

int main()
{
    OffStudent *p[5];
}
