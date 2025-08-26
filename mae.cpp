#include <bits/stdc++.h>
#define task "mae"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        int a[n];
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }

        std::map<int, int> mp;
        for (auto i : a)
        {
            mp[i]++;
        }

        int ans = 0;
        for (auto i : mp)
        {
            ans = std::max(ans, i.se);
        }

        std::cout << n - ans << "\n";
    }

    return 0;
}
