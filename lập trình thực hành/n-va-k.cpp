#include<stdio.h>
int main()
{
  int n,k;
  do
  {
    printf("Nhap n:");
    scanf("%d",&n);
    if(n<0)
    printf("n phai >=0.Nhap lai!\n");
  }while(n<0);
   do
  {
    printf("Nhap k:");
    scanf("%d",&k);
    if(k>n||k<0)
    printf("0<=k<=%d.Nhap lai!\n",n);
  }while(k>n||k<0);
  
}