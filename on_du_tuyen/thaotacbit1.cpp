#include <bits/stdc++.h>
#define task "marisa"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 35;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n;
int a[maxn + 7];

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
    while (n--)
    {
        int x, y;
        std::cin >> x >> y;
        if (x == 1)
        {
            a[y] = 1;
        }
        else if (x == 2)
        {
            std::cout <<
        }
    }

    return 0;
}
