#include <stdio.h>
int main()
{

    // nhập n mảng
    int n;
    int a[50];
    printf("Nhập n:");
    scanf("%d", &n);

    // nhập giá trị của mảng a[]
    for (int i = 0; i < n; i++)
    {
        printf("nhập a[%d]=", i);
        scanf("%d", &a[i]);
    }
    
    int s=0;
    printf("\nSo chia het cho 3 trong mang:");
    for(int i=0;i<n;i++){
        if(a[i]%3==0){
        printf("\na[%d]:%d",i,a[i]);
        s=s+a[i];
        }
    }
    printf("\nTong cac so chia het cho 3 trong mang:%d",s);
    
}