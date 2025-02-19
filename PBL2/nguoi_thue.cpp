#include "nguoi_thue.h"

bool check_so(string s){
    for (int i = 0; i < s.length(); i++){
        if (s[i] < '0' || s[i] > '9'){
            return false;
        }
    }
    return true;
}

nguoi_thue::nguoi_thue(){
    this->trang_thai = true;
    this->ID_phong = "";
    this->my_phong = nullptr;
}

nguoi_thue::nguoi_thue(string ID, string ten, string que_quan, string SDT, string CCCD, bool gioi_tinh, bool trang_thai, string ID_phong)
 : nguoi(ID, ten,gioi_tinh, que_quan, SDT, CCCD){
    
    this->trang_thai = trang_thai;
    this->ID_phong = ID_phong;
    this->my_phong = nullptr;
    
}

bool nguoi_thue::get_gioi_tinh(){
    return this->gioi_tinh;
}

bool nguoi_thue::get_trang_thai(){
    return this->trang_thai;
}

phong_tro& nguoi_thue::get_my_phong(){
    return *this->my_phong;
}

string nguoi_thue::get_ID_phong(){
    return this->ID_phong;
}

void nguoi_thue::set_gioi_tinh(bool gioi_tinh){
    this->gioi_tinh = gioi_tinh;
}

void nguoi_thue::set_trang_thai(bool trang_thai){
    this->trang_thai = trang_thai;
}

void nguoi_thue::set_ID_phong(string ID_phong){
    this->ID_phong = ID_phong;
}

void nguoi_thue::set_my_phong(phong_tro& my_phong){
    this->my_phong = &my_phong;
}

void nguoi_thue::show_info_me(){
    cout << "╔══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║           ╔══════════════════════════════════════════════╗           ║\n";
    cout << "║           ║                 THÔNG TIN CÁ NHÂN            ║           ║\n";
    cout << "║           ╚══════════════════════════════════════════════╝           ║\n";
    cout << "║                ╔═════════════════════════════════════════════════╗   ║\n";
    cout << "║  Họ và tên     ║ " << setw(48) << setfill(' ') << left << get_ten() << "║   ║ \n";
    cout << "║                ╚═════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                      ║\n";
    cout << "║                ╔═════════════════════════════════════════════════╗   ║\n";
    cout << "║  Giới tính     ║ ";
    (get_gioi_tinh()) ? cout << setw(48) << left << "Nam" << "║   ║\n": cout << setw(48) << left << "Nu"<< "║   ║\n";
    cout << "║                ╚═════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                      ║\n";
    cout << "║                ╔═════════════════════════════════════════════════╗   ║\n";
    cout << "║  Số điện thoại ║ " << setw(48) << left << get_SDT() << "║   ║\n";
    cout << "║                ╚═════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                      ║\n";
    cout << "║                ╔═════════════════════════════════════════════════╗   ║\n";
    cout << "║  CCCD          ║ " << setw(48) << left << get_CCCD() << "║   ║\n";
    cout << "║                ╚═════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                      ║\n";
    cout << "║                ╔═════════════════════════════════════════════════╗   ║\n";
    cout << "║  Địa chỉ       ║ " << setw(48) << left << get_dia_chi() << "║   ║\n";
    cout << "║                ╚═════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                      ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════╝\n";
}

hop_dong nguoi_thue::tao_hop_dong(double tien_phong){
    string ID_hop_dong,ID_thue;
    Time ngay_thue = thuc_te(), ngay_het_han;
    int ch,selected ;

    if (get_my_phong().get_count_hd() == 0) ID_hop_dong = get_my_phong().get_ID_phong() + "001";
    else ID_hop_dong = tang_chuoi_so(get_my_phong().get_hop_dong(get_my_phong().get_count_hd() - 1).get_ID_hop_dong());
    ID_thue = this->ID;

    selected = 0;
     do {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════╗\n";
        cout << "║           ╔══════════════════════════════╗          ║\n";
        cout << "║           ║        CHỌN GÓI THUÊ         ║          ║\n";
        cout << "║           ╚══════════════════════════════╝          ║\n";     
        cout << "║                                                     ║\n";
        cout << "║                                                     ║\n";
        
        for (int i = 0; i < 4; i++) {
            if (selected == i) cout << "║    >>>    " << i + 1 << ". ";
            else cout << "║           " << i + 1 << ". ";
            switch (i + 1) {
                case 1:   
                    cout << "1 tháng                        ";
                    break;
                case 2:
                    cout << "3 tháng                        ";
                    break;
                case 3:
                    cout << "6 tháng                        ";
                    break;
                case 4:
                    cout << "12 tháng                       ";
                    break;
                
            }
            if (selected == i) cout << " <<<    ║\n";
            else cout << "        ║\n";
            cout << "║                                                     ║\n";
        }
        cout << "║                                                     ║\n";
        cout << "║                                                     ║\n";
        cout << "╚═════════════════════════════════════════════════════╝\n";
        
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
    } while (ch != '\n');

    switch (++selected){
        case 1:
            ngay_het_han= date_new(ngay_thue,1);
            break;
        case 2:
            ngay_het_han = date_new(ngay_thue,3);
            break;
        case 3:
            ngay_het_han= date_new(ngay_thue,6);
            break;
        case 4:
            ngay_het_han = date_new(ngay_thue,12);
            break;
    }
    return hop_dong(ID_hop_dong,  ID_phong, ID_thue,tien_phong, ngay_thue, ngay_het_han, ngay_het_han, 1);
}

phong_tro nguoi_thue::hoi_yeu_cau_thue(chu_tro*& ct, pair<int,int>* temp, int count, hop_dong& hd, int& thoat){
    thoat = 0;
    int choice, choice1;
    cout << "Nhập số thứ tự phòng bạn muốn thuê (nhập 0 để quay lại)        : ";
    if (!(cin >> choice)){
        cin.clear(); 
        cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
        thoat = 1;
        return phong_tro();
    }

    if (choice == 0) { getch_mac(); return phong_tro(); }
    if (choice < 1 || choice > count) {
        thoat = 1;
        return phong_tro();
    }

    int t = 0;
    if (choice != 0){
        int selected = 0;
        char ch;
        cin.ignore(  std::numeric_limits<std::streamsize>::max(), '\n' );
        do{
            system("clear");
            cout << setw( 50 ) << "" << " <Thông Tin Phòng Bạn Muốn Thuê> " << endl;
            (ct + (temp + choice)->first)->get_phong((temp + choice)->second).show_ten_thuoc_tinh(t, (ct + (temp + choice)->first)->get_dia_chi()); t=0;
            cout << "╚═════╩══════════╩═════════╩════════════════╩════════════════╩════════════════════════════════════════════════════╩══════════════════════════════════════════╝" << endl;
            cout << "╔═════════════════════════════════════════════╗\n";
            cout << "║           ╔══════════════════════╗          ║\n";
            cout << "║           ║        CHỌN          ║          ║\n";
            cout << "║           ╚══════════════════════╝          ║\n";
            cout << "║                                             ║\n";
            for (int i = 0; i <2; i++) {
                if (selected == i) cout << "║    >>>    " << i + 1 << ". ";
                else cout << "║           " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << " Có                    ";
                        break;  
                    case 2:
                        cout << " Không                 ";
                        break;
                        }
                if (selected == i) cout << "   <<<  ║\n";
                else cout << "        ║\n";
                cout << "║                                             ║\n";
            }
            cout << "╚═════════════════════════════════════════════╝\n";
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
        }while(ch!='\n');

        if (++selected == 1){
            (ct + (temp + choice)->first)->get_phong((temp + choice)->second).set_ID_thue(this->ID);
            (ct + (temp + choice)->first)->get_phong((temp + choice)->second).set_trang_thai(1);
            
            set_ID_phong((ct + (temp + choice)->first)->get_phong((temp + choice)->second).get_ID_phong());
            set_trang_thai(true);
            set_my_phong((ct + (temp + choice)->first)->get_phong((temp + choice)->second));
            hd = tao_hop_dong( (ct + (temp + choice)->first)->get_phong((temp + choice)->second).get_gia_phong());
            (ct + (temp + choice)->first)->get_phong((temp + choice)->second).add_hd_array(hd);
            Time real = thuc_te();
            get_my_phong().search_hd(real, *(ct + (temp + choice)->first), this, 1);
            getch_mac();
            return (ct + (temp + choice)->first)->get_phong((temp + choice)->second);
            free(temp);
        }

    }
   
    return phong_tro();
}

phong_tro nguoi_thue::search_phong_thue_theo_gia(chu_tro*& ct, int count_chu, hop_dong& hd){
    int count , choice, choice1,thoat;
    double gia_min, gia_max;
    phong_tro phong;
    pair<int, int>* temp = nullptr;
    bool check_min = true, check_max = true;

    do {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                      XEM PHÒNG THEO GIÁ                                     ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if (!check_min) cout << "ERROR: Giá phòng tối thiểu không hợp lệ. Vui lòng nhập lại!!!" << endl;
        if (!check_max) cout << "ERROR: Giá phòng tối đa không hợp lệ. Vui lòng nhập lại!!!" << endl;
        cout << endl << endl;
        cout << "Nhập giá phòng tối thiểu (VND)                :";
        if (!(cin >> gia_min) ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            check_min = false;
        } else if (gia_min < 0 ) check_min = false;
        else check_min = true;

        cout << "Nhập giá phòng tối đa                         :";
        if (!(cin >> gia_max)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            check_max = false;
        } else if (gia_max < gia_min) check_max = false;
        else check_max =  true;
    } while(!check_max || !check_min);
    cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
    do {
        system("clear");
        int count = 0;
        cout << string(25, ' ') << "╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << string(25, ' ') << "║                                      XEM PHÒNG THEO GIÁ                                     ║\n";
        cout << string(25, ' ') << "╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl;
        for(int i = 0; i < count_chu; i++){
            for (int j = 0; j < (ct + i)->get_count_phong(); j++){
                if ((ct + i)->get_phong(j).get_gia_phong() >= gia_min && (ct + i)->get_phong(j).get_gia_phong() <= gia_max && (ct + i)->get_phong(j).get_trang_thai() == false){
                    (ct + i)->get_phong(j).show_ten_thuoc_tinh(count, (ct + i)->get_dia_chi());
                    temp = (pair<int,int>*)realloc(temp, (count + 1)*sizeof(pair<int,int>));
                    (temp + count)->first = i;
                    (temp + count)->second = j;
                }
            }
        }
        int thoat = 0;
        if (count != 0) {
            cout << "╚═════╩══════════╩═════════╩════════════════╩════════════════╩════════════════════════════════════════════════════╩══════════════════════════════════════════╝" << endl;
            cout << "   Có tất cả " << count << " phòng thoả mãn điều kiện" << endl << endl;
            if((phong = hoi_yeu_cau_thue(ct, temp, count, hd, thoat)).get_ID_phong()!="") return phong; 
            else{   
                if(thoat == 0) return phong_tro();
                cout << "ERROR: Vui lòng nhập môt số hợp lệ!" << endl;
                cout << "Nhấn phím bất kì để nhập lại!" << endl;
                getch_mac();
                continue;
            }
        }else{
            system("clear");
            cout << setw(40) << "" << "╔════════════════════════════════════════════════════════════════╗\n";
            cout << setw(40) << "" << "║            KHÔNG CÓ PHÒNG NÀO THỎA MÃN ĐIỀU KIỆN               ║\n";
            cout << setw(40) << "" << "╚════════════════════════════════════════════════════════════════╝\n" << endl;
            getch_mac();
            return phong_tro();
        }
        break;
    }while(1);
    return phong_tro();
}

phong_tro nguoi_thue::search_phong_thue_theo_dien_tich(chu_tro*& ct, int count_chu, hop_dong& hd){
    float dien_tich_min, dien_tich_max;
    int count, choice, choice1,thoat;
    phong_tro phong;
    pair<int, int>* temp = nullptr;
    bool check_max =true, check_min = true;

    do {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                   XEM PHÒNG THEO DIỆN TÍCH                                  ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if (!check_min) cout << "ERROR: Diện tích tối thiểu không hợp lệ. Vui lòng nhập lại!!!" << endl;
        if (!check_max) cout << "ERROR: Diện tích tối đa không hợp lệ. Vui lòng nhập lại!!!" << endl;
        cout << endl << endl;
        cout << "Nhập diện tích tối thiểu (mét vuông)                :";
        if (!(cin >> dien_tich_min)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            check_min = false;
        } else if (dien_tich_min < 0) check_min = false;
        else check_min = true;

        cout << "Nhập diện tích tối đa                               :";
        if (!(cin >> dien_tich_max)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            check_max = false;
        } else if (dien_tich_max < dien_tich_min) check_max = false;
        else check_max =  true;
    } while(!check_max || !check_min);
    
    do {
        system("clear");
        count = 0;
        cout << string(25, ' ') << "╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << string(25, ' ') << "║                                   XEM PHÒNG THEO DIỆN TÍCH                                  ║\n";
        cout << string(25, ' ') << "╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl; 
        for (int i = 0; i < count_chu; i++)
            for (int j = 0; j < (ct + i)->get_count_phong(); j++)
                if ((ct + i)->get_phong(j).get_dien_tich() >= dien_tich_min && (ct + i)->get_phong(j).get_dien_tich() <= dien_tich_max && (ct + i)->get_phong(j).get_trang_thai() == false) {
                    (ct + i)->get_phong(j).show_ten_thuoc_tinh(count, (ct + i)->get_dia_chi());
                    temp = (pair<int,int>*)realloc(temp, (count + 1)*sizeof(pair<int,int>));
                    (temp + count)->first = i;
                    (temp + count)->second = j;
                }
        if (count != 0) {
            cout << "╚═════╩══════════╩═════════╩════════════════╩════════════════╩════════════════════════════════════════════════════╩══════════════════════════════════════════╝" << endl;
            cout << "   Có tất cả " << count << " phòng thoả mãn điều kiện" << endl << endl;
            if((phong=hoi_yeu_cau_thue(ct, temp, count,hd,thoat)).get_ID_phong()!="") return phong; 
            else{
                if(thoat == 0) return phong_tro();
                cout << "ERROR: Vui lòng nhập môt số hợp lệ!" << endl;
                cout << "Nhấn phím bất kì để nhập lại!" << endl;
                getch_mac();
                continue;
            }
        }else{
            system("clear");
            cout << setw(40) << "" << "╔════════════════════════════════════════════════════════════════╗\n";
            cout << setw(40) << "" << "║            KHÔNG CÓ PHÒNG NÀO THỎA MÃN ĐIỀU KIỆN               ║\n";
            cout << setw(40) << "" << "╚════════════════════════════════════════════════════════════════╝\n" << endl;
            cin.ignore();
            getch_mac();

            return phong_tro();
        }
        break;
    }while(1);
    return phong_tro();
}

phong_tro nguoi_thue::search_phong_thue_theo_dia_chi(chu_tro*& ct, int count_chu, hop_dong& hd){
    string dia_chi;
    int count , choice, choice1,thoat;
    phong_tro phong;
    pair<int,int> *temp = nullptr;
    bool check = true;

    do {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                   XEM PHÒNG THEO ĐỊA CHỈ                                    ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if (!check) cout << "ERROR: Địa chỉ không được để trống. Vui lòng nhập lại!!!" << endl;
        cout << endl << endl;
        cout << "Nhập địa chỉ cần tìm                       :" ;
        getline(cin, dia_chi);
        if (dia_chi.length() == 0){
            check = false;
            continue;
        }
        break;
    } while(1);

    do{
        system("clear");
        count = 0;
        cout << string(25, ' ') << "╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << string(25, ' ') << "║                                   XEM PHÒNG THEO ĐỊA CHỈ                                    ║\n";
        cout << string(25, ' ') << "╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl;
        for (int i = 0; i < count_chu; i++)
            if ((ct + i)->get_dia_chi().find(dia_chi) != string::npos ) 
                for (int j = 0; j < (ct + i)->get_count_phong(); j++) 
                    if((ct + i)->get_phong(j).get_trang_thai() == false) {
                        (ct + i)->get_phong(j).show_ten_thuoc_tinh(count, (ct + i)->get_dia_chi());
                        temp = (pair<int,int>*)realloc(temp, (count + 1)*sizeof(pair<int,int>));
                        (temp + count)->first = i;
                        (temp + count)->second = j;
                    }
        if (count != 0) {
            cout << "╚═════╩══════════╩═════════╩════════════════╩════════════════╩════════════════════════════════════════════════════╩══════════════════════════════════════════╝" << endl;
            cout << "   Có tất cả " << count << " phòng thoả mãn điều kiện" << endl << endl;
            if((phong = hoi_yeu_cau_thue(ct, temp, count, hd, thoat)).get_ID_phong()!="") return phong; 
            else{   
               if(thoat == 0) return phong_tro();
                cout << "ERROR: Vui lòng nhập môt số hợp lệ!" << endl;
                cout << "Nhấn phím bất kì để nhập lại!" << endl;
                getch_mac();
                continue;
            }

        }else{
            system("clear");
            cout << setw(40) << "" << "╔════════════════════════════════════════════════════════════════╗\n";
            cout << setw(40) << "" << "║            KHÔNG CÓ PHÒNG NÀO THỎA MÃN ĐIỀU KIỆN               ║\n";
            cout << setw(40) << "" << "╚════════════════════════════════════════════════════════════════╝\n" << endl;
            getch_mac();
            return phong_tro();
        }
    }while(1);
    return phong_tro();
}

phong_tro nguoi_thue::search_phong_thue_ALL(chu_tro*& ct, int count_chu,hop_dong& hd){
    int count, choice, choice1,thoat;
    phong_tro phong;
    pair<int,int>* temp = nullptr;
    do{
        system("clear");
        int count = 0;
        cout << string(25, ' ') << "╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << string(25, ' ') << "║                                      XEM TẤT CẢ PHÒNG                                       ║\n";
        cout << string(25, ' ') << "╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl;
       
        for (int i = 0; i < count_chu; i++)
            for (int j = 0; j < (ct + i)->get_count_phong(); j++)
                if ((ct + i)->get_phong(j).get_trang_thai() == 0) {
                    (ct + i)->get_phong(j).show_ten_thuoc_tinh(count, (ct + i)->get_dia_chi());
                    temp = (pair<int,int>*)realloc(temp, (count + 1)*sizeof(pair<int,int>));
                    (temp + count)->first = i;
                    (temp + count)->second = j;
                }
        int thoat = 0;
        if (count != 0) {
            cout << "╚═════╩══════════╩═════════╩════════════════╩════════════════╩════════════════════════════════════════════════════╩══════════════════════════════════════════╝" << endl;
            cout << "   Có tất cả " << count << " phòng thoả mãn điều kiện" << endl << endl;
            if((phong = hoi_yeu_cau_thue(ct, temp, count, hd, thoat)).get_ID_phong()!="") return phong; 
            else{   
               
               if(thoat == 0) return phong_tro();
                system("clear");
                cout << "ERROR: Vui lòng nhập môt số hợp lệ!" << endl;
                cout << "Nhấn phím bất kì để nhập lại!" << endl;
                cin.ignore();
                getch_mac();
                continue;
            }
        }else{
            system("clear");
            cout << setw(40) << "" << "╔════════════════════════════════════════════════════════════════╗\n";
            cout << setw(40) << "" << "║            KHÔNG CÓ PHÒNG NÀO THỎA MÃN ĐIỀU KIỆN               ║\n";
            cout << setw(40) << "" << "╚════════════════════════════════════════════════════════════════╝\n" << endl;
            getch_mac();
            return phong_tro();
        }
        break;
    }while (1);
    return phong_tro();
}

int nguoi_thue::update_nguoi_thue(int& updateChoice){
    string ten, que_quan, SDT, CCCD;
    bool gioi_tinh;
    char ch;

    updateChoice = 0;
    do {
        system("clear");
        show_info_me();
        cout << string(8, ' ') << "╔═════════════════════════════════════════════════════╗\n";
        cout << string(8, ' ') << "║           ╔══════════════════════════════╗          ║\n";
        cout << string(8, ' ') << "║           ║      CẬP NHẬT THÔNG TIN      ║          ║\n";
        cout << string(8, ' ') << "║           ╚══════════════════════════════╝          ║\n";     
        cout << string(8, ' ') << "║                                                     ║\n";
        cout << string(8, ' ') << "║                                                     ║\n";
        for (int i = 0; i < 6; i++) {
            if (updateChoice == i) cout << string(8, ' ') << "║    >>>    " << i + 1 << ". ";
            else cout << string(8, ' ') <<  "║           " << i + 1 << ". ";
            switch (i + 1) {
                case 1:   
                    cout << "Tên                            ";
                    break;
                case 2:
                    cout << "Giới tính                      ";
                    break;
                case 3:
                    cout << "Số điện thoại                  ";
                    break;
                case 4:
                    cout << "CCCD                           ";
                    break;
                case 5:
                    cout << "Quê quán                       ";
                    break;
                case 6:
                    cout << "Quay lại                       ";
                    break;
            }
            if (updateChoice == i) cout << " <<<    ║\n";
            else cout << "        ║\n";
            cout << string(8, ' ') << "║                                                     ║\n";
        }
        cout << string(8, ' ') << "║                                                     ║\n";
        cout << string(8, ' ') << "║                                                     ║\n";
        cout << string(8, ' ') << "╚═════════════════════════════════════════════════════╝\n";
        
        ch = getch_mac(); 
        switch (ch) {
            case 72: 
                updateChoice = (updateChoice - 1 + 6) % 6;
                break;
            case 80: 
                updateChoice = (updateChoice + 1) % 6;
                break;
            case '\n': 
                break;
        }
    } while (ch != '\n');
    bool check = true;  
    switch (++updateChoice){
        case 1:
            do
            {   
                system("clear");
                cout << string(12, ' ') << "╔═════════════════════════════════════════════════════╗\n";
                cout << string(12, ' ') << "║                  CẬP NHẬT HỌ VÀ TÊN                 ║\n";
                cout << string(12, ' ') << "╚═════════════════════════════════════════════════════╝\n";
                cout << endl;
                show_info_me();
                cout << endl << endl;
                if (!check) cout << "ERROR: Tên không được để trống hoặc tên quá ký tự. Vui lòng nhập lại!" << endl;
                cout << "Nhập tên mới                                :"; 
                getline(cin, ten);
                if (ten.length()==0 || ten.length()>20) {
                    check = false;
                    continue;
                }
                break;
            } while (1);
            set_ten(ten);
            break;
        case 2:
            int selected;
            char ch;
            selected = 0;
            do{
                system("clear");
                cout << string(9, ' ') << "╔═════════════════════════════════════════════════════╗\n";
                cout << string(9, ' ') << "║                   CẬP NHẬT GIỚI TÍNH                ║\n";
                cout << string(9, ' ') << "╚═════════════════════════════════════════════════════╝\n";
                cout << endl;
                show_info_me();
                cout << endl << endl;
                cout << string(12, ' ') << "╔═════════════════════════════════════════════╗\n";
                cout << string(12, ' ') << "║           ╔══════════════════════╗          ║\n";
                cout << string(12, ' ') << "║           ║        CHỌN          ║          ║\n";
                cout << string(12, ' ') << "║           ╚══════════════════════╝          ║\n";
                cout << string(12, ' ') << "║                                             ║\n";
                for (int i = 0; i <2; i++) {
                    if (selected == i) cout << string(12, ' ') << "║    >>>    " << i + 1 << ". ";
                    else cout << string(12, ' ') <<  "║           " << i + 1 << ". ";
                    switch (i + 1) {
                        case 1:
                            cout << " Nam                   ";
                            break;  
                        case 2:
                            cout << " Nu                    ";
                            break;
                            }
                    if (selected == i) cout << "   <<<  ║\n";
                    else cout << "        ║\n";
                    cout <<  string(12, ' ') << "║                                             ║\n";
                }
                cout << string(12, ' ') << "╚═════════════════════════════════════════════╝\n";
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
            }while(ch!='\n');
            if (selected == 0) gioi_tinh = true;
            else gioi_tinh = false;
            this->set_gioi_tinh(gioi_tinh);
            break;
        case 3:
            do{
                system("clear");
                cout << string(12, ' ') << "╔═════════════════════════════════════════════════════╗\n";
                cout << string(12, ' ') << "║                CẬP NHẬT SỐ ĐIỆN THOẠI               ║\n";
                cout << string(12, ' ') << "╚═════════════════════════════════════════════════════╝\n";
                cout << endl;
                show_info_me();
                cout << endl << endl;
                if (!check) cout << "ERROR: Số điện thoại không hợp lệ. Vui lòng nhập lại!" << endl;
                cout << "Nhập số điện thoại mới                      :";
                getline(cin, SDT);
                if (SDT.length()!=10 || !check_so(SDT)) {
                    check = false;
                    continue;
                }
                break;
            }while(1);
            set_SDT(SDT);
            break;
        case 4:
            do{
                system("clear");
                cout << "╔═════════════════════════════════════════════════════╗\n";
                cout << "║                      CẬP NHẬT CCCD                  ║\n";
                cout << "╚═════════════════════════════════════════════════════╝\n";
                cout << endl;
                show_info_me();
                cout << endl << endl;
                cout << "   Nhap CCCD moi(12 so): ";
                if (!check) cout << "ERROR: CCCD không hợp lệ. Vui lòng nhập lại!" << endl;
                getline(cin, CCCD);
                if (CCCD.length()!=12 || !check_so(CCCD)) {
                    check = false;
                    continue;
                }
                break;
            }while(1);
            this->set_CCCD(CCCD);
            break;
        case 5:
            do
            {   system("clear");
                cout << string(12, ' ') << "╔═════════════════════════════════════════════════════╗\n";
                cout << string(12, ' ') << "║                  CẬP NHẬT QUÊ QUÁN                  ║\n";
                cout << string(12, ' ') << "╚═════════════════════════════════════════════════════╝\n";
                cout << endl;
                show_info_me();
                cout << endl << endl;
                if (!check) cout << "ERROR: Quê quán không được để trống hoặc 40 quê quán quá ký tự. Vui lòng nhập lại!" << endl;
                cout << "Nhập quê quán mới                           :";
                getline(cin, que_quan);
                if (que_quan.length()==0 || que_quan.length()>40) {
                    check = false;
                    continue;
                }
                break;
            } while (1);
            this->set_dia_chi(que_quan);
            break;
        case 6:
            system("clear");
            break;
    }
    return --updateChoice;
}

void nguoi_thue::show(){
    cout << setfill(' ') << "| " 
         << setw(9) << this->ID << " | "
         << setw(15) << this->ten << " | "
         << setw(40) << this->dia_chi << " | "
         << setw(9) << this->SDT << " | "
         << setw(12) << this->CCCD << " | ";
    if (this->gioi_tinh==true)
    {
        cout << "    Nam     |";
    }else{
        cout << "     Nữ     |";
    }
    if (this->trang_thai==true)
    {
        cout << "     Đã thuê    | ";
    }else{
        cout << "    Chưa thuê   | ";
    }
    if (this->ID_phong=="")
    {
        cout << "   Chưa có   |";
    }else{
        cout << setw(12) << this->ID_phong << " |";
    }
    cout << endl;
    cout <<  "+-----------+-----------------+------------------------------------------+------------+--------------+-------------+----------------+--------------+" << endl;
   
}

void nguoi_thue::xem_thong_tin_phong(chu_tro ct){
    system("clear");
    cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║               ╔══════════════════════════════════════════════════════════════════╗                  ║\n";
    cout << "║               ║                      THÔNG TIN PHÒNG HIỆN TẠI                    ║                  ║\n";
    cout << "║               ╚══════════════════════════════════════════════════════════════════╝                  ║\n";
    cout << "║                                                                                                     ║\n";
    cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
    cout << "║     Tên chủ trọ   ║ " << setw(75) << left << ct.get_ten() << " ║   ║\n";
    cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                                                     ║\n";
    cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
    cout << "║     SĐT chủ trọ   ║ " << setw(75) << left << ct.get_SDT() << " ║   ║\n";
    cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                                                     ║\n";
    cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
    cout << "║     Tên phòng     ║ " << setw(75) << left << get_my_phong().get_ten_phong() << " ║   ║ \n";
    cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                                                     ║\n";
    cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
    cout << "║     Giá phòng     ║ " << setw(75) << left << doubleToString(get_my_phong().get_gia_phong()) << " ║   ║\n";
    cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                                                     ║\n";
    cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
    cout << "║     Diện tích     ║ " << setw(75) << left << doubleToString(get_my_phong().get_dien_tich()) << " ║   ║\n";
    cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                                                     ║\n";
    cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
    cout << "║     Mô tả phòng   ║ " << setw(75) << left << get_my_phong().get_mo_ta_phong() << " ║   ║\n";
    cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                                                     ║\n";
    cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
    cout << "║     Địa chỉ       ║ " << setw(75) << left << ct.get_dia_chi() << " ║   ║\n";
    cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
    cout << "║                                                                                                     ║\n";
    cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    getch_mac();
}

hoa_don nguoi_thue::xem_thong_tin_hoa_don(){
    int a[20], b, choice = 0;
    char ch;

    do{
        system("clear");  
        cout << "╔═════════════════════════════════════════════════════╗\n";
        cout << "║           ╔══════════════════════════════╗          ║\n";
        cout << "║           ║            HÓA ĐƠN           ║          ║\n";
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

    int selected = 0;
    do{
        b = get_my_phong().show_bill_thue(a, choice);
        if (b == 0) return hoa_don();
        cout <<  endl;
        cout << "╔═══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║           ╔════════════════════════════════════════════════╗          ║\n";
        cout << "║           ║         BẠN CÓ MUỐN THANH TOÁN KHÔNG ?         ║          ║\n";
        cout << "║           ╚════════════════════════════════════════════════╝          ║\n";
        cout << "║                                                                       ║\n";
        cout << "║                                                                       ║\n";
    
        for (int i = 0; i < 2; i++) { 
            if (selected == i)cout << "║        >>>     " << i + 1 << ". ";
            else cout << "║                " << i + 1 << ". ";
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
            cout << "║                                                                       ║\n";
        }
        cout << "╚═══════════════════════════════════════════════════════════════════════╝\n";

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

    if (++selected == 1)  return xac_nhan_thanh_toan();    
    return hoa_don();
}
   
hoa_don nguoi_thue::xac_nhan_thanh_toan(){
    int choice, choice1, a[20], selected = 0;
    bool check = true;
    char ch;
    do{
        get_my_phong().show_bill_thue(a, 0);
        if (!check) cout << "ERROR: Số bạn chọn không hợp lệ. Vui lòng nhập lại!" << endl;
        cout << "Nhập thứ tự hóa đơn bạn muốn xác nhận (nhấn 0 để quay lại)     :";
        if (!(cin >> choice)){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            check = false;
            continue;
        } else {
            cin.clear();
            cin.ignore();
        }
        if (choice == 0) return hoa_don();
        if (choice < 0 || choice > a[0]){
            check = false;
            continue;
        }
        break;
    } while (1);
     do{
        system("clear");
        cout << "Thông tin hóa đơn bạn chọn: " << endl;
        cout << "╔═══════════════╦═══════════╦════════════╦════════════╦════════════╦════════════╦════════════╗" << endl;
        cout << "║ "  << setw(13) << left << centerText("ID hoa don", 13) << " ║ " << setw(9) << centerText("Thoi gian",9) << " ║ "<< setw(10) << left << centerText("Tien phong", 10) << " ║ " << setw(10) << left << centerText("Tien dien", 10) << " ║ " << setw(10) << left << centerText("Tien nuoc", 10) << " ║ " << setw(10) << left << centerText("Tong tien", 10) << " ║ " <<  setw(10) << left << centerText("Han nop",10) << " ║" << endl;
        cout << "╠═══════════════╬═══════════╬════════════╬════════════╬════════════╬════════════╬════════════╣" << endl;
        cout << "║ " << setw(13) << left << get_my_phong().get_bill(a[choice]).get_ID_hoa_don() << " ║ " << setw(2) << setfill('0') << right << get_my_phong().get_bill(a[choice]).get_thoi_gian().thang << "/" << setw(4) << setfill('0') << get_my_phong().get_bill(a[choice]).get_thoi_gian().nam << "   ║ " << setw(10) << setfill(' ') << left << doubleToString(get_my_phong().get_gia_phong()) << " ║ " << setw(10) << left << doubleToString(get_my_phong().get_bill(a[choice]).get_tien_dien()) << " ║ " << setw(10) << left << doubleToString(get_my_phong().get_bill(a[choice]).get_tien_nuoc()) << " ║ " << setw(10) << left << doubleToString(get_my_phong().get_gia_phong() + get_my_phong().get_bill(a[choice]).get_tien_dien() + get_my_phong().get_bill(a[choice]).get_tien_nuoc()) << " ║ " << setw(2) << setfill('0') << right << get_my_phong().get_bill(a[choice]).get_han_nop().ngay << "/" << setw(2) << setfill('0') << get_my_phong().get_bill(a[choice]).get_han_nop().thang << "/" << setw(4) << setfill('0') << get_my_phong().get_bill(a[choice]).get_han_nop().nam << " ║" << setfill(' ') << endl; 
        cout << "╚═══════════════╩═══════════╩════════════╩════════════╩════════════╩════════════╩════════════╝" << endl;
        cout << endl;
        cout <<  endl;
        cout << "╔═══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║           ╔════════════════════════════════════════════════╗          ║\n";
        cout << "║           ║           XÁC NHẬN BẠN ĐÃ THANH TOÁN ?         ║          ║\n";
        cout << "║           ╚════════════════════════════════════════════════╝          ║\n";
        cout << "║                                                                       ║\n";
        cout << "║                                                                       ║\n";
    
        for (int i = 0; i < 2; i++) { 
            if (selected == i)cout << "║        >>>     " << i + 1 << ". ";
            else cout << "║                " << i + 1 << ". ";
            switch (i + 1) {
                case 1:
                    cout << "Đã thanh toán                          ";
                    break;
                case 2:
                    cout << "Chưa thanh toán                        ";          
                    break;
            }
            if (selected == i) cout << "  <<<        ║\n";
            else cout << "             ║\n";
            cout << "║                                                                       ║\n";
        }
        cout << "╚═══════════════════════════════════════════════════════════════════════╝\n";

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
    } while (ch != '\n');

    if (++selected == 1){
        get_my_phong().get_bill(a[choice]).set_trang_thai(true);
        return get_my_phong().get_bill(a[choice]);
    }
    return hoa_don();
}

void nguoi_thue::thong_ke(hop_dong* hd,phong_tro* pt,chu_tro* ct, int count_hd, int count_phong, int count_chu){

   int count = 0, i, j, p;
   cout << string(20, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
   cout << string(20, ' ') << "║               THỐNG KÊ PHÒNG ĐÃ TỪNG THUÊ             ║\n";
   cout << string(20, ' ') << "╚═══════════════════════════════════════════════════════╝\n";
   for( i = 0; i < count_hd; i++) {  
        if( (hd + i)->get_ID_thue() == this->get_ID()) {
            if(count ==0){   
                cout << " ╔═════╦═════════════╦═══════════╦══════════════════════╦══════════════╦══════════════╗" << endl;
                cout << " ║ STT ║ ID hợp đồng ║ Tên phòng ║      Tên chủ trọ     ║   Ngày thuê  ║ Ngày hết hạn ║" << endl;
            }
            cout << " ╠═════╬═════════════╬═══════════╬══════════════════════╬══════════════╬══════════════╣" << endl;
            cout << left <<  " ║ " << setfill(' ') << setw(3) << i+1
                << " ║ " << setw(11) << (hd + i)->get_ID_hop_dong();

                for(j = 0; j < count_phong; j++){
                    if((pt + j)->get_ID_phong() == (hd + i)->get_ID_phong()){
                        cout << left << " ║ " << setw(9) << (pt + j)->get_ten_phong();
                        break;
                    }
               }
               for(p = 0; p < count_chu; p++){
                   if((ct + p)->get_ID() == (pt + j)->get_ID_chu()){
                       cout << left << " ║ " << setw(20) << (ct + p)->get_ten();
                       break;
                   }
               }
        
            cout << right << " ║ " << setw(2) << setfill('0') << (hd + i)->get_ngay_thue().ngay
                << "/" <<  setw(2) << (hd + i)->get_ngay_thue().thang
                << "/" << setw(4) << (hd + i)->get_ngay_thue().nam
                << setfill(' ') << setw(2) << ""
                << " ║ " << setw(2) << (hd + i)->get_ngay_het_han_real().ngay
                << "/" << setw(2) << (hd + i)->get_ngay_het_han_real().thang
                << "/" << setw(4) << (hd + i)->get_ngay_het_han_real().nam
                << setfill(' ') << setw(2) << ""
                << " ║" << endl;
            count++;
       }
    }
    if(count == 0){
       system("clear");
        cout << string(20, ' ') << "╔═══════════════════════════════════════════════════════╗\n";
        cout << string(20, ' ') << "║             BẠN CHƯA TỪNG THUÊ PHÒNG NÀO              ║\n";
        cout << string(20, ' ') << "╚═══════════════════════════════════════════════════════╝\n";
        getch_mac();
    }else{
        cout << " ╚═════╩═════════════╩═══════════╩══════════════════════╩══════════════╩══════════════╝" << endl;
        cout << setw(5) << "" << " Bạn có tất cả " << count << " phòng từng thuê!!" << endl << endl;
        cout << setw(26) << "" << " Nhấn phím bất kỳ để quay lại..." << endl;
        getch_mac();
    }
}

hop_dong nguoi_thue::delete_hd(chu_tro chu){
    Time real = thuc_te();
    hop_dong hd = get_my_phong().get_hop_dong(get_my_phong().find_hop_dong(real));
    Time tg = hd.get_ngay_thue();
    int temp = get_my_phong().get_count_bill() - 1;
    do {
        if (temp < 0) break;
        Time time_bill = get_my_phong().get_bill(temp).get_thoi_gian();
        if ((time_bill.nam == tg.nam && time_bill.thang <= tg.thang) || (time_bill.nam < tg.nam)) {
            break;
        };
        if (get_my_phong().get_bill(temp).get_trang_thai() == false) {
            cout << string(20, ' ') << "╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n";
            cout << string(20, ' ') << "║         ERROR: BẠN PHẢI THANH TOÁN HẾT HÓA ĐƠN MỚI ĐƯỢC PHÉP THỰC HIỆN CHỨC NĂNG NÀY        ║\n";
            cout << string(20, ' ') << "╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n";
            getch_mac();
            return hop_dong();
        }
        temp--;
    } while (1);

    int selected = 0, index_hd;
    char ch;
    do{
        system("clear");
        index_hd = get_my_phong().search_hd(real, chu, this, 1);
        
        cout << endl << endl;
        cout << "╔═══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║           ╔════════════════════════════════════════════════╗          ║\n";
        cout << "║           ║         BẠN CÓ CHẮC CHẮN HỦY HỢP ĐỒNG ?        ║          ║\n";
        cout << "║           ╚════════════════════════════════════════════════╝          ║\n";
        cout << "║                                                                       ║\n";
        cout << "║                                                                       ║\n";
    
        for (int i = 0; i < 2; i++) { 
            if (selected == i)cout << "║        >>>     " << i + 1 << ". ";
            else cout << "║                " << i + 1 << ". ";
            switch (i + 1) {
                case 1:
                    cout << "Chắc chắn huỷ hợp đồng                     ";           
                    break;
                case 2:
                    cout << "Quay lại                                   ";  
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
                selected = (selected - 1 + 2) % 2;
                break;
            case 80: 
                selected = (selected + 1) % 2;
                break;
            case '\n':
                break;
        }
    }while (ch != '\n');

    if (++selected == 1){
        get_my_phong().set_trang_thai(false);
        get_my_phong().set_hop_dong(real, index_hd);
        get_my_phong().set_ID_thue("");
        return get_my_phong().get_hop_dong(index_hd);
    }
    return hop_dong();
}
