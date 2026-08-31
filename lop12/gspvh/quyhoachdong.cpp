#include <bits/stdc++.h>
#define task "quyhoachdong"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int a, b, c, m;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    while (std::cin >> a >> b >> c >> m)
    {
        int d = a + b + c;
        if (a >= 1 && b >= 1 && c >= 1 && m >= 3 && m <= d)
        {
            std::cout << "No\n";
        }
        else
        {
            std::cout << "Yes\n";
        }
    }

    return 0;
}
