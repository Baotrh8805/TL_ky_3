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


void choleskyVarian(double **matrix, int n){
    double **temp = new double*[n];
    for(int i = 0; i < n; i++){
        temp[i] = new double[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            double sum = 0;
            for(int k = 0; k < j; k++){
                sum += temp[i][k] * temp[j][k] * temp[k][k];
            }
            if(i == j){
                temp[i][j] = matrix[i][i] - sum;
            } else {
                temp[i][j] = (matrix[i][j] - sum) / temp[j][j];
            }
        }
    }
    cout << "Ma tran L: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cout << "1"<< " ";
            }
            else{
                cout << temp[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "Ma tran L chuyen vi: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cout << "1"<< " ";
            }
            else{
                cout << temp[j][i] << " ";
            }
        }
        cout << endl;
    }
    cout << "Ma tran D: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cout << temp[i][j] << " ";
            }
            else{
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
}


int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    double **matrix = new double*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new double[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    if(isSymmertric(matrix, n)){
        choleskyVarian(matrix, n);
    } else {
        cout << "Ma tran khong doi xung" << endl;
    }
    for(int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}


