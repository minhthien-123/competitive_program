#include <bits/stdc++.h>
#define task "power"
#define int unsigned long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;

int x, y, m;

int power(int x, int y, int m)
{
    if (y == 0)
    {
        return 1;
    }
    int tmp = power(x, y / 2, m);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % m;
    }
    return (tmp * tmp) % m * x % m;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    while (std::cin >> x >> y >> m)
    {
        std::cout << power(x, y, m) << "\n";
    }

    return 0;
}
