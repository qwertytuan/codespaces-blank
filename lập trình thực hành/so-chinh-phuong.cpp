#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("nhap so nguyen:");
    scanf("%d",&n);
    for(int i=0;i<=sqrt(n);i++)
    {
        if(i*i==n)
        printf("%d la so chinh phuong",n);
    }
}