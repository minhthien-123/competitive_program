#include <bits/stdc++.h>
#define task "chip"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;

int n, m;

char a[maxn][maxn];
ii par[maxn][maxn];
int sz[maxn][maxn];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sz[i][j] = 1;
        }
    }
}

ii find(ii u)
{
    if (u == par[u.fi][u.se])
    {
        return u;
    }
    return par[u.fi][u.se] = find(par[u.fi][u.se]);
}

void merge(ii u, ii v)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return;
    }
    if (sz[u.fi][u.se] < sz[v.fi][v.se])
    {
        std::swap(u, v);
    }
    par[v.fi][v.se] = u;
    sz[u.fi][u.se] += sz[v.fi][v.se];
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] == 'L')
            {
                if (j - 1 >= 1)
                    par[i][j] = {i, j - 1};
                else
                    par[i][j] = {i, j};
            }
            else if (a[i][j] == 'R')
            {
                if (j + 1 <= m)
                    par[i][j] = {i, j + 1};
                else
                    par[i][j] = {i, j};
            }
            else if (a[i][j] == 'U')
            {
                if (i - 1 >= 1)
                    par[i][j] = {i - 1, j};
                else
                    par[i][j] = {i, j};
            }
            else if (a[i][j] == 'D')
            {
                if (i + 1 <= n)
                    par[i][j] = {i + 1, j};
                else
                    par[i][j] = {i, j};
            }
            else
            {
                par[i][j] = {i, j};
            }
        }
    }

    init();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != '.')
            {
                merge(par[i][j], {i, j});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ii root = find({i, j});
            ans = std::max(ans, sz[root.fi][root.se]);
        }
    }

    std::cout << ans;

    return 0;
}