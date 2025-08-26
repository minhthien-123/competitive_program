#include <bits/stdc++.h>
#define task "onecyc"
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

int n, m;
std::vector<ii> adj[maxn + 7];
ii a[maxn + 7];
int low[maxn + 7], num[maxn + 7], timer;
bool joint[maxn + 7];
int comp[maxn + 7], cnt, csz[maxn + 7];
int par[maxn + 7], sz[maxn + 7];
std::vector<ii> edges;
int cntedge[maxn + 7], cntnode[maxn + 7];

void tarjan(int u, int p)
{
    low[u] = num[u] = ++timer;
    for (auto e : adj[u])
    {
        int v = e.fi;
        int id = e.se;
        if (id == p)
            continue;
        if (!num[v])
        {
            tarjan(v, id);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > num[u])
            {
                joint[id] = true;
            }
        }
        else
        {
            low[u] = std::min(low[u], num[v]);
        }
    }
}

void dfs(int u, int p)
{
    comp[u] = p;
    csz[p]++;
    for (auto e : adj[u])
    {
        int v = e.fi;
        int id = e.se;
        if (comp[v] == 0 && !joint[id])
        {
            dfs(v, p);
        }
    }
}

void init(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int acs(int v)
{
    return par[v] == v ? v : par[v] = acs(par[v]);
}

void join(int a, int b)
{
    a = acs(a);
    b = acs(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            std::swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
    }
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
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i].fi >> a[i].se;
        adj[a[i].fi].pb({a[i].se, i});
        adj[a[i].se].pb({a[i].fi, i});
    }

    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            tarjan(i, 0);
        }
    }

    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!comp[i])
        {
            ++cnt;
            dfs(i, cnt);
        }
    }

    for (int i = 1; i <= cnt; i++)
    {
        init(i);
    }

    for (int i = 1; i <= m; i++)
    {
        if (joint[i])
        {
            int u = comp[a[i].fi];
            int v = comp[a[i].se];
            edges.pb({u, v});
            join(u, v);
        }
    }

    for (int i = 1; i <= cnt; i++)
    {
        cntnode[acs(i)]++;
    }
    for (auto e : edges)
    {
        cntedge[acs(e.fi)]++;
    }

    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (acs(i) == i)
        {
            int k = cntnode[i];
            int m = cntedge[i];
            ans += k * (k - 1) / 2 - m;
        }
    }

    std::cout << ans;
    return 0;
}
