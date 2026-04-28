#include <bits/stdc++.h>
#define task "comnet"
#define ll long long
#define pb push_back
#define ii std::pair<int, int>
#define fi first
#define se second

const int maxn = 3e5 + 7;

bool vis[maxn];
int n, m, base;
ii g[maxn];
std::vector<int> adj[maxn];

bool bfs(int u)
{
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 1; i <= n; i++)
        adj[i].clear();

    for (int i = 1; i <= u; i++)
        adj[g[i].fi].pb(g[i].se);
    std::queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == n)
            return true;

        for (auto e : adj[v])
        {
            if (!vis[e])
            {
                vis[e] = true;
                q.push(e);
            }
        }
    }

    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen(task ".inp", "r", stdin);
    std::freopen(task ".out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> g[i].fi >> g[i].se;
    }
    int l = 0, r = m, res = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (bfs(mid))
            res = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    std::cout << res;
    return 0;
}
