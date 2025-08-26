#include <bits/stdc++.h>
#define task "critical"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 50000;
int num[maxn + 7], low[maxn + 7], timer;
int n, m;
bool flag[maxn + 7];
int sz[maxn + 7];
int comp_sz[maxn + 7];
std::vector<int> adj[maxn + 7];
int res[maxn + 7];

void dfs(int u, std::vector<int> &vec)
{
    comp_sz[u] = -1;
    vec.pb(u);
    for (int v : adj[u])
    {
        if (comp_sz[v] == 0)
        {
            dfs(v, vec);
        }
    }
}

void tarjan(int u, int p)
{
    num[u] = low[u] = ++timer;
    sz[u] = 1;
    int children = 0;
    std::vector<int> comps;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (num[v])
        {
            low[u] = std::min(low[u], num[v]);
        }
        else
        {
            children++;
            tarjan(v, u);
            sz[u] += sz[v];
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= num[u])
            {
                flag[u] = true;
                comps.pb(sz[v]);
            }
        }
    }

    if (u == p && children < 2)
    {
        flag[u] = false;
    }

    if (flag[u])
    {
        int s = 0;
        for (int v : comps)
        {
            s += v;
        }
        s = comp_sz[u] - 1 - s;
        if (s > 0)
        {
            comps.pb(s);
        }
        s = 0;
        for (int v : comps)
        {
            res[u] += v * s;
            s += v;
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int u = 1; u <= n; u++)
    {
        if (comp_sz[u] == 0)
        {
            std::vector<int> vec;
            dfs(u, vec);
            int tmp = vec.size();
            for (int x : vec)
            {
                comp_sz[x] = tmp;
            }
        }
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            tarjan(u, u);
        }
    }

    long double s = 0;
    for (int u = 1; u <= n; u++)
    {
        s += res[u];
    }
    long double ans = s / n;
    std::cout << std::fixed << std::setprecision(2) << ans;

    return 0;
}
