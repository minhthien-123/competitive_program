#include <bits/stdc++.h>
#define task "andmax"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 64;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
int dp[maxn + 7][10];

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

    for (int i = 0; i <= maxn; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < maxn; i++)
    {
        int bit = (n >> i) & 1;
        for (int j = 0; j <= 4; j++)
        {
            if (dp[i][j] == -1)
                continue;

            for (int x = 0; x <= 1; x++)
                for (int y = 0; y <= 1; y++)
                    for (int z = 0; z <= 1; z++)
                    {
                        int s = x + y + z + j;
                        if ((s & 1) == bit)
                        {
                            int nbit = s >> 1;
                            if (nbit <= 4)
                            {
                                int tmp = 0;
                                if ((x & y & z) == 1)
                                {
                                    tmp = (1LL << i);
                                }

                                dp[i + 1][nbit] = std::max(dp[i + 1][nbit], dp[i][j] + tmp);
                            }
                        }
                    }
        }
    }

    std::cout << dp[maxn][0];
    return 0;
}
