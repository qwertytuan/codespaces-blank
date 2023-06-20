#include <stdio.h>
int main()
{
    // nhập n mảng
    int n;
    float a[50];
    printf("Nhập n:");
    scanf("%d", &n);
    // nhập giá trị của mảng a[]
    for (int i = 0; i < n; i++)
    {
        printf("nhập a[%d]=", i);
        scanf("%f", &a[i]);
    }
    // tìm x trong mảng
    float x;
    printf("Nhập x cần tìm:");
    scanf("%f", &x);
    int i = 0;
    while ((i < n) && (a[i] != x))
        i++;
    if (i < n)
        printf("x có trong mảng");
    else
        printf("x không có trong mảng");
}