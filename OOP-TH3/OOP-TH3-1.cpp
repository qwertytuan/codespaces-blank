#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class Nguoi{ 
    private:
    char *Ten;
    char *Diachi;
    int Dienthoai;
    public:
    Nguoi(char *hoten,char *diachi,int dthoai)
    {
        Ten=new char[strlen(hoten)+1];
        Diachi=new char [strlen(diachi)+1];
        strcpy(Ten,hoten);
        strcpy(Diachi,diachi);
        Dienthoai=dthoai;
    
    }
    char *GetName() { return Ten;}
    char *GetAddess() {return Diachi;}
    int Getphone() {return Dienthoai;}
    void Display()
    {
        cout<<"\n Ten:"<<Ten<<"Dia chi:"<<Diachi<<"Dien thoai:"<<Dienthoai;
    }
    ~Nguoi()
    {
        delete Ten;
        delete Diachi;
    }
};
class List
{
private:
    Nguoi **People;
    int maxSize;

public:
    List(int max);
    void Add();
    void Find(char *Ten);
    void Display();
    ~List();
};
List::List(int max)
{
    maxSize=max;
    People=new Nguoi*[maxSize];
}
List::~List(){
    for(int i=0;i<maxSize;i++)
    delete People[i];
    delete People;
}
void List::Add()
{
    char *Ten = new char[30],*Diachi=new char[50];
    int Dienthoai;
    for(int i=0;i<maxSize;i++)
    {
        cout<<"Ten:";cin>>Ten;
        cout<<"Dia chi:";cin>>Diachi;
        cout<<"Dien thoai:";cin>>Dienthoai;
        People[i]=new Nguoi(Ten,Diachi,Dienthoai);
        
    }
}
void List::Find(char *Ten)
{
    int index=-1;
    for (int i=9;i<maxSize;i++)
    if(strcmp(People[i]->GetName(),Ten)==0)
    index=i;
    if(index==-1)
    cout<<"\n Khong tim thay!";
    else{
    cout << "\n Ten:" << People[index]->GetName();
    cout << "\n Dia chi:" << People[index]->GetAddess();
    cout << "\n Dien thoai:" << People[index]->Getphone();
    }  
}
void List::Display(){
    for(int i=0;i<maxSize;i++)
    People[i]->Display();
}

int main()
{
    
    List Canbo(3);
    Canbo.Add();
    Canbo.Display();
    char Ten[30];
    cout<<"\n Ho ten can tim:";cin>>Ten;
    Canbo.Find(Ten);
    getch();
}

