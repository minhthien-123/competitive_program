#include <bits/stdc++.h>
#define task "cut"
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
int low[maxn + 7], num[maxn + 7], timer;
int d[maxn + 7], par[maxn + 7], joint[maxn + 7];
std::map<ii, int> edge_count;
std::vector<ii> res;

void dfs(int u, int p)
{
    int child = 0;
    num[u] = low[u] = ++timer;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }

        if (!num[v])
        {
            dfs(v, u);
            low[u] = std::min(low[u], low[v]);

            if (low[v] == num[v])
            {
                ii e = {std::min(u, v), std::max(u, v)};
                if (edge_count[e] == 1)
                {
                    res.pb(e);
                }
            }

            child++;
            if (u == p)
            {
                if (child > 1)
                {
                    joint[u] = true;
                }
            }
            else if (low[v] >= num[u])
            {
                joint[u] = true;
            }
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
        int u, v;
        std::cin >> u >> v;
        ii key = {std::min(u, v), std::max(u, v)};
        edge_count[key]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            dfs(u, u);
        }
    }

    std::vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (joint[i])
        {
            ans.pb(i);
        }
    }

    std::cout << res.size() << " " << ans.size() << "\n";
    for (auto i : res)
    {
        std::cout << i.fi << ' ' << i.se << "\n";
    }
    for (int i : ans)
    {
        std::cout << i << "\n";
    }

    return 0;
}
