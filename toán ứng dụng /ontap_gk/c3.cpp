#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<windows.h>

using namespace std;

vector<vector<double>> L;
vector<double> diag;

void nhapMang(vector<vector<double>>& M, int size);
bool kiemTraDieuKien(const vector<vector<double>>& M, int size);
bool kiemTraDoiXung(const vector<vector<double>>& M, int size);
void phanRaMaTran(const vector<vector<double>>& M, vector<vector<double>>& B, vector<double>& diag, int size);
void xuatKetQua(const vector<vector<double>>& B, const vector<double>& diag, int size);

int main() {
    SetConsoleOutputCP(65001);
    int size;
    cout << "Nhập số lượng hàng và cột: ";
    cin >> size;
    
    vector<vector<double>> M(size, vector<double>(size));
    L.resize(size, vector<double>(size, 0));
    diag.resize(size);
    
    nhapMang(M, size);
    
    if (!kiemTraDieuKien(M, size)) {
        cout << "Ma trận không hợp lệ cho phân rã LDL^t !\n";
        return 0;
    }
    
    phanRaMaTran(M, L, diag, size);
    xuatKetQua(L, diag, size);
    return 0;
}

void nhapMang(vector<vector<double>>& M, int size) {
    cout << "Nhập các phần tử của ma trận:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "M[" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
}

bool kiemTraDoiXung(const vector<vector<double>>& M, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (M[i][j] != M[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool kiemTraDieuKien(const vector<vector<double>>& M, int size) {
    return kiemTraDoiXung(M, size);
}

void phanRaMaTran(const vector<vector<double>>& M, vector<vector<double>>& L, vector<double>& diag, int size) {
    for (int j = 0; j < size; j++) {
        double tong = M[j][j];
        for (int k = 0; k < j; k++) {
            tong -= L[j][k] * L[j][k] * diag[k];
        }
        diag[j] = tong;
        for (int i = j + 1; i < size; i++) {
            double giaTri = M[i][j];
            for (int k = 0; k < j; k++) {
                giaTri -= L[i][k] * L[j][k] * diag[k];
            }
            L[i][j] = giaTri / diag[j];
        }
        L[j][j] = 1.0;
    }
}

void xuatKetQua(const vector<vector<double>>& L, const vector<double>& diag, int size) {
    cout << "Ma tran L | D | L^T" << endl;
    cout << fixed << setprecision(5);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(😎 << (j > i ? 0.00 : L[i][j]) << " ";
        }
        cout << " | ";
        for (int j = 0; j < size; j++) {
            cout << setw(😎 << (i == j ? diag[i] : 0.00) << " ";
        }
        cout << " | ";
        for (int j = 0; j < size; j++) {
            cout << setw(😎 << (j < i ? 0.00 : L[j][i]) << " ";
        }
        cout << "\n";
    }
}