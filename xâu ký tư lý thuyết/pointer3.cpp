#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int n;
    printf("Nhap so phan tu n = ");
    scanf("%d", &n);

    int a[n];
    float *p;
    p = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        printf("Nhap so nguyen thu %d = ", i + 1);
        scanf("%f", p + i);
    }

    printf("Cac so nguyen duoc nhap la:\n");
    for (int i = 0; i < n; i++)
        printf("%7.2f", *(p + i));
    return 0;
}