#include <bits/stdc++.h>
#define task "awards"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7], pre[maxn + 7], dp[maxn + 7], s[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >>n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        dp[i] = 1;
        s[i] = pre[n] - pre[i - 1];

        for (int j = i; j <= n; j++)
        {
            int tmp = pre[j] - pre[i - 1];

            if (tmp >= s[j + 1])
            {
                if (dp[j + 1] + 1 > dp[i])
                {
                    dp[i] = dp[j + 1] + 1;
                    s[i] = tmp;
                }
                else if (dp[j + 1] + 1 == dp[i] && tmp < s[i])
                {
                    s[i] = tmp;
                }
            }
        }
    }


    std::cout << dp[1];

    return 0;
}

// 5
// 6 2 8 3 4
