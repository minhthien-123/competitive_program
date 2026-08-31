#include <bits/stdc++.h>
#define task "fishpool"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e5 + 7;
int t;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen(task".inp", "r", stdin);
    std::freopen(task".out", "w", stdout);

    std::cin >> t;
    while (t--)
    {
        int n, k, m;
        std::cin >> n >> k >> m;

        std::vector<int> a;
        a.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int w;
            std::cin >> w;
            if (w <= m)
            {
                a.pb(w);
            }
        }

        std::sort(a.begin(), a.end());
        a.pb(m);

        int ans = 0;
        int i = 0;
        n++;

        while (k < m && i < n - 1)
        {
            while (i < n - 1 && k >= a[i + 1])
            {
                i++;
            }

            if (k >= a[i])
            {
                int tmp = a[i + 1] - k;
                int cnt = tmp / a[i];
                if (cnt > 0)
                {
                    k += cnt * a[i];
                    ans += cnt;
                }
                if (k < a[i + 1])
                {
                    k += a[i];
                    ans++;
                }
            }

            i++;
        }

        if (k < m)
            std::cout << "-1\n";
        else
            std::cout << ans << "\n";
    }

    return 0;
}