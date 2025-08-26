#include <bits/stdc++.h>
#define task "aggr"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int n, c;
int a[maxn + 7];

bool check(int d)
{
    int cnt = 1, tmp = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - tmp >= d)
        {
            cnt++;
            tmp = a[i];
        }
    }
    return cnt >= c;
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

    std::cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);

    int l = 0, r = a[n] - a[1], ans = 0;

    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    std::cout << ans;

    return 0;
}
