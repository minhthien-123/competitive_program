#include <bits/stdc++.h>
#define task "lis"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7];
int dp[maxn + 7], f[maxn + 7], ans;

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
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = std::lower_bound(f + 1, f + ans + 1, a[i]) - f;
        if (dp[i] > ans)
        {
            ans++;
        }
        f[dp[i]] = a[i];
    }

    std::cout << ans << "\n";
    int tmp = inf;
    std::vector<int> v;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i] == ans && a[i] < tmp)
        {
            ans--;
            v.pb(i);
            tmp = a[i];
        }
    }

    std::reverse(v.begin(), v.end());
    for (int i : v)
    {
        std::cout << i << " ";
    }

    return 0;
}
