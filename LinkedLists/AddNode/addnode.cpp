//===Kỹ thuật add node
#include<iostream>

using namespace std;

//==danh sách liên kết đơn cách số nguyên

struct node{
    int data;
    struct node *pNext;
};

typedef struct node NODE;

struct list{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

void KhoiTao(LIST &l){
    l.pHead = NULL;
    l.pTail =NULL;
}

NODE *KhoiTaoNode(int x){
    NODE *p =new NODE;
    if(p == NULL){
        cout<<"\nKhong du bo nho de cap phat !";
        return NULL;
    }
    p->data = x;
    p->pNext =NULL;
    return p;
}

//Hàm thêm node vào đầu danh sách
void ThemVaoDau(LIST &l, NODE *p){
    if(l.pHead == NULL){
        l.pHead = l.pTail =p;

    }
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

//Hàm thêm vào cuối danh sách
void ThemVaoCuoi(LIST &l, NODE *p){
    if(l.pHead == NULL){
        l.pHead = l.pTail =p;

    }
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}


//===Xuat danh sach lien ket don(phai truoc menu khong se bao loi)
void Output(LIST &l){
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        cout<< k->data<< " "<<endl;
    }
}

// Them node p vao sau node q
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p){
    int x;
    cout<< "\nNhap gia tri node q: ";
    cin>> x;
    NODE *q =KhoiTaoNode(x);

    //Nếu danh sách chỉ có một phần tử và phần tử đó cũng chính là node q ==> bài toán trở thành kĩ thuật thêm vào cuối danh sách
    if(q->data == l.pHead->data && l.pHead->pNext ==NULL){
        ThemVaoCuoi(l, p);
    }
    else{
        // duyệt từ đầu danh sách đến cuois danh sách để tìm node q
        for(NODE * k = l.pHead; k != NULL; k = k->pNext){
            // Nếu node q có tồn tại thì ....
            if(q->data == k->data){
                NODE *h = KhoiTaoNode(p->data); // Khởi tạo node h mới để thêm vào sau node q
                NODE *g = k->pNext; // cho node g trở đến node nằm sau node q
                h->pNext = g; // Bước 1: Tạo mối liên kết từ node h đến node g <=> cũng chính là tạo mối liên kết từ node p đến node nằm sau node q
                k->pNext = h; //  Bước 2: Tạo mối liên kết từ node q đến node h <=> chính là node k đến node h
                
            }
        }
    }
}

// menu

//Danh sach lien ket don khong can xac dinh truoc so luong phan tu cua danh sach do
void Menu(LIST &l){
    int luachon;
    while  (69){ //69 -> ham y la tra ve true
        system("cls"); // Lenh xoa man hinh
        cout<< "\n\n\t\t=======Menu=======";
        cout<< "\n\t1. Them node vao danh sach";
        cout<< "\n\t2. Xuat danh sach lien ket don";
        cout<< "\n\t3. Them node p vao sau danh sach";
        cout<< "\n\t0. Thoat";
        cout<< "\n\n\t\t=======End=======";

        cout<< "\nNhap Lua chon: ";
        cin>> luachon;
        if(luachon < 0 || luachon >3){
            cout<< "\nLua chonj khong hop le. Xin kiem tra lai !";
            system("pause"); //Dung man hinh
        }
        if(luachon == 1){
            int x;
            cout<< "\nNhap gia tri so nguyen: ";
            cin>> x;
            NODE *p =KhoiTaoNode(x); // khoi tao 1 cai node
            ThemVaoCuoi(l, p); //Them vao cuoi danh sach
        }
        else if(luachon == 2){
            Output(l);
            system("pause");
        }
        else if(luachon == 3){
            int x;
            cout<< "\nNhap gia tri node p can them vao sau: ";
            cin>> x;
            NODE *p = KhoiTaoNode(x);
            ThemNode_p_VaoSauNode_q(l, p); //thêm node p vào sau danh sách 1 phần tử
        }
        else{
            break; //Thoat khoi vong lap hien tai
        }
    }
}
int main(){
    LIST l;
    KhoiTao(l); //luon luon goi ham khoi tao danh sach lien ket don truoc khi thao tac voi danh sach
    Menu(l);

    system("pause");
    return 0;
}