#include <bits/stdc++.h>
using namespace std;

const long long m = 1000000007;
long long n, F[2][2], M[2][2];

void fibo(long long f1[2][2], long long f2[2][2]){
    long long a = (f1[0][0] * f2[0][0] % m + f1[0][1] * f2[1][0] % m) % m;
    long long b = (f1[0][0] * f2[0][1] % m + f1[0][1] * f2[1][1] % m) % m;
    long long c = (f1[1][0] * f2[0][0] % m + f1[1][1] * f2[1][0] % m) % m;
    long long d = (f1[1][0] * f2[0][1] % m + f1[1][1] * f2[1][1] % m) % m;
    F[0][0] = a; F[0][1] = b;
    F[1][0] = c; F[1][1] = d;
}

void Power(long long f[2][2], long long n){
    if (n <= 1) return;
    Power(f, n / 2);
    fibo(f, f);
    if (n % 2 != 0) fibo(f, M);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("fibo1.inp", "r", stdin);
    freopen("fibo1.out", "w", stdout);

    F[0][0] = F[0][1] = F[1][0] = 1;
    F[1][1] = 0;
    M[0][0] = M[0][1] = M[1][0] = 1;
    M[1][1] = 0;

    cin >> n;
    if (n == 0) cout << 0;
    else{
        Power(F, n - 1);
        cout << F[0][0];
    }

    return 0;

}

//1 1 2 3 5 8 13 21
