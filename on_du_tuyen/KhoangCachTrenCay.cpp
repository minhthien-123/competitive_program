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
std::vector<int> adj[maxn + 7];
int down[maxn + 7], up[maxn + 7];
int best1[maxn + 7], best2[maxn + 7], best[maxn + 7];

void dfs1(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }

        dfs1(v, u);

        int val = down[v] + 1;
        if (val > down[u])
        {
            down[u] = val;
        }
        if (val > best1[u])
        {
            best2[u] = best1[u];
            best1[u] = val;
            best[u] = v;
        }
        else if (val > best2[u])
        {
            best2[u] = val;
        }
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
        int val;
        if (best[u] == v)
        {
            val = best2[u];
        }
        else
        {
            val = best1[u];
        }
        up[v] = std::max(up[u] + 1, val + 1);
        dfs2(v, u);
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

    memset(best, -1, sizeof best);

    dfs1(1, -1);
    dfs2(1, -1);

    for (int i = 1; i <= n; i++)
    {
        std::cout << std::max(down[i], up[i]) << " ";
    }

    return 0;
}
