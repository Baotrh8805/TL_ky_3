#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 10; 
const double EPS = 1e-6; 

void multiplyMatrixVector(double A[MAX_N][MAX_N], double x[MAX_N], double result[MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += A[i][j] * x[j];
        }
    }
}

double norm(double x[MAX_N], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i] * x[i];
    }
    return sqrt(sum);
}

void normalize(double x[MAX_N], int n) {
    double normX = norm(x, n);
    if (normX < EPS) return; 
    for (int i = 0; i < n; i++) {
        x[i] /= normX;
    }
}

void powerIteration(double A[MAX_N][MAX_N], double eigenvector[MAX_N], int n) {
    double x[MAX_N], Ax[MAX_N], eigenvalue;
    
    for (int i = 0; i < n; i++) x[i] = 1.0;

    for (int i = 0; i < 1000; i++) { 
        multiplyMatrixVector(A, x, Ax, n); 
        eigenvalue = norm(Ax, n); 
        normalize(Ax, n); 
        
        double diff = 0;
        for (int i = 0; i < n; i++) diff += fabs(Ax[i] - x[i]);
        if (diff < EPS) break;

        for (int i = 0; i < n; i++) x[i] = Ax[i];
    }

    for (int i = 0; i < n; i++) eigenvector[i] = x[i];
}

int main() {
    int n;
    double A[MAX_N][MAX_N];

    cout << "Nhap kich thuoc ma tran (n x n): ";
    cin >> n;
    if (n > MAX_N) {
        cout << "Ma tran qua lon!\n";
        return 1;
    }

    cout << "Nhap ma tran " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    double eigenvector[MAX_N];
    powerIteration(A, eigenvector, n);

    cout << "Vector rieng tuong ung:\n";
    for (int i = 0; i < n; i++) {
        cout << eigenvector[i] << " ";
    }
    cout << endl;

    return 0;
}