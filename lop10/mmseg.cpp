#include <bits/stdc++.h>
#define task "mmseg"
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
int a[maxn + 7];

void sub1(int n)
{
    int mn = inf, mx = -inf, ans = inf;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        mn = std::min(mn, a[i]);
        mx = std::max(mx, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (std::min(a[i], a[j]) == mn && std::max(a[i], a[j]) == mx)
            {
                ans = std::min(ans, j - i + 1);
            }
        }
    }

    std::cout << ans << "\n";
}

void sub2(int n)
{

    int mn = inf, mx = -inf, posmin1 = 0, posmax1 = 0, ans = inf, posmin2 = 0, posmax2 = 0;

    for (int i = 1, x; i <= n; ++i)
    {
        std::cin >> a[i];
        mn = std::min(mn, a[i]);
        mx = std::max(mx, a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == mn)
        {
            if (posmin1 == 0)
            {
                posmin1 = i;
            }
            else
            {
                posmin2 = i;
            }
        }
        if (a[i] == mx)
        {
            if (posmax1 == 0)
            {
                posmax1 = i;
            }
            else
            {
                posmax2 = i;
            }
        }

        if (posmin1 != 0 && posmax1 != 0)
        {
            ans = std::min(ans, abs(posmax1 - posmin1));
            if (posmin2 != 0)
            {
                ans = std::min(ans, abs(posmin2 - posmax1));
                if (posmax2 != 0)
                {
                    ans = std::min({ans, abs(posmax2 - posmin1), abs(posmax2 - posmin2)});
                }
            }
            if (posmax2 != 0)
            {
                ans = std::min({ans, abs(posmax2 - posmin1)});
                if (posmin2 != 0)
                {
                    ans = std::min({ans, abs(posmax2 - posmin2), abs(posmin2 - posmax1)});
                }
            }
        }
    }

    std::cout << ans + 1 << "\n";
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
        int n;
        std::cin >> n;
        if (n <= 100)
        {
            sub1(n);
        }
        else
        {
            sub2(n);
        }
    }

    return 0;
}
