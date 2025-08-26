#include <bits/stdc++.h>
#define task "mxs"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
int a[maxn + 7], prf[maxn + 7], f[maxn + 7];
int n, d = 0, s = 0;

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
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        s += a[i];
        if (a[i] > 0)
        {
            d++;
        }
    }

    if (d == n)
    {
        std::cout << s;
    }
    else if (n == 2)
    {
        std::cout << a[1] + a[2];
    }
    else
    {
        s = 0;
        for (int i = 1; i <= n; ++i)
        {
            s = std::max(s + a[i], a[i]);
            prf[i] = std::max(prf[i - 1], s);
        }

        s = 0;
        for (int i = n; i >= 1; --i)
        {
            s = std::max(s + a[i], a[i]);
            f[i] = std::max(f[i + 1], s);
        }

        // for (int i = 1; i <= n; ++i)
        // {
        //     std::cout << prf[i] << " ";
        // }
        // std::cout << "\n";
        // for (int i = 1; i <= n; ++i)
        // {
        //     std::cout << f[i] << " ";
        // }
        // std::cout << "\n";

        int ans = LLONG_MIN;
        for (int i = 1; i < n; ++i)
        {
            ans = std::max(ans, f[i + 1] + prf[i]);
        }
        std::cout << ans;
    }

    return 0;
}
