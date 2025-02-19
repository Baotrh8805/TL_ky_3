#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// void eratosthenes( int n) {
//     int A[n+1];
//     for (int i = 2; i <=n; i++) A[i]=0;
//     for(int i=2; i<n ; i++){
//         if(A[i]!=0)continue;
//         for (int x = 2*i; x <=n  ; x+=i)
//         {
//             A[x]=i;
//         }
//     }
//     cout << "cac so nguyen to nho hon "<< n << " la: " << '\n';
// //     for (int i = 2; i <=n ; i++)
// //     {
// //         if (A[i]==0)
// //         {  
// //             cout << i << " ";
// //         }
        
// //     }
    
// // }



// // // bài 1 tìm các số nguyên tố nhỏ hơn n
// // int main() {
// //     system("clear");
// //     cout << "Nhap n: ";
// //     int n;
// //     cin >> n;
// //     eratosthenes(n);
// //     return 0;
// // }



// // int gcd(int a, int b){
// //     if(b>a)gcd(b,a);
// //     if(b==0)return a;
// //     else return gcd(b,a%b);
// // }
// // // // bài 2: tìm ước chung lớn nhất của 2 số bất kì
// // int main(){
// //     system("clear");
// //     int a,b;
// //     cout << "nhap a: ";
// //     cin>>a;
// //     cout << "nhap b: ";
// //     cin >> b;
// //     cout << " Uoc chung lon nhat cua " << a << " và "<< b << " là : ";
// //     cout << gcd(a,b);
// //     return 0;
// // }





// int euler_totient_fast(int n){
//     int t=1;
//     if(check_snt(n)) return n-1;
//     vector<node> arr=phan_ra_snt(n);
//     for (int i = 0; i < arr.size(); i++)
//     {
//        t *= pow(arr[i].co_so,arr[i].so_mu - 1 )*(arr[i].co_so - 1);

//     }
//     return t;
// }

// // // 3. Viết chương trình thực hiện Ecleu's Totient Function 

// // int main(){
// //     cout << " nhap n: ";
// //     int n;
// //     cin >> n;
// //     cout << "tổng các cặp số nguyên tố cùng với "<< n << " là : " << euler_totient_fast(n);
// //     return 0;

// // }

bool check_snt( int n) {

    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int so_nt_gan_nhat(int n){
    int i=1;
    do{
        if( check_snt(n-i)) return n-i;
        if( check_snt(n+i)) return n+i;
        i++;
    }while(1);
}


struct node {
    int co_so;
    int so_mu;
};

// Phân tích số nguyên n thành các thừa số nguyên tố
vector<node> phan_ra_snt(int n) {
    int i = 2, k = 0;
    vector<node> v;
    while (n > 1) {
        if (n % i == 0) {
            k++;
            n /= i;
        } else {
            if (k > 0) v.push_back((node){i, k});
            k = 0;
            i++;
        }
    }
    if (k > 0) v.push_back((node){i, k});
    return v;
}

// Kiểm tra xem n có phải là số hoàn hảo hay không
bool check_shh(int n) {
    vector<node> v = phan_ra_snt(n);
    long long result = 1;
    for (int i = 0; i < v.size(); i++) {
        result *= (pow(v[i].co_so, v[i].so_mu + 1) - 1) / (v[i].co_so - 1);
    }
        result-=n;
    if (result == n) return true;
    return false;
}

// Tìm số hoàn hảo gần n nhất
int shh_gan_nhat(int x) {
    int k = 1;
    while (true) {
        if (check_shh(x + k)) return x + k;
        if (check_shh(x - k)) return x - k;
        k++;
    }
}

int main() {
    int x;
    cout << "Nhap x: ";
    cin >> x;
    cout <<"snt: ";
    vector<node> v = phan_ra_snt(x);
    cout << x << " = ";
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
    cout << '\n';
    cout << "So hoan hao gan " << x << " nhat la: " << shh_gan_nhat(x) << endl;
    return 0;
}

// // 4. Cho n là đủ lớn, phân tích thừa số nguyên tố với số n. Ước số lớn nhứt của n -> m 

// int main(){

    
//     return 0;
// }
