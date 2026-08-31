#include <bits/stdc++.h>
#define task "subsetsum3"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf = 1e18;

int n, m;
ii a[maxn + 7];
int pre[maxn + 7];

int res = 0;
std::vector<int> ans;

void solve(int id, int s, std::vector<int> &v)
{
    if (res == m - 1)
    {
        return;
    }
    if (s >= m)
    {
        return;
    }
    if (id == n + 1)
    {
        if (s < m && s > res)
        {
            res = s;
            ans = v;
        }
        return;
    }

    if (s + (pre[n] - pre[id - 1]) <= res)
        return;

    if (s + a[id].fi < m)
    {
        v.push_back(a[id].se);
        solve(id + 1, s + a[id].fi, v);
        v.pop_back();
    }

    solve(id + 1, s, v);
}

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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi;
        a[i].se = i;
    }

    std::sort(a + 1, a + n + 1, [](ii x, ii y)
              { return x.fi > y.fi; });

    pre[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + a[i].fi;
    }

    if (pre[n] < m)
    {
        std::cout << pre[n] << "\n";
        for (int i = 1; i <= n; ++i)
        {
            std::cout << a[i].se << " ";
        }
        return 0;
    }

    std::vector<int> temp;
    solve(1, 0, temp);

    std::cout << res << "\n";
    for (int x : ans)
    {
        std::cout << x << " ";
    }

    return 0;
}