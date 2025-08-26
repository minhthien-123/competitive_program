#include <bits/stdc++.h>
#define task "baophu"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;

int n;
int a[maxn + 7];

int sub1()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x = a[i];
            int y = a[j];

            int a1 = abs(std::min(x, y));
            int a2 = abs(std::max(x, y));
            int b1 = abs(std::min(x + y, x - y));
            int b2 = abs(std::max(x + y, x - y));

            if (b1 <= a1 && a2 <= b2)
            {
                ans++;
                std::cout << i << " " << j << "\n";
            }
        }
    }

    return ans;
}

int sub2()
{
    std::sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int cnt = std::upper_bound(a + 1, a + n + 1, a[i] * 2) - a - 1;
        if (a[cnt] > 2 * a[i]) cnt--;
        if (cnt >= i)
        {
            ans += cnt - i;
        }
    }
    return ans;
}

int sub3()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            a[i] = -a[i];
        }
    }
    std::sort(a + 1, a + n + 1);
    int ans = 0;
    int i = 1, j = 1;
    while (i <= n)
    {
        while (a[j] <= a[i] * 2 && j <= n)
        {
            j++;
        }
        if (j - i - 1 >= 0)
        {
            ans += j - i - 1;
        }
        i++;
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
    int d = 0;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        if (a[i] >= 1)
        {
            d++;
        }
    }

    // std::cout << sub1() << "\n" << sub2() << "\n" << sub3() << "\n";

    // if (n <= 1000)
    // {
    //     std::cout << sub1();
    // }
    // else if (d == n)
    // {
    //     std::cout << sub2();
    // }
    // else
    // {
    //     std::cout << sub3();
    // }

    std::cout << sub1();

    return 0;
}
