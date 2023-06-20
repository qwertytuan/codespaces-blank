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

    // xóa phần tử a[k]
    int k;
    printf("\nNhập vị trí cần xóa:");
    scanf("%d", &k);
    for (int i = k; i < n - 1; i++)
        a[i] = a[i + 1];

    // in
    for (int i = 0; i < n - 1; i++)
        printf("%6.2f", a[i]);
    return 0;
}