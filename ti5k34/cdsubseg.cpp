#include <bits/stdc++.h>
#define task "cdsubseg"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;

int n;

bool check(int a[], int n, int k)
{
    for (int i = 1; i <= n - k + 1; i++)
    {
        int tmp = a[i];
        for (int j = i + 1; j <= i + k; j++)
        {
            tmp = std::__gcd(tmp, a[i]);
            if (tmp == 1)
            {
                break;
            }
        }

        if (tmp > 1)
        {
            return true;
        }
    }

    return false;
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

    int t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;

        int a[n + 7];

        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }

        int l = 1, r = n, ans = 0;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(a, n, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        std::cout << ans << "\n";
    }


    return 0;
}
