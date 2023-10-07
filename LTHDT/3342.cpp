#include<iostream>
using namespace std;
class MyDate
{
    private:
    int d,m,y;
    public:
    MyDate(int d=1,int m=1,int y=1990)
    {this->d=d;this->m=m;this->y=y;}
    void set(int d,int m,int y)
    {
        this->d=d;this->m=m;this->y=y;
    }
    void display()
    {
        cout<<"\n dd-mm-yy:"<<d<<"-"<<m<<"-"<<y;
    }
    friend int operator>(MyDate t1,MyDate t2);
};

int operator >(MyDate t1,MyDate t2)
{
    if(t1.y>t2.y) return 1;
    if((t1.y==t2.y) && (t1.m>t2.m)) return 1;
    if((t1.y==t2.y) && (t1.m>t2.m) &&(t1.d>t2.d)) return 1;
    return 0;
}
int main()
{
    
    int n;
    cout<<"Nhap n:";cin>>n;
    MyDate **a=new MyDate*[n];
    for(int i=0;i<n;i++)
    {
        int d,m,y;
        cout<<"Nhap dd-mm-yy:";cin>>d>>m>>y;
        a[i]=new MyDate(d,m,y);
       
    }
}