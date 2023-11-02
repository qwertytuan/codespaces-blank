#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class ps
{
    static void ErrorMessage();
    int tu, mau;

public:
    ps(int t = 0, int m = 1)
    {
        tu = t;
        mau = m;
    }
    ps(const ps &other)
    {
        tu = other.tu;
        mau = other.mau;
    }
    friend int operator==(const ps &, const ps &);
    friend int operator!=(const ps &, const ps &);
    friend int operator>(const ps &, const ps &);
    friend int operator>=(const ps &, const ps &);
    friend int operator<(const ps &, const ps &);
    friend int operator<=(const ps &, const ps &);
    friend ps operator+(const ps &, const ps &);
    friend ps operator-(const ps &, const ps &);
    friend ps operator*(const ps &, const ps &);
    friend ps operator/(const ps &, const ps &);
    friend ps toigian(const ps &);

    ps operator+=(const ps &c) { return (*this = *this + c); }
    ps operator-=(const ps &c) { return (*this = *this - c); }
    ps operator*=(const ps &c) { return (*this = *this * c); }
    ps operator/=(const ps &c) { return (*this = *this / c); }

    ps operator++() { return (*this = *this + 1); }
    ps operator--() { return (*this = *this - 1); }

    friend ostream &operator<<(ostream &out, const ps &c);
    friend istream &operator>>(istream &in, ps &c);
};

int operator==(const ps &c1, const ps &c2)
{
    return (c1.tu * c2.mau == c1.mau * c2.tu);
}
int operator!=(const ps &c1, const ps &c2)
{
    return (c1.tu * c2.mau != c1.mau * c2.tu);
}
int operator>(const ps &c1, const ps &c2)
{
    return (c1.tu * c2.mau > c1.mau * c2.tu);
}
int operator>=(const ps &c1, const ps &c2)
{
    return (c1.tu * c2.mau >= c1.mau * c2.tu);
}
int operator<(const ps &c1, const ps &c2)
{
    return (c1.tu * c2.mau < c1.mau * c2.tu);
}
int operator<=(const ps &c1, const ps &c2)
{
    return (c1.tu * c2.mau <= c1.mau * c2.tu);
}

ps operator+(const ps &c1, const ps &c2)
{
    return toigian(ps(c1.tu * c2.mau + c1.mau * c2.tu, c1.mau * c2.mau));
}

ps operator-(const ps &c1, const ps &c2)
{
    return toigian(ps(c1.tu * c2.mau - c1.mau * c2.tu, c1.mau * c2.mau));
}

ps operator*(const ps &c1, const ps &c2)
{
    return toigian(ps(c1.tu * c2.tu, c1.mau * c2.mau));
}

ps operator/(const ps &c1, const ps &c2)
{
    if (c1.mau * c2.tu != 0)
        return toigian(ps(c1.tu * c2.mau, c1.mau * c2.tu));
    else
    {
        ps::ErrorMessage();
        return ps(0, 1);
    }
}

int uscln(int x, int y)
{
    int a = abs(x), b = abs(y);
    if (a == 0)
        return 0;
    while (a != b)
        if (a > b)
            a = a - b ;
            else 
        if (b > a) 
            b = b - a;
    return a;
}

ps toigian(const ps &c){
    int temp=uscln(c.tu,c.mau);
    if (temp!=0)
    return ps(c.tu/temp,c.mau/temp);
    else
    return ps(0,c.mau);
}

ostream & operator<<(ostream & out,const ps &c)
{
    if(c.mau>0)
    out <<c.tu<<"/"<<c.mau;
    else
    out<<-c.tu<<"/"<<-c.mau;
    return out;
}

istream & operator >>(istream & in,ps &c)
{
    cout<<"Tu=";in>>c.tu;
    do{
        cout<<"Mau=";in>>c.mau;
    }while(c.mau==0);
    return in;
}

void ps::ErrorMessage()
{
    cout<<"Divide by zero!";
    getch();
    
}

int main()
{
    ps a,b,c;
    cin>>a; cout<<"a="<<a<<endl;
    cout<<"++a="<<++a<<endl;
    cin>>b; cout<<"b="<<b<<endl;
    cin>>c; cout<<"c="<<c<<endl;
    cout<<"a+b*c+a*c="<<(a+b)*c+a*c<<endl;
    getch();
}
