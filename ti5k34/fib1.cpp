#include <bits/stdc++.h>
#define task "fib1"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5 + 7;
int q;
int f[maxn];

char solve(int n, int k)
{
    if (n == 0) return 'a';
    if (n == 1) return 'b';
    if (k <= f[n - 2]) return solve(n - 2, k);
    return solve(n - 1, k - f[n - 2]);
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

    f[0] = f[1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    std::cin >> q;
    while (q--)
    {
        int n, k;
        std::cin >> n >> k;
        std::cout << solve(n, k) << "\n";
    }

    return 0;
}
