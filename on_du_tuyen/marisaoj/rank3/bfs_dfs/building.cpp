#include <bits/stdc++.h>
#define task "building"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;

int n, m;
int a[maxn][maxn];
bool vis[maxn][maxn] = {false};

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int mx = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] >= mx)
            {
                mx = a[i][j];
                vis[i][j] = true;
            }
        }

        mx = 0;
        for (int j = n; j >= 1; j--)
        {
            if (a[i][j] >= mx)
            {
                mx = a[i][j];
                vis[i][j] = true;
            }
        }
    }

    for (int j = 1; j <= n; j++)
    {
        int mx = 0;
        for (int i = 1; i <= m; i++)
        {
            if (a[i][j] >= mx)
            {
                mx = a[i][j];
                vis[i][j] = true;
            }
        }

        mx = 0;
        for (int i = m; i >= 1; i--)
        {
            if (a[i][j] >= mx)
            {
                mx = a[i][j];
                vis[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //std::cout << vis[i][j] << " ";
            if (!vis[i][j])
            {
                cnt++;
            }
        }
        //std::cout << "\n";
    }

    std::cout << cnt;

    return 0;
}
