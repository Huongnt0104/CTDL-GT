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
    Nguoi Hoi_phu_nu[5]={
        Nguoi ("Nguyen Thi Hoa", 21, 90, 90),
        Nguoi ("Nguyen Thi Ninh", 21, 90, 90),
        Nguoi ("Nguyen Thi Anh", 21, 90, 90),
        Nguoi ("Nguyen Thi Hanh", 21, 90, 90),
        Nguoi ("Nguyen Thi Nu", 21, 90, 90)
    };
    Nguoi *bo_nhi = nullptr;

    for (bo_nhi = Hoi_phu_nu; bo_nhi < Hoi_phu_nu + 5; bo_nhi++){
        std::cout<<(*bo_nhi).ten<<std::endl;
    }

    return 0;
}