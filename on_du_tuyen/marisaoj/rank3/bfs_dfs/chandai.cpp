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

int n, m, k;
std::vector<int> adj[maxn + 7];
int f[maxn + 7][15];

void bfs(int s)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            f[i][j] = -1;
        }
    }

    std::queue<ii> q;
    q.push({s, 0});
    f[s][0] = 0;

    while (!q.empty())
    {
        ii tmp = q.front();
        q.pop();

        int u = tmp.fi;
        int r = tmp.se;
        int du = f[u][r];

        for (int v : adj[u])
        {
            int r2 = (r + 1) % k;
            if (f[v][r2] < 0)
            {
                f[v][r2] = du + 1;
                q.push({v, r2});
            }
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs(1);

    std::cout << (f[n][0] >= 0 ? f[n][0] / k : -1) << "\n";

    return 0;
}
