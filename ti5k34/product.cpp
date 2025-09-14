#include <bits/stdc++.h>
#define task "dt205"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n;
ii a[maxn], b[maxn];
int f[maxn];

bool check(int x)
{
    for (int i = 1; i < n; i++)
    {
        int l = i + 1, r = n, pos = n + 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[i].fi * a[mid].fi >= x)
            {
                pos = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (pos <= n && a[i].se * f[pos] >= x)
        {
            return true;
        }
    }
    return false;
}

bool check1(int x)
{
    int i = 1;
    while (i <= n)
    {
        int j = i + 1;
        while (a[i].fi * a[j].fi < x && j <= n)
        {
            j++;
        }

        if (a[i].se * f[j] >= x)
        {
            return true;
        }

        i++;

        /*while (i < j)
        {
            if (h[i].se * tmp >= x)
        {
            return true;
        }

        i++;
        }*/
    }

    return false;
}

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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].fi;
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].se;
    }

    std::sort(a + 1, a + n + 1);

    f[n] = a[n].se;
    for (int i = n - 1; i >= 1; i--)
    {
        f[i] = std::max(f[i + 1], a[i].se);
    }

    // std::cout << check(9);

    int l = 1, r = 1e18, ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    std::cout << ans;

    return 0;
}
