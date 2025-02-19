#include "QLPT.h"

QLPT::QLPT(){
    this->count_chu = 0;
    this->count_thue = 0;
    this->count_phong = 0;
    this->count_hd = 0;
    this->count_bill = 0;
    this->ct = NULL;
    this->nt = NULL;
    this->pt = NULL;
    this->hd = NULL;
    this->bill = NULL;
    this->index = 0;
}

tk *QLPT::doc_file_account() {
    ifstream file("account.txt");
    if (file.is_open()) {
        string account;
        tk *head = NULL;
        while (getline(file, account)) {
            stringstream ss(account);
            string user, pass, ID, r;
            bool role;
            getline(ss, user, '|');
            getline(ss, pass, '|');
            getline(ss, ID, '|');
            getline(ss, r);
            role = stoi(r);
            tai_khoan TK = {user, pass, ID, role};
            tk *temp = new tk;
            temp->TK = TK;
            temp->next = head;
            head = temp;
        }
        file.close();
        return head;
    } else {
        cerr << "Khong the mo file account.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

chu_tro* QLPT::add_account_chu(chu_tro add) {
    bool check = false;
    if (this->count_chu == 0) {
        this->ct = new chu_tro[this->count_chu + 1];
        *ct = add;
    } else {
        chu_tro *chu = new chu_tro[this->count_chu + 1];
        for (int i = 0; i < this->count_chu; i++) {
            if (!check && (chu + i)->get_ID() > add.get_ID()) {
                *(chu + i) = add;
                check = true;
                for (int j = i; j < this->count_chu; j++) *(chu + j + 1) = *(ct + j);
                break;
            }
            else *(chu + i) = *(ct + i);
        }
        if (!check) *(chu + this->count_chu) = add;
        delete[] this->ct;
        this->ct = chu;
    }
    this->count_chu++;
    return this->ct;
}

nguoi_thue* QLPT::add_account_thue(nguoi_thue add) {
    bool check = false;
    if (this->count_thue == 0) {
        this->nt = new nguoi_thue[this->count_thue + 1];
        *nt = add;
    } else {
        nguoi_thue *thue = new nguoi_thue[this->count_thue + 1];
        for (int i = 0; i < this->count_thue; i++) {
            if (!check && (thue + i)->get_ID() > add.get_ID()) {
                *(thue + i) = add;
                check = true;
                for (int j = i; j < this->count_thue; j++) *(thue + j + 1) = *(nt + j);
                break;
            }
            else *(thue + i) = *(nt + i);
        }
        if (!check) *(thue + this->count_thue) = add;
        delete[] this->nt;
        this->nt = thue;
    }
    this->count_thue++;
    return this->nt;
}

phong_tro* QLPT::add_account_phong(phong_tro add) {
    bool check = false;
    if (this->count_phong == 0) {
        this->pt = new phong_tro[this->count_phong + 1];
        *pt = add;
    } else {
        phong_tro *phong = new phong_tro[this->count_phong + 1];
        for (int i = 0; i < this->count_phong; i++) {
            if (!check && (phong + i)->get_ID_phong() > add.get_ID_phong()) {
                *(phong + i) = add;
                check = true;
                for (int j = i; j < this->count_phong; j++) *(phong + j + 1) = *(pt + j);
                break;
            }
            else *(phong + i) = *(pt + i);
        }
        if (!check) *(phong + this->count_phong) = add;
        delete[] this->pt;
        this->pt = phong;
    }
    this->count_phong++;
    return this->pt;
}

hop_dong* QLPT::add_account_hd(hop_dong add) {
    bool check = false;
    if (this->count_hd == 0) {
        this->hd = new hop_dong[this->count_hd + 1];
        *hd = add;
    } else {
        hop_dong *hd_new = new hop_dong[this->count_hd + 1];
        for (int i = 0; i < this->count_hd; i++) {
            if (!check && (hd_new + i)->get_ID_hop_dong() > add.get_ID_hop_dong()) {
                *(hd_new + i) = add;
                check = true;
                for (int j = i; j < this->count_hd; j++) *(hd_new + j + 1) = *(hd + j);
                break;
            }
            else *(hd_new + i) = *(hd + i);
        }
        if (!check) *(hd_new + this->count_hd) = add;
        delete[] this->hd;
        this->hd = hd_new;
    }
    this->count_hd++;
    return this->hd;
}

hoa_don* QLPT::add_account_bill(hoa_don add) {
    bool check = false;
    if (this->count_bill == 0) {
        this->bill = new hoa_don[this->count_bill + 1];
        *bill = add;
    } else {
        hoa_don *bill_new = new hoa_don[this->count_bill + 1];
        for (int i = 0; i < this->count_bill; i++) {
            if (!check && (bill_new + i)->get_ID_hoa_don() > add.get_ID_hoa_don()) {
                *(bill_new + i) = add;
                check = true;
                for (int j = i; j < this->count_bill; j++) *(bill_new + j + 1) = *(bill + j);
                break;
            }
            else *(bill_new + i) = *(bill + i);
        }
        if (!check) *(bill_new + this->count_bill) = add;
        delete[] this->bill;
        this->bill = bill_new;
    }
    this->count_bill++;
    return this->bill;
}

int QLPT::binary_serach_chu(chu_tro *ct, int count, string ID){
    int left = 0;
    int right = count - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if ((ct + mid)->get_ID() == ID) return mid;
        if ((ct + mid)->get_ID() < ID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int QLPT::binary_serach_phong(phong_tro *pt, int count, string ID){
    int left = 0;
    int right = count - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if ((pt + mid)->get_ID_phong() == ID) return mid;
        if ((pt + mid)->get_ID_phong() < ID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int QLPT::binary_serach_hd(hop_dong *hd, int count, string ID){
    int left = 0;
    int right = count - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if ((hd + mid)->get_ID_hop_dong() == ID) return mid;
        if ((hd + mid)->get_ID_hop_dong() < ID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int QLPT::binary_serach_bill(hoa_don *bill, int count, string ID){
    int left = 0;
    int right = count - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if ((bill + mid)->get_ID_hoa_don() == ID) return mid;
        if ((bill + mid)->get_ID_hoa_don() < ID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void QLPT::data_chu(chu_tro& data) {
    for (int i = 0; i < this->count_phong; i++) {
        if ((pt + i)->get_ID_chu() == data.get_ID()) {
            data.add_phong_array(*(pt + i));
        }
    }
}

int QLPT::data_phong(phong_tro& data) {
    int k = 0;
    Time real = thuc_te();
    for (int i = 0; i < count_hd; i++) {
        if ((hd + i)->get_ID_phong() == data.get_ID_phong()) {
            if ((hd + i)->get_trang_thai() == 1 && 
                (((hd + i)->get_ngay_het_han_real().nam == real.nam && (hd + i)->get_ngay_het_han_real().thang == real.thang && (hd + i)->get_ngay_het_han_real().ngay < real.ngay) ||
                ((hd + i)->get_ngay_het_han_real().nam == real.nam && (hd + i)->get_ngay_het_han_real().thang < real.thang) ||
                ((hd + i)->get_ngay_het_han_real().nam < real.nam))) {
                (hd + i)->set_trang_thai(0);
                k = 1;
            }
            data.add_hd_array(*(hd + i));
        }
    }
    
    for (int i = 0; i < count_bill; i++) {
        if ((bill + i)->get_ID_phong() == data.get_ID_phong()) {
            data.add_bill_array(*(bill + i));
        }
    }
    return k;
}

void QLPT::data_thue(nguoi_thue& data, chu_tro& chu) {
    for (int i = 0; i < count_phong; i++) {
        if ((pt + i)->get_ID_thue() == data.get_ID()) {
            data.set_my_phong(*(pt + i));
            break;
        }
    }

    cout << data.get_my_phong().get_ID_chu() << endl;
    int left = 0;
    int right = count_chu - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "mid_chu = " << mid << endl;
        cout << "1 " << (ct + mid)->get_ID() << endl;
        cout << "2 " << data.get_my_phong().get_ID_chu() << endl;
        if ((ct + mid)->get_ID() ==  data.get_my_phong().get_ID_chu()) {
            chu = *(ct + mid);
            break;
        }
        if ((ct + mid)->get_ID() < data.get_my_phong().get_ID_chu()) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "2" << endl;
}

void QLPT::doc_file_chu() {
    ifstream file("chu_tro.txt");
    if (file.is_open()) {
        string chu;
        while (getline(file, chu)) {
            stringstream ss(chu);
            string ID_admin, ten, dia_chi, sdt_str, cccd_str, gioi_tinh_str;
            
            
            getline(ss, ID_admin, '|');
            getline(ss, ten, '|');
            getline(ss, sdt_str, '|');
            getline(ss, cccd_str, '|');
            getline(ss, dia_chi, '|');
            getline(ss, gioi_tinh_str);

            bool gioi_tinh = stoi(gioi_tinh_str);
            
            chu_tro CT(ID_admin, ten, sdt_str, cccd_str, dia_chi, gioi_tinh);
            data_chu(CT);
            add_account_chu(CT);
        }
        file.close();
    } else {
        cerr << "Khong the mo file chu_tro.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

void QLPT::doc_file_thue() {
    int check = 0;
    ifstream file("nguoi_thue.txt");
    if (file.is_open()) {
        string thue;
        while (getline(file, thue)) {
            stringstream ss(thue);
            string ID_user, ID_phong, ten, que_quan, sdt_str, cccd_str, gioi_tinh_str, trang_thai_str;
            bool gioi_tinh, trang_thai;
            
            getline(ss, ID_user, '|');
            getline(ss, ID_phong, '|');
            getline(ss, ten, '|');
            getline(ss, que_quan, '|');
            getline(ss, sdt_str, '|');
            getline(ss, cccd_str, '|');
            getline(ss, gioi_tinh_str, '|');
            getline(ss, trang_thai_str);
            
            
            // Chuyển đổi chuỗi sang số
            gioi_tinh = stoi(gioi_tinh_str);
            trang_thai = stoi(trang_thai_str);
            nguoi_thue NT(ID_user, ten, que_quan, sdt_str, cccd_str, gioi_tinh, trang_thai, ID_phong);
            if (trang_thai == 1) {
                if ((pt + binary_serach_phong(pt, count_phong, ID_phong))->get_trang_thai() == 0){
                    NT.set_trang_thai(0);
                    NT.set_ID_phong("");
                    check = 1;
                }
            }
            this->nt = add_account_thue(NT);
        }
        file.close();
    } else {
        cerr << "Khong the mo file nguoi_thue.txt" << endl;
        exit(EXIT_FAILURE);
    }
    if (check == 1) ghi_file_thue();
}

void QLPT::doc_file_phong() {
    int check = 0;
    ifstream file("phong_tro.txt");
    if (file.is_open()) {
        string phong;
        while (getline(file, phong)) {
            stringstream ss(phong);
            string ID_phong, ID_admin, ID_thue, gia_phong_str, so_phong, dien_tich_str, mo_ta_phong, trang_thai_str;
            double gia_phong;
            float dien_tich;
            int trang_thai;
            
            getline(ss, ID_phong, '|');
            getline(ss, ID_admin, '|');
            getline(ss, ID_thue, '|');
            getline(ss, so_phong, '|');
            getline(ss, gia_phong_str, '|');
            getline(ss, dien_tich_str, '|');
            getline(ss, mo_ta_phong, '|');
            getline(ss, trang_thai_str);
            
            gia_phong = stoul(gia_phong_str);
            dien_tich = stof(dien_tich_str);
            trang_thai = stoi(trang_thai_str);
            phong_tro P(ID_phong, ID_admin, ID_thue, so_phong, gia_phong, dien_tich, mo_ta_phong, trang_thai);
            if (data_phong(P) == 1){
                P.set_trang_thai(0);
                P.set_ID_thue("");
                check = 1;
            }
            this->pt = add_account_phong(P);
        }
        file.close();
    } else {
        cerr << "Khong the mo file phong_tro.txt" << endl;
        exit(EXIT_FAILURE);
    }
    if (check == 1) {
        ghi_file_phong();
        ghi_file_hd();
    }
}

void QLPT::doc_file_hd() {
    ifstream file("hop_dong.txt");
    if (file.is_open()) {
        string hd;
        while (getline(file, hd)) {
            stringstream ss(hd);
            string ID_hop_dong, ID_phong, ID_thue, gia_phong, thue_ngay, thue_thang, thue_nam, het_han_ngay, het_han_thang, het_han_nam, het_han_real_ngay, het_han_real_thang, het_han_real_nam, trang_thai_str;

            getline(ss, ID_hop_dong, '|');
            getline(ss, ID_phong, '|');
            getline(ss, ID_thue, '|');
            getline(ss, gia_phong, '|');
            getline(ss, thue_ngay, '/');
            getline(ss, thue_thang, '/');
            getline(ss, thue_nam, '|');
            getline(ss, het_han_ngay, '/');
            getline(ss, het_han_thang, '/');
            getline(ss, het_han_nam, '|');
            getline(ss, het_han_real_ngay, '/');
            getline(ss, het_han_real_thang, '/');
            getline(ss, het_han_real_nam, '|');
            getline(ss, trang_thai_str);

            // Chuyển đổi chuỗi sang số
            Time ngay_thue = add_time(stoi(thue_ngay), stoi(thue_thang), stoi(thue_nam));
            Time ngay_het_han = add_time(stoi(het_han_ngay), stoi(het_han_thang), stoi(het_han_nam));
            Time ngay_het_han_real = add_time(stoi(het_han_real_ngay), stoi(het_han_real_thang), stoi(het_han_real_nam));
            bool trang_thai = stoi(trang_thai_str);
            double Gia_phong = stod(gia_phong);
            hop_dong HD(ID_hop_dong, ID_phong, ID_thue, Gia_phong, ngay_thue, ngay_het_han, ngay_het_han_real, trang_thai);
            this->hd = add_account_hd(HD);
        }
        file.close();
    } else {
        cerr << "Khong the mo file hop_dong.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

void QLPT::doc_file_bill() {
    ifstream file("hoa_don.txt");
    if (file.is_open()) {
        string bill;
        while (getline(file, bill)) {
            stringstream ss(bill);
            string ID_hoa_don, ID_phong, tien_dien_str, tien_nuoc_str, han_nop_ngay, han_nop_thang, han_nop_nam, thoi_gian_thang, thoi_gian_nam, trang_thai_str;
            double tien_dien, tien_nuoc;
            Time han_nop, thoi_gian;
            int trang_thai;

            getline(ss, ID_hoa_don, '|');
            getline(ss, ID_phong, '|');
            getline(ss, tien_dien_str, '|');
            getline(ss, tien_nuoc_str, '|');
            getline(ss, thoi_gian_thang, '/');
            getline(ss, thoi_gian_nam, '|');
            getline(ss, han_nop_ngay, '/');
            getline(ss, han_nop_thang, '/');
            getline(ss, han_nop_nam, '|');
            getline(ss, trang_thai_str);

            // Chuyển đổi chuỗi sang số
            tien_dien = stod(tien_dien_str);
            tien_nuoc = stod(tien_nuoc_str);
            trang_thai = stoi(trang_thai_str);
            han_nop = add_time(stoi(han_nop_ngay), stoi(han_nop_thang), stoi(han_nop_nam));
            thoi_gian = add_time(0, stoi(thoi_gian_thang), stoi(thoi_gian_nam));
            hoa_don Bill(ID_hoa_don, ID_phong, tien_dien, tien_nuoc, thoi_gian, han_nop, trang_thai);
            this->bill = add_account_bill(Bill);
        }
        file.close();
    } else {
        cerr << "Khong the mo file hoa_don.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

void QLPT::tim_tk_chu(string ID) {
    for (int i = 0; i < this->count_chu; i++) {
        if ((this->ct + i)->get_ID() == ID) {
            this->index = i;
            break;
        }
    }
}

void QLPT::tim_tk_thue(string ID) {
    for (int i = 0; i < this->count_thue; i++) {
        if ((this->nt + i)->get_ID() == ID) {
            this->index = i;
            break;
        }
    }
}

void QLPT::ghi_file_chu() {
    ofstream file("chu_tro.txt");
    if (file.is_open()) {
        for (int i = 0; i < count_chu; i++) {
            file << (ct + i)->get_ID() << "|" << (ct + i)->get_ten() << "|" << (ct + i)->get_SDT() << "|" << (ct + i)->get_CCCD() << "|" << (ct + i)->get_dia_chi() << "|" << (ct + i)->get_gioi_tinh() << endl;
        }
        file.close();
    } else {
        cerr << "Khong the mo file chu_tro.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

void QLPT::ghi_file_thue() {
    ofstream file("nguoi_thue.txt");
    if (file.is_open()) {
        for (int i = 0; i < count_thue; i++) {
            file << (nt + i)->get_ID()<< "|" << (nt + i)->get_ID_phong() << "|" << (nt + i)->get_ten() << "|" << (nt + i)->get_dia_chi() << "|" << (nt + i)->get_SDT() << "|" << (nt + i)->get_CCCD() << "|" << (nt + i)->get_gioi_tinh() << "|" << (nt + i)->get_trang_thai()  << endl;
        }
        file.close();
    } else {
        cerr << "Khong the mo file nguoi_thue.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

void QLPT::ghi_file_phong() {
    ofstream file("phong_tro.txt");
    if (file.is_open()) {
        for (int i = 0; i < count_phong; i++) {
            file << (pt + i)->get_ID_phong() << "|" << (pt + i)->get_ID_chu() << "|" << (pt + i)->get_ID_thue() << "|" << (pt + i)->get_ten_phong() << "|" << (pt + i)->get_gia_phong() << "|" <<  (pt + i)->get_dien_tich() << "|" << (pt + i)->get_mo_ta_phong() << "|" << (pt + i)->get_trang_thai() << endl;
        }
        file.close();
    } else {
        cerr << "Khong the mo file phong_tro.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

void QLPT::ghi_file_hd() {
    ofstream file("hop_dong.txt");
    if (file.is_open()) {
        for (int i = 0; i < count_hd; i++) {
            file << (hd + i)->get_ID_hop_dong() << "|" << (hd + i)->get_ID_phong()  << "|" << (hd + i)->get_ID_thue() << "|"<< (hd+i)->get_tien_phong() << "|" << (hd + i)->get_ngay_thue().ngay << "/" << (hd + i)->get_ngay_thue().thang << "/" << (hd + i)->get_ngay_thue().nam << "|" << (hd + i)->get_ngay_het_han().ngay << "/" << (hd + i)->get_ngay_het_han().thang << "/" << (hd + i)->get_ngay_het_han().nam << "|" << (hd + i)->get_ngay_het_han_real().ngay << "/" << (hd + i)->get_ngay_het_han_real().thang << "/" << (hd + i)->get_ngay_het_han_real().nam << "|" << (hd + i)->get_trang_thai() << endl;
        }
        file.close();
    } else {
        cerr << "Khong the mo file hop_dong.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

void QLPT::ghi_file_bill() {
    ofstream file("hoa_don.txt");
    if (file.is_open()) {
        for (int i = 0; i < count_bill; i++) {
            file << (bill + i)->get_ID_hoa_don() << "|" << (bill + i)->get_ID_phong() << "|" << (bill + i)->get_tien_dien() << "|" << (bill + i)->get_tien_nuoc() << "|" << (bill + i)->get_thoi_gian().thang << "/" << (bill + i)->get_thoi_gian().nam << "|" << (bill + i)->get_han_nop().ngay << "/" << (bill + i)->get_han_nop().thang << "/" << (bill + i)->get_han_nop().nam << "|" << (bill + i)->get_trang_thai() << endl;
        }
        file.close();
    } else {
        cerr << "Khong the mo file hoa_don.txt" << endl;
        exit(EXIT_FAILURE);
    }
}

void QLPT::dang_nhap() {
    string username, password;
    char ch;
    tk *head = doc_file_account();
    bool check = true;
    do{

        system("clear");
        logo();
        cout << "         ╔═════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "         ║                                      ĐĂNG NHẬP                                      ║\n";
        cout << "         ╚═════════════════════════════════════════════════════════════════════════════════════╝\n";
        if(check == false) cout << string(20, ' ') << "ERROR:Tài khoản hoặc mật khẩu không đúng. Vui lòng nhập lại." << endl;
        cout << "             Tên đăng nhập       :";
        getline(cin, username);
        cout << "             Mật khẩu            :";
        while ((ch = getch_mac()) != '\n') { // 13 là mã ASCII của phím Enter
            if (ch == 127) { // 8 là mã ASCII của phím Backspace
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b"; // Xóa ký tự cuối cùng
                }
            } else {
                password.push_back(ch);
                cout << '*'; // Hiển thị dấu *
            }
        }
        check = false;
        tk *temp = head;
        while (temp != NULL) {
            if (temp->TK.user == username && temp->TK.pass == password){
                system("clear");
                check = true;
                if (temp->TK.role) {
                    tim_tk_chu(temp->TK.ID);
                    menu_chutro();
                } else {
                    tim_tk_thue(temp->TK.ID);
                    menu_nguoithue();
                }
                break;
            }
            temp = temp->next;
        }
        password.clear();
    } while(1);
}

void QLPT::chu_cn1(){
    int choice;
    char ch;
    do{
        choice = 0;
        do{
            system("clear");
            cout << "╔═════════════════════════════════════════════════════╗\n";
            cout << "║           ╔══════════════════════════════╗          ║\n";
            cout << "║           ║      QUẢN LÝ PHÒNG Ở         ║          ║\n";
            cout << "║           ╚══════════════════════════════╝          ║\n";
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            for (int i = 0; i < 6; i++) {
                if (choice == i) cout << "║    >>>    " << i + 1 << ". ";
                else cout << "║           " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << "Thêm phòng                     ";
                        break;
                    case 2:
                        cout << "Xóa phòng                      ";
                        break;
                    case 3:
                        cout << "Chỉnh sửa thông tin phòng      ";
                        break;
                    case 4:
                        cout << "Tìm kiếm phòng                 ";
                        break;
                    case 5:
                        cout << "Xem danh sách phòng            ";
                        break;
                    case 6:
                        cout << "Quay lại                       ";
                        break;
                }
                if (choice == i) cout << "   <<<  ║\n";
                else cout << "        ║\n";
                cout << "║                                                     ║\n";
            }
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            cout << "╚═════════════════════════════════════════════════════╝\n";

            ch = getch_mac();
            switch (ch) {
                case 72: 
                    choice = (choice - 1 + 6) % 6;
                    break;
                case 80: 
                    choice = (choice + 1) % 6;
                    break;
                case '\n': 
                    break;
            }
        }while(ch != '\n');
        ++choice;
        system("clear");

        string ID_delete;
        phong_tro temp;
        int t, selected;
        switch(choice) {
            case 1:
                temp = (ct + index)->add_phong_info();
                if (temp.get_ID_phong() == "") break;
                add_account_phong(temp);
                ghi_file_phong();
                system("clear");
                cout << endl << endl;
                cout << string(20, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
                cout << string(20, ' ') << "║            BẠN ĐÃ THÊM PHÒNG THÀNH CÔNG               ║\n";
                cout << string(20, ' ') << "╚═══════════════════════════════════════════════════════╝\n";
                getch_mac();
                break;
            case 2:{
                ID_delete = (ct + index)->delete_phong();
                if (ID_delete == "") break;
                for (int i = 0; i < count_phong; i++){
                    if ((pt + i)->get_ID_phong() == ID_delete){
                        (pt + i)->set_trang_thai(2);
                        break;
                    }
                }
                
                ghi_file_phong();
                system("clear");
                cout << string(20, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
                cout << string(20, ' ') << "║            BẠN ĐÃ XÓA PHÒNG THÀNH CÔNG                ║\n";
                cout << string(20, ' ') << "╚═══════════════════════════════════════════════════════╝\n";
                getch_mac();
                break;
            }
            case 3:
                t = (ct + index)->nhap_ten_phong_update();

                if (t == -1) break;
                do{
                    temp = (ct + index)->update_phong(t, selected);
                    if (selected == 5) break;
                    for (int i = 0; i < count_phong; i++){
                        if ((pt + i)->get_ID_phong() == temp.get_ID_phong()){
                            *(pt + i) = temp;
                            break;
                            }
                        }
                    ghi_file_phong();
                } while (1);
                break;
            case 4:
                (ct + index)->search_phong(nt, count_thue);
                break;
            case 5:
                (ct + index)->show_phong_chu(nt, this->count_thue);
                break;
        }
        system("clear");
    } while (choice != 6);
}

void QLPT::chu_cn2(){
    int choice;
    char ch;
    do{
        choice = 0;
        do{
            system("clear");
            cout << "╔═════════════════════════════════════════════════════╗\n";
            cout << "║           ╔══════════════════════════════╗          ║\n";
            cout << "║           ║      QUẢN LÝ HỢP ĐỒNG        ║          ║\n";
            cout << "║           ╚══════════════════════════════╝          ║\n";
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            for (int i = 0; i < 4; i++) {
                if (choice == i) cout << "║    >>>    " << i + 1 << ". ";
                else cout << "║           " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << "Tìm kiếm hợp đồng              ";
                        break;
                    case 2:
                        cout << "Hủy hợp đồng                   ";
                        break;
                    case 3:
                        cout << "Xem danh sách hợp đồng         ";
                        break;
                    case 4:
                        cout << "Quay lại                       ";
                        break;
                }
                if (choice == i) cout << "   <<<  ║\n";
                else cout << "        ║\n";
                cout << "║                                                     ║\n";
            }
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            cout << "╚═════════════════════════════════════════════════════╝\n";

            ch = getch_mac();
            switch (ch) {
                case 72: 
                    choice = (choice - 1 + 4) % 4;
                    break;
                case 80: 
                    choice = (choice + 1) % 4;
                    break;
                case '\n': 
                    break;
            }
        }while(ch != '\n');
        ++choice;
        system("clear");

        hop_dong temp, HD_delete;
        string ID_delete;
        switch(choice) {
            case 1:
                (ct + index)->search_hd(nt, count_thue);
                break;
            case 2:
                HD_delete = (ct + index)->delete_hd(nt, count_thue, ID_delete);
                if (HD_delete.get_ID_hop_dong() == "") break;
                for (int i = 0; i < this->count_hd; i++){
                    if ((this->hd + i)->get_ID_hop_dong() == HD_delete.get_ID_hop_dong()){
                        *(this->hd + i) = HD_delete;
                        break;
                    }
                }
                ghi_file_hd();

                for (int i = 0; i < count_phong; i++){
                    if ((pt + i)->get_ID_phong() == ID_delete){  
                        (pt + i)->set_ID_thue("");
                        (pt + i)->set_trang_thai(0);
                        break;
                    }
                }
                ghi_file_phong();

                for (int i =0; i < count_thue; i++){
                    if ((nt + i)->get_ID_phong() == ID_delete){
                        (nt + i)->set_trang_thai(0);
                        (nt + i)->set_ID_phong("");
                        break;
                    }
                }
                ghi_file_thue();
                break;
            case 3:
                (ct + index)->show_hd(nt, count_thue);  
                break;
            case 4:
                break;
        }
    } while (choice != 4);
}

void QLPT::chu_cn3(){
    int choice;
    char ch;
    do{
        choice = 0;
        do{
            system("clear");
            cout << "╔═════════════════════════════════════════════════════╗\n";
            cout << "║           ╔══════════════════════════════╗          ║\n";
            cout << "║           ║      QUẢN LÝ HÓA ĐƠN         ║          ║\n";
            cout << "║           ╚══════════════════════════════╝          ║\n";
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            for (int i = 0; i < 6; i++) {
                if (choice == i) cout << "║    >>>    " << i + 1 << ". ";
                else cout << "║           " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << "Thêm hóa đơn                   ";  
                        break;
                    case 2:
                        cout << "Xóa hóa đơn                    ";
                        break;
                    case 3:
                        cout << "Chỉnh sửa thông tin hóa đơn    ";
                        break;
                    case 4:
                        cout << "Tìm kiếm hóa đơn               ";
                        break;
                    case 5:
                        cout << "Xem danh sách hóa đơn          ";
                        break;
                    case 6:
                        cout << "Quay lại                       ";
                        break;
                }
                if (choice == i) cout << "   <<<  ║\n";
                else cout << "        ║\n";
                cout << "║                                                     ║\n";
            }
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            cout << "╚═════════════════════════════════════════════════════╝\n";

            ch = getch_mac();
            switch (ch) {
                case 72: 
                    choice = (choice - 1 + 6) % 6;
                    break;
                case 80: 
                    choice = (choice + 1) % 6;
                    break;
                case '\n': 
                    break;
            }
        }while(ch != '\n');
        ++choice;
        system("clear");

        hoa_don temp;
        hoa_don *temp1 = nullptr;
        string ID_delete;
        string ID_phong;
        int t, index1, index2, selected;
        switch(choice) {
            case 1:
                temp = (ct + index)->add_bill_phong();
                if (temp.get_ID_hoa_don() == "") break;
                this->bill = add_account_bill(temp);
                ghi_file_bill();
                system("clear");
                cout << endl << endl;
                cout << string(20, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
                cout << string(20, ' ') << "║            BẠN ĐÃ THÊM HÓA ĐƠN THÀNH CÔNG             ║\n";
                cout << string(20, ' ') << "╚═══════════════════════════════════════════════════════╝\n";
                getch_mac();
                break;
            case 2:
                ID_delete = (ct + index)->delete_bill_phong();
                if (ID_delete == "") break;
                t = 0;
                
                temp1 = new hoa_don[count_bill - 1];
                for (int i = 0; i < this->count_bill - 1; i++){
                    if ((this->bill + i)->get_ID_hoa_don() == ID_delete) { t = 1; ID_phong = (this->bill + i)->get_ID_phong(); }
                    if (t == 0) *(temp1 + i) = *(this->bill + i);
                    else *(temp1 + i) = *(this->bill + i + 1);
                }
                delete[] this->bill;
                this->bill = temp1;
                this->count_bill--;
                ghi_file_bill();
                system("clear");
                cout << string(20, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
                cout << string(20, ' ') << "║           BẠN ĐÃ XÓA HÓA ĐƠN THÀNH CÔNG               ║\n";
                cout << string(20, ' ') << "╚═══════════════════════════════════════════════════════╝\n";
                getch_mac();
                break;
            case 3:
                index1 = (ct + index)->update_bill_phong();
                if (index1 == -1) break;
                selected = 0;
                index2 = (ct + index)->get_phong(index1).nhap_bill_update();
                do {
                    temp = (ct + index)->get_phong(index1).update_bill(selected, index2);
                    if (selected == 4) break;
                    for (int i = 0; i < count_bill; i++){
                        if ((bill + i)->get_ID_hoa_don() == temp.get_ID_hoa_don()){
                            *(bill + i) = temp;
                            break;
                        }
                    }
                    ghi_file_bill();
                }while (1);
                break;
            case 4:
                (ct + index)->search_bill_phong();
                break;
            case 5:
                (ct + index)->show_bill();
                break;
            case 6:
                break;
        }
    } while (choice != 6);
}

void QLPT::menu_chutro(){
    int selected, ch;

    do{
        selected = 0;
        do{ 
            system("clear");
            cout << "╔═════════════════════════════════════════════════════╗\n";
            cout << "║           ╔══════════════════════════════╗          ║\n";
            cout << "║           ║            MENU              ║          ║\n";
            cout << "║           ╚══════════════════════════════╝          ║\n";
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            for (int i = 0; i < 5; i++) {
                if (selected == i) cout << "║    >>>    " << i + 1 << ". ";
                else cout << "║           " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << "Quản lí phòng ở                ";
                        break;
                    case 2:
                        cout << "Quản lí hợp đồng               ";
                        break;
                    case 3:
                        cout << "Quản lí hóa đơn                ";
                        break;
                    case 4:
                        cout << "Thống kê                       ";
                        break;
                    case 5:
                        cout << "Đăng xuất                      ";
                        break;
                }
                if (selected == i) cout << "   <<<  ║\n";
                else cout << "        ║\n";
                cout << "║                                                     ║\n";
            }
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            cout << "╚═════════════════════════════════════════════════════╝\n";

            ch = getch_mac();
            switch (ch) {
                case 72: 
                    selected = (selected - 1 + 5) % 5;
                    break;
                case 80: 
                    selected = (selected + 1) % 5;
                    break;
                case '\n': 
                    break;
            }
        }while(ch != '\n');
        ++selected;
        switch (selected) {
            case 1:
                chu_cn1();
                break;
            case 2:
                chu_cn2();
                break;
            case 3:
                chu_cn3();
                break;
            case 4:
                (ct + index)->thong_ke_tong(nt, this->count_thue);
                break;
            case 5:
                break;
        }
    } while(selected != 5);
}

void QLPT::menu_nguoithue() { 
    
    int selected;
    char ch;
    do{
        if ((nt + index)->get_trang_thai() == 0) {
            do { 
                selected = 0;
                do{
                    system("clear");
                    cout << "╔═════════════════════════════════════════════════════╗\n";
                    cout << "║           ╔══════════════════════════════╗          ║\n";
                    cout << "║           ║            MENU              ║          ║\n";
                    cout << "║           ╚══════════════════════════════╝          ║\n";
                    cout << "║                                                     ║\n";
                    cout << "║                                                     ║\n";
                    for (int i = 0; i < 3; i++) {
                        if (selected == i) cout << "║    >>>    " << i + 1 << ". ";
                        else cout << "║           " << i + 1 << ". ";
                        switch (i + 1) {
                            case 1:
                                cout << "Xem thông tin phòng            ";
                                break;  
                            case 2:
                                cout << "Thống kê                       ";
                                break;
                            case 3:
                                cout << "Đăng xuất                      ";
                                break;
                            }
                        if (selected == i) cout << "   <<<  ║\n";
                        else cout << "        ║\n";
                        cout << "║                                                     ║\n";
                    }
                    cout << "║                                                     ║\n";
                    cout << "║                                                     ║\n";
                    cout << "╚═════════════════════════════════════════════════════╝\n";

                    ch = getch_mac();

                    switch (ch) {
                        case 72:
                            selected = ((selected - 1 + 3) % 3);
                            break;
                        case 80: 
                            selected = ((selected + 1) % 3);
                            break;
                        case '\n': 
                            break;
                    }
                    
                }while(ch != '\n');
            
                switch (++selected) {
                        case 1:
                            nguoi_thue_cn0_1();
                            system("clear");
                            break;
                   
                        case 2:
                            system("clear");
                            (nt + index)->thong_ke(hd, pt, ct, count_hd, count_phong, count_chu);
                            break;
                        
                }
            }while( selected != 3 && nt[index].get_trang_thai() == 0);
        }
        
        selected = 6;

        if((nt+index)->get_trang_thai()==1){
            chu_tro chu;
            data_thue(*(nt + index), chu);
            Time now = thuc_te();
            do{
                selected = 0;
                do{           
                    system("clear");
                    cout << "╔═════════════════════════════════════════════════════╗\n";
                    cout << "║           ╔══════════════════════════════╗          ║\n";
                    cout << "║           ║            MENU              ║          ║\n";
                    cout << "║           ╚══════════════════════════════╝          ║\n";
                    cout << "║                                                     ║\n";
                    cout << "║                                                     ║\n";
                    for (int i = 0; i < 6; i++) {
                        if (selected == i) cout << "║    >>>    " << i + 1 << ". ";
                        else cout << "║           " << i + 1 << ". ";
                        switch (i + 1) {
                            case 1:
                                cout << "Xem thông tin phòng            ";
                                break;  
                            case 2:
                                cout << "Xem hợp đồng                   ";
                                break;
                            case 3:
                                cout << "Xem hoá đơn và thanh toán      ";
                                break;
                            case 4:
                                cout << "Hủy hợp đồng                   ";
                                break;
                         
                            case 5:
                                cout << "Thống kê                       ";
                                break;
                            case 6:
                                cout << "Đăng xuất                      ";
                                break;
                            }
                        if (selected == i) cout << "   <<<  ║\n";
                        else cout << "        ║\n";
                        cout << "║                                                     ║\n";
                    }
                    cout << "║                                                     ║\n";
                    cout << "║                                                     ║\n";
                    cout << "╚═════════════════════════════════════════════════════╝\n";

                    ch = getch_mac();
                    switch (ch) {
                        case 72:
                            selected = (selected - 1 + 6) % 6;
                            break;
                        case 80:
                            selected = (selected + 1) % 6;
                            break;
                        case '\n':
                            break;
                    }
                    
                }while(ch != '\n');
                
                system("clear");
                switch (++selected) {
                    case 1:
                        (nt + index)->xem_thong_tin_phong(chu);
                        break;
                    case 2:
                        (nt + index)->get_my_phong().search_hd(now, chu, nt, count_thue);
                        getch_mac();
                        break;
                    case 3: 
                        nguoi_thue_cn1_3();
                        break;
                    case 4: 
                        nguoi_thue_cn1_4(chu);
                        break;
                    case 5:
                        (nt + index)->thong_ke(hd, pt, ct, count_hd, count_phong, count_chu);
                        break;
                    case 6:
                        break;
                }
            } while(selected != 6 && nt[index].get_trang_thai() == 1);
        }
    }while(selected != 6); 
}

void QLPT::nguoi_thue_cn0_1(){
    int selected, gia_duoi, gia_tren;
    string dia_chi;
    float dien_tichd_tempuoi, dien_tich_tren;
    char ch;
    do{
        int k = 0;
        selected = 0;
        do{
            system("clear");
            cout << "╔═════════════════════════════════════════════════════╗\n";
            cout << "║           ╔══════════════════════════════╗          ║\n";
            cout << "║           ║          XEM PHÒNG           ║          ║\n";
            cout << "║           ╚══════════════════════════════╝          ║\n";
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            for (int i = 0; i < 5; i++) {
                if (selected == i) cout << "║    >>>    " << i + 1 << ". ";
                else cout << "║           " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << "Tìm kiếm phòng theo giá        ";
                        break;  
                    case 2:
                        cout << "Tìm kiếm phòng theo diện tích  ";
                        break;
                    case 3:
                        cout << "Tìm kiếm phòng theo địa chỉ    ";
                        break;
                    case 4:
                        cout << "Xem tất cả phòng               ";
                        break;
                    case 5:
                        cout << "Quay lại                       ";
                        break;
                    }
                if (selected == i) cout << "   <<<  ║\n";
                else cout << "        ║\n";
                cout << "║                                                     ║\n";
            }
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            cout << "╚═════════════════════════════════════════════════════╝\n";

            ch = getch_mac();
            switch (ch) {
                case 72: 
                    selected = (selected - 1 + 5) % 5;
                    break;
                case 80: 
                    selected = (selected + 1) % 5;
                    break;
                case '\n': 
                    break;
            }
        }while(ch != '\n');


        phong_tro temp;
        hop_dong hd_temp;
        switch(++selected){
            case 1:
                system("clear");
                temp = (nt + index)->search_phong_thue_theo_gia(ct, this->count_chu, hd_temp);
                break;
            case 2:
                system("clear");
                temp = (nt + index)->search_phong_thue_theo_dien_tich(ct, this->count_chu, hd_temp);
                break;
            case 3:
                system("clear");
                temp = (nt + index)->search_phong_thue_theo_dia_chi(ct, this->count_chu, hd_temp);
                break;
            case 4: 
                system("clear");
                temp = (nt + index)->search_phong_thue_ALL(ct, this->count_chu,hd_temp);
                break;
            case 5:
                break;

        }

        if (temp.get_ID_phong() != ""){
            for (int i=0; i< this->count_phong; i++){
                if ((pt + i)->get_ID_phong() == temp.get_ID_phong()){
                    *(pt + i) = temp;
                    k = 1;
                    break;
                }
            }
            add_account_hd(hd_temp);
            ghi_file_phong();
            ghi_file_thue();
            ghi_file_hd();
            system("clear");
            cout << setw(40) << "" << "╔════════════════════════════════════════════════════════════════╗\n";
            cout << setw(40) << "" << "║           CHÚC MÙNG BẠN ĐÃ THUÊ PHÒNG THÀNH CÔNG               ║\n";
            cout << setw(40) << "" << "╚════════════════════════════════════════════════════════════════╝\n" << endl;
            getch_mac();
        }else continue;
        if (k == 1) break;
    } while(selected != 5);   
}

void QLPT::nguoi_thue_cn0_2(){
    int selected;
    while ((nt + index)->update_nguoi_thue(selected) != 6 ){
        ghi_file_thue();
        system("clear");
        (nt + index)->show_info_me();
        cout << endl;
        cout << string(8, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
        cout << string(8, ' ') << "║          BẠN ĐÃ CẬP NHẬP THÔNG TIN THÀNH CÔNG         ║\n";
        cout << string(8, ' ') << "╚═══════════════════════════════════════════════════════╝\n\n";
        cout << string(13, ' ') << "Nhấn phím bất kỳ để tiếp tục...";
        getch_mac();
    };
    ghi_file_thue();
}

void QLPT::nguoi_thue_cn1_3(){
    hoa_don temp = (nt + index)->xem_thong_tin_hoa_don();
    if(temp.get_ID_hoa_don() != ""){
        for (int i = 0; i < count_bill; i++){
            if ((bill + i)->get_ID_hoa_don() == temp.get_ID_hoa_don()){
                *(bill + i) = temp;
                break;
            }
        }
        ghi_file_bill();
        system("clear");
        cout << string(20, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
        cout << string(20, ' ') << "║          BẠN ĐÃ XÁC NHẬN THANH TOÁN THÀNH CÔNG        ║\n";
        cout << string(20, ' ') << "╚═══════════════════════════════════════════════════════╝\n";
        cout << setw(30) << ""  << "!!!Nhấn phím bất kì để tiếp tục!!!" << endl;
        getch_mac();
    }
}

void QLPT::nguoi_thue_cn1_4(chu_tro chu){
    hop_dong temp = (nt + index)->delete_hd(chu);
    if (temp.get_ID_hop_dong() != ""){
        for (int i = 0; i < count_hd; i++){
            if ((hd + i)->get_ID_hop_dong() == temp.get_ID_hop_dong()){
                *(hd + i) = temp;
                break;
            }
        }
        ghi_file_hd();
        
        for (int i = 0; i < count_phong; i++){
            if ((pt + i)->get_ID_phong() == temp.get_ID_phong()){
                (pt + i)->set_ID_thue("");
                (pt + i)->set_trang_thai(0);
                break;
            }
        }
        ghi_file_phong();

        for (int i = 0; i < count_thue; i++){
            if ((nt + i)->get_ID_phong() == temp.get_ID_phong()){
                (nt + i)->set_trang_thai(0);
                (nt + i)->set_ID_phong("");
                break;
            }
        }
        ghi_file_thue();

        for (int i = 0; i < chu.get_count_phong(); i++){
            if ((chu.get_phong(i) ).get_ID_phong() == temp.get_ID_phong()){
                chu.get_phong(i).set_trang_thai(0);
                break;
                
            }
        }

    
       
        system("clear");
        cout << string(20, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
        cout << string(20, ' ') << "║             BẠN ĐÃ HỦY HỢP ĐỒNG THÀNH CÔNG            ║\n";
        cout << string(20, ' ') << "╚═══════════════════════════════════════════════════════╝\n";
        cout << setw(30) << ""  << "!!!Nhấn phím bất kì để tiếp tục!!!" << endl;
        getch_mac();
    }
}


void logo() {

    cout << "╔═════════════════════════════════════MINISTRY OF EDUCATION AND TRAINING═════════════════════════════════════╗\n";
    cout << "║                                 DA NANG UNIVERSITY OF SCIENCE AND TECHNOLOGY                               ║\n";
    cout << "║                                                                                                            ║\n";
    cout << "╠═══════════════════════════════════════╗         ╔══════════════════════════════╗                           ║\n";
    cout << "║                                       ║         ║                              ║           WE              ║\n";
    cout << "║     D                                 ║         ║      ^              ^        ║                           ║\n";
    cout << "║                                       ║         ║              *               ║          LOVE             ║\n";
    cout << "║ B   A   C   H   K   H   O   A         ║         ║              O               ║                           ║\n";
    cout << "║        ╔═══════════════════════════╗  ║         ╚══════════════════════════════╝--_        IT              ║\n";
    cout << "║     N  ║          ...              ║  ║         /   _______________________    /   '-.                     ║\n";
    cout << "║        ║            ....           ║  ║        /   /_____/_____/_____/____/   /      |    FACULTY          ║\n";
    cout << "║     A  ║             ......        ║  ║       /   /_____/_____/_____/____/   /      /+\\                    ║\n";
    cout << "║        ║              .......      ║  ║      /______________________________/       \\_/    *   *           ║\n";
    cout << "║     N  ║              .........    ║  ║                                                  *   *   *         ║\n";
    cout << "║        ║             ...........   ║  ║       Lecturer  : Võ Đức Hoàng                     *   *           ║\n";
    cout << "║     G  ║            .............  ║  ║                                                      *             ║\n";
    cout << "║        ║          ...............  ║  ║       PBL2      : QUẢN LÝ CHO THUÊ PHÒNG TRỌ                       ║\n";
    cout << "║        ║       ..................  ║  ║                                                                    ║\n";
    cout << "║        ║    ....................   ║  ║       Students  : Lê Thị CHính                                     ║\n";                                           
    cout << "║        ║  .....................    ║  ║                   Nguyễn Hữu Duy Bảo                               ║\n";
    cout << "║        ║.....................      ║  ║                                                                    ║\n";
    cout << "║        ╚═══════════════════════════╝  ║       Class     : 23T_Nhat1                                        ║\n";
    cout << "╠═══════════════════════════════════════╝                                                                    ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << endl;

}