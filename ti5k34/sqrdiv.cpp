#include <bits/stdc++.h>
#define task
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e9 + 7;


signed main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    //std::freopen(task".inp", "r", stdin);
    //std::freopen(task".out", "w", stdout);

    int t;
    std::cin >> t;

    while (t--) {
        int l, r;
        std::cin >> l >> r;
        int ans = 0;
        for (int i = 1; i * i <= r; i++)
            ans += r / (i * i) - (l - 1) / (i * i);

        std::cout << ans << "\n";
    }

    return 0;
}
