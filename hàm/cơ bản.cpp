#include <stdio.h>
long int gt(int m)
{
    long int g = 1;
    for (int i = 1; i <= m; i++)
        g = g * i;
    return g;y
}
int main()
{
    int n, k;
    printf("\nNhap n:");
    scanf("%d", &n);
    printf("\nNhap k:");
    scanf("%d", &k);
    float c = gt(n) / (gt(k) * gt(n - k));
    printf("ckn=%f", c);
    return 0;
}