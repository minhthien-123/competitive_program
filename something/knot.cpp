#include <bits/stdc++.h>
#define task "knot"
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

    int q;
    std::cin >> q;
    while (q--)
    {
        int n, k;
        std::cin >> n >> k;
        int d = 0, ans = 1;
        while (d < k)
        {
            if (ans % n != 0)
            {
                d++;
            }

            if (d == k)
            {
                std::cout << ans << "\n";
            }

            ans++;
        }
    }

    return 0;
}
