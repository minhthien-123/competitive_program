#include <bits/stdc++.h>
#define task "main"
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
std::vector<ii> adj[maxn + 7];
int d[maxn + 7], par[maxn + 7];
std::map<ii, int> mp;
bool vis[maxn + 7];
std::vector<int> res = {1};

void bfs(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }

    std::queue<int> q;
    d[s] = 0;
    q.push(s);

    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto tmp : adj[u])
        {
            int v = tmp.fi;
            if (d[v] == inf)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
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

    std::cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        mp[{u, v}] = w;
        mp[{v, u}] = w;
    }

    bfs(n);
    if (d[1] == inf)
    {
        std::cout << -1;
        return 0;
    }

    vis[1] = true;

    while (d[res[0]] > 0)
    {
        int mn = inf;
        for (int u : res)
        {
            for (auto tmp : adj[u])
            {
                int v = tmp.fi;
                int w = tmp.se;
                if (d[v] == d[u] - 1)
                {
                    mn = std::min(mn, w);
                }
            }
        }

        std::vector<int> cur;
        for (int u : res)
        {
            for (auto tmp : adj[u])
            {
                int v = tmp.fi;
                int w = tmp.se;
                if (!vis[v] && d[v] == d[u] - 1 && w == mn)
                {
                    vis[v] = true;
                    par[v] = u;
                    cur.pb(v);
                }
            }
        }
        res = cur;
    }

    std::vector<int> path;
    for (int v = n; v != 0; v = par[v])
    {
        path.pb(v);
    }
    std::reverse(path.begin(), path.end());
    std::cout << path.size() - 1 << "\n";
    for (int i = 1; i < path.size(); i++)
    {
        std::cout << mp[{path[i - 1], path[i]}] << ' ';
    }

    return 0;
}
