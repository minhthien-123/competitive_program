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
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int dp[maxn + 7][2], x[maxn + 7];
std::vector<int> adj[maxn + 7];
bool vis[maxn + 7];

void dfs(int u)
{
    vis[u] = true;
    dp[u][0] = 1 - x[u];
    dp[u][1] = x[u];
    for (int v : adj[u])
    {
        if (vis[v])
        {
            continue;
        }
        dfs(v);
        int d0, d1;
        d0 = dp[u][0];
        d1 = dp[u][1];

        dp[u][0] = d0 * dp[v][1];
        dp[u][0] %= mod;
        dp[u][1] = d1 * dp[v][1];
        dp[u][1] %= mod;

        dp[u][0] += d0 * dp[v][0];
        dp[u][0] %= mod;
        dp[u][1] += d1 * dp[v][0] + d0 * dp[v][1];
        dp[u][1] %= mod;
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
    for (int i = 0; i < n - 1; i++)
    {
        int v;
        std::cin >> v;
        adj[i + 1].pb(v);
        adj[v].pb(i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
    }

    dfs(0);

    std::cout << dp[0][1];

    return 0;
}
