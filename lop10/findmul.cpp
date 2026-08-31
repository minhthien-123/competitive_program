#include <bits/stdc++.h>
#define task "findmul"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n, a, b, c;

int lcm(int a, int b)
{
    return (a * b) / std::__gcd(a, b);
}

int count(int a, int b, int c, int x)
{
    return x / a + x / b + x / c - x / lcm(a, b) - x / lcm(b, c) - x / lcm(c, a) + x / (lcm(a, lcm(b, c)));
}

bool check(int x)
{
    int cnt = count(a, b, c, x) - count(lcm(a, b), lcm(b, c), lcm(c, a), x);

    //std::cout << x << " " << cnt << "\n";

    return cnt >= n;
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

    std::cin >> a >> b >> c >> n;

    int l = 0, r = 1e15;
    int ans = 0;

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

    //std::cout << count(32) << "\n";

    // 20 / 4 + 20 / 6 + 20 / 9 - 20 / 12 - 20 / 18 - 20 / 36 + 20 / 36
    //

    std::cout << ans;

    return 0;
}
