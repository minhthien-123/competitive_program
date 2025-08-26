#include <bits/stdc++.h>
#define task "stringmood"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
const int m = 1e9 + 7;
int n, F[2][2], M[2][2];

void mood(int f1[2][2], int f2[2][2], int m){
    int a = (f1[0][0] * f2[0][0] % m + f1[0][1] * f2[1][0] % m) % m;
    int b = (f1[0][0] * f2[0][1] % m + f1[0][1] * f2[1][1] % m) % m;
    int c = (f1[1][0] * f2[0][0] % m + f1[1][1] * f2[1][0] % m) % m;
    int d = (f1[1][0] * f2[0][1] % m + f1[1][1] * f2[1][1] % m) % m;
    F[0][0] = a; F[0][1] = b;
    F[1][0] = c; F[1][1] = d;
}

void power(int f[2][2], int n){
    if (n <= 1) return;
    power(f, n / 2);
    mood(f, f, m);
    if (n % 2 != 0) mood(f, M, m);
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    std::cin >> n;

    F[0][0] = 19;
    F[0][1] = 7;
    F[1][0] = 6;
    F[1][1] = 20;

    M[0][0] = 19;
    M[0][1] = 7;
    M[1][0] = 6;
    M[1][1] = 20;

    power(F, n);
    std::cout << F[0][0];

    return 0;
}
