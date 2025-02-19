#ifndef CHU_TRO_H
#define CHU_TRO_H

#include <limits>
#include <iomanip>
#include "phong_tro.h"
#include "nguoi.h"
#include "nguoi_thue.h"
 
class nguoi_thue;

class chu_tro: public nguoi{
    private:
        phong_tro *phong;
        int count_phong;
    public:
        chu_tro();
        chu_tro(string , string , string , string , string, bool);
        int get_count_phong();
        phong_tro& get_phong(int);

        int binary_search_thue(nguoi_thue*, int, string);
        void add_phong_array(phong_tro);
        int check_ten_phong(string);
        phong_tro add_phong_info();
        string delete_phong();
        int nhap_ten_phong_update();
        phong_tro update_phong(int, int&);
        void show_phong_chu(nguoi_thue*, int); 
        void search_phong(nguoi_thue*, int);

        void search_hd(nguoi_thue*, int); 
        hop_dong delete_hd(nguoi_thue*, int, string&);
        void show_hd_time(nguoi_thue*, int);
        void show_hd_phong(nguoi_thue*, int);
        void show_hd(nguoi_thue*, int);
        
        hoa_don add_bill_phong();
        int update_bill_phong();
        string delete_bill_phong();
        void search_bill_phong();
        void show_bill_time();
        void show_bill_phong();
        void show_bill();

        void thong_ke_tong(nguoi_thue*, int);
};

#endif