#include <bits/stdc++.h>
#define task "median"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, k;
int a[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    int med = (n - 1) / 2;

    int l = a[med], r = a[med] + k;

    while (l < r)
    {
        int mid = (l + r + 1) / 2;

        int cnt = 0;
        for (int i = med; i < n; i++)
        {
            if (a[i] < mid)
            {
                cnt += mid - a[i];
            }
        }

        if (cnt <= k)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    std::cout << l;

    return 0;
}
