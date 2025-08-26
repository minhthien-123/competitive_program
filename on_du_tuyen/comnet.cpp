#include <bits/stdc++.h>
#define task "comnet"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, m, base;
bool vis[maxn + 7];
ii g[maxn + 7];
std::vector<int> adj[maxn + 7];

bool bfs(int u)
{
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }

    for (int i = 1; i <= u; i++)
    {
        adj[g[i].fi].pb(g[i].se);
    }

    std::queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == n)
        {
            return 1;
        }

        for (auto e : adj[v])
        {
            if (!vis[e])
            {
                vis[e] = 1;
                q.push(e);
            }
        }
    }

    return 0;
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

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> g[i].fi >> g[i].se;
    }
    int l = 1, r = m, res = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (bfs(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    std::cout << res;

    return 0;
}
