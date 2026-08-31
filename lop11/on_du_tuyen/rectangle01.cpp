#include <bits/stdc++.h>
#define task "main"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;

int m, n;
int a[maxn + 7][maxn + 7], f[maxn + 7], l[maxn + 7], r[maxn + 7];
int ans = -inf;

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

    f[0] = -1, f[n + 1] = -1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[j] = a[i][j] * (f[j] + 1);
        }

        /*for (int j = 1; j <= n; j++)
        {
            std::cout << f[j] << " ";
        }
        std::cout << "\n";*/

        for (int j = 1; j <= n; j++)
        {
            l[j] = j;
            while (f[l[j] - 1] >= f[j])
            {
                l[j] = l[l[j] - 1];
            }
        }
        for (int j = n; j >= 1; j--)
        {
            r[j] = j;
            while (f[r[j] + 1] >= f[j])
            {
                r[j] = r[r[j] + 1];
            }
        }
        for (int j = 1; j <= n; j++)
        {
            ans = std::max(ans, (r[j] - l[j] + 1) * f[j]);
        }
    }

    std::cout << ans;

    return 0;
}
