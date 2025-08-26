#include <bits/stdc++.h>
#define task "dsu"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<int, ii>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e5;
const int inf = 1e18;

int n, m;
std::vector<std::pair<ii, ii>> adj;
int par[maxn + 7];
int ans[maxn + 7];

void make_set()
{
    for (int v = 1; v <= n; v++)
    {
        par[v] = v;
    }
}

int find_set(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v]);
}

bool join(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
    {
        return false;
    }
    par[b] = a;
    return true;
}

bool cmp(std::pair<ii, ii> a, std::pair<ii, ii> b)
{
    return a.fi.fi < b.fi.fi;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        std::cin >> u >> v >> c;
        adj.pb({{c, i}, {u, v}});
    }

    std::sort(adj.begin(), adj.end(), cmp);
    make_set();

    int i = 0;
    while (i < m)
    {
        int c = adj[i].fi.fi;
        std::vector<std::pair<ii, ii>> res;

        while (i < m && adj[i].fi.fi == c)
        {
            res.pb(adj[i]);
            i++;
        }

        std::vector<bool> f(res.size(), false);
        for (int j = 0; j < res.size(); j++)
        {
            int u = res[j].se.fi;
            int v = res[j].se.se;
            if (find_set(u) != find_set(v))
            {
                f[j] = true;
            }
        }

        for (int j = 0; j < res.size(); j++)
        {
            int u = res[j].se.fi;
            int v = res[j].se.se;
            join(u, v);
        }

        for (int j = 0; j < res.size(); j++)
        {
            int id = res[j].fi.se;
            if (f[j])
            {
                ans[id] = 1;
            }
            else
            {
                ans[id] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        std::cout << ans[i];
    }

    return 0;
}