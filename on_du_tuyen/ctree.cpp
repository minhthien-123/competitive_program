#include <bits/stdc++.h>
#define task "ctree"
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

int n;
std::vector<int> adj[maxn + 7];
bool vis[maxn + 7];
int par[maxn + 7];
int mx, id;

void dfs(int u, int d)
{
    vis[u] = true;
    if (d > mx)
    {
        mx = d;
        id = u;
    }

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            par[v] = u;
            dfs(v, d + 1);
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

    std::cin >> n;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    mx = -1;
    memset(vis, false, sizeof vis);
    dfs(1, 0);
    int s = id;

    mx = -1;
    memset(vis, false, sizeof vis);
    memset(par, -1, sizeof par);
    dfs(s, 0);
    int t = id;

    std::vector<int> path;
    while (t != -1)
    {
        path.pb(t);
        t = par[t];
    }

    std::reverse(path.begin(), path.end());

    if (path.size() % 2 == 0)
    {
        std::cout << 2 << "\n";
        int a = path[path.size() / 2 - 1];
        int b = path[path.size() / 2];
        std::cout << std::min(a, b) << " " << std::max(a, b);
    }
    else
    {
        std::cout << 1 << "\n";
        std::cout << path[path.size() / 2];
    }

    return 0;
}
