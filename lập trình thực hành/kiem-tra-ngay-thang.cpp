#include<stdio.h>
int main()
{
    int ngay ,thang ,nam;

    do

    {

    printf("Nhap d:");

    scanf("%d" ,&ngay);

    if ( ngay<=0 || ngay>31) 
 
 printf("Nhap sai! %d khong phai la ngay hop le.\n",ngay); 

 } while ( ngay<=0 || ngay>31);

 do

 {
    printf("Nhap m:");

    scanf("%d" ,&thang);

    if ( thang<=0 || thang>12) 

 printf("Nhap sai! %d khong phai la thang hop le.\n",thang); 

 } while ( thang<=0 || thang>12);
 do

 {
    printf("Nhap y:");

    scanf("%d" ,&nam);

    if (nam <= 0)

 printf ("Nhap sai! %d khong phai la nam hop le.\n",nam);

 } while ( nam<= 0);

}