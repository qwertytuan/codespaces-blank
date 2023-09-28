#include<iostream>
using namespace std;

class A{
		int pri;
	public:
		int pub;
		friend void funcA(A);
		friend class B;
        friend void funcB(A);
        friend class C;
};
class B{
	void func(A a){
		cout<<a.pri;
		cout<<a.pub;
	}
};
class C{
	void func(A a){
	cout<<a.pri;
	cout<<a.pub;
	}
};
void funcA(A a){
	cout<<a.pri;
	cout<<a.pub;
}
void funcB(A a){
	cout<<a.pri;
	cout<<a.pub;
}
int main(){}
