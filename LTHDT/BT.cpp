#include<iostream>
using namespace std;
class tron{
    private:
    float r;
    public:
    init(float r)
    {
        this -> r=r;
    }
    float dtich()
    {
        return 3.14*r*r;
    }
    float chuvi()
    {
        return 2*3.14*r;
    }
    void display()
    {
        cout<<"Dien tich la:"<<dtich()<<", chu vi la:"<<chuvi();
    }
};
int main()
{
    int n;
    cout<<"Nhap n:"; cin>>n;
    tron *c= new tron[n];
    for(int i=0;i<n;i++)
    {
        float r;
        cout<<"Nhap ban kinh lan vong:" <<i+1<<endl;
        cin>>r;
        c[i].init(r);
    }
    for (int i=0;i<n;i++)
    c[i].display();
}
