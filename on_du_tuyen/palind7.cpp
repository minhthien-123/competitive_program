#include <bits/stdc++.h>
#define task "palind7"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

std::string a;
bool dp[maxn + 7][maxn + 7];
int par[maxn + 7], f[maxn + 7];

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

    std::cin >> a;
    int n = a.size();
    a = " " + a;

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = true;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (a[i] == a[j])
            {
                if (len == 2)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
    }

    for (int i = 1; i <= n + 1; i++)
    {
        f[i] = inf;
    }
    f[n + 1] = 0;

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            if (dp[i][j] && f[j + 1] + 1 < f[i])
            {
                f[i] = f[j + 1] + 1;
                par[i] = j + 1;
            }
        }
    }

    std::cout << f[1] << "\n";
    int tmp = 1;
    while (tmp <= n)
    {
        std::cout << a.substr(tmp, par[tmp] - tmp) << "\n";
        tmp = par[tmp];
    }

    return 0;
}
