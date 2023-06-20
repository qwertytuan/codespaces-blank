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

    for (int i = n - 1; i >= 0; i--)
        if (a[i] < 0)
        {
            printf("\na[%d] là số âm cuối cùng", i);
            break;
        }
}