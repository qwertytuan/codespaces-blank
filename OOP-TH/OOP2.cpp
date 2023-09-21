#include <iostream>
using namespace std;
void func(int i, int j=0)
{
cout<<"so nguyen :"<<i<<"  "<<j<<"\n";
}
void func(float f=0, float g=0)
{
cout<<"so thuc :"<<f<<"  "<<g<<"\n";
}
int main(){
	int i=1, j=2;
	float f=1.5, g=2.5;
	func();
	func(i);
	func(f);
	func(i,j);
	func(f,g);
}
