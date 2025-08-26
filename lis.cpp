#include <bits/stdc++.h>
#define task "lis"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 5e5 + 7;
const int maxw = 507;
const int inf = 1e9;

int n, w;
int a[maxn], d[maxw][maxw], dp[maxn], f[maxn], ans;

void sub1()
{
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            d[i][j] = inf;

    d[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        d[i][0] = 0;

        for (int j = 1; j <= i; j++)
        {
            d[i][j] = inf;
            for (int k = 0; k < i; k++)
                if (a[k] < a[i])
                    d[i][j] = std::min(d[i][j], d[k][j - 1] + a[i]);
        }
    }

    ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][j] <= w)
                ans = std::max(ans, j);
}

int bs(int l, int r, int x)
{
    int res;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (a[f[m]] < x)
        {
            l = m + 1;
            res = m;
        }
        else
        {
            r = m - 1;
        }
    }
    return f[res];
}

void sub2()
{
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    dp[1] = f[1] = 1;
    ans = 1;
    for (int i = 2; i <= n; i++)
    {
        int tmp = bs(1, dp[ans], a[i]);
        dp[i] = dp[tmp] + 1;
        f[dp[i]] = i;
        if (dp[i] > dp[ans])
            ans = i;
    }

    ans = dp[ans];
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen(task ".inp", "r", stdin);
    std::freopen(task ".out", "w", stdout);

    std::cin >> n >> w;

    if (n <= 500)
        sub2();
    else
        sub2();

    std::cout << ans;

    return 0;
}
