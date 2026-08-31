#include <bits/stdc++.h>
#define task "sleddogs"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k;
ii a[maxn + 7], b[maxn + 7];
std::multiset<ii> ms;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].se;
        a[i].fi = a[i].se % k;
    }
    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i].se;
        b[i].fi = b[i].se % k;
    }
    for (int i = 1; i <= n; i++)
    {
        ms.insert(b[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        auto it = ms.upper_bound(ii((k - a[i].fi) % k, 2e9));
        if (it == ms.begin())
        {
            it = --ms.end();
            ans += (it->se + a[i].se + k - 1) / k;
            ms.erase(it);
        }
        else
        {
            it--;
            ans += (it->se + a[i].se + k - 1) / k;
            ms.erase(it);
        }
    }
    std::cout << ans;

    return 0;
}
