#include <bits/stdc++.h>
#define task "cano"
#define int long long
#define ld long double
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n, m, k;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> m >> k;
    std::cout << 2 * n * k / m - k;

    return 0;
}
