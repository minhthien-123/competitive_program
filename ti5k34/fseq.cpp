#include <bits/stdc++.h>
#define task "fseq"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n;
ii ans = {LLONG_MIN, LLONG_MIN};
int a[maxn + 7];
int f[maxn + 7], pre[maxn + 7];

void sub1()
{
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            res = std::max(res, (pre[j] - pre[i - 1]) / (j - i + 1));
        }
    }
    std::cout << res << "\n";
    return;
}

void sub2()
{
    std::cout << *std::max_element(a + 1, a + n + 1) << "\n";
    return;
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
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        f[a[i]]++;
        if (f[a[i]] == ans.fi)
        {
            ans.se = std::min(ans.se, a[i]);
        }
        if (f[a[i]] > ans.fi)
        {
            ans.fi = f[a[i]];
            ans.se = a[i];
        }
    }

    // sub1();
    // sub2();

    if (n <= 1000)
    {
        sub1();
    }
    else
    {
        sub2();
    }

    std::cout << ans.se;

    return 0;
}
