#include <bits/stdc++.h>

const long long mod = 1e9;

long long power(long long x, long long y){
    if (y == 0) return 1;
    long long tmp = power(x, y / 2);
    if (y % 2 == 0) return (tmp * tmp) % mod;
    else            return x * (tmp * tmp % mod) % mod;
}

int n;
long long a[1000005], ans = 0;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("MUL.inp", "r", stdin);
    std::freopen("MUL.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    for (int i = 1; i <= n; i++){
        long long x;
        std::cin >> x;
        ans = (ans + power(a[i], x)) % mod;
    }

    std::cout << ans;

    return 0;
}

// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144