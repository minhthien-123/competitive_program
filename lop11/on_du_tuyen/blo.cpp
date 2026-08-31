#include <bits/stdc++.h>
#define task "blo"
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
std::vector<int> adj[maxn + 7];
int deg[maxn + 7], s[maxn + 7], cl[maxn + 7], cur[maxn + 7], f[maxn + 7];
int low[maxn + 7], num[maxn + 7], d[maxn + 7], timer;

void dfs(int u)
{
    int tmp = 0;
    s[++tmp] = u;
    cl[u] = 1;
    f[u] = 0;
    d[u] = 1;
    num[u] = low[u] = ++timer;

    while (tmp)
    {
        int u = s[tmp];
        if (cur[u] < deg[u])
        {
            int v = adj[u][cur[u]++];
            if (v != f[u])
            {
                if (!cl[v])
                {
                    s[++tmp] = v;
                    cl[v] = 1;
                    f[v] = u;
                    d[v] = 1;
                    num[v] = low[v] = ++timer;
                }
                else
                {
                    low[u] = std::min(low[u], num[v]);
                }
            }
        }
        else
        {
            int w = f[u];
            if (w)
            {
                low[w] = std::min(low[w], low[u]);
                d[w] += d[u];
            }
            --tmp;
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
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    for (int u = 1; u <= n; u++)
    {
        if (!cl[u])
        {
            dfs(u);
        }
    }

    for (int u = 1; u <= n; u++)
    {
        int ans = 2 * (n - 1);
        if (!f[u])
        {
            for (int v : adj[u])
            {
                if (f[v] == u)
                {
                    ans += d[v] * (n - d[v] - 1);
                }
            }
        }
        else
        {
            int sum = 0;
            for (int v : adj[u])
            {
                if (f[v] == u && low[v] >= num[u])
                {
                    sum += d[v];
                    ans += d[v] * (n - d[v] - 1);
                }
            }

            ans += sum * (n - sum - 1);
        }
        std::cout << ans << "\n";
    }


    return 0;
}
