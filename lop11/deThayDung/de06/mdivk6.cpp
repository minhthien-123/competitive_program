#include <bits/stdc++.h>

long long ans = -9e18;
long long n, k;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("mdivk6.inp", "r", stdin);
    std::freopen("mdivk6.out", "w", stdout);

    std::cin >> n >> k;
    for (long long i = 0, x; i < n; i++){
        std::cin >> x;
        if (x % k == 0)
            ans = std::max(ans, x);
    }

    std::cout << ans;

    return 0;
}