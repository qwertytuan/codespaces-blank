#include<iostream>
#include<conio.h>
#include<string.h>
class mayin{
    protected:
    string sohieu[25];
    int soluong;
    public:
    mayin()
    {};
    mayin(string s,int sl=0){strcpy(sohieu,s);soluong=sl;}
    void nhapkho(int sl){soluong+=sl;}
    void xuatkho(int sl){soluong=(soluong>sl)?soluong-sl:0;}
    void baocao(){
        cout<<"May in"<<sohieu<<" ton:"<<soluong<<" chiec\n";
    }
};

class inmau:virtual public mayin{
    protected:
    int bangmau;
    inmau(int bm){bangmau=bm;}
    public:
    inmau
}
