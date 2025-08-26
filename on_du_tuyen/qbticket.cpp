#include <bits/stdc++.h>
#define task "qbticket"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, s, f;
int a[maxn + 7], dp[maxn + 7];
int l[3], c[3];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    for (int i = 1; i <= 3; i++)
    {
        std::cin >> l[i];
    }
    for (int i = 1; i <= 3; i++)
    {
        std::cin >> c[i];
    }

    std::cin >> n >> s >> f;
    a[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = s + 1; i <= f; i++)
    {
        dp[i] = inf;
        for (int j = i - 1; j >= s; j--)
        {
            int tmp = a[i] - a[j], res;
            if (tmp > l[3])
            {
                break;
            }
            if (tmp > l[2])
            {
                res = c[3];
            }
            else if (tmp > l[1])
            {
                res = c[2];
            }
            else
            {
                res = c[1];
            }
            dp[i] = std::min(dp[i], dp[j] + res);
        }
    }

    std::cout << dp[f] << "\n";

    return 0;
}
