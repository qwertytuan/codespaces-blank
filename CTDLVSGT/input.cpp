NODE* TimKiem (List L, int x){
    //tao node p
    NODE *p;
    //gan p bang phan tu dau danh sach
    p = L.First;
    //su dung vong lap
    while ((p!=NULL) && (p->info!=x)){
        p=p->next;
    }
    //tra ve ket qua, neu NULL thi khong tim thay
    return p;
}
void XoaDau (List &L){
    //gan p bang phan tu dau danh sach
    NODE *p = L.First;
    //thuc hien gan lai phan tu dau danh sach
    L.First = L.First->next;
    L.First->prev = NULL;
    //neu khong ton tai phan tu dau danh sach
    if (L.First==NULL){
        L.Last = NULL;
    }
    //thay doi con tro next ve NULL
    p->next = NULL;
    //xoa node p duoc gan bang phan tu dau danh sach
    delete p;
}
void XoaCuoi (List &L){
    //tao node p va gan bang phan tu cuoi danh sach
    NODE *p = L.Last;
    //thuc hien gan lai phan tu cuoi danh sach
    L.Last = L.Last->prev;
    L.Last->next = NULL;
    //kiem tra phan tu cuoi neu rong
    if (L.Last==NULL){
        L.First = NULL;
    }
    //thay doi con tro prev cua node p ve NULL
    p->prev = NULL;
    //xoa p duoc gan bang phan tu cuoi danh sach
    delete p;
}


void XoaTheoKhoaK(List &L, int k){
    //tim kiem theo du lieu x va gan vao node p
    NODE *p = TimKiem(L, k);
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
        //xoa node p co phan tu la khoa k
        delete p;
    }
}
