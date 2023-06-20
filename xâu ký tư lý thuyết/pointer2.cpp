#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    float *a;
    printf("\n n=");
    scanf("%d", &n);
    // float a[i]= float *a + a = (float *)malloc(n * sizeof(float));
    a = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        printf("Nhap a[%d]=", i);
        scanf("%f", &a[i]);
    }
    printf("Mang da nhap:");
    for (int i = 0; i < n; i++)
        printf("%6.2f", a[i]);
    float s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    printf("\n Trung binh = %6.2f", s / n);
    return 0;
}