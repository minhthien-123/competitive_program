#include <bits/stdc++.h>
#define task "bluehouse"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e4;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
std::vector<ii> adj[maxn + 7];
std::vector<int> g[maxn + 7];
int low[maxn + 7], num[maxn + 7], timer;
int par[maxn + 7], sz[maxn + 7];
int U[maxn + 7], V[maxn + 7];
bool flag[maxn + 7];

void make_set(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    return (v == par[v]) ? v : par[v] = find_set(par[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            std::swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

void tarjan(int u, int p)
{
    low[u] = num[u] = ++timer;
    for (auto &tmp : adj[u])
    {
        int v = tmp.fi;
        int id = tmp.se;
        if (id == p)
            continue;
        if (!num[v])
        {
            tarjan(v, id);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > num[u])
                flag[id] = true;
        }
        else
        {
            low[u] = std::min(low[u], num[v]);
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
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        num[i] = low[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> U[i] >> V[i];
        adj[U[i]].pb({V[i], i});
        adj[V[i]].pb({U[i], i});
        flag[i] = false;
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
            tarjan(u, -1);
    }

    for (int u = 1; u <= n; u++)
        make_set(u);
    for (int i = 1; i <= m; i++)
    {
        if (!flag[i])
            union_sets(U[i], V[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (flag[i])
        {
            int u = find_set(U[i]);
            int v = find_set(V[i]);
            g[u].pb(v);
            g[v].pb(u);
        }
    }

    std::vector<int> vec;
    for (int i = 1; i <= n; i++)
    {
        if (find_set(i) == i && g[i].size() == 1)
        {
            vec.pb(i);
        }
    }

    int cnt = vec.size();
    std::cout << (cnt + 1) / 2 << "\n";

    int res = cnt / 2;
    for (int i = 0; i < res; i++)
    {
        std::cout << vec[i] << " " << vec[i + res] << "\n";
    }
    if (cnt % 2 == 1)
    {
        std::cout << vec[cnt - 1] << " " << vec[0] << "\n";
    }

    return 0;
}