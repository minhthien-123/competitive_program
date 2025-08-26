#include <bits/stdc++.h>
#define task "bonso"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int prime[maxn];

void sieve()
{
    for (int i = 1; i <= maxn; i++)
    {
        prime[i] = 1;
    }

    for (int i = 2; i <= maxn; i++)
    {
        for (int j = i; j <= maxn; j += i)
        {
            prime[j]++;
        }
    }
}

void sub1(int n)
{
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i + j == n)
            {
                int d1 = 0, d2 = 0;
                for (int k = 1; k <= i; k++)
                {
                    if (i % k == 0)
                    {
                        d1++;
                    }
                }

                for (int k = 1; k <= j; k++)
                {
                    if (j % k == 0)
                    {
                        d2++;
                    }
                }

                ans += d1 * d2;
            }
        }
    }

    std::cout << ans;
}

void sub2(int n)
{
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        int j = n - i;
        int d1 = 0, d2 = 0;
        for (int k = 1; k <= i; k++)
        {
            if (i % k == 0)
            {
                d1++;
            }
        }

        for (int k = 1; k <= j; k++)
        {
            if (j % k == 0)
            {
                d2++;
            }
        }

        ans += d1 * d2;
    }

    std::cout << ans;
}

void sub3(int n)
{
    sieve();

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int j = n - i;
        ans += prime[i] * prime[j];
    }

    std::cout << ans;

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

    int n;
    std::cin >> n;

    if (n <= 100)
    {
        sub1(n);
    }else if (n <= 1000)
    {
        sub2(n);
    }
    else
    {
        sub3(n);
    }

    return 0;
}
