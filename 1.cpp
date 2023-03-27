#include<stdio.h>
int main()
{
    int n;
    do
    {
    printf("nhap n:");
    scanf("%d",&n);
    if(n<100||n>999)
    {
        printf("nhap sai, nhap lai:\n");
    }
    }
    while(n<100||n>999);
    int so_du,thuong=n,tong=0,tich=1;
    do{
        so_du=thuong%10;
        tong+=so_du;
        tich *=so_du;
        thuong=thuong/10;
    }
    while(thuong!=0);
    printf("tong= %d\ntich=%d\n",tong,tich);
}
