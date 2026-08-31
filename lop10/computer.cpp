#include <bits/stdc++.h>
#define task "computer"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int a1, a2, a3, b1, b2, b3;
signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    std::cout << std::min(a1 + a3, b1) + std::min(a2 + a3, b2) + std::min(a1 + a2 + a3, b3);

    return 0;
}
