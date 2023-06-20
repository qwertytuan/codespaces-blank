#include<stdio.h>
#include<stdlib.h>

int main()
{
    float a[100];
    int n;
    printf("\n nhap n=");
    scanf("%d",&n);
    float *p=a;
    for(int i=0;i<n;i++)
    {
        printf("\n Nhap a[%d]=",i);
        scanf("%f",p+i);
    }
    float s=0;
    for (int i=0;i<n;i++)
    s=s+a[i];
    printf("\n cac phan tu da nhap:");
    for(int i=0;i<n;i++)
    printf("%6.2f",*(p+i));


}
