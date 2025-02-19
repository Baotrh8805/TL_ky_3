#ifndef NGUOI_THUE_H
#define NGUOI_THUE_H
#include <limits> 
#include "chu_tro.h"
#include "phong_tro.h"
#include "nguoi.h"
using namespace std;

class phong_tro;
class chu_tro;

bool check_so(string);

class nguoi_thue: public nguoi{
    private:
   
        bool gioi_tinh;
        bool trang_thai;
        string ID_phong;
        phong_tro* my_phong;
    public:
        nguoi_thue();
        nguoi_thue(string, string, string, string, string, bool, bool, string); 
    
        bool get_gioi_tinh();
        bool get_trang_thai();
        string get_ID_phong();
        phong_tro& get_my_phong();
        
        void set_gioi_tinh(bool);
        void set_trang_thai(bool);
        void set_ID_phong(string);
        void set_my_phong(phong_tro&);

        void show_info_me();

        hop_dong tao_hop_dong(double tien_phong);
        phong_tro hoi_yeu_cau_thue(chu_tro*&, pair<int,int>*, int, hop_dong&, int&);
        phong_tro search_phong_thue_theo_gia(chu_tro*&, int, hop_dong&);
        phong_tro search_phong_thue_theo_dien_tich(chu_tro*&, int, hop_dong&);
        phong_tro search_phong_thue_theo_dia_chi(chu_tro*&, int, hop_dong&);
        phong_tro search_phong_thue_ALL(chu_tro*&, int, hop_dong&);
        int update_nguoi_thue(int &);
        void show();
        void xem_thong_tin_phong(chu_tro);
        hoa_don xem_thong_tin_hoa_don();
        hoa_don xac_nhan_thanh_toan();
        void thong_ke(hop_dong*, phong_tro*, chu_tro*,int, int, int);
        hop_dong delete_hd(chu_tro);
};  

#endif