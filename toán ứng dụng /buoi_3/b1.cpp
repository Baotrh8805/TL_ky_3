#include <iostream>
using namespace std;

int modpow(int x, int n, int m)
{
    if (n == 0)
        return 1 % m; // Nếu n = 0, trả về 1 % m
    long u = modpow(x, n / 2, m); // Đệ quy tính lũy thừa của x^(n/2)
    u = (u * u) % m; // Bình phương kết quả và lấy modulo m
    if (n % 2 == 1)
        u = (u * x) % m; // Nếu n lẻ, nhân thêm x và lấy modulo m
    return u;
}

bool check_equal(int x, int y, int m, int n)
{
    if ((x + y) % m == (x % m + y % m) % m)
        return true; // Kiểm tra phép cộng modulo
    if ((x - y) % m == (x % m - y % m + m) % m)
        return true; // Kiểm tra phép trừ modulo
    if ((x * y) % m == (x % m * y % m) % m)
        return true; // Kiểm tra phép nhân modulo
    if (modpow(x, n, m) == modpow(x % m, n, m))
        return true; // Kiểm tra phép lũy thừa modulo
    return false; // Nếu không có phép nào bằng nhau, trả về false
}

int main()
{
    int x, y, m, n;
    cout << "Nhap x: ";
    cin >> x; 
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap m: ";
    cin >> m; 
    cout << "Nhap n: ";
    cin >> n; 
    if (check_equal(x, y, m, n))
        cout << "2 ve bang nhau\n"; 
    else
        cout << "2 ve khong bang nhau\n"; 

    return 0; 
}