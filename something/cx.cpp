#include <bits/stdc++.h>
#define task "cx"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int q;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> q;
    while (q--)
    {
        int a, b, c, n;
        std::cin >> a >> b >> c >> n;
        int S = a + b + c;
        if ((S + n) % 3 != 0)
        {
            std::cout << "NO\n";
            continue;
        }

        int T = (S + n) / 3;
        if (T >= std::max({a, b, c}))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
