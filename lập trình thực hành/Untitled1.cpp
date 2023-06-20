#include<stdio.h>
int main()
{
	while(true){
	
	int x,y,z,n;
		x=0;
		y=1;
		printf("nhap n:");
		scanf("%d",&n);
for(int i=1;i<=246;i++)
	{
		z=x+y;
		x=y;
		y=z;
		printf("day fibonaci:%d\n",x);
		if(x>n)
		{
			break;
		}
	}
	if(n>20000){break;
	}
}

 } 


