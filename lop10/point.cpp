#include <bits/stdc++.h>
#define task "point"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;

int x, y;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> x >> y;

    if (x > 0)
    {
        if (y > 0)
        {
            std::cout << "I";
        }
        else
        {
            std::cout << "IV";
        }
    }
    else if (x < 0)
    {
        if (y > 0)
        {
            std::cout << "II";
        }
        else
        {
            std::cout << "III";
        }
    }

    return 0;
}
