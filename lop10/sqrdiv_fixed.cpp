#include <bits/stdc++.h>
#define task "sqrdiv"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int t;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> t;
    while (t--)
    {
        int a, b;
        std::cin >> a >> b;
        int ans = 0;
        for (int i = 1; i * i <= b; i++)
        {
            ans += b / (i * i) - (a - 1) / (i * i);
        }
        std::cout << ans << "\n";
    }

    return 0;
}
