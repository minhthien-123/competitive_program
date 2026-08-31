#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 3e6 + 7;
int n, dmax = 0, vmax = 0;
int a[maxn], d[maxn];
int tt = 1e6 + 7;

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        d[a[i] + tt]++;
        if (d[a[i] + tt] > dmax)
        {
            dmax = d[a[i] + tt];
            vmax = a[i];
        }
        if (d[a[i] + tt] == dmax)
        {
            vmax = std::min(vmax, a[i]);
        }
    }

    //std::cout << vmax << " " << dmax << "\n";

    for (int i = 1; i <= n; i++)
    {
        if (a[i] != vmax)
        {
            std::cout << a[i] << " ";
        }
    }

    for (int i = 1; i <= dmax; i++)
    {
        std::cout << vmax << " ";
    }

    return 0;
}
