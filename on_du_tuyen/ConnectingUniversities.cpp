#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, k;
int a[maxn + 7], s[maxn + 7];
std::vector<int> adj[maxn + 7];
int ans = 0;

void dfs(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs(v, u);
        s[u] += s[v];
        ans += std::min(s[v], 2 * k - s[v]);
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

    std::cin >> n >> k;
    for (int i = 1; i <= 2 * k; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= 2 * k; i++)
    {
        s[a[i]] = 1;
    }

    dfs(1, -1);

    std::cout << ans;

    return 0;
}
