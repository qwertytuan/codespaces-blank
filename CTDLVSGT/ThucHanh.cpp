#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *prev;
    Node *next;
};

struct List
{
    Node *first;
    Node *last;
};

List L;
Node *p;

void createList(List &L)
{
    L.first = L.last = NULL;
}

Node *getNode(int x)
{
    p = new Node;
    p->info = x;
    p->prev = p->next = NULL;
    return p;
}

void addNode(List &L, Node *p)
{
    if (L.first == NULL && L.last == NULL)
        L.first = p;
    else
    {
        p->prev = L.last;
        L.last->next = p;
    }
    L.last = p;
}

void displayList(List L, char orient)
{
    if (L.first == NULL && L.last == NULL)
        cout << "Danh sách rỗng";
    else
    {
        if (orient == 'T')
            p = L.first;
        else
            p = L.last;
        while (p != NULL)
        {
            cout << p->info << " ";
            if (orient == 'T')
                p = p->next;
            else
                p = p->prev;
        }
        cout << "\n";
    }
}
// Hàm xóa tất cả các nút có giá trị x trong danh sách liên kết đôi
Node* TimKiem (List L, int x){
    //tao Node p
    Node *p;
    //gan p bang phan tu dau danh sach
    p = L.first;
    //su dung vong lap
    while ((p!=NULL) && (p->info!=x)){
        p=p->next;
    }
    //tra ve ket qua, neu NULL thi khong tim thay
    return p;
}
void XoaDau (List &L){
    //gan p bang phan tu dau danh sach
    Node *p = L.first;
    //thuc hien gan lai phan tu dau danh sach
    L.first = L.first->next;
    L.first->prev = NULL;
    //neu khong ton tai phan tu dau danh sach
    if (L.first==NULL){
        L.last = NULL;
    }
    //thay doi con tro next ve NULL
    p->next = NULL;
    //xoa Node p duoc gan bang phan tu dau danh sach
    delete p;
}
void XoaCuoi (List &L){
    //tao Node p va gan bang phan tu cuoi danh sach
    Node *p = L.last;
    //thuc hien gan lai phan tu cuoi danh sach
    L.last = L.last->prev;
    L.last->next = NULL;
    //kiem tra phan tu cuoi neu rong
    if (L.last==NULL){
        L.first = NULL;
    }
    //thay doi con tro prev cua Node p ve NULL
    p->prev = NULL;
    //xoa p duoc gan bang phan tu cuoi danh sach
    delete p;
}


void XoaTheoX(List &L, int x){
    //tim kiem theo du lieu x va gan vao Node p
    Node *p = TimKiem(L, x);
    //neu tim thay ket qua
    if(p != NULL){
        //neu p->prev == NULL thuc hien xoa dau
        if (p->prev==NULL){
            XoaDau(L);
            return;
        }
        //neu p->next == NULL thuc hien xoa cuoi
        if (p->next==NULL){
            XoaCuoi(L);
            return;
        }
        //thay doi lai lien ket cua phan tu co khoa K can xoa
        p->prev->next = p->next;
        p->next->prev = p->prev;
        //gan con tro prev va next cua phan tu co khoa K can xoa ve null
        p->prev = NULL; 
        p->next = NULL;
        //xoa Node p co phan tu la khoa k
        delete p;
    }
}



int main()
{
    int x;
    do
    {
        cout << "+ Nhập số nguyên (0->Stop): ";
        cin >> x;
        if (x != 0 )
            addNode(L, getNode(x));
    } while (x != 0 );
    
    cout << "Danh sach theo chieu chuan la:\n";
    displayList(L, 'T');
    cout << "Danh sach theo chieu nguoc la:\n";
    displayList(L, 'N');

    cout << "Nhập giá trị x cần xóa: "<<endl;
    cin >> x;
    XoaTheoX(L, x);
    cout << "Danh sach sau khi xoa cac nut co gia tri " << x << " la:\n";
    displayList(L, 'T');
}