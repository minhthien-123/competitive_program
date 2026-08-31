#include <bits/stdc++.h>
#define task "socola"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n, k;
int a[maxn + 7];

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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    int l = 1, r = 1e18, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i] / mid;
        }
        if (sum >= k)
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
