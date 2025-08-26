#include <bits/stdc++.h>
#define int long long

const int mod = 998244353;
const int maxn = 2e5 + 7;

int n, m, a[maxn], b[maxn], ans = 1;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    a[1] = b[1];
    for (int i = 1; i <= n; i++){
        int cnt = 0;
        for (int j = 1; j <= m; j++)
            if (std::__gcd(b[i - 1], j) == b[i])
                cnt++;
        if (cnt != 0)
            ans = (ans % mod * cnt % mod) % mod;
    }

    std::cout << ans;

    return 0;
}
