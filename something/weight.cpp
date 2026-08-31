#include <bits/stdc++.h>
#define task "weight"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

long long n, i, ans[1000005], a[1000005];
stack<long long> st;

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
    for (i = 1; i <= n; i++) std::cin >> a[i];

    for (i = 1; i <= n; i++){

    }

    for (i = 1; i <= n; i++) std::cout << ans[i] << " ";

    return 0;
}
