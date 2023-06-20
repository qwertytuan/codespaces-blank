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
    // tìm max

    float max = a[0];

    int idx1 = 0;

    for (int i = 0; i < n; i++)

        if (max < a[i])

        {
            max = a[i];

            idx1 = i;
        }
    // tìm min

    float min = a[0];

    int idx2 = 0;

    for (int i = 0; i < n; i++)

        if (min > a[i])

        {
            min = a[i];

            idx2 = i;
        }
    // in max,min

    printf("Max=%6.2f,Vị trí=%d\n", max, idx1);

    printf("Min=%6.2f,Vị trí=%d\n", min, idx2);
}