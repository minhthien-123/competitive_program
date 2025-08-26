#include <bits/stdc++.h>
#define task "team"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int f[maxn];
int n, d;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> d;

    memset(f, 0, sizeof f);

    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        f[x]++;
    }

    int ans = 0;

    for (int i = d; i <= maxn; i++)
    {
        if (f[i] > 1)
        {
            ans += (f[i] * (f[i] - 1)) / 2;
        }
    }

    std::cout << ans;

    return 0;
}
