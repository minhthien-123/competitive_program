#include <bits/stdc++.h>
#define task "area"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k;
int f[maxn + 7][maxn + 7], g[maxn + 7][maxn + 7];

int power(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    int tmp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}

struct area
{
    int x1, y1, x2, y2;
} a[maxn + 7];

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

    std::cin >> n >> k;
    int maxX = 0, maxY = 0;
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, y1, x2, y2};
        maxX = std::max(maxX, x2);
        maxY = std::max(maxY, y2);
        f[x1][y1]++;
        f[x2 + 1][y1]--;
        f[x1][y2 + 1]--;
        f[x2 + 1][y2 + 1]++;
    }

    for (int i = 0; i <= maxX + 1; i++)
    {
        for (int j = 0; j <= maxY + 1; j++)
        {
            if (i > 0)
            {
                f[i][j] += f[i - 1][j];
            }
            if (j > 0)
            {
                f[i][j] += f[i][j - 1];
            }
            if (i > 0 && j > 0)
            {
                f[i][j] -= f[i - 1][j - 1];
            }
            g[i][j] = f[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= maxX; i++)
    {
        for (int j = 1; j <= maxY; j++)
        {
            if (g[i][j] > 0)
            {
                int v = (i * j) % mod;
                ans = (ans + power(v, k)) % mod;
            }
        }
    }

    std::cout << ans;
    return 0;
}