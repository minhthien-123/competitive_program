#include <bits/stdc++.h>
#define task "bonus"
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

int n, k;
int a[maxn + 7][maxn + 7], f[maxn + 7][maxn + 7];
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

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= n; j++)
        {
            ans = std::max(ans, f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k]);
        }
    }

    std::cout << ans;

    return 0;
}
