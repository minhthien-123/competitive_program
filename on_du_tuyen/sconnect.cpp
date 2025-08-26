#include <bits/stdc++.h>
#define task "sconnect"
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
int num[maxn + 7], low[maxn + 7], timer;
bool vis[maxn + 7];
std::stack<int> path;

void dfs(int u)
{
    low[u] = num[u] = ++timer;
    path.push(u);
    vis[u] = true;

    for (int v : adj[u])
    {
        if (!num[v])
        {
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = std::min(low[u], num[v]);
        }
    }

    if (low[u] == num[u])
    {
        int v;
        do
        {
            v = path.top();
            path.pop();
            vis[v] = false;
            std::cout << v << " ";
        } while (v != u);
        std::cout << "\n";
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
    }

    for (int u = 1; u <= n; u++)
    {
        if (!num[u])
        {
            dfs(u);
        }
    }

    return 0;
}
