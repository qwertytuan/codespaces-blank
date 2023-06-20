#include<stdio.h>
#include<math.h>

int main()
{
    int x;
    printf("nhap x:");
    scanf("%d",&x);
    float ex=1;
    int i=1,gt=1;
    while(pow(x,i)/gt>=0.0002)
    {
        ex=ex+pow(x,i)/gt;
        i++;
        gt=gt*i;
    }
    printf("ket qua=%f",ex);
}