#include <bits/stdc++.h>
#define task "kd"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int da, d0, dd;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        if (x < 0)
        {
            da++;
        }
        else if (x == 0)
        {
            d0++;
        }
        else
        {
            dd++;
        }
    }

    std::cout << da * dd + d0 * (n - d0);

    return 0;
}
