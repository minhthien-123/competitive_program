#include <bits/stdc++.h>

long long n, a = LLONG_MAX, b = LLONG_MIN;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("dist11.inp", "r", stdin);
    std::freopen("dist11.out", "w", stdout);

    std::cin >> n;
    for (long long i = 1, x; i <= n; i++){
        std::cin >> x;
        a = std::min(a, x);
        b = std::max(b, x);
    }

    std::cout << b - a;

    return 0;
}