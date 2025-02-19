#include "hop_dong.h"

hop_dong::hop_dong(){
    ID_hop_dong = "";
    ID_phong = "";
    ID_thue = "";
    tien_phong = 0;
    ngay_thue = add_time(0, 0, 0);
    ngay_het_han = add_time(0, 0, 0);
    ngay_het_han_real = add_time(0, 0, 0);
    trang_thai = true;
}

hop_dong::hop_dong(string ID_hop_dong, string ID_phong, string ID_thue,double  tien_phong, Time ngay_thue, Time ngay_het_han, Time ngay_het_han_real, bool trang_thai){
    this->ID_hop_dong = ID_hop_dong;
    this->ID_phong = ID_phong;
    this->ID_thue = ID_thue;
    this->tien_phong = tien_phong;
    this->ngay_thue = ngay_thue;
    this->ngay_het_han = ngay_het_han;
    this->ngay_het_han_real = ngay_het_han_real;
    this->trang_thai = trang_thai;
}

string hop_dong::get_ID_hop_dong(){
    return this->ID_hop_dong;
}

string hop_dong::get_ID_phong(){
    return this->ID_phong;
}

string hop_dong::get_ID_thue(){
    return this->ID_thue;
}

double hop_dong::get_tien_phong(){
    return this->tien_phong;
}

Time hop_dong::get_ngay_thue(){
    return this->ngay_thue;
}

Time hop_dong::get_ngay_het_han(){
    return this->ngay_het_han;
}

Time hop_dong::get_ngay_het_han_real(){
    return this->ngay_het_han_real;
}

bool hop_dong::get_trang_thai(){

    
    return this->trang_thai;
}

void hop_dong::set_ID_hop_dong(string ID_hop_dong){
    this->ID_hop_dong = ID_hop_dong;
}

void hop_dong::set_ID_phong(string ID_phong){
    this->ID_phong = ID_phong;
}

void hop_dong::set_ID_thue(string ID_thue){
    this->ID_thue = ID_thue;
}

void hop_dong::set_tien_phong(double tien_phong){
    this->tien_phong = tien_phong;
}

void hop_dong::set_ngay_thue(Time ngay_thue){
    this->ngay_thue = ngay_thue;
}

void hop_dong::set_ngay_het_han(Time ngay_het_han){
    this->ngay_het_han = ngay_het_han;
}

void hop_dong::set_ngay_het_han_real(Time ngay_het_han_real){
    this->ngay_het_han_real = ngay_het_han_real;
}

void hop_dong::set_trang_thai(bool trang_thai){
    this->trang_thai = trang_thai;
}

void hop_dong::show(){
    cout << "ID hop dong: " << this->ID_hop_dong << endl;
    cout << "ID thue:" << this->ID_thue << endl;
    cout << "Ngay thue: " << this->ngay_thue.ngay << "/" << this->ngay_thue.thang << "/" << this->ngay_thue.nam << endl;
    cout << "Ngay het han: " << this->ngay_het_han.ngay << "/" << this->ngay_het_han.thang << "/" << this->ngay_het_han.nam << endl;
    cout << "Ngay het han real: " << this->ngay_het_han_real.ngay << "/" << this->ngay_het_han_real.thang << "/" << this->ngay_het_han_real.nam << endl;
    cout << "Trang thai: " << this->trang_thai << endl;
}