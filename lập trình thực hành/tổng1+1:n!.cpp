#include<stdio.h>
int main()
{
    int n,i;
    float tong=0;
    printf("Nhap n:");
    scanf("%d",&n);
    int gt=1;
    for(i=1;i<=n;i++)
    {
        gt=gt*i;
        tong=tong+1.0/gt;
    }
    printf("Tong s=%5.2f",tong);
}