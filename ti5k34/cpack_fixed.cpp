#include <bits/stdc++.h>
#define task "cpack"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n, q;
ii a[maxn + 7], query[maxn + 7];
int par[maxn + 7], res[maxn + 7], sz[maxn + 7];
bool flag[maxn + 7];

void init()
{
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u)
{
    if (par[u] == u)
    {
        return u;
    }
    return par[u] = find(par[u]);
}

void merge(int u, int v)
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
    par[v] = u;
    sz[u] += sz[v];
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi;
        a[i].se = i;
    }

    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= q; i++)
    {
        std::cin >> query[i].fi;
        query[i].se = i;
    }
    std::sort(query + 1, query + q + 1);

    int j = 1, ans = 0;

    init();

    for (int i = 1; i <= q; i++)
    {
        int cur = query[i].fi;
        while (j <= n && a[j].fi <= cur)
        {
            int u = a[j].se;
            flag[u] = true;
            if (flag[u - 1])
            {
                merge(u, u - 1);
            }
            if (flag[u + 1])
            {
                merge(u, u + 1);
            }
            ans = std::max(ans, sz[find(u)]);
            j++;
        }
        res[query[i].se] = ans;
    }

    for (int i = 1; i <= q; i++)
    {
        std::cout << res[i] << "\n";
    }

    return 0;
}
