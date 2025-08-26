#include <bits/stdc++.h>
#define task "lucky"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;

int rev(int x)
{
    int res = 0;
    while (x > 0)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int w, maxx, maxy;
int f[maxn + 7];
std::map<ii, std::vector<int>> mpx, mpy;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> maxx >> maxy >> w;

    for (int i = 1; i <= maxn; ++i)
    {
        f[i] = rev(i);
    }

    for (int x = 1; x <= maxx; x++)
    {
        int y = f[x];
        int gcd = std::__gcd(x, y);
        ii tmp = {x / gcd, y / gcd};
        mpx[tmp].pb(x);
    }

    for (int y = 1; y <= maxy; y++)
    {
        int x = f[y];
        int gcd = std::__gcd(x, y);
        ii tmp = {x / gcd, y / gcd};
        mpy[tmp].pb(y);
    }

    int ans = inf;
    int ansx = -1, ansy = -1;

    for (int x = 1; x <= maxx; x++)
    {
        std::vector<std::pair<int, std::vector<int>>> v;
        for (auto &i : mpx)
        {
            int cnt = std::upper_bound(i.se.begin(), i.se.end(), x) - i.se.begin();
            if (cnt != 0 && mpy.find(i.fi) != mpy.end())
            {
                v.pb({cnt, mpy[i.fi]});
            }
        }

        if (v.empty())
        {
            continue;
        }

        int l = 1, r = maxy, y = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (auto &i : v)
            {
                cnt += (std::upper_bound(i.se.begin(), i.se.end(), mid) - i.se.begin()) * i.fi;
                if (cnt >= w)
                {
                    break;
                }
            }

            if (cnt >= w)
            {
                y = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (y != -1 && x * y < ans)
        {
            ans = x * y;
            ansx = x;
            ansy = y;
        }
    }

    if (ans == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << ansx << " " << ansy;
    }

    return 0;
}