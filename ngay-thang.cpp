#include<stdio.h>
int main()
{
    int ngay,thang,nam;
    printf("nhap thang:");
    scanf("%d",&thang);
    printf("nhap nam:");
    scanf("%d",&nam);
    switch(thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    ngay=31;
    case 2:
    ngay=28;
    case 4:
    case 6:
    case 9:
    case 11:
    ngay=30;
    }
    int a,b;
    a=nam%10;
    b=nam/10%10;
    if((a+b)%4==0)
    {
        switch(thang)
        {
        case 2:
        ngay=29;
        }
    }
printf("thang %d cua nam %d co %d ngay",thang,nam,ngay);
}