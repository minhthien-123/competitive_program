#include <bits/stdc++.h>
#define task "frpr"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int m, n, x, y;

bool check(int k)
{
    int cnt1 = k / x;
    int cnt2 = k / y;
    int cnt = k / (x * y);

    int d1 = k - cnt1;
    int d2 = k - cnt2;
    int d = k - (cnt1 + cnt2 - cnt);

    return d1 >= m && d2 >= n && d >= m + n;

    if (d1 >= m)
    {
        if (d2 >= n)
        {
            return true;
        }
        else
        {
            d2 += d;
            return d2 >= n;
        }
    }
    else
    {
        if (d2 >= n)
        {
            d1 += d;
            return d1 >= m;
        }
        else
        {
            d1 += m - d;
            d -= (m - d);
            d2 += d;

            return d2 >= n;
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> m >> n >> x >> y;

    int l = 1, r = 1e18;
    int ans = LLONG_MAX;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        //std::cout << l << " " << r << " " << mid << "\n";

        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    std::cout << ans;

    return 0;
}
