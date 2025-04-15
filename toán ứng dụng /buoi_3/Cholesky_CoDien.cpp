#include <iostream>


#include <math.h>
using namespace std;


bool isSymmertric(double **matrix, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] != matrix[j][i]){
                return false;
            }
        }
    }
    return true;
}


double det(double **A, int n) {
    double **matrix = new double*[n];
    for(int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            matrix[i][j] = A[i][j];
        }
    }
    double res = 1;
    for(int i = 0; i < n; ++i) {
        if(matrix[i][i] == 0) {
            for(int j = i + 1; j < n; ++j) {
                if(matrix[j][i] != 0) {
                    for(int k = 0; k < n; ++k) {
                        int t = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = t;
                    }
                }
            }
        }
        if(matrix[i][i] == 0) return 0;
        res = res * matrix[i][i];
        for(int j = i + 1; j < n; ++j) {
            double ratio = -matrix[j][i]/matrix[i][i];
            for(int k = i; k < n; ++k) {
                matrix[j][k] = matrix[i][k] * ratio + matrix[j][k];
            }
        }
    }
    return res;
}


bool isPositive(double **matrix, int n) {
    for(int i = 0; i < n; ++i){
        if(det(matrix, i) <= 0){
            return false;
        }
    }
    return true;
}


void cholesky(double **matrix, int n){
    double **temp = new double*[n];
    for(int i = 0; i < n; ++i){
        temp[i] = new double[n];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            temp[i][j] = 0;
        }
    }
    double sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            sum = 0;
            for(int k = 0; k < j; ++k){
                sum += temp[i][k] * temp[j][k];
            }
            if(i == j){
                temp[i][j] = sqrt(matrix[i][i] - sum);
            }
            else {
                temp[i][j] = (matrix[i][j] - sum) / temp[j][j];
            }
        }
    }
    cout << "Ma tran L: " << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Ma tran L chuyen vi: " << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << temp[j][i] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; ++i){
        delete[] temp[i];
    }
    delete[] temp;
}


int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    double **matrix = new double*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new double[n];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    if(isSymmertric(matrix, n) && isPositive(matrix, n)){
        cholesky(matrix, n);
    } else {
        cout << "Khong the phan tich Cholesky" << endl;
    }
    for(int i = 0; i < n; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}


