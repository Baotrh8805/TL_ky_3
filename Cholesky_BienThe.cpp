#include <iostream> 

using namespace std;

class Matrix {
    int row, col;
    double **data = nullptr;
public:
    Matrix(int row = 0, int col = 0) :row(row), col(col) {
        data = new double*[row];
        for(int i = 0; i < row; ++i) {
            data[i] = new double[col];
        }
    }

    Matrix(const Matrix &m) :row(m.row), col(m.col) {
        data = new double*[row];
        for(int i = 0; i < row; ++i) {
            data[i] = new double[col];
            for(int j = 0; j < col; ++j)
                data[i][j] = m.data[i][j];
        }
    }

    ~Matrix() {
        for(int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    Matrix SubMatrix(int row, int col) {
        if(row > this->row || col > this->col) 
            throw invalid_argument("Kich thuoc cua ma tran con khong hop le");
        Matrix sub(row, col);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                sub.data[i][j] = data[i][j];
            }    
        }
        return sub;
    }

    Matrix Transpose() {
        Matrix T(col, row);
        for(int i = 0; i < col; ++i) {
            for(int j = 0; j < row; ++j) {
                T.data[i][j] = data[j][i];
            }
        }
        return T;
    }

    bool IsSymmetry() {
        for(int i = 0; i < row; ++i) {
            for(int j = i + 1; j < col; ++j) {
                if(data[i][j] != data[j][i]) return false;
            }
        }
        return true;
    }

    bool IsSquare() {
        return row == col;
    }

    double Det() {
        if(!IsSquare()) throw invalid_argument("Ma tran tinh dinh thuc phai la ma tran vuong");
        double res = 1;
        for(int i = 0; i < row; ++i) {
            if(data[i][i] == 0) {
                for(int j = i + 1; j < row; ++j) {
                    if(data[j][i] != 0) {
                        for(int k = 0; k < col; ++k) {
                            int t = data[i][k];
                            data[i][k] = data[j][k];
                            data[j][k] = t;
                        }
                    }
                }
            }
            if(data[i][i] == 0) return 0;
            res = res * data[i][i];
            for(int j = i + 1; j < row; ++j) {
                double ratio = -data[j][i]/data[i][i];
                for(int k = i; k < col; ++k) {
                    data[j][k] = data[i][k] * ratio + data[j][k];
                }
            }
        }
        return res;
    }

    void CholeskyVariant() {
        if(!IsSquare()) throw invalid_argument("Ma tran phai la ma tran vuong");
        if(!IsSymmetry()) throw invalid_argument("Ma tran phai la ma tran doi xung");
        Matrix L(row, col), D(row, col);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                L.data[i][j] = 0;
                D.data[i][j] = 0;
            }
            L.data[i][i] = 1;
        }
        double sum = 0;
        for(int j = 0; j < col; ++j) {
            for(int i = j; i < row; ++i) {
                sum = 0;
                if(i == j) {
                    for(int k = 0; k < i; ++k) {
                        sum += D.data[k][k] * L.data[i][k] * L.data[i][k];
                    }
                    D.data[i][i] = data[i][i] - sum;
                }
                else {
                    for(int k = 0; k < j; ++k) {
                        sum += D.data[k][k] * L.data[i][k] * L.data[j][k];
                    }
                    L.data[i][j] = (data[i][j] - sum) / D.data[j][j];
                }
            }
        }
        Matrix LT(L.Transpose());
        cout << "Ma tran L:" << endl << L << endl;
        cout << "Ma tran D:" << endl << D << endl;
        cout << "Ma tran LT:" << endl << LT << endl;
        cout << "Ket qua L * D * LT:" << endl << L * D * LT << endl;
    }
    friend ostream &operator<<(ostream &os, const Matrix &m);
    friend istream &operator>>(istream &is, Matrix &m);
    friend Matrix operator*(const Matrix &a, const Matrix &b);
};

ostream &operator<<(ostream &os, const Matrix &m) {
    for(int i = 0; i < m.row; ++i) {
        for(int j = 0; j < m.col; ++j) {
            os << m.data[i][j] << '\t';
        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matrix &m) {
    for(int i = 0; i < m.row; ++i) {
        for(int j = 0; j < m.col; ++j) {
            is >> m.data[i][j];
        }
    }
    return is;
}

Matrix operator*(const Matrix &a, const Matrix &b) {
    if(a.col != b.row) 
        throw invalid_argument("Kich thuoc 2 ma tran khi nhan khong hop le");
    Matrix res(a.row, b.col);
    double sum = 0;
    for(int i = 0; i < a.row; ++i) {
        for(int j = 0; j < b.col; ++j) {  
            sum = 0;              
            for(int k = 0; k < b.row; ++k) {
                sum += a.data[i][k] * b.data[k][j];
            }
            res.data[i][j] = sum;
        }   
    }     
    return res;
}

int main() {
    int n;
    cout << "Nhap kich thuoc ma tran: ";
    cin >> n;
    Matrix A(n, n);
    cout << "Nhap ma tran A: " << endl;
    cin >> A;
    A.CholeskyVariant();
    return 0;
}