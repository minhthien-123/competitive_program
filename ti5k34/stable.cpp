#include <bits/stdc++.h>
#define task "stable"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n;
ii a[maxn + 7];

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi;
        a[i].se = i;
    }

    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i].se << " ";
    }

    return 0;
}
