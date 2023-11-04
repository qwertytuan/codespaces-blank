#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct BenhNhan
{
    int mabv;
    char hoten[50];
    float Tuoi;
    char diachi[100];
    struct BenhNhan *next;
};

struct DanhSach
{
   BenhNhan *head;
   BenhNhan *tail;
};
DanhSach ds;

void khoiTao(DanhSach *ds)
{
    ds->head = NULL;
    ds->tail = NULL;
}

BenhNhan *taoBenhNhan(int mabv, char *hoten, float Tuoi, char *diachi)
{
   BenhNhan *Bn = (BenhNhan *)malloc(sizeof(BenhNhan)); // Cap phat bo nho dong cho Benh Nhan
    Bn->mabv = mabv;
    strcpy(Bn->hoten, hoten);
    Bn->Tuoi = Tuoi;
    strcpy(Bn->diachi, diachi);
    Bn->next = NULL; // Gan gia tri NULL cho con tro next cua Benh Nhan
    return Bn;
}

void themBenhNhan(DanhSach *ds,BenhNhan *Bn)
{
    if (ds->head == NULL)
    {
        ds->head = Bn;
        ds->tail = Bn;
    }
    else
    {
        ds->tail->next = Bn;
        ds->tail = Bn;
    }
}

BenhNhan *xoaBenhNhan(DanhSach *ds)
{
    if (ds->head == NULL)
    {
        return NULL;
    }
    else
    {
       BenhNhan *Bn = ds->head;
        ds->head = ds->head->next;
        if (ds->head == NULL)
        {
            ds->tail = NULL;
        }
        return Bn;
    }
}

int isEmpty(DanhSach *ds)
{
    return (ds->head == NULL);
}

BenhNhan *front(DanhSach *ds)
{
    return ds->head;
}

void inBenhNhan(BenhNhan *Bn)
{
    cout << "Ma so: " << Bn->mabv << endl;
    cout << "Ho ten:" << Bn->hoten << endl;
    cout << "Tuoi:" << Bn->Tuoi << endl;
    cout << "Dia chi:" << Bn->diachi << endl;
    cout << "\n";
}

void inDanhSach(DanhSach *ds)
{
   BenhNhan *Bn = ds->head; // Gan con tro Bn bang con tro head cua danh sach lien ket
    while (Bn != NULL)
    {
        inBenhNhan(Bn);
        Bn = Bn->next; // Cap nhat lai con tro Bn bang con tro next cua Benh Nhan hien tai
    }
}

int tinhSoBenhNhanTuoitren8(DanhSach *ds)
{
    int dem = 0;
   BenhNhan *Bn = ds->head; // Gan con tro Bn bang con tro head cua danh sach lien ket
    while (Bn != NULL)
    {
        if (Bn->Tuoi > 8)
        {
            dem++;
        }
        Bn = Bn->next; // Cap nhat lai con tro Bn bang con tro next cua Benh Nhan hien tai
    }
    return dem; // Tra ve gia tri cua bien dem
}

void nhapDanhSach(DanhSach *ds, int n)
{
    khoiTao(ds); // Goi ham khoiTao de khoi tao danh sach rong
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin Benh Nhan thu :" << i + 1 << endl;
        int mabv;
        char hoten[50];
        float Tuoi;
        char diachi[100];
        cout << "Nhap ma so: ";
        cin >> mabv;
        cout << "Nhap ho ten: ";
        cin >> hoten;
        cout << "Nhap Tuoi: ";
        cin >> Tuoi;
        cout << "Nhap dia chi: ";
        cin >> diachi;

       BenhNhan *Bn = taoBenhNhan(mabv, hoten, Tuoi, diachi);
        themBenhNhan(ds, Bn);
        cout << "\n";
    }
}


BenhNhan *xoaBenhNhanTheoMa(DanhSach *ds, int mabv)
{
    if (ds->head == NULL)
    {               
        return NULL;
    }
    else
    {                           
       BenhNhan *Bn = ds->head; // Gan con tro Bn bang con tro head cua danh sach lien ket
       BenhNhan *prev = NULL;   // Gan con tro prev bang NULL de luu lai con tro tro den phan tu truoc Bn
        while (Bn != NULL)
        { 
            if (Bn->mabv == mabv)
            { 
                if (prev == NULL)
                {                        // Neu Bn la phan tu dau tien cua danh sach
                    ds->head = Bn->next; // Cap nhat lai con tro head bang con tro next cua Bn
                    if (ds->head == NULL)
                    {                    // Neu danh sach chi co mot phan tu
                        ds->tail = NULL; // Cap nhat lai con tro tail bang NULL
                    }
                }
                else
                {                          // Neu Bn khong phai la phan tu dau tien cua danh sach
                    prev->next = Bn->next; // Cap nhat lai con tro next cua prev bang con tro next cua Bn
                    if (Bn == ds->tail)
                    {                    // Neu Bn la phan tu cuoi cung cua danh sach
                        ds->tail = prev; // Cap nhat lai con tro tail bang prev
                    }
                }
                return Bn; // Tra ve con tro Bn
            }
            prev = Bn;     // Cap nhat lai con tro prev bang con tro Bn
            Bn = Bn->next; // Cap nhat lai con tro Bn bang con tro next cua Bn
        }
        return NULL; 
    }
}

/*void XoaBn(int mabv)
{
    for (size_t i = 0; i <BenhNhan.size(); i++)
    {
        if (BenhNhan[i].id == id)
        {
           BenhNhan.erase(BenhNhan.begin() + i);
            return;
        }
    }
}

// Tìm sinh viên dựa trên ID
BenhNhan* TimBenhNhan(int id)
{
    for (size_t i = 0; i <BenhNhan.size(); i++)
    {
        if (BenhNhan[i].id == id)
        {
            return &BenhNhan[i];
        }
    }
    return nullptr;
}
*/

int main()
{
    DanhSach ds;
    int n, mabv;
    cout<<"-----------------------------------------"<<endl;
    cout << "Nhap so Bn can them:";
    cin >> n;
    nhapDanhSach(&ds, n);
    cout<<"-----------------------------------------"<<endl;
    inDanhSach(&ds);
    cout<<"-----------------------------------------"<<endl;
    cout << "Nhap ma Bn can xoa:";
    cin >> mabv;
    xoaBenhNhanTheoMa(&ds, mabv);
    cout<<"-----------------------------------------"<<endl;
    cout << "Danh Sach sau khi xoa la:\n";
    inDanhSach(&ds);
    cout<<"-----------------------------------------"<<endl;
}
 