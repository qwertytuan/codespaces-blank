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
        printf("\nnhập a[%d]=", i);
        scanf("%f", &a[i]);
    }
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            y = y + 1;
    }
    printf("\nSố lượng số dương là:%d\n", y);
    printf("Số lượng số âm là:%d", n - y);
}