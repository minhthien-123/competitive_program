#include <bits/stdc++.h>
#define task "bai2"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert
#define ld long double

ld r, x, y;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> r >> x >> y;
    ld z = std::sqrt(x * x + y * y);
    std::cout << (r < z);

    return 0;
}
