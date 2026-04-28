#include <bits/stdc++.h>
#define task "matmul"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 107;

int m, n, p;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n >> p;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            std::cin >> b[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
