#include <bits/stdc++.h>
#define task "frog"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n, k;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    int res = n;
    while (k >= 0)
    {
        if (k % n == 0)
        {
            std::cout << res;
            return 0;
        }

        res = n;
        n = k % n;
        k = k % res + res;
        res = n;
    }

    return 0;
}
