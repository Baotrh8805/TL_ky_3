#ifndef HOA_DON_H
#define HOA_DON_H

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdio>     // Để sử dụng getchar()
#include <unistd.h>
#include <termios.h> 
using namespace std;

struct Time {
    int ngay;
    int thang;
    int nam;
};

Time add_time(int, int, int);
string doubleToString(double);
string centerText(const string&, int);
Time thuc_te();
Time date_new(Time, int);
double tinh_tien_dien(int, int);
double tinh_tien_nuoc(int, int);

char getch_mac_sp();
char getch_mac();

class hoa_don{
    private:
        string ID_hoa_don;
        string ID_phong;
        double tien_dien;
        double tien_nuoc;
        Time thoi_gian;
        Time han_nop;
        bool trang_thai;
    public:
        hoa_don();
        hoa_don(string, string ,double, double, Time, Time, bool);
        string get_ID_hoa_don();
        string get_ID_phong();
        double get_tien_dien();
        double get_tien_nuoc();
        Time get_han_nop();
        Time get_thoi_gian();
        bool get_trang_thai();

        void set_ID_hoa_don(string);
        void set_ID_phong(string);
        void set_tien_dien(double);
        void set_tien_nuoc(double );
        void set_han_nop(Time);
        void set_thoi_gian(Time);
        void set_trang_thai(bool);
        
    
};

#endif