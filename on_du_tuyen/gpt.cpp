#include <bits/stdc++.h>
#define task "gpt"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e9;
const int inf  = 1e18;
const int mod  = 1e9 + 7;
const int inv  = (mod + 1) / 2;

int k, n;
int a[] = {0, 1, 6, 1, 6, 5, 6, 1, 6, 1};
int b[] = {0, 1, 4, 9, 6, 5, 6, 9, 4, 1};

int solve(int x)
{
    int sum = 0;
    for (int i = 1; i <= x; i++)
    {
        sum += a[i];
        sum %= 10;
    }

    return sum;
}

int solvek(int x)
{
    int sum = 0;
    for (int i = 1; i <= x; i++)
    {
        sum += b[i];
        sum %= 10;
    }

    return sum;
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

    std::cin >> k >> n;

    int m = n / 10;

    n = n % 10;

    int res;

    if (k == 1)
    {
        res = solvek(9);
    }
    else
    {
        res = solve(9);
    }

    res %= 10;

    //std::cout << res << "\n";

    int ans = res * m;

    //std::cout << n << "\n";

    //std::cout << solve(n) << "\n";

    ans %= 10;

    if (k == 1)
    {
        ans += solvek(n);
    }
    else
    {
        ans += solve(n);
    }

    ans %= 10;

    std::cout << ans;

    return 0;
}
