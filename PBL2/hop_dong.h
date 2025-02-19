#ifndef HOP_DONG_H
#define HOP_DONG_H

#include <iostream>
#include <string>
#include <limits>
#include "hoa_don.h"
using namespace std;
class hoa_don;
class hop_dong{
    private:
        string ID_hop_dong;
        string ID_phong;
        string ID_thue;
        double tien_phong;
        Time ngay_thue;
        Time ngay_het_han;
        Time ngay_het_han_real;
        bool trang_thai;
    public:
        hop_dong();
        hop_dong(string, string, string, double, Time, Time, Time, bool);
        string get_ID_hop_dong();
        string get_ID_phong();
        string get_ID_thue();
        double get_tien_phong();
        Time get_ngay_thue();
        Time get_ngay_het_han();
        Time get_ngay_het_han_real();
        bool get_trang_thai();

        void set_ID_hop_dong(string );
        void set_ID_phong(string);
        void set_ID_thue(string);
        void set_tien_phong(double);
        void set_ngay_thue(Time);
        void set_ngay_het_han(Time);
        void set_ngay_het_han_real(Time);
        void set_trang_thai(bool);

        void show();
};

#endif