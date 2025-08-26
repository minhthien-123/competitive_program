#include <bits/stdc++.h>
#define task "us"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

int t;

ii solve(int x)
{
    int cnt = 0, sum = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (i * i == x)
            {
                cnt++;
                sum += i;
            }
            else
            {
                cnt += 2;
                sum += i + x / i;
            }
        }
    }

    return {cnt, sum};
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".ans", "w", stdout);
    }

    std::cin >> t;
    while (t--)
    {
        int a, b;
        std::cin >> a >> b;
        int cnt = 0, sum = 0;
        for (int i = a; i <= b; i++)
        {
            ii tmp = solve(i);
            cnt += tmp.fi;
            sum += tmp.se;
        }

        std::cout << cnt << " " << sum << "\n";
    }

    return 0;
}
