#include <bits/stdc++.h>
#define task "special"
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

bool check(int n)
{
    while (n > 0)
    {
        int tmp = n % 10;
        if (tmp != 3 && tmp != 6 && tmp != 9)
        {
            return false;
        }
        n /= 10;
    }

    return true;
}

void sub1(int n)
{
    n = pow(10, n) - 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            ans++;
        }
    }

    std::cout << ans;
}

void sub2(int n)
{
    std::cout << 3 * ((int)pow(3, n) - 1) / 2;
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

    for (int i = 1; i <= n; i++)
    {
        sub1(i);
        std::cout << " ";
        sub2(i);
        std::cout << "\n";
    }

    return 0;
}
