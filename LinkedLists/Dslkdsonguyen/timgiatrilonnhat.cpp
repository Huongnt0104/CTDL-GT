#include<iostream>
using namespace std;

// =====Bài toán: Danh sách liên kết đơn các số nguyên. Tìm giá trị lớn nhất

// ==== KHAI BÁO DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN=====
// khai báo cấu trúc của một cái node
struct  node
{
    int data; //dữ liệu chưa trong một cái node
    struct node *pNext; // con trỏ dùng để liên kết các node với nhau
};
typedef struct node NODE; // chuyển struct node -> NODE

// Khai báo cấu trúc của một danh sách liên kết đơn
struct list
{
    NODE *pHead; //node quản lý đầu danh sách
    NODE *pTail; //node quản lý cuối danh sách
};
typedef struct list LIST;

//  ==== KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN =====

void KhoiTao(LIST &l){
    // cho 2 node trỏ đến NULL - vì danh sách liên kết đơn chưa có phần tử
    l.pHead = NULL;
    l.pTail = NULL;
}

// Hàm khởi tạo 1 cái node
NODE *KhoiTaoNode(int x){
    NODE *p = new NODE; // cấp phát vùng nhớ cho NODE p
    if (p == NULL){
        cout<<"\nKhong du bo nhơ de cap phat !";
        return NULL;
    }
    p->data = x; // truyền giá trị x vào cho data
    p->pNext =NULL; // đầu tiên khai báo node thì node đó chưa cos liên kết đến node nào hết ==> con trỏ sẽ trỏ đến NULL
    return p; // trả về NODE p vừa khởi tạo
}

// Hàm thêm node vào đầu danh sách liên kêttt
void ThemVaoDau(LIST &l, NODE *p){
    // danh sách đang rỗng
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;// node đầu cũng chính là node cuối và là p
    }
    else{
        p->pNext = l.pHead; // cho con trỏ của node cần thêm là node p liên kêt đến node đầu - pHead
        l.pHead = p; //cập nhật lại pHead chính là node p
    }
}

// Hàm thêm node pa vào cuối danh sách liên kết đơn
void ThemVaoCuoi(LIST &l, NODE *p){
    // danh sách đang rỗng
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;// node đầu cũng chính là node cuối và là p
    }
    else{
        l.pTail->pNext = p;// cho con trỏ của pTail liên kết với node p
        l.pTail = p ;//cập nhật lại p là node pTail
    }
}


// Hàm xuất danh sách liên kết đơn
void XuatList(LIST l){//không có dấu & vì có LIST rồi ,có thay đổi gì đâu
    for(NODE *k =l.pHead; k!= NULL; k= k->pNext){
        cout<< k->data<<" ";
    }
}

// Hàm tìm giá trị lơn nhất trong danh sách
int TimMax(LIST l){
    int max = l.pHead->data; // giả sử node đầu là node lớn nhất
    //Bắt đầu duyệt từ node thứ hai
    for (NODE *k = l.pHead->pNext; k!= NULL; k = k -> pNext){
        if(max < k->data){
            max = k->data; // cập nhật lại giá trị max
        }
    }
    return max;
}

int main(){
    LIST l;
    KhoiTao(l); //khởi tạo danh sách liên kết đơn

    int n;
    cout<< "\nNhap so luong node can them: ";
    cin >> n;
    for (int i = 1; i<= n; i++){
        int x;
        cout << "\nNhap gia tri so nguyen";
        cin >> x;
        NODE *p = KhoiTaoNode(x); // khởi tạo một cái node số nguyên
        ThemVaoDau(l ,p); //thêm node p vào đầu danh sách liên kết đơn

    }
    cout<< "\n\n\t Danh sach lien ket don\n";
    XuatList(l);
    cout <<"\nGia tri lon nhat: "<<TimMax(l)<<endl;
    system("pause");
    return 0;
}