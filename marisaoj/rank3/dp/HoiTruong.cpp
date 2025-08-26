#include <bits/stdc++.h>
#define task "HoiTruong"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int n;
ii a[maxn + 7];
std::vector<int> adj[maxn + 7];
int dp[maxn + 7];

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
        std::cin >> a[i].fi >> a[i].se;
        adj[a[i].se].pb(a[i].fi);
    }

    dp[0] = 0;
    for (int i = 1; i <= maxn; i++)
    {
        dp[i] = dp[i - 1];
        for (int j : adj[i])
        {
            dp[i] = std::max(dp[i], dp[j - 1] + i - j + 1);
        }
        //std::cout << dp[i] << "\n";
    }

    std::cout << dp[maxn];

    return 0;
}
