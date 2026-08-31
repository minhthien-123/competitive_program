#include <bits/stdc++.h>
#define task "tlastant"
#define int unsigned long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n, m;

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
    int res = 1;
    while (res < n * m - m + 1)
    {
        res = (int)(m / (m - 1) * res);
    }

    std::cout << n * m + 1 - res;
    return 0;
}
