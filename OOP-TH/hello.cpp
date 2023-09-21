#include<iostream>
using namespace std;
void selection_sort(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int minPos=i;
        for(int j=i+1;j<n;j++)
        if(a[j]<a[minPos])
        minPos=j;
        if(minPos!=i)
        {
            int temp=a[i];
            a[i]=a[minPos];
            a[minPos]=temp;
        }
    }
}
void Display_array(int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;

}
int main()
{
    system("cls");
    int n;
    cout<<"Nhap so phan tu cua mang:";
    cin>>n;
    srand(time(0));
    int a[n];
    for(int i=0;i<n;i++)
    a[i]=rand()%100;
    cout<<"mang duoc tao ra la:\n";
    Display_array(a,n);
    cout<<"\nMang sau khi sap xep: \n";
    selection_sort(a,n);
    Display_array(a,n);
}