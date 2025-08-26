#include <bits/stdc++.h>
#define task "ants"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, k;
int x[maxn], a[maxn];

bool check(int m)
{
    int cnt = 0, tmp = 0;

    for (int i = 1; i <= n; i++)
    {
        if (tmp < a[i])
        {
            cnt++;
            int md = m;
            int j = i;
            tmp = 0;

            while (j <= n && x[j] - x[i] <= md)
            {
                tmp += a[i];
                if (tmp > a[j])
                {
                    break;
                }
                j++;
            }

            i = j - 1;
            if (cnt > k) return false;
        }
    }

    return cnt <= k;
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

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);
    std::sort(x + 1, x + n + 1);

    int l = 0, r = 1e18, ans = -1;

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

    return 0;
}
