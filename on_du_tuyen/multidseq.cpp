#include <bits/stdc++.h>
#define task "multidseq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n, k;
int dp[maxn + 7], f[maxn + 7];

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
        dp[i] = 1;
    }

    for (int p = 2; p <= k; p++)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int tmp = dp[i];
            if (!tmp)
            {
                continue;
            }
            for (int j = i; j <= n; j += i)
            {
                f[j] += tmp;
                f[j] %= mod;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i] = f[i];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[i];
        ans %= mod;
    }

    std::cout << ans;

    return 0;
}
