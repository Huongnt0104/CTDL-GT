#include<iostream>
#include<string>

class SinhVien{
    public:
        SinhVien(){
            m_hoTen = "";
            m_tuoi = 0;
            m_diem = 0;
        }
    public:
        std::string m_hoTen;
        int m_tuoi;
        double m_diem;
};

int main(){
    SinhVien sv1;
    SinhVien *sv1Ptr = &sv1;
    std::cout<<"Nguyễn Tất Hướng";
    SinhVien sv2;
    SinhVien *sv2Ptr = &sv2;
    return 0;
}