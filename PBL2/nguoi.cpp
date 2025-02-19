# include "nguoi.h"

nguoi::nguoi(){
    this->ID = "";
    this->ten = "";
    this->gioi_tinh = 0;
    this->dia_chi = "";
    this->SDT = "";
    this->CCCD = "";
}

nguoi::nguoi(string ID, string ten, bool gioi_tinh, string dia_chi, string SDT, string CCCD){
    this->ID = ID;
    this->ten = ten;
    this->gioi_tinh = gioi_tinh;
    this->dia_chi = dia_chi;
    this->SDT = SDT;
    this->CCCD = CCCD;
}

string nguoi::get_ID(){
    return this->ID;
}

string nguoi::get_ten(){
    return this->ten;
}

bool nguoi::get_gioi_tinh(){
    return this->gioi_tinh;
}

string nguoi::get_dia_chi(){
    return this->dia_chi;
}

string nguoi::get_SDT(){
    return this->SDT;
}

string nguoi::get_CCCD(){
    return this->CCCD;
}

void nguoi::set_ID(string ID){
    this->ID = ID;
}

void nguoi::set_ten(string ten){
    this->ten = ten;
}

void nguoi::set_gioi_tinh(bool gioi_tinh){
    this->gioi_tinh = gioi_tinh;
}

void nguoi::set_dia_chi(string dia_chi){
    this->dia_chi = dia_chi;
}

void nguoi::set_SDT(string SDT){
    this->SDT = SDT;
}

void nguoi::set_CCCD(string CCCD){
    this->CCCD = CCCD;
}

nguoi::~nguoi(){
}