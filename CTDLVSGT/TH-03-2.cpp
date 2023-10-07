#include<iostream>
#include <stdlib.h>
using namespace std;


void readArray(int a[], int *n, char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        cout<<"Không thể mở tệp"<< filename<<endl;
        exit(1);
    }
    *n = 0;
    while (fscanf(f, "%d", &a[*n]) == 1)
    {
        (*n)++;
    }
    fclose(f);
}


void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x) // tăng dần
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}
int main()
{

}