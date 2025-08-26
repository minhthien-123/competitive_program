#include <bits/stdc++.h>
#define task "tom"
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

int n, q;
std::vector<int> adj[maxn + 7];
int up[maxn + 7][20], h[maxn + 7];

int down1[maxn + 7], down2[maxn + 7], downj[maxn + 7];
int uplen[maxn + 7];

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (up[u][0] == v)
        {
            continue;
        }

        h[v] = h[u] + 1;
        up[v][0] = u;

        for (int j = 1; j <= 19; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        dfs(v);
    }
}

void dfs_down(int u, int p)
{
    down1[u] = down2[u] = downj[u] = 0;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs_down(v, u);
        int d = down1[v] + 1;
        if (d > down1[u])
        {
            down2[u] = down1[u];
            down1[u] = d;
            downj[u] = v;
        }
        else if (d > down2[u])
        {
            down2[u] = d;
        }
    }
}

void dfs_up(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        uplen[v] = uplen[u] + 1;
        if (downj[u] == v)
        {
            uplen[v] = std::max(uplen[v], down2[u] + 1);
        }
        else
        {
            uplen[v] = std::max(uplen[v], down1[u] + 1);
        }
        dfs_up(v, u);
    }
}

int lca(int u, int v)
{
    if (!u || !v)
    {
        return u + v;
    }

    if (h[u] != h[v])
    {
        if (h[u] < h[v])
        {
            std::swap(u, v);
        }

        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; j++)
        {
            if (k >> j & 1)
            {
                u = up[u][j];
            }
        }
    }

    if (u == v)
    {
        return u;
    }

    for (int j = 19; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int ascend(int u, int d)
{
    for (int j = 0; d > 0 && j <= 19; j++)
    {
        if (d & 1)
        {
            u = up[u][j];
            if (u == 0)
            {
                return 0;
            }
        }
        d >>= 1;
    }
    return u;
}

int answer_query(int t, int j)
{
    if (t == j)
    {
        return 0;
    }
    int p = lca(t, j);
    int dist = h[t] + h[j] - 2 * h[p];
    int distt = dist >> 1;
    int distj = (dist - 1) >> 1;
    if (h[t] > h[j])
    {
        int A = ascend(t, distt);
        return distt + uplen[A];
    }
    else
    {
        int B = ascend(j, distj);
        return distt + down1[B] + 1;
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

    std::cin >> n >> q;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);
    dfs_down(1, 0);
    dfs_up(1, 0);

    while (q--)
    {
        int t, j;
        std::cin >> t >> j;
        std::cout << answer_query(t, j) << '\n';
    }

    return 0;
}
