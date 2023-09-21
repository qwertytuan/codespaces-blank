#include<iostream>
using namespace std;

int &fct(int &a, int b){
	b+=a;
	if (b>5) a++;
	return a;
}
int main(){
	int i=2, j=4;
	int k=fct(i,j);
	k++;
	cout<<i<<"  "<<j<<"  "<<k<<"\n";
	int &l=fct(i,j);
	l++;
	cout<<i<<"  "<<j<<"  "<<l<<"\n";
}
