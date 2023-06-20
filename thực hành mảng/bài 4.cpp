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

    // nhập 1 số x và tìm mảng có x
    float x;

    printf("Nhập số thực x=");

    scanf("%f", &x);

    printf("Phần tử lớn hơn %6.2f có trong mảng là:",x);

    for (int i = 0; i < n; i++)
        if (a[i] > x)
            printf("\na[%d]=%6.2f", i, a[i]);
  
}