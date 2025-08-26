#include <bits/stdc++.h>
#define task "equa"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxs = 180;
const int maxx = 20;
const int inf  = 1e18;

int a, b, c, d, mod;
std::string n;
int m[maxs + 7];
int dp[maxx + 7], f[maxx + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> a >> b >> c >> d >> n >> mod;

    for (int x = 0; x <= 9; x++)
    {
        for (int y = 0; y <= 9; y++)
        {
            for (int z = 0; z <= 9; z++)
            {
                for (int t = 0; t <= 9; t++)
                {
                    m[a * x + b * y + c * z + d * t] ++;
                }
            }
        }
    }

    std::reverse(n.begin(), n.end());

    dp[0] = 1;
    for (auto i : n)
    {
        int tmp = i - '0';
        std::fill(f, f + maxx, 0);

        for (int j = 0; j <= maxx; j++)
        {
            if (dp[j] == 0)
            {
                continue;
            }

            int cur = (tmp - j + 10) % 10;

            for (int k = cur; k <= maxs; k += 10)
            {
                int t = (j + k) / 10;
                if (t >= 20)
                {
                    continue;
                }

                f[t] = (f[t] + dp[j] * m[k]) % mod;
            }
        }

        std::copy(f, f + maxx, dp);
    }

    std::cout << dp[0] % mod;

    return 0;
}
