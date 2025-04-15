#include <iostream>
using namespace std;

// Tính nghịch đảo modular của a theo mod m (dùng Euclid mở rộng)
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m; a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;
    return x1;
}

// Giải hệ phương trình đồng dư x ≡ a[i] (mod m[i])
int solveCRT(int a[], int m[], int n) {
    int M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int Mi = M / m[i];
        int yi = modInverse(Mi, m[i]);
        result += a[i] * Mi * yi;
    }

    return (result % M + M) % M; // Đảm bảo kết quả không âm
}

int main() {
    int n;
    cout << "Nhập số lượng phương trình: ";
    cin >> n;

    int a[n], m[n];

    for (int i = 0; i < n; i++) {
        cout << "Phương trình " << i + 1 << ":\n";
        cout << "  Nhập a" << i + 1 << ": ";
        cin >> a[i];
        cout << "  Nhập m" << i + 1 << ": ";
        cin >> m[i];
    }

    int x = solveCRT(a, m, n);
    int M = 1;
    for (int i = 0; i < n; i++) M *= m[i];

    cout << "\nNghiệm nhỏ nhất x = " << x << " (mod " << M << ")" << endl;

    return 0;
}

