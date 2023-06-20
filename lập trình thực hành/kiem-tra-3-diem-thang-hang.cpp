#include<stdio.h>
int main()
{
    int x1 ,y1;

    int x2 ,y2;

    int x3 ,y3;
    
    printf ("Nhap A(x1,y1):");

    scanf ("%d%d" ,&x1 ,&y1);

    printf ("Nhap B(x2,y2):");

    scanf ("%d%d" ,&x2 ,&y2);

    printf ("Nhap C(x3,y3):");

    scanf ( "%d%d" ,&x3 ,&y3);

     int a= x1 * (y2-y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

    if (a == 0)

        printf("3 diem thang hang\n");
    else

        printf("3 diem khong thang hang\n");
}