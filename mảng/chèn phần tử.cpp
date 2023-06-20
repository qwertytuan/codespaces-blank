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

    //chèn phần tử x vào vị trí k
    float x;

    int k;

    printf("Nhập vị trí cần chèn:");

    scanf("%d", &k);

    printf("Nhập giá trị cần chèn:");

    scanf("%f", &x);

    if (k == n)
        a[n] = x;
    else
    {
        for (int i = n; i > k; i--)
            a[i] = a[i - 1];
        a[k] = x;
    }
    for (int i = 0; i < n; i++)
        printf("%6.2f", a[i]);
}