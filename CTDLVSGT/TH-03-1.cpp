#include <iostream>
using namespace std;

void Selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
        swap(a[i], a[min]);
    }
}
void inputarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }
    cout << "\n";
}
int main()
{
    int n;
    cout << "Nhap n:";
    cin >> n;
    int a[n];
    inputarray(a, n);
    cout << "mang goc: ";
    printArray(a, n);
    Selectionsort(a, n);
    cout << "mang sau khi sap lai: ";
    printArray(a, n);
}
