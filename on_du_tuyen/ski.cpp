#include <bits/stdc++.h>
#define task "ski"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e6;
int n, m, t;
int a[maxn + 7], f[maxn + 7];
int par[maxn + 7], sz[maxn + 7], cnt[maxn + 7];
struct ski
{
    int w, u, v;
};
std::vector<ski> vec;
int ans = 0;

int idx(int i, int j)
{
    return (i - 1) * m + j;
}

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    return par[v] == v ? v : par[v] = find(par[v]);
}

bool cmp(ski x, ski y)
{
    return x.w < y.w;
}

void join(int u, int v, int w)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return;
    }

    if (sz[u] < sz[v])
    {
        std::swap(u, v);
    }

    int su = sz[u], sv = sz[v];
    int cu = cnt[u], cv = cnt[v];
    if (su < t && su + sv >= t)
    {
        ans += cu * w;
    }
    if (sv < t && su + sv >= t)
    {
        ans += cv * w;
    }

    par[v] = u;
    sz[u] += sz[v];
    cnt[u] += cnt[v];
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

    std::cin >> n >> m >> t;

    for (int i = 1; i <= n * m; i++)
    {
        init(i);
    }

    for (int i = 1; i <= n * m; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n * m; i++)
    {
        std::cin >> f[i];
        if (f[i] == 1)
        {
            cnt[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int u = idx(i, j);
            if (j < m)
            {
                int v = idx(i, j + 1);
                vec.pb({std::llabs(a[u] - a[v]), u, v});
            }
            if (i < n)
            {
                int v = idx(i + 1, j);
                vec.pb({std::llabs(a[u] - a[v]), u, v});
            }
        }
    }

    std::sort(vec.begin(), vec.end(), cmp);

    for (auto e : vec)
    {
        join(e.u, e.v, e.w);
    }

    std::cout << ans << "\n";
    return 0;
}
