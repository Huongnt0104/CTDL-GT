#include<iostream>
#include<string>

struct Nguoi{
    Nguoi(std::string te, int tu, float vm, float cc){
        ten = te;
        tuoi = tu;
        vong_mot = vm;
        chieu_cao = cc;
        zin = true;
    }
    std::string ten;
    int tuoi;
    float vong_mot;
    float chieu_cao;
    bool zin;

};

void pha_zin(Nguoi *nguoi){
    std::cout<<"Pha zin nguoi: "<<(*nguoi).ten << std::endl;
    (*nguoi).zin = false;
}

int main(){
    Nguoi Hoi_phu_nu[5]={
        Nguoi ("Nguyen Thi Hoa", 21, 90, 90),
        Nguoi ("Nguyen Thi Ninh", 21, 90, 90),
        Nguoi ("Nguyen Thi Anh", 21, 90, 90),
        Nguoi ("Nguyen Thi Hanh", 21, 90, 90),
        Nguoi ("Nguyen Thi Nu", 21, 90, 90)
    };
    std::cout<<"Ten nguoi: "<<Hoi_phu_nu[3].ten<<std::endl;
    std::cout<<"Tinh trang: "<<((Hoi_phu_nu[3]).zin ? "con zin" : "mat zin");
    pha_zin(&Hoi_phu_nu[3]);
    std::cout<<"Tinh trang sau mot dem hen ho: "<<((Hoi_phu_nu[3]).zin ? "con zin" : "mat zin");
    return 0;
}