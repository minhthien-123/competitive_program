#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6;
const int inf  = 1e18;

int n, k, q;
int a[maxn + 7];
int ans[maxn + 7];

void sub1()
{
    if (q == 1)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int t = i; t <= j; t++)
                {
                    if (a[j] - a[t - 1] <= k && a[t] - a[t - 1] <= k)
                    {
                        std::cout << i << " " << j << " " << t << "\n";
                        ans[i] = std::max(ans[i], j - i + 1);
                    }
                }
            }
        }
    }
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

    std::cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }

    sub1();
    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << ' ';
    }
    std::cout << "\n";

    return 0;
}
