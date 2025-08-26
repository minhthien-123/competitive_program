#include <bits/stdc++.h>
#define task "bishop"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int m, n;
int a[maxn + 7][maxn + 7];
int d1[maxn * maxn + 7], d2[maxn * maxn + 7];

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

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int id1 = i - j + n;
            int id2 = i + j;
            d1[id1] += a[i][j];
            d2[id2] += a[i][j];
        }
    }

    int ans = -inf;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int id1 = i - j + n;
            int id2 = i + j;
            int w   = d1[id1] + d2[id2] - a[i][j];
            ans = std::max(ans, w);
        }
    }

    std::cout << ans;

    return 0;
}