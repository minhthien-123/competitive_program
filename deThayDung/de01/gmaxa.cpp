#include <bits/stdc++.h>

long long n, ans = LLONG_MAX, d = 0;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("gmaxa.inp", "r", stdin);
    std::freopen("gmaxa.out", "w", stdout);

    std::cin >> n;
    for (long long i = 0, x; i < n; i++){
        std::cin >> x;
        if (x > 0) {
            ans = std::min(ans, x);
            d++;
        }
    }

    if (d == 0) ans = 0;
    std::cout << ans << '\n';

    return 0;
}