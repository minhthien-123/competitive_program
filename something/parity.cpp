#include <bits/stdc++.h>
#define int long long

const int maxn = 1e6;

int n, a[maxn + 5], res[2 * maxn + 5], ans = 0;
std::map<int, int> mp;

signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::freopen("parity.inp", "r", stdin);
    std::freopen("parity.out", "w", stdout);

    std::cin >> n;
    for (int i = 1, x; i <= n; i++){
        std::cin >> x;
        if (x % 2 == 0) a[i] = a[i - 1] + 1;
        else            a[i] = a[i - 1] - 1;
    }

    mp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        ans += mp[a[i]];
        mp[a[i]]++;
    }

    std::cout << ans;

    return 0;
}