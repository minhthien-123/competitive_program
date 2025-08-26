#include <bits/stdc++.h>
#define task "crarr"
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

std::vector<int> adj[maxn + 7];
bool vis[maxn + 7];
int d[maxn + 7];
int k, n;
int ans = 0;

void dfs(int u)
{
    vis[u] = 1;
    d[u] = 1;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
            d[u] += d[v];
        }
    }

    if (d[u] >= k)
    {
        d[u] = 0;
        ans++;
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

    std::cin >> k >> n;

    for (int i = 1; i < n; i++)
    {
        int x;
        std::cin >> x;
        adj[x].pb(i + 1);
    }

    std::memset(vis, 0, sizeof vis);
    std::memset(d, -1, sizeof d);

    dfs(1);

    std::cout << ans;

    return 0;
}
