#include "hoa_don.h"

Time add_time(int ngay, int thang, int nam){
    Time TG;
    TG.ngay = ngay;
    TG.thang = thang;
    TG.nam = nam;
    return TG;
}

hoa_don::hoa_don(){
    this->ID_hoa_don = "";
    this->ID_phong = "";
    this->tien_dien = 0;
    this->tien_nuoc = 0;
    this->han_nop = add_time(0, 0, 0);
    this->thoi_gian = add_time(0, 0, 0);
    this->trang_thai = false;
}

hoa_don::hoa_don(string ID, string ID_phong, double tien_dien, double tien_nuoc, Time thoi_gian, Time han_nop, bool trang_thai){
    this->ID_hoa_don = ID;
    this->ID_phong = ID_phong;
    this->tien_dien = tien_dien;
    this->tien_nuoc = tien_nuoc;
    this->han_nop = han_nop;
    this->thoi_gian = thoi_gian;
    this->trang_thai = trang_thai;
}

string hoa_don::get_ID_hoa_don(){
    return this->ID_hoa_don;
}

string hoa_don::get_ID_phong(){
    return this->ID_phong;
}

double hoa_don::get_tien_dien(){
    return this->tien_dien;
}

double hoa_don::get_tien_nuoc(){
    return this->tien_nuoc;
}

Time hoa_don::get_han_nop(){
    return this->han_nop;
}

Time hoa_don::get_thoi_gian(){
    return this->thoi_gian;
}

bool hoa_don::get_trang_thai(){
    return this->trang_thai;
}

void hoa_don::set_ID_hoa_don(string ID){
    this->ID_hoa_don = ID;
}

void hoa_don::set_ID_phong(string ID_phong){
    this->ID_phong = ID_phong;
}

void hoa_don::set_tien_dien(double tien_dien){
    this->tien_dien = tien_dien;
}

void hoa_don::set_tien_nuoc(double tien_nuoc){
    this->tien_nuoc = tien_nuoc;
}

void hoa_don::set_han_nop(Time han_nop){
    this->han_nop = han_nop;
}

void hoa_don::set_thoi_gian(Time thoi_gian){
    this->thoi_gian = thoi_gian;
}

void hoa_don::set_trang_thai(bool trang_thai){
    this->trang_thai = trang_thai;
}



string doubleToString(double value) {
    string result = to_string(value);
    result.erase(result.find_last_not_of('0') + 1, string::npos);
    if (result.back() == '.') 
        result.pop_back(); 
    return result;
}

string centerText(const string& text, int width) {
    if (width <= text.length()) return text.substr(0, width); // Nếu độ rộng nhỏ hơn hoặc bằng độ dài văn bản, cắt bớt văn bản
    int padding = (width - text.length()) / 2;
    int extra = (width - text.length()) % 2; // Thêm khoảng trắng nếu độ rộng là số lẻ
    return std::string(padding, ' ') + text + std::string(padding + extra, ' ');
}

Time thuc_te(){
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    // Chuyển đổi thời gian thành time_t để có thể sử dụng với std::localtime
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    // Chuyển đổi thành struct tm để có thể định dạng thời gian
    std::tm* now_tm = std::localtime(&now_time);
    
    Time TG;
    TG.ngay = now_tm->tm_mday;       // Ngày trong tháng (1-31)
    TG.thang = now_tm->tm_mon + 1;   // Tháng trong năm (0-11), cần cộng thêm 1 để có tháng từ 1-12
    TG.nam = now_tm->tm_year + 1900; // Năm kể từ 1900, cần cộng thêm 1900 để có năm hiện tại
    return TG;
}

Time date_new(Time date, int month){ 
    Time t = date;
    do {
        if (t.thang == 12) {
            t.thang = 1;
            t.nam++;
        }else{
            t.thang++;
        }
    }while (--month);

    int day_max;
    switch (t.thang) {
        case 4: case 6: case 9: case 11:
            day_max = 30;
            break;
        case 2: 
            if (t.nam % 400 == 0 || (t.nam % 4 == 0 && t.nam % 100 != 0)) {
                day_max = 29;
            } else {
                day_max = 28;
            }
            break;
        default: 
            day_max = 31;
            break;
    }
    if (t.ngay > day_max)  t.ngay = day_max;
    return t;
}

double tinh_tien_dien(int soDienCu, int soDienMoi) {
    int soDienTieuThu = soDienMoi - soDienCu;
    double tienDien = 0.0;

    if (soDienTieuThu <= 50) {
        tienDien = soDienTieuThu * 1.678; // Đơn giá cho 50 kWh đầu tiên
    } else if (soDienTieuThu <= 100) {
        tienDien = 50 * 1.678 + (soDienTieuThu - 50) * 1.734;
    } else if (soDienTieuThu <= 200) {
        tienDien = 50 * 1.678 + 50 * 1.734 + (soDienTieuThu - 100) * 2.014;
    } else if (soDienTieuThu <= 300) {
        tienDien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (soDienTieuThu - 200) * 2.536;
    } else if (soDienTieuThu <= 400) {
        tienDien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (soDienTieuThu - 300) * 2.834;
    } else {
        tienDien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (soDienTieuThu - 400) * 2.927;
    }

    return tienDien;
}

double tinh_tien_nuoc(int soNuocCu, int soNuocMoi) {
    int soNuocTieuThu = soNuocMoi - soNuocCu;
    double tienNuoc = 0.0;

    if (soNuocTieuThu <= 10) {
        tienNuoc = soNuocTieuThu * 6000; // Đơn giá cho 10 m³ đầu tiên
    } else if (soNuocTieuThu <= 20) {
        tienNuoc = 10 * 6000 + (soNuocTieuThu - 10) * 7000;
    } else if (soNuocTieuThu <= 30) {
        tienNuoc = 10 * 6000 + 10 * 7000 + (soNuocTieuThu - 20) * 8000;
    } else {
        tienNuoc = 10 * 6000 + 10 * 7000 + 10 * 8000 + (soNuocTieuThu - 30) * 10000;
    }

    return tienNuoc;
}



char getch_mac_sp() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt); // Lấy thuộc tính hiện tại của terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Tắt chế độ canonical và echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Áp dụng thuộc tính mới
    ch = getchar(); // Đọc ký tự từ bàn phím
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Khôi phục thuộc tính cũ
    
    return ch; // Trả về ký tự đã nhập
}
char getch_mac() {
    char ch = getch_mac_sp();
    if (ch == 0x1B) { // ESC
        char next = getch_mac(); // Đọc ký tự tiếp theo
        if (next == '[') { // Nếu là '['
            char arrow = getch_mac(); // Đọc ký tự thứ ba
            switch (arrow) {
                case 'A': return 72; // Mũi tên lên
                case 'B': return 80; // Mũi tên xuống
                case 'C': return 77; // Mũi tên phải (nếu cần)
                case 'D': return 75; // Mũi tên trái (nếu cần)
            }
        }
    }
    return ch; // Trả về ký tự đã nhập nếu không phải phím đặc biệt
}
