#include <bits/stdc++.h>
#define task "tbforest"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e5 + 7;
const int mod = 1e9 + 7;

int n, ans = 0;
int a[maxn], dp[maxn];
std::map<int, int> mp;

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

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + i - mp[a[i]];

        ans += dp[i];
        ans %= mod;

        mp[a[i]] = i;
    }

    std::cout << ans;

    return 0;
}
