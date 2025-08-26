#include <bits/stdc++.h>
#define task "fibocnt"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int l, r;
std::vector<int> fibo;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    fibo.pb(0); fibo.pb(1);
    for (int i = 2; i <= 100; i++)
    {
        fibo.pb(fibo[i - 1] + fibo[i - 2]);
    }

    std::cin >> l >> r;
    int ans = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (fibo[i] >= l && fibo[i] <= r) ans++;
    }
    std::cout << ans;

    return 0;
}
