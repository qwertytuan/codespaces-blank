#include<stdio.h>
int main()
{
	long long int x,y,z,n;
		x=0;
		y=1;
		printf("nhap n:");
		scanf("%lli",&n);
for(int i=1;i<=n;i++)
	{
		z=x+y;
		x=y;
		y=z;
		printf("day fibonaci:%lli\n",x);
		if(x>n)
		{
			break;
		}
	}
}

 

