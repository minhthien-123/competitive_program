#include <bits/stdc++.h>
#define task "tank"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int n, m;
int a[maxn], f[maxn];

bool check(int k)
{
    for (int i = k; i <= n; i++)
    {
        if ((f[i] - f[i - k]) < m)
        {
            return false;
        }
    }

    return true;
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

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    // for (int i = 1; i <= n; i++)
    // {

    // }

    int l = 1, r = n, ans = -1;

    while (l <= r)
    {
        int mid = l + r >> 1;

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
