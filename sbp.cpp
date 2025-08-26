#include <bits/stdc++.h>
#define task ""
#define int long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int cp(int x)
{
    if (sqrt(x) * sqrt(x) == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check(int x, int n)
{
    if (cp(x) && x % n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sub1(int n)
{
    int ans = n * n;
    while (!check(ans, n))
    {
        ans--;
    }
    std::cout << ans;
}

void sub2(int n)
{
    std::cout << (n - 1) * (n - 1);
}

int n;

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
    if (n <= 1e3)
    {
        sub1(n);
    }
    else
    {
        sub2(n);
    }

    return 0;
}
