#include <bits/stdc++.h>
#define task "tps"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 2e3;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, k;
int a[maxn + 7], b[maxn + 7];

bool check(int mid)
{
    for (int i = 1; i <= n; i++)
    {
        int d = 0;
        int cur = i;
        while (cur < i + n && d <= k)
        {
            d++;
            int lim = b[cur] + 2 * mid;
            int l = cur, r = i + n;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (b[mid] > lim)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            cur = l;
        }
        if (cur >= i + n && d <= k)
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

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> k;

    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i];
        b[i + n] = a[i] + 1000000;
    }

    int l = 1, r = 500000, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
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
