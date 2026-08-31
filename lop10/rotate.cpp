#include <bits/stdc++.h>
#define task "rotate"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int a, b, c, d, res;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> a >> b >> c >> d;

    int res = std::max({a / c - b / d, c / d - a / b, d / b - c / a, b / a - d / c});

    if (res == (a / c - b / d))
    {
        std::cout << 0;
    }
    else if (res == (c / d - a / b))
    {
        std::cout << 1;
    }
    else if (res == (d / b - c / a))
    {
        std::cout << 2;
    }
    else if (res == (b / a - d / c))
    {
        std::cout << 3;
    }

    return 0;
}
