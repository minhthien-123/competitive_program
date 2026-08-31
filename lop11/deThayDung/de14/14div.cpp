#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e6 + 5;

ll n, k, j, len, d;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("14div.inp", "r", stdin);
    std::freopen("14div.out", "w", stdout);

    std::cin >> n >> k;

    for (ll i = 1; i * i < n; i++){
        if (n % i == 0)
            std::cout << i << " ";
    }

    for (ll i = sqrt(n); i >= 1; i--){
        if (n % i == 0)
            std::cout << n / i << " ";
    }

    return 0;
}
