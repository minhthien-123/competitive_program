#include <bits/stdc++.h>
#define task "subsetsum"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n, m, s = 0;
int a[maxn + 7];
bool dp[maxn + 7];
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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        s += a[i];
    }

    if (s < m)
    {
        std::cout << "NO";
        return 0;
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i]; j--)
        {
            if (dp[j - a[i]] && !dp[j])
            {
                dp[j] = 1;
                f[j] = i;
            }
        }
    }

    if (!dp[m])
    {
        std::cout << "NO";
        return 0;
    }

    std::cout << "YES\n";
    std::vector<int> ans;
    while (m)
    {
        ans.pb(f[m]);
        m -= a[f[m]];
    }
    std::reverse(ans.begin(), ans.end());
    for (int x : ans)
    {
        std::cout << x << " ";
    }

    return 0;
}
