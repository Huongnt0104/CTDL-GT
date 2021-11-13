#include<iostream>
#include<string>

struct Nguoi{
    Nguoi(std::string te, int tu, float vm, float cc){
        ten = te;
        tuoi = tu;
        vong_mot = vm;
        chieu_cao = cc;
    }
    std::string ten;
    int tuoi;
    float vong_mot;
    float chieu_cao;
};

int main(){
    Nguoi Nga("Nguyen Thị Nga", 21, 90, 90);
    Nguoi Huyen("Nguyen Thị Nga", 21, 90, 90);
    Nguoi Hoai("Nguyen Thị Nga", 21, 90, 90);

    // KHi khai báo tuần tự ta có thể dùng VD: &Nga + 1 => bởi vì nó được lưu tuần tự liên tiêp trong bộ nhớ
    // Cộng trừ địa chỉ không được khuyến khích vì còn tùy thuộc trình biên dịch

    Nguoi *bo_nhi;// dấu * mang tính chất cú pháp khai báo(syntax)
    bo_nhi = &Nga;
    std::cout<< (*bo_nhi) .tuoi; //dấu * mang tính chất toán tử (phép toán lấy giá trị trong địa chỉ đó)
    return 0;
}