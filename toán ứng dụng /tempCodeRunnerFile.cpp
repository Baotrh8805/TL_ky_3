#include <iostream> 

#include <cmath> 

#include <vector> 

using namespace std; 

 

// Hàm kiểm tra số nguyên tố 

bool isPrime(int n) { 

if (n < 2) return false; 

int sqrtN = sqrt(n); 

for (int i = 2; i <= sqrtN; ++i) 

if (n % i == 0) return false; 

return true; 

} 

 

// Hàm kiểm tra số hoàn hảo 

bool isPerfect(int n) { 

int sum = 1; 

for (int i = 2; i <= n / 2; ++i) 

if (n % i == 0) sum += i; 

return sum == n && n != 1; 

} 

 

// Tìm ước số nguyên tố lớn nhất của N 

int largestPrimeFactor(int n) { 

int maxPrime = -1; 

while (n % 2 == 0) { 

maxPrime = 2; 

n /= 2; 

} 

for (int i = 3; i <= sqrt(n); i += 2) { 

while (n % i == 0) { 

maxPrime = i; 

n /= i; 

} 

} 

if (n > 2) maxPrime = n; 

return maxPrime; 

} 

 

int main() { 

int N = 97700; 

int M = largestPrimeFactor(N); 

cout << "Uoc so nguyen to lon nhat cua " << N << " la: " << M << endl; 

 

// Tìm và liệt kê các số hoàn hảo trong đoạn [1, M] 

vector<int> perfectNumbers; 

int sumPerfect = 0; 

for (int i = 1; i <= M; ++i) { 

if (isPerfect(i)) { 

perfectNumbers.push_back(i); 

sumPerfect += i; 

} 

} 

 

cout << "\nCac so hoan hao tu 1 den " << M << ": "; 

for (int num : perfectNumbers) cout << num << " "; 

cout << "\nSo luong: " << perfectNumbers.size(); 

cout << "\nTong cac so hoan hao: " << sumPerfect << endl; 

 

// Tìm và liệt kê các số nguyên tố nhỏ hơn M 

vector<int> primeNumbers; 

int sumPrime = 0; 

for (int i = 2; i < M; ++i) { 

if (isPrime(i)) { 

primeNumbers.push_back(i); 

sumPrime += i; 

} 

} 

 

cout << "\nCac so nguyen to nho hon " << M << ": "; 

for (int num : primeNumbers) cout << num << " "; 

cout << "\nSo luong: " << primeNumbers.size(); 

cout << "\nTong cac so nguyen to: " << sumPrime << endl; 

 

return 0; 

} 

 