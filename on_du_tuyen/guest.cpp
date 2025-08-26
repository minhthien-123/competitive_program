#include <bits/stdc++.h>
#define task "guest"
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
int a[maxn + 7];
int par[maxn + 7];
int dp[maxn + 7][2];
std::vector<int> adj[maxn + 7];
std::vector<int> ans;
int cnt, sum;
std::vector<int> v;

void dfs(int u)
{
    dp[u][1] = a[u];
    dp[u][0] = 0;

    for (int v : adj[u])
    {
        dfs(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += std::max(dp[v][1], dp[v][0]);
    }
}

void trace(int u, bool flag)
{
    if (!flag && dp[u][1] > dp[u][0])
    {
        ans.pb(u);
        for (int v : adj[u])
        {
            trace(v, 1);
        }
    }
    else
    {
        for (int v : adj[u])
        {
            trace(v, 0);
        }
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
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x >> a[i];
        if (x != 0)
        {
            adj[x].pb(i);
        }
        else
        {
            v.pb(i);
        }
    }

    int s = 0;
    for (int i : v)
    {
        dfs(i);
        s += std::max(dp[i][0], dp[i][1]);
    }

    for (int i : v)
    {
        trace(i, 0);
    }

    std::cout << ans.size() << " " << s << "\n";

    for (int i : ans)
    {
        std::cout << i << "\n";
    }

    return 0;
}
