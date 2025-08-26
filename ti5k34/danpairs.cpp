#include <bits/stdc++.h>
#define task "dans"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, m, k;
int a[maxn], b[maxn];

bool check(int x)
{
    int i = 1, j = 1, cnt = 0;

    while (i <= m && j <= n)
    {
        if (abs(a[i] - b[j]) <= x)
        {
            cnt++;
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return cnt >= k;
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

    std::cin >> m >> n >> k;


    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }

    std::sort(a + 1, a + m + 1);
    std::sort(b + 1, b + n + 1);

    int l = 0, r = std::max(abs(a[m] - b[1]), abs(a[1] - b[n])), ans = r;

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
