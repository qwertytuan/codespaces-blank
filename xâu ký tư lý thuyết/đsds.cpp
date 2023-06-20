#include<stdio.h>
int main()
{
    char str[2560000];
    printf("\nNhập xâu:");
    fgets(str, sizeof(str), stdin); 
    printf(" %s",str);
}