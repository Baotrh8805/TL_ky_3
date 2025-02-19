#ifndef PHONG_TRO_H
#define PHONG_TRO_H

#include <limits>
#include <string>
#include "hoa_don.h"
#include "hop_dong.h"
#include "chu_tro.h"

string tang_chuoi_so(string);

class chu_tro;
class nguoi_thue;

class phong_tro{
    private:
        string ID_phong;
        string ID_chu;
        string ID_thue;
        string ten_phong;
        double gia_phong;
        float dien_tich;
        string mo_ta_phong;
        int trang_thai;
        hop_dong *HD;
        hoa_don *bill;
        int count_bill;
        int count_hd;
    public:
        phong_tro();
        phong_tro(string, string, string, string, double , float, string, int);
        string get_ID_phong();
        string get_ID_chu();
        string get_ID_thue();
        double get_gia_phong();
        string get_ten_phong();
        float get_dien_tich();
        string get_mo_ta_phong();
        int get_trang_thai();
        int get_count_bill();
        int get_count_hd();
        hoa_don& get_bill(int);
        hop_dong& get_hop_dong(int);
        hop_dong* get_array_hd();
        
        void set_ID_phong(string);
        void set_ID_chu(string);
        void set_ID_thue(string);
        void set_gia_phong(double );
        void set_ten_phong(string);  
        void set_dien_tich(float);
        void set_mo_ta_phong(string);
        void set_trang_thai(int);
        void set_count_bill(int);
        void set_count_hd(int);
        void set_bill(hoa_don, int);
        void set_hop_dong(Time, int);

        void show();

        int find_bill(Time);
        void add_hd_array(hop_dong);
        int nhap_bill_update();
        int nhap_bill_delete();
        void add_bill_array(hoa_don);
        hoa_don add_bill_info();
        hoa_don update_bill(int &, int);
        string delete_bill();
        void search_bill(Time, int&);
        void show_bill();

        int search_hd(Time, chu_tro, nguoi_thue*, int);
        void show_hd_time(Time, chu_tro, nguoi_thue*, int, int&);
        void show_hd_full(chu_tro, nguoi_thue*, int);
        int find_hop_dong(Time);

        void show_ten_thuoc_tinh(int&, string);
        int show_bill_thue(int[], int);
};

#endif