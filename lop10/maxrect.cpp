#include <bits/stdc++.h>
#define task "maxrect"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int m, n, ans, i, j;
int a[maxn], beg[maxn], en[maxn];
char x;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n;

    ans = 0;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++) {
            std::cin >> x;
            if (x == 'B') a[j] = 0;
            else          a[j] += 1;
        }

        std::vector<ii> v;

        for (j = 0; j < n; j++) {
            while (!v.empty() && v.back().fi >= a[j]) v.pop_back();

            if (v.empty()) beg[j] = -1;
            else           beg[j] = v.back().se;

            v.push_back({a[j], j});
        }

        v.clear();

        for (j = n - 1;j >= 0; j--) {
            while (!v.empty() && v.back().fi >= a[j]) v.pop_back();

            if (v.empty()) en[j] = n;
            else           en[j] = v.back().se;

            v.push_back({a[j], j});
        }

        for (j = 0; j < n; j++) {
            ans = std::max(ans, a[j] * (en[j] - beg[j] - 1));
        }
    }

    std::cout << ans;
    return 0;
}
