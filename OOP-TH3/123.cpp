#include<iostream>
using namespace std;
class sp{
    private:
    float a,b;
    public:
    sp(float a=0,float b=0)
    { this ->a=a;this->b=b;}
    void add()
    {
        cout<<"\n Phan thuc:"; cin>>a;
        cout<<"\n Phan ao:"; cin>>b;
    }
void display()
{
    cout<<"s="<<a;
    if(b>=0)
    cout<<"+"<<b<<"i";
    else
    cout<<b<<"i";
}
};
int main()
{
   sp s;
    s.display();
}