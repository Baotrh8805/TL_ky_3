#include <iostream>
#include <string>
#include <conio.h> // Thư viện để sử dụng hàm _getch()
#include <windows.h> // Thư viện để sử dụng hàm SetConsoleCursorPosition và SetConsoleTextAttribute

void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void drawLoginScreen() {
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Màu vàng

    std::cout << "╔═════════════════════════════════════════════════════╗\n";
    std::cout << "║           ╔══════════════════════════════╗          ║\n";
    std::cout << "║           ║           ĐĂNG NHẬP          ║          ║\n";
    std::cout << "║           ╚══════════════════════════════╝          ║\n";
    std::cout << "║                  ╔══════════════════════════════╗   ║\n";
    std::cout << "║ Tên đăng nhập    ║                              ║   ║\n";
    std::cout << "║                  ╚══════════════════════════════╝   ║\n";
    std::cout << "║                                                     ║\n";
    std::cout << "║                  ╔══════════════════════════════╗   ║\n";
    std::cout << "║ Mật khẩu         ║                              ║   ║\n";
    std::cout << "║                  ╚══════════════════════════════╝   ║\n";
    std::cout << "║                                                     ║\n";
    std::cout << "╚═════════════════════════════════════════════════════╝\n";

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Màu trắng mặc định
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void handleLogin(const std::string& username, const std::string& password) {
    gotoxy(0, 15); // Di chuyển con trỏ xuống dưới để hiển thị kết quả
    if (username == "admin" && password == "password") {
        std::cout << "Đăng nhập thành công!" << std::endl;
    } else {
        std::cout << "Tên đăng nhập hoặc mật khẩu không đúng!" << std::endl;
    }
}

void dang_nhap() {
    std::string username, password;
    char ch;

    drawLoginScreen();

    gotoxy(22, 5); // Di chuyển con trỏ đến vị trí nhập tên đăng nhập
    std::getline(std::cin, username);

    gotoxy(22, 9); // Di chuyển con trỏ đến vị trí nhập mật khẩu
    while ((ch = _getch()) != 13) { // 13 là mã ASCII của phím Enter
        if (ch == 8) { // 8 là mã ASCII của phím Backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b"; // Xóa ký tự cuối cùng
            }
        } else {
            password.push_back(ch);
            std::cout << '*'; // Hiển thị dấu *
        }
    }

    // Kiểm tra tài khoản khi nhấn Enter
    handleLogin(username, password);
}

int main() {
    // Thiết lập mã hóa ký tự cho console
    SetConsoleOutputCP(CP_UTF8);

    dang_nhap();
    return 0;
}