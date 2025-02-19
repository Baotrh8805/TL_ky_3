#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct node {
    int co_so;
    int so_mu;
};

// bài 1 phân rã thừa số nguyên tố
vector<node>  phan_ra_snt( int n) {
    int i,k = 0;
      i = 2;
    vector<node> v;
    while (n > 1 || k>0) {
        if (n % i == 0) {
            k++;    
            n /= i;
        } else {
            if(k > 0 ) v.push_back((node){i,k});
            k = 0;
            i++;
        }
    }
    return v;
}

vector<int> cac_uoc_so( int n) {
    vector<int> arr;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            arr.push_back(i);
            if (i != n / i) {
                arr.push_back(n / i);
            }
        }
    }
    return arr;
}

// bài 1 phân rã thừa số nguyên tố
void B1( int n) {
    vector<node> v = phan_ra_snt(n);
    cout << n << " = ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].co_so ;
        if (v[i].so_mu > 1) {
            cout << "^" << v[i].so_mu;
        }
        if (i < v.size() - 1) {
            cout << " * ";
        }else {
            cout << endl;
        }
    }
}

// bài 2 ct tính tổng sống lượng ước và liệt kê các ước số đó
void B2( int n) {
    vector<int> arr = cac_uoc_so(n);
    cout << "Số lượng ước số của n: " << arr.size() << endl;
    cout << "Các ước số của n: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}


// bài 3 viết công thức tính tổng số ước số của n
void B3( int n) {
    vector<node> v = phan_ra_snt(n);
    int result = 1;
    for (node val : v) {
        result *= (pow(val.co_so, val.so_mu + 1) - 1) / (val.co_so - 1);
    }
    cout << "Tổng các ước số của n: " << result << endl;
}

// bài 4 viết công thức tính tích số ước số của n
void B4( int n) {
    vector<int> arr = cac_uoc_so(n);
    long long result = 1;
    result = pow(n,  arr.size() / 2);
    cout << "Tích tích ước số của n: " << result << endl;
}

// bài 5 kiểm tra số nguyên tố 
void B5_1( int n) {

    cout << "Kiểm tra số nguyên tố bằng cách kiểm tra từ 2 đến căn bật 2 của n nếu chia hết cho một số nào thì n không là số nguyên tố : " << endl;
    if (n < 2) {
        cout << n << " không phải là số nguyên tố" << endl;
        return;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << n << " không phải là số nguyên tố" << endl;
            return;
        }
    }
    cout << n << " là số nguyên tố" << endl;
}

void B5_2( int n) {
    cout << "Kiểm tra bằng cách tính số ước ủa n nếu ước lớn hơn 2 thì n không phải là số nguyên tố: " << endl;
    vector<int> arr = cac_uoc_so(n);
    if (arr.size() > 2) {
        cout << n << " không phải là số nguyên tố" << endl;
    } else {
        cout << n << " là số nguyên tố" << endl;
    }
}

// bài 6 ước lượng số lượng số nguyên tố từ 1 đến n
void B6( int n) {
   cout << "Ước lượng số lượng số nguyên tố từ 1 đến n: " << n / log(n) << endl;
}

int main() {
    cout << "Nhap n: ";
     int n;
    cin >> n;
    system("clear");
    B1(n);
    B2(n);
    B3(n);
    B4(n);
    B5_1(n);
    B5_2(n);
    B6(n);
    return 0;   
}



