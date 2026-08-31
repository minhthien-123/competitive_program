#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;

ii piza[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int a, b, c, n;
    std::cin >> a >> b >> c;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int price;
        std::cin >> price;
        piza[i] = {price, i + 1};
    }

    std::sort(piza, piza + n);

    if (a > c) {
        std::cout << a << "\n0";
    } else {
        int ans = a + b;
        std::vector<int> res;

        int cnt = 1 << n;
        for (int mask = 0; mask < cnt; mask++) {
            int cur = a;
            std::vector<int> tmp;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cur += piza[i].fi;
                    tmp.pb(piza[i].se);
                }
            }

            if (cur > c) {
                if (cur < ans) {
                    ans = cur;
                    res = tmp;
                }
            }
        }

        if (ans == a + b) {
            std::cout << a + b << "\n" << "-1";
        } else {
            std::cout << ans << "\n";
            std::cout << res.size() << "\n";
            for (int idx : res) {
                std::cout << idx << " ";
            }
        }
    }

    return 0;
}