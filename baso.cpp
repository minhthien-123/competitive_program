#include <bits/stdc++.h>
#define task "baso"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n;

int sub1()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (i * j * k <= n)
                {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int sub2()
{
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        for (int j = i + 1; j * j * i <= n; j++)
        {
            int k = n / i / j - j;
            if (k > 0)
            {
                ans += 6 * k;
            }
        }
    }

    for (int i = 1; i * i <= n; i++)
    {
        int k = n / i / i;
        if (k >= i)
        {
            k--;
        }
        ans += k * 3;
    }

    for (int i = 1; i * i * i <= n; i++)
    {
        ans ++;
    }

    return ans;
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

    if (n <= 100)
    {
        std::cout << sub1();
    }
    else
    {
        std::cout << sub2();
    }

    return 0;
}