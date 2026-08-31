#include <bits/stdc++.h>
#define task "bai1"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

long double calc(int x)
{
    return 2 - 1 / x;
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

    int n;
    std::cin >> n;

    if (n % 2 == 0)
    {
        return calc(n) - calc(n / 2 - 1);
    }

    return 0;
}
