#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char Name[5000];
    int Age;
    float Score;
} student;

void InputStudent(student sv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("+ Name: ");
        fflush(stdin);
        gets(sv[i].Name);
        printf("\n+ Age: ");
        scanf("%d", &sv[i].Age);
        printf("+ Score: ");
        scanf("%f", &sv[i].Score);
    }
}

void PrintStudent(student sv[], int n)
{
    printf("Danh sach sinh vien duoc nhap la:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s, %d, %5.2f\n", i + 1, sv[i].Name, sv[i].Age, sv[i].Score);
    }
}

int main()
{
    system("cls");

    int n;
    printf("Nhap so sinh vien n = ");
    scanf("%d", &n);

    student sv[n];

    InputStudent(sv, n);
    PrintStudent(sv, n);

    return 0;
}
