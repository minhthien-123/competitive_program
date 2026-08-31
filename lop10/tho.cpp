#include <bits/stdc++.h>
#define task "divseg"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int t;

bool check(int l, int r, int k)
{
    return (l % k == 0 || (l / k) != (r / k));
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

    std::cin >> t;
    while (t--)
    {
        int l, r, d;
        std::cin >> l >> r >> d;

        int k = 0, tmp = 1;
        while (tmp * d <= r)
        {
            tmp *= d;
            k++;
        }

        //std::cout << tmp << " " << k << "\n";

        while (!check(l, r, tmp))
        {
            tmp /= d;
            k--;
        }

        if (k == 0)
        {
            std::cout << "-1\n";
        }
        else
        {
            int res = l / tmp + (l % tmp != 0);
            std::cout << k << " " << res * tmp << "\n";
        }

    }

    return 0;
}