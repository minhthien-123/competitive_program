#include <bits/stdc++.h>
#define task "even"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

int n;

int s(int x)
{
    return x * (x + 2) / 4;
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

    n *= 4;

    int ans = sqrt(n);

    if (ans % 2 != 0)
    {
        ans++;
    }

    while (s(ans) > (n / 4))
    {
        ans -= 2;
    }

    std::cout << ans;

    return 0;
}


// n * (n + 1) / 2 <= k
// n * (n + 1) <= 2k
// n * n <= n * (n + 1) <= 2k  
// n <= sqrt(2k)