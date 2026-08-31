#include <bits/stdc++.h>

long long mx = LLONG_MIN, ans = LLONG_MAX, n;
std::map<long long, long long> m;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::freopen("dxb3.inp", "r", stdin);
    std::freopen("dxb3.out", "w", stdout);

    std::cin >> n;
    for (long long i = 0, x; i < n; i++){
        std::cin >> x;
        m[x]++;
        if (m[x] == mx)
            if (x < ans)
                ans = x;
        mx = std::max(mx, m[x]);
    }

    std::cout << ans;

    return 0;
}