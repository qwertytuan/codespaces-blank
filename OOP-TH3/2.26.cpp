#include<iostream>
#include<conio.h>
using namespace std;

class vector{
    private:
    int n;
    float *v;
    public:
    vector(int size=0)
    {
        n=size;
        v=new float[n];

    }
    vector(const vector &a);
    void operator=(const vector &a);
    void nhap();
    void display();
    friend vector operator+(const vector &a,const vector &b);
   ~vector(){delete v;}
};
vector::vector(const vector &a)
{
    v= new float[a.n];
    n=a.n;
    for(int i=0;i<a.n;i++)
    v[i]=a.v[i];
}
void vector::display()
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
        cout<<"\n";
}

void vector::nhap()
{
    for (int i=0;i<n;i++)
    {
        cout<<"v["<<i<<"]=";
        cin>>v[i];
    }
}


void vector::operator=(const vector &a)
{
    delete v;
    n=a.n;
    v=new float[n];
    for(int i=0;i<n;i++)
    v[i]=a.v[i];
}

 vector operator+(const vector &a,const vector &b)
{
    vector c(a.n);
    for(int i=0;i<a.n;i++)
    c.v[i]=a.v[i]+b.v[i];
    return c;
}

int main()
{
    vector x(3);
    x.nhap();
    x.display();
    vector y(3);
    y.nhap();
    y.display();
    vector z;
    cout<<"\nTong la:\n";
    z=x+y;
    z.display();
    
}