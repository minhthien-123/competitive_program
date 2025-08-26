#include <bits/stdc++.h>
#define task "cau1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e12;
const int inf  = 1e18;

int m, n;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n;
    if (n % m != 0)
    {
        std::cout << -1;
        return 0;
    }

    int x = n / m;
    int ans = inf;
    for (int i = 1; i * i <= x; i++)
    {
        int j = x / i;
        if (std::__gcd(i, j) == 1)
        {
            //std::cout << i << " " << j << " " << (i + j) * m << "\n";
            ans = std::min(ans, (i + j) * m);
        }
    }

    std::cout << ans;

    return 0;
}
