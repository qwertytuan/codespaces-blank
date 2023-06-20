#include<stdio.h>
int main()
{
    float diem_tong_ket;

    printf ("Nhap diem tong ket:");

    scanf ("%f",&diem_tong_ket);

    if (diem_tong_ket>=8)
    {
        printf ("Hoc sinh dat loai Gioi");
    }
    else if (diem_tong_ket<8&&diem_tong_ket>=6.5)
    {
        printf ("Hoc sinh dat loai Kha");
    }
    else if (diem_tong_ket<6.5&&diem_tong_ket>=5)
    {
        printf ("Hoc sinh dat loai Trung Binh");
    }
    else
    {
        printf ("Hoc sinh dat loai Yeu");
    }
}