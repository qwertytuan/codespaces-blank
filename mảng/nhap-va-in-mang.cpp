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
    // in mảng ra màn hình
    printf("Mảng đã nhập:\n");
    for (int i = 0; i < n; i++)
        printf("a[%d]=%6.2f\n", i, a[i]);
    // giá trị trung bình
    float s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    printf("Trung bình của a[i]=%6.2f", s / n);
}