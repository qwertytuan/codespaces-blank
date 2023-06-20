#include <stdio.h>
int main()
{

    // nhập d,c mảng
    int d, c;
    int a[30][30];
    int b[30][30];
    printf("Nhập dòng:");
    scanf("%d", &d);
    printf("Nhập cột:");
    scanf("%d", &c);

    // nhập giá trị của mảng a[i][j]
    for (int i = 0; i < d; i++)
        for (int j = 0; j < c; j++)
        {
            printf("nhập a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
            printf("nhập b[%d][%d]=", i, j);
            scanf("%d", &b[i][j]);
        }
    // in mảng
    printf("Ma trận a:\n");
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("Ma trận b:\n");
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    // tổng 2 ma trận
    printf("Tổng của 2 ma trận:\n");
    printf("Ma trận c:\n");
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", a[i][j] + b[i][j]);
        printf("\n");
    }
    // tích 2 ma trận
    printf("Tích của 2 ma trận:\n");
    for (int i = 0; i < d; i++)

        for (int j = 0; j < c; j++)
        {
            int s[50][50];
            s[i][j] = 0;
            for (int t = 0; t < i; t++)
                s[i][j] += a[i][t] * b[t][j];
        }
}