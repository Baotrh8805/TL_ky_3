#include <iostream>
using namespace std;
int modInverse(int a, int m)
{
    int ix = 1;
    while ((ix * a) % m != 1)
    {
        ix++;
    }
    return ix;
}

int findMinX(int num[], int rem[], int k)
{
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int Xk = prod / num[i];
        int inv = modInverse(Xk, num[i]);
        result += rem[i] * Xk * inv;
    }
    return result;
}

int main()
{
    int num[] = {5, 7, 3}; // Các module
    int rem[] = {3, 4, 2}; // Các số dư tương ứng
    int k = sizeof(num) / sizeof(num[0]);

    cout << "x= " << findMinX(num, rem, k) << endl;
    return 0;
}
