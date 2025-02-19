#ifndef NGUOI_H 
#define NGUOI_H
#include <iostream>
#include <string>
using namespace std;

class nguoi
{
    protected:
        string ID;
        string ten;
        bool gioi_tinh;
        string dia_chi;
        string SDT;
        string CCCD;
    public:
        nguoi();
        nguoi(string, string, bool, string, string, string);
        string get_ID();
        string get_ten();
        bool get_gioi_tinh();
        string get_dia_chi();
        string get_SDT();
        string get_CCCD();

        void set_ID(string ID);
        void set_ten(string ten);
        void set_gioi_tinh(bool gioi_tinh);
        void set_dia_chi(string dia_chi);
        void set_SDT(string SDT);
        void set_CCCD(string CCCD);
        
        ~nguoi();
        
};
#endif