#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n, m, k;
std::vector<int> adj[maxn];
int a[maxn], d1[maxn], d2[maxn];
bool vis1[maxn + 7], vis2[maxn + 7];

void bfs1(int s)
{
    std::queue<int> q;
    q.push(s);
    vis1[s] = true;
    d1[s] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!vis1[v])
            {
                q.push(v);
                vis1[v] = true;
                d1[v] = d1[u] + 1;
            }
        }
    }
}

void bfs2(int s)
{
    std::queue<int> q;
    q.push(s);
    d2[s] = 0;
    vis2[s] = true;

    while (q.size())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!vis2[v])
            {
                q.push(v);
                vis2[v] = true;
                d2[v] = d2[u] + 1;
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

    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        std::cin >> a[i];
    }

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs1(1);
    bfs2(n);

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (d2[a[i]] <= d1[n])
        {
            ans++;
        }
    }

    std::cout << ans;

    return 0;
}
