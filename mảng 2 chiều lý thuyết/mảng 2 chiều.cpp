#include <stdio.h>
int main()
{

    // nhập d,c mảng
    int d, c;
    int a[30][30];
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
        }
        //in mảng
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}