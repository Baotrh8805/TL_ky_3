#include <iostream>
using namespace std;
// Định lý số dư Trung Hoa
void Input(int a[],int m[], const int &n) {
   for (int i = 0; i < n; i++) {
       cout << "Nhập a" << i+1 << ": "; cin >> a[i];
       cout << "Nhập m" << i+1 << ": "; cin >> m[i];
   }
}


int CRT(int a[],int m[],int Y[],int n) {
   int ans = 0;
   for (int i = 0; i < n; i++) {
       ans += a[i] * m[i] * Y[i];
   }
   return ans;
}


int main(){
   int n;
   cout << "Nhập số lượng phương trình (n): "; cin >> n;
   int a[n];
   int m[n];
   Input(a, m, n);
   int M = 1;
   for (int i = 0; i < n; i++) {
       M *= m[i];
   }
   int X[n];
   for (int i = 0; i < n; i++) {
       X[i] = M / m[i];
   }
   int Y[n];
   for (int i = 0; i < n; i++) {
       Y[i] = X[i] % m[i];
   }
   int ans = CRT(a, X, Y, n);
   cout << "Nghiệm: " << ans << endl;
   cout << "Cách khác: " << ans % M << " + k" << M << endl;
   return 0;
}