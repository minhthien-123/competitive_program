#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
std::vector<int> adj[maxn + 7];
int sz[maxn + 7], dp[maxn + 7], ans[maxn + 7];

void dfs1(int u, int p)
{
    sz[u] = 1;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v];
    }
}

void dfs2(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        ans[v] = ans[u] - sz[v] + n - sz[v];
        dfs2(v, u);
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs1(1, -1);
    ans[1] = dp[1];
    dfs2(1, -1);

    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << " ";
    }

    return 0;
}
