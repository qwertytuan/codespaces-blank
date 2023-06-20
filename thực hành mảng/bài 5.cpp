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
// sort mảng lấy a[0] vs a[n-1]
  for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                float x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
    // in mảng tăng
    for (int i = 0; i < n; i++)
        printf("%6.2f", a[i]);
    // in max,min
    printf("\nmax=%6.2f\n", a[n-1]);
    printf("min=%6.2f\n", a[0]);
}

