#include <bits/stdc++.h>
#define task ""
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int a[maxn], d[maxn];
std::vector<int> adj[maxn];
int q[maxn][3];
int n, m, k, query;

void bfs(int s, int r, int c)
{
    std::queue<int> q;
    q.push(s);
    if (a[s] == 0)
    {
        a[s] = c;
    }
    d[s] = r;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (d[u] > 0)
        {
            for (auto v : adj[u])
            {
                if (a[v] == 0)
                {
                    q.push(v);
                    d[v] = d[u] - 1;
                    a[v] = c;
                }
                else
                {
                    if (d[u] - 1 > d[v])
                    {
                        q.push(v);
                        d[v] = d[u] - 1;
                    }
                }
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
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    std::cin >> query;
    for (int i = 1; i <= query; i++)
    {
        std::cin >> q[i][1] >> q[i][2] >> q[i][3];
    }

    for (int i = query; i >= 1; i--)
    {
        bfs(q[i][1], q[i][2], q[i][3]);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << "\n";
    }

    return 0;
}
