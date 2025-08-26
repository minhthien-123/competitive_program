#include <bits/stdc++.h>
#define task "liq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7];
int dp[maxn + 7];
int f[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        dp[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                f[i] = j;
            }
        }
    }

    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > dp[res])
        {
            res = i;
        }
    }

    std::vector<int> v;

    while (res)
    {
        v.pb(res);
        res = f[res];
    }
    reverse(v.begin(), v.end());

    std::cout << v.size() << "\n";
    for (int i : v)
    {
        std::cout << i << " ";
    }

    return 0;
}
