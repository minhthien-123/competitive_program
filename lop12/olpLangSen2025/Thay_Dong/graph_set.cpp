#include <bits/stdc++.h>
#define task "graph_set"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, m;
int d[maxn + 7][10], g[10], trace[maxn + 7][10];
int par[maxn + 7], sz[maxn + 7];
std::vector<int> adj[maxn + 7];
bool flag;

int acs(int v)
{
    if (v == par[v])
    {
        return v;
    }
    int p = acs(par[v]);
    par[v] = p;
    return p;
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

void bfs(int u, int p)
{
    for (int j = 1; j <= n; j++)
    {
        d[p][j] = -1;
    }

    std::queue<int> q;
    q.push(u);
    d[p][u] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (d[p][v] == -1) 
            {
                d[p][v] = d[p][u] + 1;
                trace[p][v] = u;
                q.push(v);
            }
        }
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
    for (int v = 0; v <= n; v++)
    {
        par[v] = v;
        sz[v] = 1;
    }

    for (int i = 0, x; i < 3; i++)
    {
        std::cin >> x;
        int tmp = 0;
        for (int j = 1, u; j <= x; j++)
        {
            std::cin >> u;
            if (tmp != 0)
            {
                join(u, tmp);
            }
            g[i] = acs(u);
            tmp = u;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u = acs(u);
        v = acs(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 0; i < 3; i++)
    {
        bfs(g[i], i);
    }

    int tmp = inf, pos = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = acs(i);
        bool check = 0;
        for (int j = 0; j < 3; j++)
        {
            if (u == g[j])
            {
                check = 1;
            }
        }

        if (check)
        {
            continue;
        }

        int res = -2;
        for (int j = 0; j < 3; j++)
        {
            res += d[j][u];
        }

        if (tmp > res)
        {
            tmp = res;
            pos = i;
        }
    }

    std::vector<int> v;
    for (int i = 0; i < 3; i++)
    {
        int u = pos;
        while (u)
        {
            if (u != g[0] && u != g[1] && u != g[2])
            {
                v.pb(u);
            }
            u = trace[i][u];
        }
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::cout << v.size() << "\n";
    for (int i : v)
    {
        std::cout << i << " ";
    }

    return 0;
}
