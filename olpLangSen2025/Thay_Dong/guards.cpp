#include <bits/stdc++.h>
#define task "guards"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 500;

int m, n;
int d1 = 0, d2 = 0;
int a[maxn + 7][maxn + 7], h[maxn + 7][maxn + 7], v[maxn + 7][maxn + 7];
std::vector<int> adj[maxn * maxn + 7];
int f[maxn * maxn + 7];

bool dfs(int u, std::vector<int> &used)
{
    for (int v : adj[u])
    {
        if (used[v])
        {
            continue;
        }
        used[v] = 1;
        if (f[v] == 0 || dfs(f[v], used))
        {
            f[v] = u;
            return true;
        }
    }

    return false;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> m >> n;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 2)
            {
                continue;
            }
            if (j == 1 || a[i][j - 1] == 2)
            {
                d1++;
            }
            h[i][j] = d1;
        }
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if (a[i][j] == 2)
            {
                continue;
            }
            if (i == 1 || a[i - 1][j] == 2)
            {
                d2++;
            }
            v[i][j] = d2;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                if (h[i][j] > 0 && v[i][j] > 0)
                {
                    //std::cout << h[i][j] << " " << v[i][j] << "\n";
                    adj[h[i][j]].pb(v[i][j]);
                }
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << h[i][j] << " ";
        }
        std::cout << "\n";
    }

    cnt = 0;
    for (int i = 1; i <= d1; i++)
    {
        std::vector<int> used(d2 + 1, 0);
        if (dfs(i, used))
        {
            cnt++;
        }
    }

    std::cout << cnt << "\n";
    return 0;
}