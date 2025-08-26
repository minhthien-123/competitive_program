#include <bits/stdc++.h>
#define task "sub"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e6 + 7;

int s, d = 0, n;
int a[maxn];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    if (std::fopen(task".inp", "r"))
    {
        std::freopen(task".inp", "r", stdin);
        std::freopen(task".out", "w", stdout);
    }

    std::cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    int d = 0;
    int l = 1;
    int ans = LLONG_MAX;

    for (int i = 1; i <= n; i++)
    {
        d += a[i];
        while (d >= s)
        {
            ans = std::min(ans, i - l + 1);
            d -= a[l++];
        }
    }

    std::cout << ans;

    return 0;
}
