#include <bits/stdc++.h>
#define task "reimu"
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

int n, q;
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

    std::cin >> n >> q;

    int mn = n + 1, mx = 0;

    while (q--)
    {
        int i, j;
        std::cin >> i >> j;
        mn = std::min({mn, i, j});
        mx = std::max({mx, i, j});
        std::cout << (mn - 1) * (n - mx) << "\n";
    }

    return 0;
}
