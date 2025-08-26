#include <bits/stdc++.h>
#define task "antmove"
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

int n, k, m, ans[maxn + 7], l, f[maxn + 7];
ii p[maxn + 7];
int t[maxn + 7];
struct ant
{
    int x, w, d, t;
} a[maxn + 7];
bool cmp1(ant x, ant y)
{
    return x.x < y.x;
}
bool cmp2(ant x, ant y)
{
    return x.t < y.t;
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

    std::cin >> n >> l >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].x >> a[i].w >> a[i].d;
        if (a[i].d)
        {
            a[i].t = abs(l - a[i].x);
        }
        else
        {
            a[i].t = a[i].x;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> t[i];
    }
    std::sort(a + 1, a + n + 1, cmp1);
    std::deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        dq.pb(a[i].w);
    }
    std::sort(a + 1, a + n + 1, cmp2);
    for (int i = 1; i <= n; i++)
    {
        if (!a[i].d)
        {
            p[i] = {a[i].t, dq.front()};
            dq.pop_front();
        }
        else
        {
            p[i] = {a[i].t, dq.back()};
            dq.pop_back();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] + p[i].se;
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = p[i].fi;
    }
    for (int i = 1; i <= m; i++)
    {
        int pos = std::upper_bound(f + 1, f + n + 1, t[i]) - f;
        pos--;
        std::cout << ans[pos] << " ";
    }

    return 0;
}
