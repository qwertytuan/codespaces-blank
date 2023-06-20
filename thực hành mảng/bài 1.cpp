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

    int i = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == x)
            printf("\na[%d]=%6.2f", i, x);
    while ((i < n) && (a[i] != x))
        i++;
    if (i < n)
        int p = 0;
    else
    {
        printf("x không có trong mảng");
    }
}
