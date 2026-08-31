#include <bits/stdc++.h>
#define task "ants"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int x, k, n, ans = LLONG_MIN;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    // std::freopen(task".inp", "r", stdin);
    // std::freopen(task".out", "w", stdout);

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x;

        if (x > 0)
            ans = std::max(ans, k - x);
        else
            ans = std::max(ans, -x);
    }

    std::cout << ans;

    return 0;
}
