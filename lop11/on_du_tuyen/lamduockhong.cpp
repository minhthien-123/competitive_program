#include <bits/stdc++.h>
#define task "lamduockhong"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 21;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int a[maxn + 7][maxn + 7], dp[1 << maxn];

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

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
        }
    }

    dp[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int sum = 0;
        int i = __builtin_popcount(mask) - 1;
        for (int j = 0; j < n; j++)
        {
            if ((mask & (1 << j)) && (a[i][j]))
            {
                sum = (sum + dp[mask ^ (1 << j)]) % mod;
            }
        }
        dp[mask] = sum;
    }

    std::cout << dp[(1 << n) - 1];

    return 0;
}
