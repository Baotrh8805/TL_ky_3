#ifndef QLPT_H
#define QLPT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstddef> 
#include "nguoi_thue.h"
#include "chu_tro.h"

using namespace std;
void logo();
struct tai_khoan {
    string user;
    string pass;
    string ID;
    bool role;
};

struct tk{
    tai_khoan TK;
    tk* next;
};

class QLPT{
    private:
        chu_tro *ct;
        int count_chu;
        nguoi_thue *nt;
        int count_thue;
        phong_tro *pt;
        int count_phong;
        hop_dong *hd;
        int count_hd;
        hoa_don *bill;
        int count_bill;
        int index;
    public:
        QLPT();

        tk *doc_file_account();
        chu_tro* add_account_chu(chu_tro);
        nguoi_thue* add_account_thue(nguoi_thue);
        phong_tro* add_account_phong(phong_tro);
        hop_dong* add_account_hd(hop_dong);
        hoa_don* add_account_bill(hoa_don);
        
        int binary_serach_chu(chu_tro*, int, string);
        int binary_serach_phong(phong_tro*, int, string);
        int binary_serach_hd(hop_dong*, int, string);
        int binary_serach_bill(hoa_don*, int, string);

        void data_chu(chu_tro&);
        int data_phong(phong_tro&);
        void data_thue(nguoi_thue&, chu_tro&);

        void doc_file_chu();
        void doc_file_thue();
        void doc_file_phong();
        void doc_file_hd();
        void doc_file_bill();

        void tim_tk_chu(string);
        void tim_tk_thue(string);

        void ghi_file_chu();
        void ghi_file_thue();
        void ghi_file_phong();
        void ghi_file_hd();
        void ghi_file_bill(); 

        void dang_nhap();

        void chu_cn1();
        void chu_cn2();
        void chu_cn3();
        void menu_chutro();


        void menu_nguoithue();
        void nguoi_thue_cn0_1();
        void nguoi_thue_cn0_2();
        void nguoi_thue_cn1_1();
        void nguoi_thue_cn1_2();
        void nguoi_thue_cn1_3();
        void nguoi_thue_cn1_4(chu_tro);
    };
#endif

 

 
