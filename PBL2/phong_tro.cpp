#include "phong_tro.h"

string tang_chuoi_so(string s){
    int n = s.length();
    for (int i = n-1; i >= 0; i--){
        if (s[i] == '9'){
            s[i] = '0';
        }
        else{
            s[i]++;
            break;
        }
    }
    return s;
}


phong_tro::phong_tro()
:ID_phong(""), ID_chu(""), ID_thue(""), ten_phong(""), gia_phong(0), dien_tich(0), mo_ta_phong(""), trang_thai(false), count_bill(0), count_hd(0)
{

}

phong_tro::phong_tro(string ID_phong, string ID_chu, string ID_thue, string ten_phong, double gia_phong, float dien_tich, string mo_ta_phong, int trang_thai) 
    :ID_phong(ID_phong), ID_chu(ID_chu), ID_thue(ID_thue),  ten_phong(ten_phong), gia_phong(gia_phong), dien_tich(dien_tich), mo_ta_phong(mo_ta_phong), trang_thai(trang_thai), count_bill(0), count_hd(0)
{
    
}

string phong_tro::get_ID_phong(){
    return this->ID_phong;
}

string phong_tro::get_ID_chu(){
    return this->ID_chu;
}

string phong_tro::get_ID_thue(){
    return this->ID_thue;
}

double phong_tro::get_gia_phong(){
    return this->gia_phong;
}

string phong_tro::get_ten_phong(){
    return this->ten_phong;
}

float phong_tro::get_dien_tich(){
    return this->dien_tich;
}

string phong_tro::get_mo_ta_phong(){
    return this->mo_ta_phong;
}
 
int phong_tro::get_trang_thai(){
    return this->trang_thai;
}

int phong_tro::get_count_bill(){
    return this->count_bill;
}

int phong_tro::get_count_hd(){
    return this->count_hd;
}

hoa_don& phong_tro::get_bill(int index){
    return *(bill+index);
}

hop_dong& phong_tro::get_hop_dong(int index){
    return *(HD + index);
}

hop_dong* phong_tro::get_array_hd(){
    return this->HD;
}

void phong_tro::set_ID_phong(string ID_phong){
    this->ID_phong = ID_phong;
}

void phong_tro::set_ID_chu(string ID_chu){
    this->ID_chu = ID_chu;
}

void phong_tro::set_ID_thue(string ID_thue){
    this->ID_thue = ID_thue;
}

void phong_tro::set_gia_phong(double gia_phong){
    this->gia_phong = gia_phong;
}

void phong_tro::set_ten_phong(string ten_phong){
    this->ten_phong = ten_phong;
}

void phong_tro::set_dien_tich(float dien_tich){
    this->dien_tich = dien_tich;
}

void phong_tro::set_mo_ta_phong(string mo_ta_phong){
    this->mo_ta_phong = mo_ta_phong;
}

void phong_tro::set_trang_thai(int trang_thai){
    this->trang_thai = trang_thai;
}

void phong_tro::set_count_bill(int count_bill){
    this->count_bill = count_bill;
}

void phong_tro::set_count_hd(int count_hd){
    this->count_hd = count_hd;
}

void phong_tro::set_bill(hoa_don bill, int index){
    *(this->bill + index) = bill;
}

void phong_tro::set_hop_dong(Time het_han_real, int index){
   (HD + index)->set_ngay_het_han_real(het_han_real);
   (HD + index)->set_trang_thai(false);
}

void phong_tro::show(){
    cout << "ID phong: " << this->ID_phong << endl;
    cout << "Ten phong: " << this->ten_phong << endl;
    cout << "Gia phong: " << this->gia_phong << endl;
    cout << "Ten phong: " << this->ten_phong << endl;
    cout << "Dien tich: " << this->dien_tich << endl;
    cout << "Mo ta phong: " << this->mo_ta_phong << endl;
}

int phong_tro::find_bill(Time find){
    for (int i = count_bill - 1; i >= 0; i--){
        if ((bill + i)->get_thoi_gian().nam == find.nam && (bill + i)->get_thoi_gian().thang == find.thang)
            return i;
    }
    return -1;
}

int phong_tro::nhap_bill_update(){
    Time TG;
    int index = -1;
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                               CHỈNH SỬA THÔNG TIN HÓA ĐƠN PHÒNG                                     ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn chỉnh sửa hóa đơn       :"<< get_ten_phong() << endl;
        cout << endl;
        cout << "Nhập thời gian hóa đơn phòng " << this->ten_phong << " cần chỉnh sửa"<< endl;
        cout << "Nhập tháng                                  : ";
        if(!(cin >> TG.thang)){
            TG.thang = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập năm                                    : ";
        if(!(cin >> TG.nam)){
            TG.nam = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        if (TG.thang == -1 || TG.nam == -1 || TG.thang < 1 || TG.thang > 12 || TG.nam < 2000) {
            cout << endl;
            cout << "ERROR: Thời gian không hợp lệ. Vui lòng nhập lại!" << endl;
            cout << "Nhấn phím bất kỳ để nhập lại...";
            getch_mac();
            continue;
        }
        for (int i = count_bill -1; i >=0 ; i--){
            if (TG.thang==(bill+i)->get_thoi_gian().thang && TG.nam==(bill+i)->get_thoi_gian().nam){
                if ((bill+i)->get_trang_thai()==true){
                    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════╗\n";
                    cout << "║                HÓA ĐƠN ĐÃ THANH TOÁN. KHÔNG THỂ SỬA ĐỔI THÔNG TIN!!!                     ║\n";
                    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════╝\n";
                    getch_mac();
                    return -1;
                }
                index = i;
                break;
            }
        }
        if (index == -1){
            cout << endl;
            cout << "ERROR: Hóa đơn không tồn tại. Vui lòng nhập lại!" << endl;
            cout << "Nhấn phím bất kỳ để nhập lại...";
            getch_mac();
            continue;
        }
        break;
    }
    return index;
}

int phong_tro::nhap_bill_delete(){
    Time TG;
    int index = -1;
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                        XÓA HÓA ĐƠN PHÒNG                                            ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn xóa hóa đơn             :"<< get_ten_phong() << endl;
        cout << endl;
        cout << "Nhập thời gian hóa đơn phòng " << this->ten_phong << " cần xóa"<< endl;
        cout << "Nhập tháng                                  : ";
        if(!(cin >> TG.thang) || TG.thang < 1 || TG.thang > 12){
            TG.thang = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập năm                                    : ";
        if(!(cin >> TG.nam) || TG.nam < 2023){
            TG.nam = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        if (TG.thang == -1 || TG.nam == -1) {
            cout << endl;
            cout << "ERROR: Thời gian không hợp lệ. Vui lòng nhập lại!" << endl;
            cout << "Nhấn phím bất kỳ để nhập lại...";
            getch_mac();
            continue;
        }
        for (int i = count_bill -1; i >=0 ; i--){
            if (TG.thang==(bill+i)->get_thoi_gian().thang && TG.nam==(bill+i)->get_thoi_gian().nam){
                if ((bill+i)->get_trang_thai()==true){
                    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════╗\n";
                    cout << "║                 HÓA ĐƠN ĐÃ THANH TOÁN. KHÔNG THỂ XÓA HÓA ĐƠN     !!!                     ║\n";
                    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════╝\n";
                    getch_mac();
                    return -1;
                }
                index = i;
                break;
            }
        }
        if (index == -1){
            cout << endl;
            cout << "ERROR: Hóa đơn không tồn tại. Vui lòng nhập lại!" << endl;
            cout << "Nhấn phím bất kỳ để nhập lại...";
            getch_mac();
            continue;
        }
        break;
    }
    return index;
}

void phong_tro::add_bill_array(hoa_don H){
    if (count_bill==0)
    {
        this->bill = new hoa_don[count_bill + 1];
        *(bill+0)=H;
    }else{
        hoa_don *new_b = new hoa_don[count_bill + 1];
        for (int i = 0; i < count_bill; i++)
        {
            *(new_b+i) = *(bill+i);
        }
        *(new_b+count_bill)= H;
        delete[] bill;
        bill = new_b;   
    }
    count_bill++;
}

hoa_don phong_tro::add_bill_info(){
    Time HN, real = thuc_te(), TG;
    if (count_hd != 0 && (HD + count_hd - 1)->get_ngay_thue().thang == real.thang && (HD + count_hd - 1)->get_ngay_thue().nam == real.nam){
        cout << "╔═════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║            THỜI GIAN THUÊ CHƯA ĐỦ 1 THÁNG ĐỂ THÊM HÓA ĐƠN CHO PHÒNG             ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return hoa_don();
    }
    TG.thang = real.thang -1;
    if (TG.thang == 0){
        TG.thang = 12;
        TG.nam = real.nam - 1;
    } else {
        TG.nam = real.nam;
    }
    if(count_bill!=0 && get_bill(count_bill-1).get_thoi_gian().thang == TG.thang && get_bill(count_bill-1).get_thoi_gian().nam == TG.nam){
        cout << "╔═════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║        HÓA ĐƠN THÁNG " << setw(2) << setfill ('0') << TG.thang << " NĂM " << TG.nam << " ĐÃ ĐƯỢC TẠO. VUI LÒNG CHỜ ĐẾN THÁNG SAU.       ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return hoa_don();
    }

    double tien_dien, tien_nuoc;
    int so_dien_cu, so_dien_moi, so_nuoc_cu, so_nuoc_moi;
    string ID;
    bool check;
    do{
        system("clear");
        check = true;
        cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                           THÊM HÓA ĐƠN PHÒNG                                             ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn thêm hóa đơn   : " << get_ten_phong() << endl << endl;
        cout << "Thêm hóa đơn tháng " << TG.thang << " năm " << TG.nam << " cho phòng " << this->ten_phong << endl;
        cout << endl;
        cout << "Hạn nộp hóa đơn" << endl;
        cout << "Nhập ngày                          : ";
        if (!(cin >> HN.ngay)) {
            HN.ngay = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập tháng                         : ";
        if(!(cin >> HN.thang)){
            HN.thang = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập năm                           : ";
        if(!(cin >> HN.nam)){
            HN.nam = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << endl;
        cout << "Các chi phí của phòng" << endl;
        cout << "Nhập số điện cũ                    : ";
        if (!(cin >> so_dien_cu)) {
            so_dien_cu = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập số điện mới                   : ";
        if (!(cin >> so_dien_moi)) {
            so_dien_moi = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập số nước cũ                    : ";
        if (!(cin >> so_nuoc_cu)) {
            so_nuoc_cu = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập số nước mới                   : ";
        if (!(cin >> so_nuoc_moi)) {
            so_nuoc_moi = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore();
        }
        cout << endl << endl;
        if (HN.ngay == -1 || HN.thang == -1 || HN.nam == -1 || HN.thang < 1 || HN.thang > 12 || HN.nam < 0 || HN.ngay < 1 || HN.ngay > 31) {
            cout << "LỖI: Hạn nộp hóa đơn không hợp lệ." << endl;
            check = false;
        } else if ((HN.ngay < real.ngay && HN.thang == real.thang && HN.nam == real.nam) || (HN.thang < real.thang && HN.nam == real.nam) || HN.nam < real.nam) {
            cout << "LỖI: Ngày hạn nộp phải lớn hơn ngày hiện tại." << endl;
            check = false;
        }
        if (so_dien_cu == -1 || so_dien_moi == -1 || so_dien_cu < 0 || so_dien_moi < 0) {
            cout << "Lỗi: Tiền điện không hợp lệ." << endl;
            check = false;
        } else if (so_dien_moi < so_dien_cu) {
            cout << "Lỗi: Số điện mới phải lớn hơn số điện cũ." << endl;
            check = false;
        }
        if (so_nuoc_cu == -1 || so_nuoc_moi == -1 || so_nuoc_cu < 0 || so_nuoc_moi < 0) {
            cout << "Lỗi: Tiền nước không hợp lệ." << endl;
            check = false;
        } else if (so_nuoc_moi < so_nuoc_cu) {
            cout << "Lỗi: Số nước mới phải lớn hơn số nước cũ." << endl;
            check = false;
        }
        if (check == false) {
            cout << "Nhấn phím bất kỳ để nhập lại...";
            getch_mac();
            continue;
        }
        break;
    }while(1);

    tien_dien = tinh_tien_dien(so_dien_cu, so_dien_moi);
    tien_nuoc = tinh_tien_nuoc(so_nuoc_cu, so_nuoc_moi);

    bool TT = false;
    if (this->count_bill == 0) ID = this->ID_phong + "001";
    else ID = tang_chuoi_so((bill + this->count_bill - 1)->get_ID_hoa_don());
    hoa_don H(ID, this->ID_phong, tien_dien, tien_nuoc, TG, HN, TT);
    add_bill_array(H);
    return H;
}

hoa_don phong_tro::update_bill(int & selected, int index){
    Time TG, HN, real = thuc_te();
    int SDC, SDM, SNC, SNM;
    if (index==-1) return hoa_don();
    selected = 0;
    char ch;
    do {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                               CHỈNH SỬA THÔNG TIN HÓA ĐƠN PHÒNG                                     ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "╔════════════════════════════════════════════════════╗\n";
        cout << "║  ╔═══════════════════════════════════════════════╗ ║\n";
        cout << "║  ║                THÔNG TIN HÓA ĐƠN              ║ ║\n";
        cout << "║  ╚═══════════════════════════════════════════════╝ ║\n";
        cout << "║               ╔════════════════════════════════╗   ║\n";
        cout << "║ Tên phòng     ║" << setw(32) << setfill(' ') << left << get_ten_phong() << "║   ║ \n";
        cout << "║               ╚════════════════════════════════╝   ║\n";
        cout << "║                                                    ║\n";
        cout << "║               ╔════════════════════════════════╗   ║\n";
        cout << "║ Thời gian     ║" << setw(2) << setfill('0') << right << (bill + index)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + index)->get_thoi_gian().nam << string(25, ' ') << setfill(' ') <<  "║   ║\n";
        cout << "║               ╚════════════════════════════════╝   ║\n";
        cout << "║                                                    ║\n";
        cout << "║               ╔════════════════════════════════╗   ║\n";
        cout << "║ Giá phòng     ║" << setw(32) << setfill(' ') << left << doubleToString(get_gia_phong()) << "║   ║\n";
        cout << "║               ╚════════════════════════════════╝   ║\n";
        cout << "║                                                    ║\n";
        cout << "║               ╔════════════════════════════════╗   ║\n";
        cout << "║ Tiền điện     ║" << setw(32) << left << doubleToString((bill + index)->get_tien_dien()) << "║   ║\n";
        cout << "║               ╚════════════════════════════════╝   ║\n";
        cout << "║                                                    ║\n";
        cout << "║               ╔════════════════════════════════╗   ║\n";
        cout << "║ Tiền nước     ║" << setw(32) << left << doubleToString((bill + index)->get_tien_nuoc())<< "║   ║\n";
        cout << "║               ╚════════════════════════════════╝   ║\n";
        cout << "║                                                    ║\n";
        cout << "║               ╔════════════════════════════════╗   ║\n";
        cout << "║ Tổng tiền     ║" << setw(32) << left << doubleToString(get_gia_phong() + (bill + index)->get_tien_dien() + (bill + index)->get_tien_nuoc()) << "║   ║\n";
        cout << "║               ╚════════════════════════════════╝   ║\n";
        cout << "║                                                    ║\n";
        cout << "║               ╔════════════════════════════════╗   ║\n";
        cout << "║ Hạn nộp       ║" << setw(2) << setfill('0') << right << (bill + index)->get_han_nop().ngay << "/" << setw(2) << setfill('0') << (bill + index)->get_han_nop().thang << "/" << setw(4) << setfill('0') << (bill + index)->get_han_nop().nam << string(22, ' ') << setfill(' ') << "║   ║\n";
        cout << "║               ╚════════════════════════════════╝   ║\n";
        cout << "║                                                    ║\n";
        cout << "╚════════════════════════════════════════════════════╝\n";

        cout << endl << endl;
        cout << "╔═══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║           ╔════════════════════════════════════════════════╗          ║\n";
        cout << "║           ║        BẠN MUỐN CHỈNH SỬA THÔNG TIN GÌ         ║          ║\n";
        cout << "║           ╚════════════════════════════════════════════════╝          ║\n";
        cout << "║                                                                       ║\n";
        cout << "║                                                                       ║\n";
    
        for (int i = 0; i < 4; i++) { 
            if (selected == i)cout << "║        >>>     " << i + 1 << ". ";
            else cout << "║                " << i + 1 << ". ";
            switch (i + 1) {
                case 1:
                    cout << "Tiền điện                                  ";
                    break;
                case 2:
                    cout << "Tiền nước                                  ";
                    break;
                case 3:
                    cout << "Hạn nộp                                    ";
                    break;
                case 4:
                    cout << "Thoát                                      ";
                    break;
            }
            if (selected == i) cout << "  <<<    ║\n";
            else cout << "         ║\n";
            cout << "║                                                                       ║\n";
        }
        cout << "╚═══════════════════════════════════════════════════════════════════════╝\n";

        ch = getch_mac();
        switch (ch) {
            case 72: 
                selected = (selected - 1 + 4) % 4;
                break;
            case 80: 
                selected = (selected + 1) % 4;
                break;
            case '\n':
                break;
        }
    } while(ch != '\n');

    system("clear");
    cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                               CHỈNH SỬA THÔNG TIN HÓA ĐƠN PHÒNG                                     ║\n";
    cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << endl << endl;
    cout << "╔════════════════════════════════════════════════════╗\n";
    cout << "║  ╔═══════════════════════════════════════════════╗ ║\n";
    cout << "║  ║                THÔNG TIN HÓA ĐƠN              ║ ║\n";
    cout << "║  ╚═══════════════════════════════════════════════╝ ║\n";
    cout << "║               ╔════════════════════════════════╗   ║\n";
    cout << "║ Tên phòng     ║" << setw(32) << left << get_ten_phong() << "║   ║ \n";
    cout << "║               ╚════════════════════════════════╝   ║\n";
    cout << "║                                                    ║\n";
    cout << "║               ╔════════════════════════════════╗   ║\n";
    cout << "║ Thời gian     ║" << setw(2) << setfill('0') << right << (bill + index)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + index)->get_thoi_gian().nam << string(25, ' ') << setfill(' ') << "║   ║\n";
    cout << "║               ╚════════════════════════════════╝   ║\n";
    cout << "║                                                    ║\n";
    cout << "║               ╔════════════════════════════════╗   ║\n";
    cout << "║ Giá phòng     ║" << setw(32) << setfill(' ') << left << doubleToString(get_gia_phong()) << "║   ║\n";
    cout << "║               ╚════════════════════════════════╝   ║\n";
    cout << "║                                                    ║\n";
    cout << "║               ╔════════════════════════════════╗   ║\n";
    cout << "║ Tiền điện     ║" << setw(32) << left << doubleToString((bill + index)->get_tien_dien()) << "║   ║\n";
    cout << "║               ╚════════════════════════════════╝   ║\n";
    cout << "║                                                    ║\n";
    cout << "║               ╔════════════════════════════════╗   ║\n";
    cout << "║ Tiền nước     ║" << setw(32) << left << doubleToString((bill + index)->get_tien_nuoc())<< "║   ║\n";
    cout << "║               ╚════════════════════════════════╝   ║\n";
    cout << "║                                                    ║\n";
    cout << "║               ╔════════════════════════════════╗   ║\n";
    cout << "║ Tổng tiền     ║" << setw(32) << left << doubleToString(get_gia_phong() + (bill + index)->get_tien_dien() + (bill + index)->get_tien_nuoc()) << "║   ║\n";
    cout << "║               ╚════════════════════════════════╝   ║\n";
    cout << "║                                                    ║\n";
    cout << "║               ╔════════════════════════════════╗   ║\n";
    cout << "║ Hạn nộp       ║" << setw(2) << setfill('0') << right << (bill + index)->get_han_nop().ngay << "/" << setw(2) << setfill('0') << (bill + index)->get_han_nop().thang << "/" << setw(4) << setfill('0') << (bill + index)->get_han_nop().nam << string(22, ' ') << setfill(' ') << "║   ║\n";
    cout << "║               ╚════════════════════════════════╝   ║\n";
    cout << "║                                                    ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n";
    cout << endl << endl;   

    switch ( ++selected) {
        case 1:
            cout << "Nhập số điện cũ        : ";
            if (!(cin >> SDC)) {
                SDC = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.clear();
                cin.ignore();
            }
            cout << "Nhập số điện mới       : ";
            if (!(cin >> SDM)) {
                SDM = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.clear();
                cin.ignore();
            }
            if (SDC == -1 || SDM == -1 || SDM < SDC || SDC < 0) cout << endl << "Lỗi: Tiền điện không hợp lệ. Không thể sửa đổi hóa đơn!" << endl;
            else (bill + index)->set_tien_dien(tinh_tien_dien(SDC, SDM));
            break;
        case 2:
            cout << "Nhập số nước cũ        : ";
            if (!(cin >> SNC)) {
                SNC = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.clear();
                cin.ignore();
            }
            cout << "Nhập số nước mới       : ";
            if (!(cin >> SNM)) {
                SNM = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.clear();
                cin.ignore();
            }
            if (SNC == -1 || SNM == -1 || SNM < SNC || SNC < 0) cout << endl << "Lỗi: Tiền nước không hợp lệ. Không thể sửa đổi hóa đơn!" << endl;
            else (bill + index)->set_tien_nuoc(tinh_tien_nuoc(SNC, SNM));
            break;
        case 3:
            cout << "Nhập hạn nộp mới" << endl;
            cout << "Nhập ngày mới          : ";
            if (!(cin >> HN.ngay)){
                HN.ngay = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (HN.ngay < 1 || HN.ngay > 31) {
                HN.ngay = -1;
                cin.clear();
                cin.ignore();
            }
            cout << "Nhập tháng mới         : ";
            if (!(cin >> HN.thang)) {
                HN.thang = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (HN.thang < 1 || HN.thang > 12) {
                HN.thang = -1;
                cin.clear();
                cin.ignore();
            }
            cout << "Nhập năm mới           : ";
            if (!(cin >> HN.nam)) {
                HN.nam = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.clear();
                cin.ignore();
            }
            if (HN.ngay == -1 || HN.thang == -1 || HN.nam == -1) cout << endl << "ERROR: Hạn nộp không hợp lệ. Không thể sửa đổi hóa đơn!" << endl;
            else if (HN.ngay < real.ngay && HN.thang <= real.thang && HN.nam <= real.nam) cout << endl << "ERROR: Hạn nộp không hợp lệ. Ngày hạn nộp phải lớn hơn ngày hiện tại. Không thể sửa đổi hóa đơn!" << endl;
            else (bill + index)->set_han_nop(HN);
            break;
    }

    return *(bill+index);
}

string phong_tro::delete_bill(){
    Time TG;
    int index =  nhap_bill_delete(), selected = 0;
    char ch;
    if (index==-1) return "";
    do {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                        XÓA HÓA ĐƠN PHÒNG                                            ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << string(23, ' ') << "╔════════════════════════════════════════════════════╗\n";
        cout << string(23, ' ') << "║  ╔═══════════════════════════════════════════════╗ ║\n";
        cout << string(23, ' ') << "║  ║         THÔNG TIN HÓA ĐƠN MUỐN XÓA            ║ ║\n";
        cout << string(23, ' ') << "║  ╚═══════════════════════════════════════════════╝ ║\n";
        cout << string(23, ' ') << "║               ╔════════════════════════════════╗   ║\n";
        cout << string(23, ' ') << "║ Tên phòng     ║ " << setfill(' ') << setw(30) << left << get_ten_phong() << " ║   ║ \n";
        cout << string(23, ' ') << "║               ╚════════════════════════════════╝   ║\n";
        cout << string(23, ' ') << "║                                                    ║\n";
        cout << string(23, ' ') << "║               ╔════════════════════════════════╗   ║\n";
        cout << string(23, ' ') << "║ Thời gian     ║ " << setw(2) << setfill('0') << right << (bill + index)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + index)->get_thoi_gian().nam << string(23, ' ') << " ║   ║\n";
        cout << string(23, ' ') << "║               ╚════════════════════════════════╝   ║\n";
        cout << string(23, ' ') << "║                                                    ║\n";
        cout << string(23, ' ') << "║               ╔════════════════════════════════╗   ║\n";
        cout << string(23, ' ') << "║ Giá phòng     ║ " << setw(30) << setfill(' ') << left << doubleToString(get_gia_phong()) << " ║   ║\n";
        cout << string(23, ' ') << "║               ╚════════════════════════════════╝   ║\n";
        cout << string(23, ' ') << "║                                                    ║\n";
        cout << string(23, ' ') << "║               ╔════════════════════════════════╗   ║\n";
        cout << string(23, ' ') << "║ Tiền điện     ║ " << setw(30) << left << doubleToString((bill + index)->get_tien_dien()) << " ║   ║\n";
        cout << string(23, ' ') << "║               ╚════════════════════════════════╝   ║\n";
        cout << string(23, ' ') << "║                                                    ║\n";
        cout << string(23, ' ') << "║               ╔════════════════════════════════╗   ║\n";
        cout << string(23, ' ') << "║ Tiền nước     ║ " << setw(30) << left << doubleToString((bill + index)->get_tien_nuoc())<< " ║   ║\n";
        cout << string(23, ' ') << "║               ╚════════════════════════════════╝   ║\n";
        cout << string(23, ' ') << "║                                                    ║\n";
        cout << string(23, ' ') << "║               ╔════════════════════════════════╗   ║\n";
        cout << string(23, ' ') << "║ Tổng tiền     ║ " << setw(30) << left << doubleToString(get_gia_phong() + (bill + index)->get_tien_dien() + (bill + index)->get_tien_nuoc()) << " ║   ║\n";
        cout << string(23, ' ') << "║               ╚════════════════════════════════╝   ║\n";
        cout << string(23, ' ') << "║                                                    ║\n";
        cout << string(23, ' ') << "║               ╔════════════════════════════════╗   ║\n";
        cout << string(23, ' ') << "║ Hạn nộp       ║ " << setw(2) << setfill('0') << right << (bill + index)->get_han_nop().ngay << "/" << setw(2) << setfill('0') << (bill + index)->get_han_nop().thang << "/" << setw(4) << setfill('0') << (bill + index)->get_han_nop().nam << string(20, ' ') << setfill(' ') << " ║   ║\n";
        cout << string(23, ' ') << "║               ╚════════════════════════════════╝   ║\n";
        cout << string(23, ' ') << "║                                                    ║\n";
        cout << string(23, ' ') << "╚════════════════════════════════════════════════════╝\n";

        cout << endl << endl;
        cout << string(15, ' ') << "╔═══════════════════════════════════════════════════════════════════════╗\n";
        cout << string(15, ' ') << "║           ╔════════════════════════════════════════════════╗          ║\n";
        cout << string(15, ' ') << "║           ║       BẠN CÓ CHẮC CHẮN MUỐN XÓA KHÔNG ?        ║          ║\n";
        cout << string(15, ' ') << "║           ╚════════════════════════════════════════════════╝          ║\n";
        cout << string(15, ' ') << "║                                                                       ║\n";
        cout << string(15, ' ') << "║                                                                       ║\n";
    
        for (int i = 0; i < 2; i++) { 
            if (selected == i)cout << string(15, ' ') << "║        >>>     " << i + 1 << ". ";
            else cout << string(15, ' ') << "║                " << i + 1 << ". ";
            switch (i + 1) {
                case 1:
                    cout << "Có                                         ";
                    break;
                case 2:
                    cout << "Không                                      ";
                    break;
            }
            if (selected == i) cout << "  <<<    ║\n";
            else cout << "         ║\n";
            cout << string(15, ' ') << "║                                                                       ║\n";
        }
        cout << string(15, ' ') << "╚═══════════════════════════════════════════════════════════════════════╝\n";

        ch = getch_mac();
        switch (ch) {
            case 72: 
                selected = (selected - 1 + 2) % 2;
                break;
            case 80: 
                selected = (selected + 1) % 2;
                break;
            case '\n':
                break;
        }
    } while(ch != '\n');

    if (++selected == 1) {
        string ID = (bill + index)->get_ID_hoa_don();
        bool check = false;
        hoa_don* H = new hoa_don[count_bill - 1];
        for (int i = 0; i < count_bill; i++) {
            if (i == index) {
                check = true;
                continue;
            }
            if (check) {
                H[i - 1] = *(bill + i);
            } else {
                H[i] = *(bill + i);
            }
        }
        delete[] bill;
        bill = H;
        this->count_bill--;
        return ID;
    }
    return "";
}

void phong_tro::search_bill(Time t, int& stt){
    for (int i = count_bill - 1; i >= 0; i--) {
        if ((bill + i)->get_thoi_gian().thang == t.thang && (bill + i)->get_thoi_gian().nam == t.nam) {
            if (stt == 0) {
                cout << "Danh sách hóa đơn tháng " << t.thang << " năm " << t.nam << endl;
                cout << "╔═════╦═══════╦═══════════════╦════════════╦════════════╦════════════╦═════════════════╦════════════╦════╗" << endl;
                cout << "║ " << setw(3) << setfill(' ')<< left << centerText("STT", 3) << " ║ " << setw(5) << left << centerText("Phong", 5) << " ║ " << setw(13) << left << centerText("ID hoa don", 13) << " ║ " << setw(10) << left << centerText("Tien phong", 10) << " ║ " << setw(10) << left << centerText("Tien dien", 10) << " ║ " << setw(10) << left << centerText("Tien nuoc", 10) << " ║ " << setw(10) << left << centerText("Tong tien", 15) << " ║ " <<  setw(10) << left << centerText("Han nop",10) << " ║ " <<  setw(2) << left << centerText("TT",2) << " ║" << endl;
            }
            stt++;
            cout << "╠═════╬═══════╬═══════════════╬════════════╬════════════╬════════════╬═════════════════╬════════════╬════╣" << endl;
            cout << "║ " << setw(3) << setfill(' ')<< left << stt << " ║ " << setw(5) << left << ten_phong << " ║ " << setw(13) << left << (bill + i)->get_ID_hoa_don() << " ║ " << setw(10) << left << doubleToString(gia_phong) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_dien()) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_nuoc()) << " ║ " << setw(15) << left << doubleToString(gia_phong + (bill + i)->get_tien_dien() + (bill + i)->get_tien_nuoc()) << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_han_nop().ngay << "/" << setw(2) << setfill('0') << (bill + i)->get_han_nop().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_han_nop().nam << " ║ " << setw(2) << setfill(' ') << left << (bill + i)->get_trang_thai() << " ║" << endl; 
            break;
        }
    }
}

void phong_tro::show_bill(){
    int choice = 0;
    char ch;
    do{
        system("clear");
        cout << "╔═════════════════════════════════════════════════════╗\n";
        cout << "║           ╔══════════════════════════════╗          ║\n";
        cout << "║           ║    XEM HÓA ĐƠN THEO PHÒNG    ║          ║\n";
        cout << "║           ╚══════════════════════════════╝          ║\n";
        cout << "║                                                     ║\n";
        cout << "║                                                     ║\n";
        for (int i = 0; i < 4; i++) {
            if (choice == i) cout << "║    >>>    " << i + 1 << ". ";
            else cout << "║           " << i + 1 << ". ";
            switch (i + 1) {
                case 1:
                    cout << "Hóa đơn chưa thanh toán        ";         
                    break;
                case 2:
                    cout << "Hóa đơn đã thanh toán          ";
                    break;
                case 3:
                    cout << "Tất cả hóa đơn                 ";
                    break;
                case 4:
                    cout << "Thoát                          ";
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
    } while (ch != '\n');
    int count;
    system("clear");
    switch (++choice) {
        case 1:
            count = 0;
            for (int i = 0; i < count_bill; i++) {
                if ((bill + i)->get_trang_thai() == false) {
                    if (count == 0) {
                        cout << "Tất cả hóa đơn chưa thanh toán của phòng " << ten_phong << " là: " << endl;
                        cout << "╔═════╦═══════════════╦═══════════╦════════════╦════════════╦════════════╦═════════════════╦════════════╗" << endl;
                        cout << "║ " << setw(3) << setfill(' ')<< left << centerText("STT", 3) << " ║ " << setw(13) << left << centerText("ID hoa don", 13) << " ║ " << setw(9) << centerText("Thoi gian",9) << " ║ "<< setw(10) << left << centerText("Tien phong", 10) << " ║ " << setw(10) << left << centerText("Tien dien", 10) << " ║ " << setw(10) << left << centerText("Tien nuoc", 10) << " ║ " << setw(15) << left << centerText("Tong tien", 15) << " ║ " <<  setw(10) << left << centerText("Han nop",10) << " ║" << endl;
                    }
                    count++;
                    cout << "╠═════╬═══════════════╬═══════════╬════════════╬════════════╬════════════╬═════════════════╬════════════╣" << endl;
                    cout << "║ " << setw(3) << setfill(' ')<< left << count << " ║ "  << setw(13) << left << (bill + i)->get_ID_hoa_don() << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_thoi_gian().nam << "   ║ " << setw(10) << setfill(' ') << left << doubleToString(gia_phong) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_dien()) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_nuoc()) << " ║ " << setw(15) << left << doubleToString(gia_phong + (bill + i)->get_tien_dien() + (bill + i)->get_tien_nuoc()) << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_han_nop().ngay << "/" << setw(2) << setfill('0') << (bill + i)->get_han_nop().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_han_nop().nam << " ║" << endl; 
                }
            }
            if (count == 0){
                cout << "╔═════════════════════════════════════════════════════════╗\n";
                cout << "║       KHÔNG CÓ HÓA ĐƠN NÀO CHƯA THANH TOÁN              ║\n";
                cout << "╚═════════════════════════════════════════════════════════╝\n";
                getch_mac();
            } else{
                cout << "╚═════╩═══════════════╩═══════════╩════════════╩════════════╩════════════╩═════════════════╩════════════╝" << endl;
                cout << "Có tất cả " << count << " hóa đơn chưa thanh toán của phòng " << ten_phong << endl;
                cout << "Nhấn phím bất kỳ để thoát" << endl;
                getch_mac();
            }
            break;
        case 2:
            count = 0;
            for (int i = count_bill - 1; i >= 0; i--) {
                if ((bill + i)->get_trang_thai() == true) {
                    if (count == 0){
                        cout << "Tất cả hóa đơn đã thanh toán của phòng " << ten_phong << " là: " << endl;
                        cout << "╔═════╦═══════════════╦═══════════╦════════════╦════════════╦════════════╦═════════════════╗" << endl;
                        cout << "║ " << setw(3) << setfill(' ')<< left << centerText("STT", 3)  << " ║ " << setw(13) << left << centerText("ID hoa don", 13) << " ║ " << setw(9) << centerText("Thoi gian",9) << " ║ "<< setw(10) << left << centerText("Tien phong", 10) << " ║ " << setw(10) << left << centerText("Tien dien", 10) << " ║ " << setw(10) << left << centerText("Tien nuoc", 10) << " ║ " << setw(15) << left << centerText("Tong tien", 15) << " ║" << endl;
                    }
                    count++;
                    cout << "╠═════╬═══════════════╬═══════════╬════════════╬════════════╬════════════╬═════════════════╣" << endl;
                    cout << "║ " << setw(3) << setfill(' ')<< left << count << " ║ "  << setw(13) << left << (bill + i)->get_ID_hoa_don() << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_thoi_gian().nam << "   ║ " << setw(10) << setfill(' ') << left << doubleToString(gia_phong) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_dien()) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_nuoc()) << " ║ " << setw(15) << left << doubleToString(gia_phong + (bill + i)->get_tien_dien() + (bill + i)->get_tien_nuoc()) << " ║" << endl;
                }
            }
            if (count == 0) {
                cout << "╔═════════════════════════════════════════════════════════╗\n";
                cout << "║         KHÔNG CÓ HÓA ĐƠN NÀO ĐÃ THANH TOÁN              ║\n";
                cout << "╚═════════════════════════════════════════════════════════╝\n";
                getch_mac();
            } else{
                cout << "╚═════╩═══════════════╩═══════════╩════════════╩════════════╩════════════╩═════════════════╝" << endl;
                cout << "Có tất cả " << count << " hóa đơn đã thanh toán của phòng " << ten_phong << endl;
                cout << "Nhấn phím bất kỳ để thoát" << endl;
                getch_mac();
            }
            break;
        case 3:
            count = 0;
            for (int i = count_bill - 1; i >= 0; i--) {                
                if (count == 0){
                    cout << "Tất cả hóa đơn của phòng " << ten_phong << " là: " << endl;
                cout << "╔═════╦═══════════════╦═══════════╦════════════╦════════════╦════════════╦═════════════════╦════════════╦════╗" << endl;
                cout << "║ " << setw(3) << setfill(' ')<< left << centerText("STT", 3) << " ║ " << setw(13) << left << centerText("ID hoa don", 13) << " ║ " << setw(9) << centerText("Thoi gian",9) << " ║ "<< setw(10) << left << centerText("Tien phong", 10) << " ║ " << setw(10) << left << centerText("Tien dien", 10) << " ║ " << setw(10) << left << centerText("Tien nuoc", 10) << " ║ " << setw(15) << left << centerText("Tong tien", 15) << " ║ " <<  setw(10) << left << centerText("Han nop",10) << " ║ " << setw(2) << setfill(' ') << left << centerText("TT", 2) << " ║" << endl;
                }
                count++;
                cout << "╠═════╬═══════════════╬═══════════╬════════════╬════════════╬════════════╬═════════════════╬════════════╬════╣" << endl;
                cout << "║ " << setw(3) << setfill(' ') << left << count << " ║ " << setw(13) << left << (bill + i)->get_ID_hoa_don() << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_thoi_gian().nam << "   ║ " << setw(10) << setfill(' ') << left << doubleToString(gia_phong) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_dien()) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_nuoc()) << " ║ " << setw(15) << left << doubleToString(gia_phong + (bill + i)->get_tien_dien() + (bill + i)->get_tien_nuoc()) << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_han_nop().ngay << "/" << setw(2) << setfill('0') << (bill + i)->get_han_nop().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_han_nop().nam << " ║ " << setw(2) << setfill(' ') << left << (bill + i)->get_trang_thai() << " ║" << endl;
            }
            cout  << "╚═════╩═══════════════╩═══════════╩════════════╩════════════╩════════════╩═════════════════╩════════════╩════╝" << endl;
            cout << "Có tất cả " << count << " hóa đơn của phòng " << ten_phong << endl;
            cout << "Nhấn phím bất kỳ để thoát" << endl;
            getch_mac();
            break;
        case 4:
            break;
    }
}

void phong_tro::add_hd_array(hop_dong add){
    if (count_hd == 0)
    {
        this->HD = new hop_dong[count_hd + 1];
        *(HD+0) = add;
    }else{
        hop_dong *temp = new hop_dong[count_hd + 1];
        for (int i = 0; i < count_hd; i++)
        {
            *(temp+i) = *(HD+i);
        }
        *(temp+count_hd) = add;
        delete[] HD;
        HD = temp;   
    }
    count_hd ++;
}

int phong_tro::find_hop_dong(Time find){
    for(int i = this->count_hd -1; i >= 0; i--){
        if ((((HD + i)->get_ngay_thue().nam < find.nam) || ((HD + i)->get_ngay_thue().nam == find.nam && (HD + i)->get_ngay_thue().thang <= find.thang)) &&
            ((HD + i)->get_ngay_het_han_real().nam > find.nam) || ((HD + i)->get_ngay_het_han_real().nam == find.nam && (HD + i)->get_ngay_het_han_real().thang > find.thang) || 
            ((HD + i)->get_ngay_het_han_real().nam == find.nam && (HD + i)->get_ngay_het_han_real().thang == find.thang && (HD + i)->get_ngay_het_han_real().ngay >= find.ngay))
            return i;
    }
    return -1;
}

int phong_tro::search_hd(Time find, chu_tro ct, nguoi_thue* nt, int count_nt){
    int index = find_hop_dong(find);
    system("clear");
    if (index == -1) {
        cout << "╔══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║           KHÔNG TÌM THẤY HỢP ĐỒNG NÀO TRONG THỜI GIAN NÀY            ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return -1;
    } else{
        cout << string(36, ' ') << "╔════════════════════════════════════════╗\n";
        cout << string(36, ' ') << "║           THÔNG TIN HỢP ĐỒNG           ║\n";
        cout << string(36, ' ') << "╚════════════════════════════════════════╝\n";
        cout << endl << endl;
        int index_thue = ct.binary_search_thue(nt, count_nt, (HD + index)->get_ID_thue());
        nguoi_thue temp = *(nt + index_thue);
        const string italic_on = "\033[3m";
        const string italic_off = "\033[0m";
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                      CỘNG HÒA XÃ HỘI CHỦ NGHĨA VIỆT NAM                                         ║\n";
        cout << "║                                          Độc lập - Tự do - Hạnh phúc                                            ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║                                              HỢP ĐỒNG THUÊ TRỌ                                                  ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║      " << italic_on << "- Căn cứ Bộ luật Dân sự số 91/2015/QH13 ngày 24/11/2015;" << italic_off << "                                                   ║\n";
        cout << "║      " << italic_on << "- Căn cứ vào Luật Thương mại số 36/2005/QH11 ngày 14 tháng 06 năm 2005;" << italic_off << "                                    ║\n";
        cout << "║      " << italic_on << "- Căn cứ vào nhu cầu và sự thỏa thuận của các bên tham gia Hợp đồng;" << italic_off << "                                       ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║      Hôm nay ngày " << setw(2) << setfill('0') << right << (HD + index)->get_ngay_thue().ngay << " tháng " << setw(2) << right << (HD + index)->get_ngay_thue().thang << " năm " << setw(4) << right << (HD + index)->get_ngay_thue().nam << setfill (' ') << ", các bên gồm                                                             ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║      A. BÊN CHO THUÊ (Bên A):                                                                                   ║\n";
        cout << "║      - Ông/Bà: " << setw(20) << left << ct.get_ten() << "                             Số điện thoại: " << setw(10) << left << ct.get_SDT() << "                       ║\n";
        cout << "║      - Số CMND: " << setw(10) << left << ct.get_CCCD() << "                                    Nơi cấp: Cục trưởng CCS QLHC VTTXH              ║\n";
        cout << "║      - Địa chỉ: " << setw(30) << left << ct.get_dia_chi() << "                                                                  ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║      B. BÊN THUÊ (Bên B):                                                                                       ║\n";
        cout << "║      - Ông/Bà: " << setw(20) << left << temp.get_ten() << "                             Giới tính: ";
        if (temp.get_gioi_tinh() == 1) cout << setw(3) << "Nam";
        else cout << setw(3) << "Nữ ";
        cout << "                                  ║\n";
        cout << "║      - Số CMND: " << setw(10) << left << temp.get_CCCD() << "                                    Nơi cấp: Cục trưởng CCS QLHC VTTXH              ║\n";
        cout << "║      - Địa chỉ: " << setw(30) << left << temp.get_dia_chi() << "                                                                  ║\n";
        cout << "║      - Số điện thoại: " << setw(10) << left << temp.get_SDT() << "                                                                                ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║      Đã thỏa thuận ký kết Hợp đồng thuê trọ với các điều khoản sau đây:                                         ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║      1. Bên A cho Bên B thuê phòng trọ tại địa chỉ: " << setw(30) << left << ten_phong << "                              ║\n";
        cout << "║      2. Thời hạn thuê: Từ ngày " << setw(2) << setfill('0') << right << (HD + index)->get_ngay_thue().ngay << " tháng " << setw(2) << right << (HD + index)->get_ngay_thue().thang << " năm " << setw(4) << right << (HD + index)->get_ngay_thue().nam << " đến ngày " << setw(2) << right << (HD + index)->get_ngay_het_han().ngay << " tháng " << setw(2) << right << (HD + index)->get_ngay_het_han().thang << " năm " << setw(4) << right << (HD + index)->get_ngay_het_han().nam << setfill(' ') << "                               ║\n";
        cout << "║      3. Giá thuê: " << setw(10) << left << doubleToString((HD +index)->get_tien_phong()) << " VND/tháng" << "                                                                          ║\n";
        cout << "║      4. Bên B cam kết thanh toán đầy đủ tiền thuê phòng trọ hàng tháng trước ngày hạn nộp hàng tháng.           ║\n";
        cout << "║      5. Bên B cam kết không sử dụng phòng trọ để mục đích đánh bạc, sử dụng ma túy, sử dụng chất cấm.           ║\n"; 
        cout << "║                                                               Ngày " << setw(2) << setfill('0') << right << (HD + index)->get_ngay_thue().ngay << " tháng " << setw(2) << right << (HD + index)->get_ngay_thue().thang << " năm " << setw(4) << right << (HD + index)->get_ngay_thue().nam << setfill(' ') << "                         ║\n";
        cout << "║                        Bên A (Bên cho thuê)                               Bên B (Bên thuê)                      ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "║                             Đã ký                                             Đã ký                             ║\n";
        cout << "║                                                                                                                 ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    }   
    return index;
}

void phong_tro::show_hd_time(Time t, chu_tro ct, nguoi_thue* nt, int count_nt, int& stt){
    int index = find_hop_dong(t);
    if (index != -1 && this->ID_phong == (HD + index)->get_ID_phong()){
        if (stt == 0) {
            cout << "Danh sách hợp đồng thuộc tháng " << t.thang << " năm " << t.nam  << "của chủ trọ " << ct.get_ten() << endl;
            cout << "╔═════╦═════════════╦════════════╦════════════╦════════════╦══════════════════════╦════════════╦════════════════╦══════════════╗   " << endl;
            cout << "║ STT ║ ID hop dong ║  Bat dau   ║  Ket thuc  ║   Thuc te  ║    Ten nguoi thue    ║    SDT     ║    Giá phòng   ║  Trạng thái  ║" << endl;
       
        }
        stt++;
        nguoi_thue temp = *(nt + ct.binary_search_thue(nt, count_nt, (HD + index)->get_ID_thue()));
      
        cout << "╠═════╬═════════════╬════════════╬════════════╬════════════╬══════════════════════╬════════════╬════════════════╬══════════════╣" << endl;
        cout << left << setfill(' ') << "║ " << setw(3) << stt << " ║  "  << setw(11) << (HD + index)->get_ID_hop_dong() << "║ " << right << setw(2) << setfill('0') << (HD + index)->get_ngay_thue().ngay << "/" << setw(2) << (HD + index)->get_ngay_thue().thang << "/" << setw(4) << (HD + index)->get_ngay_thue().nam << " ║ " << setw(2) << (HD + index)->get_ngay_het_han().ngay << "/" << setw(2) << (HD + index)->get_ngay_het_han().thang << "/" << setw(4) << (HD + index)->get_ngay_het_han().nam << " ║ " << setw(2) << (HD + index)->get_ngay_het_han_real().ngay << "/" << setw(2) << (HD + index)->get_ngay_het_han_real().thang << "/" << setw(4) << (HD + index)->get_ngay_het_han_real().nam << " ║ " << setw(20) << left << setfill(' ')<< temp.get_ten() << " ║ " << setw(10) << temp.get_SDT() << " ║ " << setw(14) << doubleToString((HD + index)->get_tien_phong()) << " ║ " << setw(12) << (((HD + index)->get_trang_thai()) ? "Còn thời hạn" : "Hết thời hạn") << " ║" << endl;
    }
}

void phong_tro::show_hd_full(chu_tro ct,  nguoi_thue* nt, int count_nt){
    int index, count = 0;
    system("clear");
    if (count_hd == 0){
        cout << "╔═════════════════════════════════════════════════════════╗\n";
        cout << "║               PHÒNG CHƯA CÓ HỢP ĐỒNG NÀO                ║\n";
        cout << "╚═════════════════════════════════════════════════════════╝\n";
        return;
    }
    for (int i = this->count_hd - 1; i >= 0; i--){
        if (count == 0){
            cout << "Danh sách tất cả hợp đồng của phòng " << get_ten_phong() << " của chủ trọ " << ct.get_ten() << endl; 
            cout << "╔═════╦═════════════╦════════════╦════════════╦════════════╦══════════════════════╦════════════╦════════════════╦══════════════╗   " << endl;
            cout << "║ STT ║ ID hop dong ║  Bat dau   ║  Ket thuc  ║   Thuc te  ║    Ten nguoi thue    ║    SDT     ║    Giá phòng   ║  Trạng thái  ║" << endl;
        }
        count++;
        nguoi_thue temp = *(nt + ct.binary_search_thue(nt, count_nt, (HD + i)->get_ID_thue()));
        cout << "╠═════╬═════════════╬════════════╬════════════╬════════════╬══════════════════════╬════════════╬════════════════╬══════════════╣" << endl;
        cout << left << setfill(' ') << "║ " << setw(3) << count << " ║  "  << setw(11) << (HD +i)->get_ID_hop_dong() << "║ " << right << setw(2) << setfill('0') << (HD + i)->get_ngay_thue().ngay << "/" << setw(2) << (HD + i)->get_ngay_thue().thang << "/" << setw(4) << (HD +i)->get_ngay_thue().nam << " ║ " << setw(2) << (HD +i)->get_ngay_het_han().ngay << "/" << setw(2) << (HD + i)->get_ngay_het_han().thang << "/" << setw(4) << (HD + i)->get_ngay_het_han().nam << " ║ " << setw(2) << (HD + i)->get_ngay_het_han_real().ngay << "/" << setw(2) << (HD + i)->get_ngay_het_han_real().thang << "/" << setw(4) << (HD + i)->get_ngay_het_han_real().nam << " ║ " << setw(20) << left << setfill(' ')<< temp.get_ten() << " ║ " << setw(10) << temp.get_SDT() << " ║ " << setw(14) << doubleToString((HD +i)->get_tien_phong()) << " ║ " << setw(12) << (((HD + i)->get_trang_thai()) ? "Còn thời hạn" : "Hết thời hạn") << " ║" << endl;
    }
    cout << "╚═════╩═════════════╩════════════╩════════════╩════════════╩══════════════════════╩════════════╩════════════════╩══════════════╝" << endl;
    cout << "Tìm thấy " << count << " hợp đồng thỏa mãn" << endl;
}

void phong_tro::show_ten_thuoc_tinh(int& stt, string DC){
    if (stt == 0){
        cout << "╔═════╦══════════╦═════════╦════════════════╦════════════════╦════════════════════════════════════════════════════╦══════════════════════════════════════════╗" << endl;
        cout << "║ STT ║ ID Phòng ║  Phòng  ║   Giá (nvđ)    ║ Diện tích (m²) ║                     Mô Tả Phòng                    ║                Địa Chỉ                   ║ " << endl; 
    } 
    stt ++;
    cout << "╠═════╬══════════╬═════════╬════════════════╬════════════════╬════════════════════════════════════════════════════╬══════════════════════════════════════════╣"  << endl;
    cout << setfill(' ') << "║ " 
         << left << setw(3) << stt << " ║ "
         << setw(8) << this->ID_phong << " ║ "
         << setw(7) << this->ten_phong << " ║ "
         << setw(14) << doubleToString(get_gia_phong()) << " ║ "
         << setw(14) << doubleToString(get_dien_tich())  << " ║ "
         << setw(50) << this->mo_ta_phong << " ║ "
         << setw(40) << DC << " ║ " <<endl;     
}

int phong_tro::show_bill_thue(int a[10], int choice){
    int count = 0, check = 0;
    char ch;
    Time temp = get_hop_dong(count_hd - 1).get_ngay_thue();
    system("clear");
    switch (++choice) {
        case 1:
            for (int i = count_bill - 1; i >= 0; i--) {
                if ((bill + i)->get_thoi_gian().nam < temp.nam || ((bill + i)->get_thoi_gian().thang <= temp.thang && (bill + i)->get_thoi_gian().nam == temp.nam)) break;
                if ((bill + i)->get_trang_thai() == false) {
                    if (count == 0) {
                        cout << "Tất cả hóa đơn chưa thanh toán của phòng " << ten_phong << " là: " << endl;
                        cout << "╔═════╦═══════════════╦═══════════╦════════════╦════════════╦════════════╦════════════╦════════════╗" << endl;
                        cout << "║ " << setw(3) << setfill(' ')<< left << centerText("STT", 3) << " ║ " << setw(13) << left << centerText("ID hoa don", 13) << " ║ " << setw(9) << centerText("Thoi gian",9) << " ║ "<< setw(10) << left << centerText("Tien phong", 10) << " ║ " << setw(10) << left << centerText("Tien dien", 10) << " ║ " << setw(10) << left << centerText("Tien nuoc", 10) << " ║ " << setw(10) << left << centerText("Tong tien", 10) << " ║ " <<  setw(10) << left << centerText("Han nop",10) << " ║" << endl;
                    }
                    count++;
                    cout << "╠═════╬═══════════════╬═══════════╬════════════╬════════════╬════════════╬════════════╬════════════╣" << endl;
                    cout << "║ " << setw(3) << setfill(' ')<< left << count << " ║ "  << setw(13) << left << (bill + i)->get_ID_hoa_don() << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_thoi_gian().nam << "   ║ " << setw(10) << setfill(' ') << left << doubleToString(gia_phong) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_dien()) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_nuoc()) << " ║ " << setw(10) << left << doubleToString(gia_phong + (bill + i)->get_tien_dien() + (bill + i)->get_tien_nuoc()) << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_han_nop().ngay << "/" << setw(2) << setfill('0') << (bill + i)->get_han_nop().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_han_nop().nam << " ║" << endl; 
                    a[count] = i;
                    a[0] = count;
                }
            }
            if (count == 0){
                cout << "╔═════════════════════════════════════════════════════════╗\n";
                cout << "║       KHÔNG CÓ HÓA ĐƠN NÀO CHƯA THANH TOÁN              ║\n";
                cout << "╚═════════════════════════════════════════════════════════╝\n";
                getch_mac();
                return 0;
            } else{
                cout << "╚═════╩═══════════════╩═══════════╩════════════╩════════════╩════════════╩════════════╩════════════╝" << endl;
                cout << "Có tất cả " << count << " hóa đơn chưa thanh toán của phòng " << ten_phong << endl;
                return 1;
            }
            break;
        case 2:
            for (int i = count_bill - 1; i >= 0; i--) {
                if ((bill + i)->get_thoi_gian().nam < temp.nam || ((bill + i)->get_thoi_gian().thang <= temp.thang && (bill + i)->get_thoi_gian().nam == temp.nam)) break;
                if ((bill + i)->get_trang_thai() == true) {
                    if (count == 0){
                        cout << "Tất cả hóa đơn đã thanh toán của phòng " << ten_phong << " là: " << endl;
                        cout << "╔═════╦═══════════════╦═══════════╦════════════╦════════════╦════════════╦════════════╗" << endl;
                        cout << "║ " << setw(3) << setfill(' ')<< left << centerText("STT", 3)  << " ║ " << setw(13) << left << centerText("ID hoa don", 13) << " ║ " << setw(9) << centerText("Thoi gian",9) << " ║ "<< setw(10) << left << centerText("Tien phong", 10) << " ║ " << setw(10) << left << centerText("Tien dien", 10) << " ║ " << setw(10) << left << centerText("Tien nuoc", 10) << " ║ " << setw(10) << left << centerText("Tong tien", 10) << " ║" << endl;
                    }
                    count++;
                    cout << "╠═════╬═══════════════╬═══════════╬════════════╬════════════╬════════════╬════════════╣" << endl;
                    cout << "║ " << setw(3) << setfill(' ')<< left << count << " ║ "  << setw(13) << left << (bill + i)->get_ID_hoa_don() << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_thoi_gian().nam << "   ║ " << setw(10) << setfill(' ') << left << doubleToString(gia_phong) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_dien()) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_nuoc()) << " ║ " << setw(10) << left << doubleToString(gia_phong + (bill + i)->get_tien_dien() + (bill + i)->get_tien_nuoc()) << " ║" << endl;
                }
            }
            if (count == 0) {
                cout << "╔═════════════════════════════════════════════════════════╗\n";
                cout << "║         KHÔNG CÓ HÓA ĐƠN NÀO ĐÃ THANH TOÁN              ║\n";
                cout << "╚═════════════════════════════════════════════════════════╝\n";
                getch_mac();
            } else{
                cout << "╚═════╩═══════════════╩═══════════╩════════════╩════════════╩════════════╩════════════╝" << endl;
                cout << "Có tất cả " << count << " hóa đơn đã thanh toán của phòng " << ten_phong << endl;
                cout << "Nhấn phím bất kỳ để tiếp tục" << endl;
                getch_mac();
            }
            break;
        case 3:
            for (int i = count_bill - 1; i >= 0; i--) {  
                if ((bill + i)->get_thoi_gian().nam < temp.nam || ((bill + i)->get_thoi_gian().thang <= temp.thang && (bill + i)->get_thoi_gian().nam == temp.nam)) break;              
                if (count == 0){
                    cout << "Tất cả hóa đơn của phòng " << ten_phong << " là: " << endl;
                    cout << "╔═════╦═══════════════╦═══════════╦════════════╦════════════╦════════════╦════════════╦════════════╦════╗" << endl;
                    cout << "║ " << setw(3) << setfill(' ')<< left << centerText("STT", 3) << " ║ " << setw(13) << left << centerText("ID hoa don", 13) << " ║ " << setw(9) << centerText("Thoi gian",9) << " ║ "<< setw(10) << left << centerText("Tien phong", 10) << " ║ " << setw(10) << left << centerText("Tien dien", 10) << " ║ " << setw(10) << left << centerText("Tien nuoc", 10) << " ║ " << setw(10) << left << centerText("Tong tien", 10) << " ║ " <<  setw(10) << left << centerText("Han nop",10) << " ║ " << setw(2) << setfill(' ') << left << centerText("TT", 2) << " ║" << endl;
                }
                if ((bill + i)->get_trang_thai() == false) check = 1;
                count++;
                cout << "╠═════╬═══════════════╬═══════════╬════════════╬════════════╬════════════╬════════════╬════════════╬════╣" << endl;
                cout << "║ " << setw(3) << setfill(' ') << left << count << " ║ " << setw(13) << left << (bill + i)->get_ID_hoa_don() << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_thoi_gian().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_thoi_gian().nam << "   ║ " << setw(10) << setfill(' ') << left << doubleToString(gia_phong) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_dien()) << " ║ " << setw(10) << left << doubleToString((bill + i)->get_tien_nuoc()) << " ║ " << setw(10) << left << doubleToString(gia_phong + (bill + i)->get_tien_dien() + (bill + i)->get_tien_nuoc()) << " ║ " << setw(2) << setfill('0') << right << (bill + i)->get_han_nop().ngay << "/" << setw(2) << setfill('0') << (bill + i)->get_han_nop().thang << "/" << setw(4) << setfill('0') << (bill + i)->get_han_nop().nam << " ║ " << setw(2) << setfill(' ') << left << (bill + i)->get_trang_thai() << " ║" << endl;
            }

             if (count == 0) {
                cout << "╔═════════════════════════════════════════════════════════╗\n";
                cout << "║                   KHÔNG CÓ HÓA ĐƠN NÀO                  ║\n";
                cout << "╚═════════════════════════════════════════════════════════╝\n";
                getch_mac();
            } else{
                cout  << "╚═════╩═══════════════╩═══════════╩════════════╩════════════╩════════════╩════════════╩════════════╩════╝" << endl;
                cout << "Có tất cả " << count << " hóa đơn của phòng " << ten_phong << endl;
                if (check == 1) return 1;
                cout << "Nhấn phím bất kỳ để tiếp tục" << endl;
                getch_mac();
                break;
            }
        case 4:
            break;
    }
    return 0;
}
