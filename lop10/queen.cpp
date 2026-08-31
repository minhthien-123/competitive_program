#include <bits/stdc++.h>
#define task "queen"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3 + 7;

int a[maxn][maxn];
int m, n;
int row_sum[maxn], col_sum[maxn], d_sum1[maxn], d_sum2[maxn];

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
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
            row_sum[i] += a[i][j];
            col_sum[j] += a[i][j];
            d_sum1[i - j + n - 1] += a[i][j];
            d_sum2[i + j] += a[i][j];
        }
    }

    int ans = LLONG_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp = row_sum[i] + col_sum[j] + d_sum1[i - j + n - 1] + d_sum2[i + j] - a[i][j];
            std::cout << tmp << "\n";
            ans = std::max(tmp, ans);
        }
    }

    std::cout << ans;

    return 0;
}
