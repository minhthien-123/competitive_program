#include <bits/stdc++.h>
#define task "marbles"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 500;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int add(int a, int b)
{
    return (a + b) % mod;
}
int sub(int a, int b)
{
    return (a - b + mod) % mod;
}

int n, m, k;
int dp0[2][maxn + 7][maxn + 7], dp1[2][maxn + 7][maxn + 7];
int pre0[maxn + 7], pre1[maxn + 7];

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

    std::cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        dp0[1][0][i] = 1;
    }

    for (int p = 2; p <= n; p++)
    {
        int cur = p % 2, pre = 1 - cur;

        for (int i = 0; i <= k; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp0[cur][i][j] = dp1[cur][i][j] = 0;
            }
        }

        for (int i = 0; i <= k; i++)
        {
            pre0[0] = pre1[0] = 0;
            for (int j = 1; j <= m; j++)
            {
                pre0[j] = add(pre0[j - 1], dp0[pre][i][j]);
                pre1[j] = add(pre1[j - 1], dp1[pre][i][j]);
            }
            int d0 = pre0[m], d1 = pre1[m];

            for (int j = 1; j <= m; j++)
            {
                int l0 = pre0[j - 1];
                int g0 = sub(d0, l0);
                int l1 = pre1[j - 1];
                int gt1 = sub(d1, pre1[j]);

                dp0[cur][i][j] = add(dp0[cur][i][j], g0);
                dp1[cur][i][j] = add(dp1[cur][i][j], l0);
                dp1[cur][i][j] = add(dp1[cur][i][j], l1);
                if (i + 1 <= k)
                {
                    dp0[cur][i + 1][j] = add(dp0[cur][i + 1][j], gt1);
                }
            }
        }
    }

    int ans = 0, last = n % 2;
    for (int i = 1; i <= m; i++)
    {
        ans = add(ans, dp0[last][k][i]);
        ans = add(ans, dp1[last][k][i]);
    }

    std::cout << ans << "\n";
    return 0;
}
