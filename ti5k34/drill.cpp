#include <bits/stdc++.h>
#define task "drill"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;

int n, k;
int a[maxn], f[maxn];

void sub1()
{
    int res = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                if ((i - j) % 2 == 0)
                {
                    sum += abs(a[j] - a[i]);
                }
                else
                {
                    sum += abs(a[j] - a[i] + k);
                }
            }
        }
        res = std::min(res, sum);
    }

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                if ((i - j) % 2 == 0)
                {
                    sum += abs(a[j] - a[i]);
                }
                else
                {
                    sum += abs(a[j] - a[i] - k);
                }
            }
        }
        res = std::min(res, sum);
    }

    std::cout << res;
}

void sub2()
{
    std::vector<int> res;
    int tmp1, tmp2, s1, s2;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            res.pb(a[i]);
        }
        else
        {
            res.pb(a[i] - k);
        }
    }

    std::sort(res.begin(), res.end());
    tmp1 = res[res.size() / 2];
    tmp2 = tmp1 + k;

    s1 = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            s1 += abs(a[i] - tmp1);
        }
        else
        {
            s1 += abs(a[i] - tmp2);
        }
    }

    res.clear();

    for (int i = 1; i <= n; i++)
    {
        if (i % 2!= 0)
        {
            res.pb(a[i]);
        }
        else
        {
            res.pb(a[i] - k);
        }
    }
    std::sort(res.begin(), res.end());
    tmp1 = res[res.size() / 2];
    tmp2 = tmp1 + k;
    s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            s2 += abs(a[i] - tmp2);
        }
        else
        {
            s2 += abs(a[i] - tmp1);
        }
    }

    std::cout << std::min(s1, s2);
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
        std::cin >> a[i];
    }

    sub2();

    return 0;
}
