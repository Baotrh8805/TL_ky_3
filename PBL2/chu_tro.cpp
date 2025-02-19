#include "chu_tro.h"

chu_tro::chu_tro(){
    nguoi();
    this->count_phong = 0;
}

chu_tro::chu_tro(string ID_admin, string ten, string SDT, string CCCD, string dia_chi, bool gioi_tinh) :nguoi(ID_admin, ten, gioi_tinh, dia_chi, SDT, CCCD)
{
    this->count_phong = 0;
}

int chu_tro::get_count_phong(){
    return this->count_phong;
}

phong_tro& chu_tro::get_phong(int i){
    return *(phong + i);
}

int chu_tro::binary_search_thue(nguoi_thue *nt, int count, string ID){
    int left = 0;
    int right = count - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if ((nt + mid)->get_ID() == ID) return mid;
        if ((nt + mid)->get_ID() < ID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void chu_tro::add_phong_array(phong_tro P){
    bool check = false;
    if (this->count_phong == 0){
        this->phong= new phong_tro[this->count_phong + 1];
        *phong = P;
    }else{
        phong_tro *new_p = new phong_tro[this->count_phong + 1];
        for (int i = 0; i < this->count_phong; i++){
            if(!check && (phong+i)->get_ten_phong() > P.get_ten_phong()){
                *(new_p+i) = P;
                check = true;
                for (int j = i; j < this->count_phong; j++) *(new_p+j+1) = *(phong+j);
                break;
            }
            else
            *(new_p+i) = *(this->phong+i);
        }
        if (!check) *(new_p + this->count_phong) = P;
        delete[] this->phong;
        this->phong = new_p;   
    }
    this->count_phong++;
}

int chu_tro::check_ten_phong(string ten_phong){
    for (int i = 0; i < count_phong; i++){
        if ((phong + i)->get_ten_phong() == ten_phong && (phong + i)->get_trang_thai() !=2){
            return i;
        }
    }
    return -1;
}

phong_tro chu_tro::add_phong_info(){
    string ten_phong, mo_ta_phong, ID;
    double dien_tich, gia_phong;
    bool check  ;
    do{
        system("clear");
        check = true;
        cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                                 THÊM PHÒNG                                               ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng (hoặc nhấn 0 để thoát)              : ";
        getline(cin, ten_phong);
       

        if (ten_phong == "0") return phong_tro();
        cout << "Nhập giá phòng                                     : ";
        if (!(cin >> gia_phong)) {
            gia_phong = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập diện tích                                     : ";
        if (!(cin >> dien_tich)) {
            dien_tich = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else {
            if (dien_tich > 9999999)
            {
                cout << "ERROR: Diện tích không hợp lệ. Vui lòng nhập lại!" << endl;
                cout << "Nhấn phím bất kỳ để nhập lại...";
                getch_mac();
                continue;
            }
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập mô tả phòng                                   : ";
        getline(cin, mo_ta_phong);
         if (  ten_phong.length() > 7 || ten_phong == ""){
            cout << "ERROR: Tên phòng không được quá 7 kí tự và không được để trống. Vui lòng nhập lại!" << endl;
            cout << "Nhấn phím bất kỳ để nhập lại...";
            getch_mac();
            continue;
        }
        cout << endl << endl;
        if (check_ten_phong(ten_phong) != -1 || ten_phong == "" || ten_phong.length() > 7) {
            cout << "ERROR: Tên phòng không được để trống hoặc lớn hơn 7 kí tự hoặc phòng đã tồn tại. Vui lòng nhập lại!" << endl;
            check = false;
        }
        if (gia_phong < 0 || gia_phong > 9999999) {
            cout << "ERROR: Giá phòng không được bé hơn 0 hoặc lớn hơn 9.999.999. Vui lòng nhập lại!" << endl;
            check = false;
        }
        if (dien_tich < 0 || dien_tich > 9999999) {
            cout << "ERROR: Diện tích không được bé hơn 0 hoạc lớn hơn 9.999.999. Vui lòng nhập lại!" << endl;
            check = false;
        }
        if (mo_ta_phong == "" || mo_ta_phong.length() > 50) {
            cout << "ERROR: Mô tả phòng không được để trống hoặc lớn hơn 50 ký tự. Vui lòng nhập lại!" << endl;
            check = false;
        }
        if (check == false) {
            cout << endl << endl;
            cout << "Nhấn phím bất kỳ để nhập lại...";
            getch_mac();
            continue;
        }
        break;
    }while(1);
    
    if (this->count_phong == 0) ID = get_ID() + "001";
    else ID = tang_chuoi_so((phong + this->count_phong - 1)->get_ID_phong());
    phong_tro P(ID, get_ID(), "", ten_phong, gia_phong, dien_tich, mo_ta_phong, 0);
    add_phong_array(P);
    return P; 
}

string chu_tro::delete_phong(){
    string ten_phong;
    int index, selected = 0;
    char ch;
    bool check = true;
    if (count_phong == 0) {
        system("clear");
        cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║         BẠN CHƯA TẠO PHÒNG NÀO! KHÔNG THỂ SỬ DỤNG CHỨC NĂNG NÀY            ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return "";
    }
    do{
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                            XÓA PHÒNG                                                ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if(!check) cout << "ERROR: Tên phòng không được để trống hoặc phòng không tồn tại. Vui lòng nhập lại!" << endl;
        cout << endl << endl;
        cout << "Nhập tên phòng muốn xóa (hoặc nhập 0 để thoát)              : ";
        getline(cin, ten_phong);
        cout << endl << endl;
        if (ten_phong == "0") return "";
        index = check_ten_phong(ten_phong);
        if ( index == -1 || ten_phong == "") {
            check = false;
            continue;
        }
        if((phong + index)->get_trang_thai()==1){
            system("clear");
            cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
            cout << "║               PHÒNG ĐANG ĐƯỢC CHO THUÊ, KHÔNG THỂ XOÁ PHÒNG!!!             ║\n";
            cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
            cout << endl;
            cout << "Nhấn phím bất kỳ để nhập lại...";
            getch_mac();
            return "";
        }
            
        break;
    }while(1);
    
    

    do {  
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║               ╔══════════════════════════════════════════════════════════════════╗                  ║\n";
        cout << "║               ║                    THÔNG TIN PHÒNG MUỐN XÓA                      ║                  ║\n";
        cout << "║               ╚══════════════════════════════════════════════════════════════════╝                  ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Tên phòng     ║" << setw(77) << left << (phong + index)->get_ten_phong() << "║   ║ \n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Giá phòng     ║" << setw(77) << left << doubleToString((phong + index)->get_gia_phong()) << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Diện tích     ║" << setw(77) << left << doubleToString((phong + index)->get_dien_tich()) << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Mô tả phòng   ║" << setw(77) << left << (phong + index)->get_mo_ta_phong() << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;   
        cout << string (15,' ') << "╔═══════════════════════════════════════════════════════════════════════╗\n";
        cout << string (15,' ') << "║           ╔════════════════════════════════════════════════╗          ║\n";
        cout << string (15,' ') << "║           ║      BẠN CÓ CHẮC CHẮN MUỐN XÓA PHÒNG ?         ║          ║\n";
        cout << string (15,' ') << "║           ╚════════════════════════════════════════════════╝          ║\n";
        cout << string (15,' ') << "║                                                                       ║\n";
        cout << string (15,' ') << "║                                                                       ║\n";
       
        for (int i = 0; i < 2; i++) { 
            if (selected == i) cout << string (15,' ') << "║        >>>     " << i + 1 << ". ";
            else cout << string (15,' ') << "║                " << i + 1 << ". ";
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
            cout << string (15,' ') << "║                                                                       ║\n";
        }
        cout << string (15,' ') << "╚═══════════════════════════════════════════════════════════════════════╝\n";

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

    if (selected == 1) return "";

    string ID_delete = (phong + index)->get_ID_phong();
    (phong + index)->set_trang_thai(2);
    return ID_delete;
}

int chu_tro::nhap_ten_phong_update(){
    string ten_phong;
    int index;
    bool check = true;
    if (count_phong == 0) {
        system("clear");
        cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║         BẠN CHƯA TẠO PHÒNG NÀO! KHÔNG THỂ SỬ DỤNG CHỨC NĂNG NÀY            ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return 0;
    }
    do{
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                   CHỈNH SỬA THÔNG TIN PHÒNG                                         ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if(!check) cout << "ERROR: Tên phòng không được để trống hoặc phòng không tồn tại. Vui lòng nhập lại!" << endl;
        cout << endl << endl;
        cout << "Nhập tên phòng muốn chỉnh sửa (hoặc nhập 0 để thoát)         : ";
        getline(cin, ten_phong);
        if (ten_phong == "0") return -1;
        cout << endl << endl;
        index = check_ten_phong(ten_phong);
        if ( index == -1 || ten_phong == "") {
            check = false;
            continue;
        }
        if ((phong + index)->get_trang_thai()==1){
             system("clear");
            cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
            cout << "║            PHÒNG ĐANG CHO THÊ KHÔNG THỂ CHỈNH SỬA THÔNG TIN                ║\n";
            cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
            cout << endl;
            cout << "Nhấn phím bất kỳ để quay lại...";
            getch_mac();
            return -1;
        }
        
         
        break;
    }while(1);
    return index;
}

phong_tro chu_tro::update_phong(int index, int &selected){
    int ch, startX, startY; 
    double gia_phong, dien_tich;
    string mo_ta_phong, ten_phong; 
    cout << endl << endl;
    selected = 0;
    do {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║               ╔══════════════════════════════════════════════════════════════════╗                  ║\n";
        cout << "║               ║                 THÔNG TIN PHÒNG MUỐN CHỈNH SỬA                   ║                  ║\n";
        cout << "║               ╚══════════════════════════════════════════════════════════════════╝                  ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Tên phòng     ║" << setw(77) << left << (phong + index)->get_ten_phong() << "║   ║ \n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Giá phòng     ║" << setw(77) << left << doubleToString((phong + index)->get_gia_phong()) << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Diện tích     ║" << setw(77) << left << doubleToString((phong + index)->get_dien_tich()) << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Mô tả phòng   ║" << setw(77) << left << (phong + index)->get_mo_ta_phong() << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";

        cout << endl << endl;
        cout << string (15,' ') << "╔═══════════════════════════════════════════════════════════════════════╗\n";
        cout << string (15,' ') << "║           ╔════════════════════════════════════════════════╗          ║\n";
        cout << string (15,' ') << "║           ║        BẠN MUỐN CHỈNH SỬA THÔNG TIN GÌ         ║          ║\n";
        cout << string (15,' ') << "║           ╚════════════════════════════════════════════════╝          ║\n";
        cout << string (15,' ') << "║                                                                       ║\n";
        cout << string (15,' ') << "║                                                                       ║\n";
    
        for (int i = 0; i < 5; i++) { 
            if (selected == i)cout << string (15,' ') << "║        >>>     " << i + 1 << ". ";
            else cout << string (15,' ') << "║                " << i + 1 << ". ";
            switch (i + 1) {
                case 1:
                    cout << "Tên phòng                                  ";
                    break;
                case 2:
                    cout << "Giá phòng                                  ";
                    break;
                case 3:
                    cout << "Diện tích                                  ";
                    break;
                case 4:
                    cout << "Mô tả phòng                                ";
                    break;
                case 5:
                    cout << "Thoát                                      ";
                    break;
            }
            if (selected == i) cout << "  <<<    ║\n";
            else cout << "         ║\n";
            cout << string (15,' ') << "║                                                                       ║\n";
        }
        cout << string (15,' ') << "╚═══════════════════════════════════════════════════════════════════════╝\n";

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
    } while(ch != '\n');
    ++selected;
    
    do{
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║               ╔══════════════════════════════════════════════════════════════════╗                  ║\n";
        cout << "║               ║                 THÔNG TIN PHÒNG MUỐN CHỈNH SỬA                   ║                  ║\n";
        cout << "║               ╚══════════════════════════════════════════════════════════════════╝                  ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Tên phòng     ║" << setw(77) << left << (phong + index)->get_ten_phong() << "║   ║ \n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Giá phòng     ║" << setw(77) << left << doubleToString((phong + index)->get_gia_phong()) << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Diện tích     ║" << setw(77) << left << doubleToString((phong + index)->get_dien_tich()) << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "║                   ╔═════════════════════════════════════════════════════════════════════════════╗   ║\n";
        cout << "║     Mô tả phòng   ║" << setw(77) << left << (phong + index)->get_mo_ta_phong() << "║   ║\n";
        cout << "║                   ╚═════════════════════════════════════════════════════════════════════════════╝   ║\n";
        cout << "║                                                                                                     ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;   

        switch (selected) {
            case 1:
                cout << "Nhập tên phòng mới      : ";
                getline(cin, ten_phong);
                if (ten_phong == "" || check_ten_phong(ten_phong) != -1) {
                    cout << "ERROR: Tên phòng đã tồn tại hoặc không được để trống!";
                    getch_mac();
                    continue;
                }
                (phong+index)->set_ten_phong(ten_phong);
                break;
            case 2:
                cout << "Nhập giá phòng mới      : ";
                if (!(cin >> gia_phong)) {
                    gia_phong = -1;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    cin.clear();
                    cin.ignore();
                }
                if (gia_phong < 0) {
                    cout << "ERROR: Giá phòng không hợp lệ. Vui lòng nhập lại!";
                    getch_mac();
                    continue;
                }
                (phong+index)->set_gia_phong(gia_phong);
                break;
            case 3:
                cout << "Nhập diện tích mới      : ";
                if (!(cin >> dien_tich)) {
                    dien_tich = -1;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    cin.clear();
                    cin.ignore();
                }
                if (dien_tich < 0) {
                    cout << "ERROR: Diện tích không hợp lệ. Vui lòng nhập lại!";
                    getch_mac();
                    continue;
                }
                (phong+index)->set_dien_tich(dien_tich);
                break;
            case 4:
                cout << "Nhập mô tả phòng mới    : ";
                getline(cin, mo_ta_phong);
                if (mo_ta_phong == "") {
                    cout << "ERROR: Mô tả phòng không được để trống!";
                    getch_mac();
                    continue;
                }
                (phong+index)->set_mo_ta_phong(mo_ta_phong);
                break;
        }
        break;
    } while(1);
    return *(phong+index);
}

void chu_tro::show_phong_chu(nguoi_thue* nt, int count_thue){
    if (count_phong == 0) {
        system("clear");
        cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║         BẠN CHƯA TẠO PHÒNG NÀO! KHÔNG THỂ SỬ DỤNG CHỨC NĂNG NÀY            ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return;
    }
    int choice, count;
    char ch;
    bool check_phong = true;
    do{
        choice = 0;
        do{
            system("clear");
            cout << "╔═════════════════════════════════════════════════════╗\n";
            cout << "║           ╔══════════════════════════════╗          ║\n";
            cout << "║           ║     XEM DANH SÁCH PHÒNG      ║          ║\n";
            cout << "║           ╚══════════════════════════════╝          ║\n";
            cout << "║                                                     ║\n";
            cout << "║                                                     ║\n";
            for (int i = 0; i < 4; i++) {
                if (choice == i) cout << "║    >>>   " << i + 1 << ". ";
                else cout << "║          " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << "Xem tất cả phòng còn trống      ";      
                        break;
                    case 2:
                        cout << "Xem tất cả phòng đã cho thuê    ";
                        break;
                    case 3:
                        cout << "Xem tất cả phòng                ";
                        break;
                    case 4:
                        cout << "Thoát                           ";
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
        switch (choice){
            case 1:
                count = 0;
                for (int i = 0; i < count_phong; i++) {
                    if((phong+i)->get_trang_thai()==0 ){
                        if (count == 0){
                            cout << "╔═════╦═══════════╦═════════╦════════════════╦════════════════╦════════════════════════════════════════════════════╗" << endl;
                            cout << "║ STT ║ ID_Phong  ║  Phòng  ║ Giá Phòng(vnđ) ║ Diện tích (m²) ║                         Mô Tả Phòng                ║" << endl;
                        }
                        count++;
                        cout << "╠═════╬═══════════╬═════════╬════════════════╬════════════════╬════════════════════════════════════════════════════╣" << endl;
                        cout << "║ " << setw(3) << left << doubleToString(count) << " ║ " << setw(9) << left << (phong + i)->get_ID_phong() << " ║ " << setw(7) << left << (phong + i)->get_ten_phong() << " ║ " << setw(14) << left << doubleToString((phong + i)->get_gia_phong()) << " ║ " << setw(14) << left << doubleToString((phong + i)->get_dien_tich()) << " ║ " << setw(50) << left << (phong + i)->get_mo_ta_phong() << " ║" << endl;
                    }
                }
                if (count != 0 ){
                    cout << "╚═════╩═══════════╩═════════╩════════════════╩════════════════╩════════════════════════════════════════════════════╝" << endl;
                    cout << "Có tất cả " << count << " phòng chưa cho thuê!" << endl;
                    cout << "Nhấn phím bất kỳ để tiếp tục...";
                    getch_mac();
                }
                else {
                    cout << "╔══════════════════════════════════════════════════════════╗\n";
                    cout << "║                  KHÔNG CÓ PHÒNG NÀO TRỐNG!               ║\n";
                    cout << "╚══════════════════════════════════════════════════════════╝\n";
                    getch_mac();
                }
                break;
            case 2:
                count = 0;
                for (int i = 0; i < count_phong; i++){
                    if((phong+i)->get_trang_thai()==1){
                        if (count == 0) {
                            cout << "╔═════╦═══════════╦═══════════╦════════════════╦══════════════════════╦════════════╦══════════════╦══════════════════════════════════════════╗" << endl;
                            cout << "║ STT ║ ID_Phong  ║   Phòng   ║ Giá Phòng(vnđ) ║    Tên Người Thuê    ║    SDT     ║     CCCD     ║                Quê Quán                  ║" << endl;
                        }
                        check_phong = false;
                        count++;
                        cout << "╠═════╬═══════════╬═══════════╬════════════════╬══════════════════════╬════════════╬══════════════╬══════════════════════════════════════════╣" << endl;
                        for (int j = 0; j < count_thue; j++){
                            if((nt+j)->get_ID_phong()==(phong+i)->get_ID_phong()){
                                cout << left << "║ " << setw(3) <<  doubleToString(count) << " ║ " << setw(9) <<  (phong + i)->get_ID_phong() << " ║ " << setw(9) <<  (phong + i)->get_ten_phong() << " ║ " << setw(14) <<  doubleToString((phong + i)->get_gia_phong()) << " ║ " << setw(20) <<  (nt + j)->get_ten()  << " ║ " << setw(10) <<  (nt + j)->get_SDT() << " ║ " << setw(12) <<  (nt + j)->get_CCCD() << " ║ " << setw(40) <<  (nt + j)->get_dia_chi() << " ║\n";
                                check_phong = true;
                                break;
                            }
                        }
                        if (!check_phong)cout << left << "║ " << setw(3) <<  doubleToString(count) << " ║ " << setw(9) <<  (phong + i)->get_ID_phong() << " ║ " << setw(9) <<  (phong + i)->get_ten_phong() << " ║ " << setw(14) <<  doubleToString((phong + i)->get_gia_phong()) << " ║ " << setw(20) <<  "NULL"  << " ║ " << setw(10) <<  "NULL" << " ║ " << setw(12) << "NULL" << " ║ " << setw(40) <<  "NULL" << " ║\n";
                    }
                }
                if (count != 0){
                    cout << "╚═════╩═══════════╩═══════════╩════════════════╩══════════════════════╩════════════╩══════════════╩══════════════════════════════════════════╝" << endl;
                    cout << "Có tất cả " << count << " phòng đã cho thuê" << endl;
                    cout << "Nhấn phím bất kỳ để tiếp tục...";
                    getch_mac();
                }
                else {
                    cout << "╔══════════════════════════════════════════════════════════╗\n";
                    cout << "║                KHÔNG CÓ PHÒNG NÀO CHO THUÊ!              ║\n";
                    cout << "╚══════════════════════════════════════════════════════════╝\n";
                    getch_mac();
                }
                break;
            case 3:
                count = 0;
                if (count_phong == 0){
                    cout << "╔══════════════════════════════════════════════════════════╗\n";
                    cout << "║              BẠN CHƯA TẠO BẤT KÌ PHÒNG NÀO!              ║\n";
                    cout << "╚══════════════════════════════════════════════════════════╝\n";
                    getch_mac();
                }
                else{
                    for (int i = 0; i < count_phong; i++){
                        if((phong+i)->get_trang_thai()!=2){
                            if (count == 0) {
                                cout << "╔═════╦═══════════╦═══════════╦════════════════╦══════════════════════╦════════════╦══════════════╦══════════════════════════════════════════╗" << endl;
                                cout << "║ STT ║ ID_Phong  ║   Phòng   ║ Giá Phòng(vnđ) ║     Tên Người Thuê   ║     SDT    ║     CCCD     ║                Quê Quán                  ║" << endl;
                            }
                            check_phong = false;
                            count++;
                            cout << "╠═════╬═══════════╬═══════════╬════════════════╬══════════════════════╬════════════╬══════════════╬══════════════════════════════════════════╣" << endl;
                            for (int j = 0; j < count_thue; j++){
                                if((nt+j)->get_ID_phong()==(phong+i)->get_ID_phong()){
                                    cout << left << "║ " << setw(3) <<  doubleToString(count) << " ║ " << setw(9) <<  (phong + i)->get_ID_phong() << " ║ " << setw(9) <<  (phong + i)->get_ten_phong() << " ║ " << setw(14) <<  doubleToString((phong + i)->get_gia_phong()) << " ║ " << setw(20) <<  (nt + j)->get_ten()  << " ║ " << setw(10) <<  (nt + j)->get_SDT() << " ║ " << setw(12) <<  (nt + j)->get_CCCD() << " ║ " << setw(40) <<  (nt + j)->get_dia_chi() << " ║\n";
                                    check_phong = true;
                                    break;
                                }
                            }
                            if (!check_phong)cout << left << "║ " << setw(3) <<  doubleToString(count) << " ║ " << setw(9) <<  (phong + i)->get_ID_phong() << " ║ " << setw(9) <<  (phong + i)->get_ten_phong() << " ║ " << setw(14) <<  doubleToString((phong + i)->get_gia_phong()) << " ║ " << setw(20) <<  "NULL"  << " ║ " << setw(10) <<  "NULL" << " ║ " << setw(12) << "NULL" << " ║ " << setw(40) <<  "NULL" << " ║\n";
                        }  
                    }
                    if(count != 0){ 
                        cout << "╚═════╩═══════════╩═══════════╩════════════════╩══════════════════════╩════════════╩══════════════╩══════════════════════════════════════════╝" << endl;
                        cout << "Bạn có tất cả " << count << " phòng" << endl;
                        cout << "Nhấn phím bất kỳ để tiếp tục...";
                        getch_mac();
                    }
                }
                break;
            case 4:
                
                break;
        }
    }while(choice != 4);
}

void chu_tro::search_phong(nguoi_thue* nt, int count_thue){
    string ten_phong;
    int index, count;
    bool check_ten = true;
    do{
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                            TÌM KIẾM PHÒNG                                           ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if (!check_ten) cout << string(20, ' ') << "ERROR: Tên phòng không được để trống. Vui lòng nhập lại!" << endl;
        cout << endl << endl;
        cout << "Nhập tên phòng muốn tìm (hoặc nhấn 0 để thoát)         : ";
        getline(cin, ten_phong);
        if (ten_phong == "0") return;
        if (ten_phong == "") {
            check_ten = false;
            continue;
        }
        break;
    }while(1);

    bool check = false, check_phong = false;
    count = 0;

    
    system("clear");
    for (int i = 0; i < this->count_phong; i++){  
        if ((phong+i)->get_ten_phong().find(ten_phong)!=string::npos && (phong+i)->get_trang_thai()!=2 ){
            
            if (!check) {
                cout << "╔═════╦═════════╦═══════╦════════════╦══════════════════════╦════════════╦══════════════╦════════════════════════════════╗" << endl;
                cout << "║ " << setw(3) << left << centerText("STT", 3) << " ║ " << setw(7) << left << centerText("Ma ID", 7) << " ║ " << setw(5) << left << centerText("Phong", 5) << " ║ " << setw(10) << left << centerText("Gia", 10) << " ║ " << setw(20) << left << centerText("Ten nguoi thue", 20) << " ║ " << setw(10) << left << centerText("SDT", 10) << " ║ " << setw(12) << left << centerText("CCCD", 12) << " ║ " << setw(30) << left << centerText("Que quan", 30) << " ║" << endl;
                check = true;
            }
            check_phong = false;
            count ++;
            cout << "╠═════╬═════════╬═══════╬════════════╬══════════════════════╬════════════╬══════════════╬════════════════════════════════╣" << endl;
            int find = binary_search_thue(nt, count_thue, (phong+i)->get_ID_thue());
            if (find != -1)  cout << "║ " << setw(3) << left << doubleToString(count) << " ║ " << setw(7) << left << (phong + i)->get_ID_phong() << " ║ " << setw(5) << left << (phong + i)->get_ten_phong() << " ║ " << setw(10) << left << doubleToString((phong + i)->get_gia_phong()) << " ║ " << setw(20) << left << (nt + find)->get_ten()  << " ║ " << setw(10) << left << (nt + find)->get_SDT() << " ║ " << setw(12) << left << (nt + find)->get_CCCD() << " ║ " << setw(30) << left << (nt + find)->get_dia_chi() << " ║\n";
            else cout << "║ " << setw(3) << left << doubleToString(count) << " ║ " << setw(7) << left << (phong + i)->get_ID_phong() << " ║ " << setw(5) << left << (phong + i)->get_ten_phong() << " ║ " << setw(10) << left << doubleToString((phong + i)->get_gia_phong()) << " ║ " << setw(20) << left << "NULL" << " ║ " << setw(10) << left << "NULL" << " ║ " << setw(12) << left << "NULL" << " ║ " << setw(30) << left << "NULL" << " ║\n";
        }
    }
    
    if (count == 0) {
        cout << "╔═══════════════════════════════════════════════════════╗\n";
        cout << "║            KHÔNG TÌM THẤY PHÒNG NÀO THỎA              ║\n";
        cout << "╚═══════════════════════════════════════════════════════╝\n";
        getch_mac();
    } else {
        cout << "╚═════╩═════════╩═══════╩════════════╩══════════════════════╩════════════╩══════════════╩════════════════════════════════╝" << endl;
        cout << "Tìm thấy " << count << " phòng thỏa mãn" << endl;
        cout << "Nhấn phím bất kì để tiếp tục" << endl;
        getch_mac();
    }
}

void chu_tro::search_hd(nguoi_thue* nt, int count_thue){
    if (count_phong == 0) {
        system("clear");
        cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║         BẠN CHƯA TẠO PHÒNG NÀO! KHÔNG THỂ SỬ DỤNG CHỨC NĂNG NÀY            ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return;
    }
    string ten_phong;
    Time t, real = thuc_te();
    int index;
    bool check;
    do{
        system("clear");
        check = true;
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                          TÌM KIẾM HỢP ĐỒNG                                          ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn tìm (hoặc nhấn 0 để thoát)              : ";
        getline(cin, ten_phong);
        if (ten_phong == "0") return;
        index = check_ten_phong(ten_phong); 
        cout << "Nhập thời gian hợp đồng muốn tìm kiếm" << endl;
        cout << "Nhập tháng                                                  : ";
        if (!(cin >> t.thang)) {
            t.thang = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (t.thang < 1 || t.thang > 12) {
            t.thang = -1;
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập năm                                                     : ";
        if (!(cin >> t.nam)) {
            t.nam = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            cin.clear();
            cin.ignore();
        }
        if (ten_phong == "" || index == -1) {
            check = false;
            cout << "ERROR: Tên phòng không được để trống hoặc không tồn tại. Vui lòng nhập lại!" << endl;
        }
        if (t.thang == -1 || t.nam == -1 || (t.thang > real.thang && t.nam == real.nam) || t.nam > real.nam) {
            check = false;
            cout << "ERROR: Thời gian không hợp lệ. Vui lòng nhập lại!" << endl;
        }
        if (!check){
            getch_mac();
            continue;
        }
        break;
    }while(1);
    (phong + index)->search_hd(t, *(this), nt, count_thue);
    getch_mac();
}

hop_dong chu_tro::delete_hd(nguoi_thue* nt, int count_thue, string& ID_pt){
    if (count_phong == 0) {
        system("clear");
        cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║         BẠN CHƯA TẠO PHÒNG NÀO! KHÔNG THỂ SỬ DỤNG CHỨC NĂNG NÀY            ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return hop_dong();
    }
    string ten_phong;
    Time real = thuc_te();
    int index;
    do{
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                           HỦY HỢP ĐỒNG                                              ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn tìm (hoặc nhấn 0 để thoát)              : ";
        getline(cin, ten_phong);
        if (ten_phong == "0") return hop_dong();
        index = check_ten_phong(ten_phong);
        if (ten_phong == "" || index == -1) {
            cout << "ERROR: Tên phòng không được để trống hoặc không tồn tại. Vui lòng nhập lại!" << endl;
            getch_mac();
            continue;
        }
        break;
    }while(1);

    int selected = 0;
    char ch;
    int index_hd;
    do{
        system("clear");
        index_hd = (phong + index)->search_hd(real, *(this), nt, count_thue);
        if (index_hd == -1) {
            selected = 1;
            break;
        }
        cout << "╔═══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║           ╔════════════════════════════════════════════════╗          ║\n";
        cout << "║           ║      BẠN CÓ CHẮC CHẮN MUỐN HỦY HỢP ĐỒNG?       ║          ║\n";
        cout << "║           ╚════════════════════════════════════════════════╝          ║\n";
        cout << "║                                                                       ║\n";
        cout << "║                                                                       ║\n";
        for (int i = 0; i < 2; i++) { 
            if (selected == i) cout << "║        >>>     " << i + 1 << ". ";
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
    }while(ch != '\n');

    if (++selected == 1) {
        (phong + index)->set_trang_thai(false);
        (phong + index)->set_hop_dong(real, index_hd);
        (phong + index)->set_ID_thue("");
        ID_pt = (phong + index)->get_ID_phong();
        return (phong + index)->get_hop_dong(index_hd);   
    } 
    return hop_dong();
}

void chu_tro::show_hd_time(nguoi_thue* nt, int count_thue){
    int n;
    Time t, real = thuc_te();
    bool check_time = true;
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                XEM DANH SÁCH HỢP ĐỒNG THEO THỜI GIAN                                ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if (!check_time) cout << "ERROR: Thời gian hợp đồng không hợp lệ. Vui lòng nhập lại!" << endl;
        cout << endl << endl;
        cout << "Nhập thời gian hợp đồng muốn xem danh sách" << endl;
        cout << "Nhập tháng                                  : ";
        if (!(cin >> t.thang)) {
            t.thang = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (t.thang < 1 || t.thang > 12) {
            t.thang = -1;
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập năm                                    : ";
        if (!(cin >> t.nam)) {
            t.nam = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            cin.clear();
            cin.ignore();
        }
        if (t.thang == -1 || t.nam == -1 || ( t.thang > real.thang && t.nam == real.nam) || t.nam > real.nam) {
            check_time = false;
            continue;
        }
        break;
    }
    system("clear");
    int count = 0;
    for (int i = 0; i < count_phong; i++){
        (phong + i)->show_hd_time(t, *(this), nt, count_thue, count);
    }
    if(count == 0){
        cout << "╔═════════════════════════════════════════════════════════╗\n";
        cout << "║            KHÔNG TÌM THẤY HỢP ĐỒNG NÀO THỎA             ║\n";
        cout << "╚═════════════════════════════════════════════════════════╝\n";
        getch_mac();
    } else {
        cout << "╚═════╩═════════════╩════════════╩════════════╩════════════╩══════════════════════╩════════════╩════════════════╩══════════════╝" << endl;
        cout << "Tìm thấy " << count << " hợp đồng thỏa mãn" << endl;
        cout << "Nhấn phím bất kì để tiếp tục" << endl;
        getch_mac();
    }
}

void chu_tro::show_hd_phong(nguoi_thue* nt, int count_thue){
     string ten_phong;
    int index;
    bool check = true;
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                  XEM DANH SÁCH HỢP ĐỒNG PHÒNG                                       ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if (!check) cout << "ERROR: Tên phòng không được để trống hoặc không tồn tại. Vui lòng nhập lại!" << endl;
        cout << endl << endl;
        cout << "Nhập tên phòng muốn xem danh sách hợp đồng        : ";
        getline(cin, ten_phong);
        index = check_ten_phong(ten_phong);
        if (ten_phong == "" || index == -1) {
            check = false;
            continue;
        }
        break;
    }
    (phong + index)->show_hd_full(*(this), nt, count_thue);
    cout << endl;
    cout << "  Nhấn phím bất kì để tiếp tục!!!" << endl;
    getch_mac();
}

void chu_tro::show_hd(nguoi_thue* nt, int count_thue){
    if (count_phong == 0) {
        system("clear");
        cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║         BẠN CHƯA TẠO PHÒNG NÀO! KHÔNG THỂ SỬ DỤNG CHỨC NĂNG NÀY            ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return;
    }
    int choice;
    char ch;
    do{
        choice = 0;
        do{
            system("clear");
            cout << "╔════════════════════════════════════════════════════════════╗\n";
            cout << "║           ╔════════════════════════════════════╗           ║\n";
            cout << "║           ║      XEM DANH SÁCH HỢP ĐỒNG        ║           ║\n";
            cout << "║           ╚════════════════════════════════════╝           ║\n";
            cout << "║                                                            ║\n";
            cout << "║                                                            ║\n";
            for (int i = 0; i < 3; i++) {
                if (choice == i) cout << "║    >>>    " << i + 1 << ". ";
                else cout << "║           " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << "Xem danh sách hợp đồng theo thời gian ";               
                        break;
                    case 2:
                        cout << "Xem danh sách hợp đồng theo phòng     ";
                        break;
                    case 3:
                        cout << "Thoát                                 ";
                        break;
                }
                if (choice == i) cout << "   <<<  ║\n";
                else cout << "        ║\n";
                cout << "║                                                            ║\n";
            }
            cout << "║                                                            ║\n";
            cout << "║                                                            ║\n";
            cout << "╚════════════════════════════════════════════════════════════╝\n";

            ch = getch_mac();
            switch (ch) {
                case 72: 
                    choice = (choice - 1 + 3) % 3;
                    break;
                case 80: 
                    choice = (choice + 1) % 3;
                    break;
                case '\n': 
                    break;
            }
        }while(ch != '\n');
        
        switch (++choice){
            case 1:
                show_hd_time(nt, count_thue);
                break;
            case 2:
                show_hd_phong(nt, count_thue);
                break;
            case 3:
                break;
        }
    } while (choice != 3);
}

hoa_don chu_tro::add_bill_phong(){
    string ten_phong;
    int index;
    do{
        system("clear");
        cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                           THÊM HÓA ĐƠN PHÒNG                                             ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn thêm hóa đơn (hoặc nhấn 0 để thoát)   : ";
        getline(cin, ten_phong);
        if (ten_phong == "0") return hoa_don();
        cout << endl << endl;
        index = check_ten_phong(ten_phong);
        if ( index == -1 || ten_phong == "") {
            cout << "ERROR: Tên phòng không được để trống hoặc không tồn tại. Vui lòng nhập lại!" << endl;
            getch_mac();
            continue;
        }
        break;
    }while(1);

    system("clear");
    if ((phong + index)->get_trang_thai() == false){
        cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║            PHÒNG CHƯA CHO THUÊ NÊN KHÔNG THỂ THÊM HÓA ĐƠN              ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return hoa_don();
    }
    return (phong + index)->add_bill_info();
}

int chu_tro::update_bill_phong(){
    string ten_phong;
    int index;
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                               CHỈNH SỬA THÔNG TIN HÓA ĐƠN PHÒNG                                     ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn chỉnh sửa hóa đơn (hoặc nhấn 0 để thoát) : ";
        getline(cin, ten_phong);
        if (ten_phong == "0") return -1;
        index = check_ten_phong(ten_phong);
        if (index == -1 || ten_phong == "") {
            cout << endl << "ERROR: Tên phòng không được để trống hoặc không tồn tại. Vui lòng nhập lại!" << endl;
            getch_mac();
            continue;
        }
        break;
    }
    if ((phong + index)->get_trang_thai() == false){
        system("clear");
        cout << "╔══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║           PHÒNG CHƯA CHO THUÊ NÊN KHÔNG CÓ HÓA ĐƠN.                  ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return -1;
    }
    if ((phong+index)->get_count_bill()==0){
        system("clear");
        cout << "╔══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                   PHÒNG CHƯA CÓ HÓA ĐƠN NÀO                          ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return -1;
    }
    return index;
}

string chu_tro::delete_bill_phong(){
    string ten_phong;
    int index;
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                        XÓA HÓA ĐƠN PHÒNG                                            ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn xóa hóa đơn (hoặc nhấn 0 để thoát)     : ";
        getline(cin, ten_phong);
        if (ten_phong == "0") return "";
        cout << endl;
        index = check_ten_phong(ten_phong);
        if (index == -1 || ten_phong == "") {
            cout << "ERROR: Tên phòng không được để trống hoặc không tồn tại. Vui lòng nhập lại!" << endl;
            getch_mac();
            continue;
        }
        break;
    }
    if ((phong + index)->get_trang_thai() == false){
        system("clear");
        cout << "╔══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║           PHÒNG CHƯA CHO THUÊ NÊN KHÔNG CÓ HÓA ĐƠN.                  ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return "";
    }
    if ((phong+index)->get_count_bill()==0){
        system("clear");
        cout << "╔══════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                   PHÒNG CHƯA CÓ HÓA ĐƠN NÀO                          ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return "";
    }
    return (phong+index)->delete_bill();
}

void chu_tro::search_bill_phong(){
    string ten_phong;
    Time t, real = thuc_te();
    bool check = true, check_time = true;
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                     TÌM KIẾM HÓA ĐƠN PHÒNG                                          ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn tìm kiếm hóa đơn (hoặc nhấn 0 để thoát)  : ";
        getline(cin, ten_phong);
        if (ten_phong == "0") return;
        cout << endl;
        cout << "Nhập thời gian hóa đơn muốn tìm kiếm" << endl;
        cout << "Nhập tháng                                                   : ";
        if (!(cin >> t.thang)) {
            t.thang = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (t.thang < 1 || t.thang > 12) {
            t.thang = -1;
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập năm                                                     : ";
        if (!(cin >> t.nam)) {
            t.nam = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            cin.clear();
            cin.ignore();
        }
        cout << endl << endl;
        if (t.thang == -1 || t.nam == -1 || (t.thang > real.thang && t.nam == real.nam) || t.nam > real.nam) {
            check_time = false;
            cout << "ERROR: Thời gian hóa đơn không hợp lệ. Vui lòng nhập lại!" << endl;
        }
        if (ten_phong == "") {
            cout << "ERROR: Tên phòng không được để trống. Vui lòng nhập lại!" << endl;
            check = false;
        }
        if (check == false || check_time == false) {
            cout << "Nhấn phím bất kỳ để tiếp tục" << endl;
            getch_mac();
            continue;
        }
        break;
    }
    int count = 0;
    for (int i = 0; i < this->count_phong; i++){
        if((phong + i)->get_ten_phong().find(ten_phong) != string::npos){
            (phong + i)->search_bill(t, count);
        }
    }
    if (count == 0) {
        cout << endl;
        cout << "╔═════════════════════════════════════════════════════════╗\n";
        cout << "║            KHÔNG TÌM THẤY HÓA ĐƠN NÀO THỎA              ║\n";
        cout << "╚═════════════════════════════════════════════════════════╝\n";
        getch_mac();
    } else {
        cout << "╚═════╩═══════╩═══════════════╩════════════╩════════════╩════════════╩═════════════════╩════════════╩════╝" << endl;
        cout << "Tìm thấy " << count << " hóa đơn thỏa mãn" << endl;
        cout << "Nhấn phím bất kì để tiếp tục" << endl;
        getch_mac();
    }
}

void chu_tro::show_bill_time(){
    int n;
    Time t, real = thuc_te();
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                XEM DANH SÁCH HÓA ĐƠN THEO THỜI GIAN                                 ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập thời gian hóa đơn muốn xem danh sách" << endl;
        cout << "Nhập tháng                                  : ";
        if (!(cin >> t.thang)) {
            t.thang = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (t.thang < 1 || t.thang > 12) {
            t.thang = -1;
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập năm                                    : ";
        if (!(cin >> t.nam)) {
            t.nam = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            cin.clear();
            cin.ignore();
        }
        if (t.thang == -1 || t.nam == -1 || ( t.thang > real.thang && t.nam == real.nam) || t.nam > real.nam) {
            cout << endl << "ERROR: Thời gian hóa đơn không hợp lệ. Vui lòng nhập lại!" << endl;
            getch_mac();
            continue;
        }
        break;
    }
    cout << endl << endl;

    int count = 0;
    for (int i = 0; i < count_phong; i++){
        if ((phong+i)->get_count_bill()==0) continue;
        (phong + i)->search_bill(t, count);
    }
    if (count == 0) {
        cout << "╔═════════════════════════════════════════════════════════╗\n";
        cout << "║            KHÔNG TÌM THẤY HÓA ĐƠN NÀO THỎA              ║\n";
        cout << "╚═════════════════════════════════════════════════════════╝\n";
        getch_mac();
    } else {
        cout << "╚═════╩═══════╩═══════════════╩════════════╩════════════╩════════════╩═════════════════╩════════════╩════╝" << endl;
        cout << "Tìm thấy " << count << " hóa đơn thỏa mãn" << endl;
        cout << "Nhấn phím bất kì để tiếp tục" << endl;
        getch_mac();
    }
}

void chu_tro::show_bill_phong(){
    string ten_phong;
    int index;
    while (1){
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                   XEM DANH SÁCH HÓA ĐƠN PHÒNG                                       ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << endl << endl;
        cout << "Nhập tên phòng muốn xem danh sách hóa đơn        : ";
        getline(cin, ten_phong);
        index = check_ten_phong(ten_phong);
        if (ten_phong == "" || index == -1) {
            cout << endl << "ERROR: Tên phòng không được để trống hoặc không tồn tại. Vui lòng nhập lại!" << endl;
            getch_mac();
            continue;
        }
        break;
    }
    if ((phong + index)->get_trang_thai() == false) {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════╗\n";
        cout << "║        PHÒNG CHƯA CHO THUÊ NÊN KHÔNG CÓ HÓA ĐƠN         ║\n";
        cout << "╚═════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return;
    }
    if ((phong+index)->get_count_bill()==0) {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════╗\n";
        cout << "║                PHÒNG CHƯA CÓ HÓA ĐƠN NÀO                ║\n";
        cout << "╚═════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return;
    }
    (phong + index)->show_bill();
}

void chu_tro::show_bill(){
    int choice;
    char ch;
    do{
        choice = 0;
        do{
            system("clear");
            cout << "╔════════════════════════════════════════════════════════════╗\n";
            cout << "║           ╔════════════════════════════════════╗           ║\n";
            cout << "║           ║      XEM DANH SÁCH HÓA ĐƠN         ║           ║\n";
            cout << "║           ╚════════════════════════════════════╝           ║\n";
            cout << "║                                                            ║\n";
            cout << "║                                                            ║\n";
            for (int i = 0; i < 3; i++) {
                if (choice == i) cout << "║    >>>    " << i + 1 << ". ";
                else cout << "║           " << i + 1 << ". ";
                switch (i + 1) {
                    case 1:
                        cout << "Xem danh sách hóa đơn theo thời gian  ";               
                        break;
                    case 2:
                        cout << "Xem danh sách hóa đơn theo phòng      ";
                        break;
                    case 3:
                        cout << "Thoát                                 ";
                        break;
                }
                if (choice == i) cout << "   <<<  ║\n";
                else cout << "        ║\n";
                cout << "║                                                            ║\n";
            }
            cout << "║                                                            ║\n";
            cout << "║                                                            ║\n";
            cout << "╚════════════════════════════════════════════════════════════╝\n";

            ch = getch_mac();
            switch (ch) {
                case 72: 
                    choice = (choice - 1 + 3) % 3;
                    break;
                case 80: 
                    choice = (choice + 1) % 3;
                    break;
                case '\n': 
                    break;
            }
        }while(ch != '\n');
        
        switch (++choice){
            case 1:
                show_bill_time();
                break;
            case 2:
                show_bill_phong();
                break;
            case 3:
                break;
        }
    } while (choice != 3);
}

void chu_tro::thong_ke_tong(nguoi_thue *nt, int count_thue){
    Time t, real = thuc_te();
    bool check = true;
    if (count_phong == 0) {
        system("clear");
        cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║         BẠN CHƯA TẠO PHÒNG NÀO! KHÔNG THỂ SỬ DỤNG CHỨC NĂNG NÀY            ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
        getch_mac();
        return;
    }
    while(1) {
        system("clear");
        cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                           THỐNG KÊ TỔNG                                             ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        if (!check) cout << "ERROR: Thời gian không hợp lệ. Vui lòng nhập lại!" << endl;
        cout << endl << endl;
        cout << "Bạn muốn thống kê doanh thu trong tháng nào?" << endl;
        cout << "Nhập tháng                                   : ";
        if (!(cin >> t.thang)) {
            t.thang = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (t.thang < 1 || t.thang > 12) {
            t.thang = -1;
            cin.clear();
            cin.ignore();
        }
        cout << "Nhập năm                                     : ";
        if (!(cin >> t.nam)) {
            t.nam = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            cin.clear();
            cin.ignore();
        }
        if (t.thang == -1 || t.nam == -1 || (t.thang > real.thang && t.nam == real.nam) || t.nam > real.nam) {
            check = false;
            continue;
        }
        break;
    }
    

    int count = 0, count_phong_trong = 0, count_phong_cho_thue = 0, count_phong_da_xoa = 0;
    double doanh_thu = 0;
    for (int i = 0; i < count_phong; i++) {
        if (count == 0){
            cout << "Thống kê tổng tháng " << t.thang << " năm " << t.nam << " của chủ trọ " << get_ten() << " như sau:" << endl;
            cout << "╔═════╦═══════╦══════════╦══════════════════════╦════════════╦═════════════════╦════════╗" << endl;
            cout << "║ " << setw(3) << setfill(' ')<< left << centerText("STT", 3) << " ║ " << setw(5) << left << centerText("Phong", 5) << " ║ " << setw(8) << left << centerText("TT Phong", 8) << " ║ " << setw(20) << left << centerText("Nguoi thue", 20) << " ║ " << setw(11) << left << centerText("SĐT thue", 11) << " ║ " << setw(15) << left << centerText("Tong don", 15) << " ║ " <<  setw(6) << left << centerText("TT Nop",6) << " ║" << endl;
        }
        count ++;
        cout << "╠═════╬═══════╬══════════╬══════════════════════╬════════════╬═════════════════╬════════╣" << endl; 
        if((phong + i)->find_hop_dong(t) != -1) {
            int find_hd = (phong + i)->find_hop_dong(t);
            nguoi_thue temp = *(nt + binary_search_thue(nt, count_thue, (phong + i)->get_hop_dong(find_hd).get_ID_thue()));
            count_phong_cho_thue++;
            if ((phong + i)->find_bill(t) != -1){
                int find_bill = (phong + i)->find_bill(t);
                cout << "║ " << setw(3) << left << count << " ║ " << setw(5) << left << (phong + i)->get_ten_phong() << " ║ " << setw(8) << left << "Da thue" << " ║ " << setw(20) << left << temp.get_ten() << " ║ " << setw(10) << left << temp.get_SDT() << " ║ " << setw(15) << left << doubleToString((phong + i)->get_bill(find_bill).get_tien_dien() + (phong + i)->get_bill(find_bill).get_tien_nuoc() + (phong + i)->get_gia_phong()) << " ║ ";
                (phong + i)->get_bill(find_bill).get_trang_thai() ? cout << setw(6) << left << "Yes" << " ║" << endl : cout << setw(6) << left << "No" << " ║"<< endl;
                doanh_thu += (phong + i)->get_bill(find_bill).get_tien_dien() + (phong + i)->get_bill(find_bill).get_tien_nuoc() + (phong + i)->get_gia_phong();
            }
            else cout << "║ " << setw(3) << left << count << " ║ " << setw(5) << left << (phong + i)->get_ten_phong() << " ║ " << setw(8) << left << "Da thue" << " ║ " << setw(20) << left << temp.get_ten() << " ║ " << setw(10) << left << temp.get_SDT() << " ║ " << setw(15) << left << "0" << " ║ " << setw(6) << left << "0" << " ║" << endl;
        }
        else {
            if((phong + i)->get_trang_thai() == 2) {

                count_phong_da_xoa++;
                cout << "║ " << setw(3) << left << count << " ║ " << setw(5) << left << (phong + i)->get_ten_phong() << " ║ " << setw(8) << left << "Da xoa" << " ║ " << setw(20) << left << "NULL" << " ║ " << setw(10) << left << "NULL" << " ║ " << setw(15) << left << "0" << " ║ " << setw(6) << left << "0" << " ║" << endl;

            }else{
            count_phong_trong++;
            cout << "║ " << setw(3) << left << count << " ║ " << setw(5) << left << (phong + i)->get_ten_phong() << " ║ " << setw(8) << left << "Trong" << " ║ " << setw(20) << left << "NULL" << " ║ " << setw(10) << left << "NULL" << " ║ " << setw(15) << left << "0" << " ║ " << setw(6) << left << "0" << " ║" << endl;
            }
        }

    }
    cout << "╚═════╩═══════╩══════════╩══════════════════════╩════════════╩═════════════════╩════════╝" << endl;
    cout << "Tong so phong: " << count_phong << endl;
    cout << "So phong trong: " << count_phong_trong << endl;
    cout << "So phong cho thue: " << count_phong_cho_thue << endl;
    cout << "So phong da xoa: " << count_phong_da_xoa << endl;
    cout << fixed << "Tong doanh thu trong thang " << t.thang << " nam " << t.nam << " la: " << doubleToString(doanh_thu) << endl;
    cout << "Nhấn phím bất kỳ để tiếp tục" << endl;
    getch_mac();
}