#include <bits/stdc++.h>
#define task "numorder"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n, m, k;

bool check(int x)
{
    int cnt = 0;
    for (int i = 1; i <= std::min(m, n) && i * i <= x; i++)
    {
        int j = (int)sqrt(x - i * i);
        cnt += j;
    }
    return cnt >= k;
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

    std::cin >> n >> m >> k;

    int l = 1, r = 1e18, ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;

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