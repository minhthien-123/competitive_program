#include <bits/stdc++.h>
#define task "bonus2"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf = 1e18;

int k, n, ans;
int a[maxn + 7][maxn + 7], pre[maxn + 7][maxn + 7];

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
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }

    ans = -inf;
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= n; j++)
        {
            int s = pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k];
            ans = std::max(ans, s);
        }
    }

    std::cout << ans;

    return 0;
}
