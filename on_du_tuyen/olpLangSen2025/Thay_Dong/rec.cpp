#include <bits/stdc++.h>
#define task "rec"
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

int n;
iii a[maxn + 7];
int f[maxn + 7], par[maxn + 7], dp[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi.fi >> a[i].fi.se;
        if (a[i].fi.fi > a[i].fi.se)
        {
            std::swap(a[i].fi.fi, a[i].fi.se);
        }
        a[i].se = i;
    }

    std::sort(a + 1, a + n + 1);
    std::vector<int> f;
    std::vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        int val = a[i].fi.se;
        int pos = std::upper_bound(f.begin(), f.end(), val) - f.begin();
        if (pos >= f.size())
        {
            f.pb(val);
            res.pb(i);
        }
        else
        {
            f[pos] = val;
            res[pos] = i;
        }
        par[i] = (pos > 0 ? res[pos - 1] : 0);
    }

    int ans = f.size();
    std::cout << ans << "\n";

    std::vector<int> v;
    int cur = res[ans - 1];
    while (cur != 0)
    {
        v.pb(a[cur].se);
        cur = par[cur];
    }
    std::reverse(v.begin(), v.end());
    for (int id : v)
        std::cout << id << " ";
    std::cout << "\n";

    return 0;
}
