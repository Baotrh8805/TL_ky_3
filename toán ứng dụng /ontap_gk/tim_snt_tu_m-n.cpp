#include <iostream>
#include <math.h>
using namespace std;

void tim_snt( int m,int n) {
    for(int i=m; i<=n ; i++){
      
    }
    int A[n+1];
    for (int i = 2; i <=n; i++) A[i]=0;
    for(int i=2; i<n ; i++){
        if(A[i]!=0)continue;
        for (int x = 2*i; x <=n  ; x+=i)
        {
            A[x]=i;
        }
    }
    cout << "cac so nguyen to tu  "<< m << " den " <<  n << " la:" << '\n';
    for (int i = m; i <=n ; i++)
    {
        if (A[i]==0)
        {  
            cout << i << " ";
        }
        
    }
    cout << '\n';
}
int main(){
    system("clear");
    int m,n;
    cout << "nhap m: ";
    cin >> m;
    cout << "nhap n: ";
    cin >> n;
    tim_snt(m,n);
    return 0;
}