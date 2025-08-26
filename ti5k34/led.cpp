#include <bits/stdc++.h>
#define task "led"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n, m;
int a[maxn + 7];
int d[maxn + 7];

bool check(int k)
{
    for (int i = 1; i <= n; i++)
    {
        d[a[i]] = 0;
    }

    int cnt = 0, ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (d[a[i]] == 0)
        {
            ans++;
            cnt++;
        }
        d[a[i]]++;
    }

    for (int i = k + 1; i <= n; i++)
    {
        if (d[a[i]] == 0)
        {
            cnt++;
        }
        d[a[i]]++;
        d[a[i - k]]--;
        if (d[a[i - k]] == 0)
        {
            cnt--;
        }
        ans = std::max(ans, cnt);
    }
    return ans == m;
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

    std::cin >> n  >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    int l = 1, r = n, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
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
