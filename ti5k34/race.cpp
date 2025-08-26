#include <bits/stdc++.h>
#define task "race"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5; // 10^5

int n;

int a[maxn + 7];

int sub1()
{
    int ans = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ans = std::min(ans, abs(a[i] - a[j]));
            }
        }
    }

    return ans;
}

int sub2()
{
    std::sort(a + 1, a + n + 1);
    int ans = LLONG_MAX;
    for (int i = 2; i <= n; i++)
    {
        ans = std::min(ans, a[i] - a[i - 1]);
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
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    // std::cout << sub1() << " " << sub2() << "\n";

    if (n <= 1000)
    {
        std::cout << sub1();
    }
    else
    {
        std::cout << sub2();
    }

    return 0;
}
